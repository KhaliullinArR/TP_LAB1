#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "List.h"


class Vector {

public:
	Vector(const int length = 1);
	Vector(const Vector& vector);
	void setCoor(List<double>& list);
	 List<double>& getCoor();
	~Vector();
	int getDim();
	Vector& operator= (const Vector& vector);
	friend Vector operator +(const Vector& vector1, const Vector& vector2);
	friend Vector operator -(const Vector& vector1, const Vector& vector2);
	friend Vector operator *(const double a, const Vector& vector1);
	friend Vector operator *(const Vector& vector1, const double a);
	friend double operator *(const Vector& vector1, const Vector& vector2);
	friend std::ostream& operator<<(std::ostream& out, Vector& vector);
	friend std::istream& operator>>(std::istream& in, Vector& vector);
	friend class Matrix;
	

private:
	List<double> coor;
	int dim;

};


std::ostream& operator<<(std::ostream& out, Vector &vector);
std::istream& operator>>(std::istream& in, Vector &vector);

#endif

