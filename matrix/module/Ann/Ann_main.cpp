#include "config.hpp"
#include "Graph.hpp"

using namespace mario;

matrix x = mario::matrixRand(8000, 8, 0, 1);
matrix theta = mario::matrixRand(8, 1, 0, 1);
matrix bias = mario::matrixRand(1, 1, 0, 1);

matrix y = (x*theta + bias) + mario::matrixRand(8000, 1, -0.01, 0.01);

void test1()
{
	try
	{
		mario::Operator *fc = new Fc(8, 1);
		mario::Operator *sig = new Sigmoid(1);
		mario::Operator *mse = new Mse(1);

		double loss = 0;
		double lr = 5.;
		double lrDecay = 1.;

		for (int i = 1; i <= 10000; ++i)
		{
			matrix fc_out = fc->forward(x.block(0, 0, 4000, x.cols()));
			matrix sig_out = sig->forward(fc_out);
			matrix mse_out = mse->forward(sig_out);


			if (0 == i % 1000)
			{
				lr *= lrDecay;
			}

			matrix mse_back = mse->backward(y.block(0, 0, 4000, y.cols()));
			matrix sig_back = sig->backward(mse_back);
			matrix fc_back = fc->backward(sig_back);
			fc->update(lr);

			if (0 == i % 1000)
			{
				fc_out = fc->forward(x.block(4000, 0, 4000, x.cols()));
				sig_out = sig->forward(fc_out);
				mse_out = mse->forward(sig_out);

				mse_back = mse->backward(y.block(4000, 0, 4000, y.cols()));

				loss = mse->getLoss();
				cout << i << ":\t" << loss << "\tLearning Rate: " << lr << endl;
			}


			if (10000 == i)
			{
				cout << y.block(0, 0, 100, y.cols()) << endl;
				cout << (mse_out - y).block(0, 0, 100, y.cols()) << endl;
			}
		}
	}
	catch(const char *e)
	{
		cerr << e << endl;
	}

	/*cout << fc->getW() - theta << endl;
	cout << fc->getB() - bias << endl;*/
}

void test2()
{
	try
	{
		Graph graph;

		//feed train and test data
		graph.loadTrainData(x.block(0, 0, 7500, x.cols()), y.block(0, 0, 7500, y.cols()));
		graph.loadTestData(x.block(7500, 0, 500, x.cols()), y.block(7500, 0, 500, y.cols()));

		//set parameters
		graph.setBatchSize(400);
		graph.setLrDecay(0.95, 5000);
		graph.setLearningRate(.5);

		//set network structure
		graph.clearStruct();
		graph.addFullConnection(8, 4);
		graph.addSigmoid(4);
		graph.addFullConnection(4, 1);
		graph.addMse(1);

		//init structure
		graph.init();

		for (int ite = 1; ite <= 20000; ++ite)
		{
			//train and show its loss
			graph.train();
			if (0 == ite % 2000)
			{
				cout << ite << "\n    trainLoss: " << graph.getLoss();

				//predict and show its loss
				graph.predict();
				cout << ite << "\t    testLoss: "<< graph.getLoss() << endl;
				cout << "==============================\n";
			}
		}
	}
	catch(const char *e)
	{
		cerr << e << endl;
	}
}

int main(int argc, char **argv)
{
//	test1();

	test2();

	return 0;
}
