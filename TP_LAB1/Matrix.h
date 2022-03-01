#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Vector.h"
#include "List.h"



class Matrix {

public:
	Matrix(const Matrix& matrix);
	Matrix(const int m = 1, const int n = 1);
	~Matrix();
	int getColumnsCount();
	int getRawsCount();
	Matrix& operator=(const Matrix& matrix);
	//setAnElement(const int i, const int j);


	//void setCoor();



	friend Matrix operator +(const Matrix& matrix1, const Matrix& matrix2);
	friend Matrix operator -(const Matrix& matrix1, const Matrix& matrix2);
	friend Matrix operator *(const double a, const Matrix& matrix1);
	friend Matrix operator *(const Matrix& matrix1, const double a);
	friend Matrix operator *(const Matrix& matrix1, const Matrix& matrix2);
	friend std::ostream& operator<<(std::ostream& out, Matrix& matrix);
	friend std::istream& operator>>(std::istream& in, Matrix& matrix);

private:
	int m, n;
	List<Vector> raws;

};


std::ostream& operator<<(std::ostream& out, Matrix& matrix);
std::istream& operator>>(std::istream& in, Matrix& matrix);

#endif


