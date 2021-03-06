#ifndef MATRIX_H_
#define	MATRIX_H_

#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

namespace mario
{
#define		EPSINON		1e-14

	bool isEqual(const double &_num1, const double &_num2);

	typedef class Matrix
	{
	private:
		int m_row;
		int m_col;
		double *m_data;

	public:
		Matrix();
		Matrix(const int &_row, const int &_col, const double &_e = 0);
		Matrix(const Matrix &_m);

		~Matrix();

		void release();

		int rows() const;

		int cols() const;

		bool isSquareMatrix() const;

		double* getRowPoint(const int &_r) const;

		double get(const int &_row, const int &_col) const;

		bool set(const int &_row, const int &_col, const double &_e);

		double getDet() const;

		Matrix inv_LU() const;

		Matrix T() const;

		Matrix mul(const Matrix &_m) const;

		double dot(const Matrix &_m) const;

		double operator()(const int &_row, const int &_col) const;

		Matrix& operator=(const Matrix &_m);

		Matrix row(const int &_i) const;

		Matrix col(const int &_i) const;

		Matrix block(const int &_row, const int &_col, const int &_height, const int &_width) const;

		Matrix sumByRow() const;

		Matrix sumByCol() const;

		Matrix meanByRow() const;

		Matrix meanByCol() const;

		Matrix log2() const;

		Matrix sqrt() const;

		Matrix exp() const;

		Matrix sin() const;

		Matrix cos() const;

		Matrix tan() const;

		Matrix sigmoid() const;

		Matrix tanh() const;

		Matrix relu() const;

		friend Matrix diag(const int &_n, const double &_e);

		friend Matrix operator+(const Matrix &_m1, const Matrix &_m2);

		friend Matrix& operator+=(Matrix &_m1, const Matrix &_m2);

		friend Matrix operator+(const Matrix &_m, const double &_e);

		friend Matrix operator+(const double &_e, const Matrix &_m);

		friend Matrix& operator+=(Matrix &_m, const double &_e);

		friend Matrix operator-(const Matrix &_m1, const Matrix &_m2);

		friend Matrix& operator-=(Matrix &_m1, const Matrix &_m2);

		friend Matrix operator-(const Matrix &_m, const double &_e);

		friend Matrix operator-(const double &_e, const Matrix &_m);

		friend Matrix& operator-=(Matrix &_m, const double &_e);

		friend Matrix operator*(const Matrix &_m1, const Matrix &_m2);

		friend Matrix operator*(const Matrix &_m, const double &_e);

		friend Matrix operator*(const double &_e, const Matrix &_m);

		friend Matrix& operator*=(Matrix &_m, const double &_e);

		friend Matrix operator/(const Matrix &_m, const double &_e);

		friend Matrix operator/(const Matrix &_m1, const Matrix &_m2);

		friend Matrix& operator/=(Matrix &_m, const double &_e);

		friend Matrix operator/(const double &_e, const Matrix &_m);

		friend Matrix matrixRand(const int &_row, const int &_col, const double &_start, const double &_end);

		friend Matrix copyRow(const Matrix &_m, const int &_rowNum);

		friend ostream& operator<<(ostream &_out, const Matrix &_m);

	protected:
		bool swapRow(const int &_i, const int &_j);

	}matrix;	//	!matrix

	Matrix diag(const int &_n, const double &_e);

	Matrix operator+(const Matrix &_m1, const Matrix &_m2);

	Matrix& operator+=(Matrix &_m1, const Matrix &_m2);

	Matrix operator+(const Matrix &_m, const double &_e);

	Matrix operator+(const double &_e, const Matrix &_m);

	Matrix& operator+=(Matrix &_m, const double &_e);

	Matrix operator-(const Matrix &_m1, const Matrix &_m2);

	Matrix& operator-=(Matrix &_m1, const Matrix &_m2);

	Matrix operator-(const Matrix &_m, const double &_e);

	Matrix operator-(const double &_e, const Matrix &_m);

	Matrix& operator-=(Matrix &_m, const double &_e);

	Matrix operator*(const Matrix &_m1, const Matrix &_m2);

	Matrix operator*(const Matrix &_m, const double &_e);

	Matrix operator*(const double &_e, const Matrix &_m);

	Matrix& operator*=(Matrix &_m, const double &_e);

	Matrix operator/(const Matrix &_m, const double &_e);

	Matrix operator/(const Matrix &_m1, const Matrix &_m2);

	Matrix& operator/=(Matrix &_m, const double &_e);

	Matrix operator/(const double &_e, const Matrix &_m);

	Matrix matrixRand(const int &_row, const int &_col, const double &_start = -1, const double &_end = 1);

	ostream& operator<<(ostream &_out, const Matrix &_m);

}		//!mario

#endif // !MATRIX_H_
