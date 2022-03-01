#include "Matrix.h"
#include "Vector.h"
#include "Exception.h"
#include "ListException.h"
#include "List.cpp"
#include <iostream>
#include <iomanip>

Matrix::Matrix(const Matrix& matrix):Matrix(matrix.m, matrix.n){
	(*this) = matrix;
}

Matrix::Matrix(const int m, const int n): m(m), n(n){

	if (m <= 0 || n <= 0) throw MatrixDimException();

	for (size_t i = 0; i < m; i++){
		Vector vector(n);
		raws.append(vector);
	}

}

Matrix::~Matrix()
{
}

int Matrix::getColumnsCount()
{
	return n;
}

int Matrix::getRawsCount()
{
	return n;
}

Matrix& Matrix::operator=(const Matrix& matrix)
{

	if ((matrix.m != this->m) || (matrix.n != this->n)) throw MatrixDimException();
	
	if (this == &matrix)
		return *this;

	List<Vector>::Iterator it_this = raws.begin();
	List<Vector>::Iterator it = matrix.raws.begin();
	
	for (; it != raws.end(); ++it, ++it_this)
		(*it_this) = (*it);

	

	return *this;
}

Matrix operator+(const Matrix& matrix1, const Matrix& matrix2)
{

	if ((matrix1.m != matrix2.m) || (matrix1.n != matrix2.n)) throw MatrixDimException();

	//Ex
	Matrix temp(matrix1.m, matrix1.n);

	List<Vector>::Iterator it1 = matrix1.raws.begin();
	List<Vector>::Iterator it2 = matrix2.raws.begin();
	List<Vector>::Iterator temp_it = temp.raws.begin();


	for (; it1 != matrix1.raws.end(); ++it1, ++it2, ++temp_it) {

		(*temp_it) = (*it1) + (*it2);
	}

	return temp;
}

Matrix operator-(const Matrix& matrix1, const Matrix& matrix2)
{

	if ((matrix1.m != matrix2.m) || (matrix1.n != matrix2.n)) throw MatrixDimException();

	Matrix temp(matrix1.m, matrix1.n);

	List<Vector>::Iterator it1 = matrix1.raws.begin();
	List<Vector>::Iterator it2 = matrix2.raws.begin();
	List<Vector>::Iterator temp_it = temp.raws.begin();


	for (; it1 != matrix1.raws.end(); ++it1, ++it2, ++temp_it) {

		(*temp_it) = (*it1) - (*it2);
	}

	return temp;
}

Matrix operator*(const double a, const Matrix& matrix1)
{
	Matrix temp(matrix1.m, matrix1.n);

	List<Vector>::Iterator it1 = matrix1.raws.begin();
	List<Vector>::Iterator temp_it = temp.raws.begin();


	for (; it1 != matrix1.raws.end(); ++it1, ++temp_it) {

		(*temp_it) = a * (*it1);
	}

	return temp;
}

Matrix operator*(const Matrix& matrix1, const double a)
{
	return a * matrix1;
}

Matrix operator*(const Matrix& matrix1, const Matrix& matrix2)
{

	if (matrix1.n != matrix2.m) throw MatrixDimException();

	Matrix temp(matrix1.m, matrix2.n);

	List<Vector>::Iterator it1 = matrix1.raws.begin();
	List<Vector>::Iterator it2 = matrix2.raws.begin();
	List<Vector>::Iterator temp_it = temp.raws.begin();

	List<List<double>::Iterator> list;

	for (; it2 != matrix2.raws.end(); ++it2)
	{
		list.append((*it2).getCoor().begin());
	}

	List<Vector> vectors;


	Vector temp_ve(matrix2.m);
	for (size_t i = 0; i < matrix2.n; i++)
	{
		List<List<double>::Iterator>::Iterator list_it = list.begin();
		List<double> coor;
		for (; list_it!=list.end(); ++list_it)
		{
			coor.append(*(*list_it));
			++(*list_it);
		}
		
		temp_ve.setCoor(coor);
		vectors.append(temp_ve);
	}



	Vector raw(matrix2.n);
	List<Vector> ::Iterator it = vectors.begin();
	for (; it1 != matrix1.raws.end(); ++it1, ++temp_it){
		List<double> coor;
		it = vectors.begin();
		for (; it != vectors.end(); ++it)
		{
			coor.append((*it1) * (*it));
		}
		raw.setCoor(coor);
		(*temp_it) = raw;
	}
	
	

	return temp;
}


std::ostream& operator<<(std::ostream& out, Matrix& matrix) {
	
	std::cout << std::endl;

	
	List<Vector>::Iterator it = matrix.raws.begin();
	for (; it != matrix.raws.end(); ++it) {
		std::cout << *it;
		std::cout << std::endl;
	}
	

	return out;
}

std::istream& operator>>(std::istream& in, Matrix& matrix)
{
	List<Vector>::Iterator it = matrix.raws.begin();

	for (size_t i = 0; i < matrix.m; i++) {
		
		
		std::cin >> *it;
		++it;
		
	}


	return in;
}
