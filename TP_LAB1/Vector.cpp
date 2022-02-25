#include "Vector.h"
#include "Exception.h"
#include "List.cpp"
#include <iostream>
#include <iomanip>

Vector::Vector(const int length):dim(0){

	if (length < 0) throw NegativeDimException();

	dim = length;

	/*for (size_t i = 0; i < length; i++)
		coor.append(0);*/


}

Vector::Vector(const Vector& vector){
	*this = vector;
}

void Vector::setCoor(List<double> &list){

	if (list.size() != this->dim)throw VectorException();


	if (coor.size() == 0) {


		List<double>::Iterator it = list.begin();

		for (; it != list.end(); ++it)
			coor.append(*it);
	}else {

		List<double>::Iterator it = list.begin();
		List<double>::Iterator it_this = coor.begin();

		for (; it != list.end(); ++it, ++it_this)
			*it_this = *it;
	}

	
	
}

List<double>& Vector::getCoor()
{
	return coor;
}

Vector::~Vector(){
}



int Vector::getDim()
{
	return dim;
}

Vector& Vector::operator=(const Vector& vector)
{
	if (this == &vector)
		return *this;
	
	dim = vector.dim;
	coor.~List();

	List<double>::Iterator it = vector.coor.begin();

	for (;it != vector.coor.end(); ++it) 
		coor.append(*it);
	


	return *this;
}

Vector operator+(const Vector& vector1, const Vector& vector2)
{
	if (vector1.dim != vector2.dim)throw DifferentDimException();

	Vector temp(vector1.dim);

	List<double>::Iterator it1 = vector1.coor.begin();
	List<double>::Iterator it2 = vector2.coor.begin();

	for (; it1 != vector1.coor.end(); ++it1, ++it2)
		temp.coor.append(*it1 + *it2);



	return temp;
}

Vector operator-(const Vector& vector1, const Vector& vector2)
{
	if (vector1.dim != vector2.dim)throw DifferentDimException();

	Vector temp(vector1.dim);

	List<double>::Iterator it1 = vector1.coor.begin();
	List<double>::Iterator it2 = vector2.coor.begin();

	for (; it1 != vector1.coor.end(); ++it1, ++it2)
		temp.coor.append(*it1 - *it2);



	return temp;
}

Vector operator*(const double a, const Vector& vector1)
{
	Vector temp(vector1.dim);


	List<double>::Iterator it = vector1.coor.begin();
	

	for (; it != vector1.coor.end(); ++it)
		temp.coor.append(a * *it);



	return temp;
}

Vector operator*(const Vector& vector1, const double a)
{
	return  a * vector1;
}

double operator*(const Vector& vector1, const Vector& vector2)
{
	if (vector1.dim != vector2.dim)throw DifferentDimException();


	List<double>::Iterator it1 = vector1.coor.begin();
	List<double>::Iterator it2 = vector2.coor.begin();

	double res = 0;

	for (; it1 != vector1.coor.end(); ++it1, ++it2)
		res += *it1 * (*it2);

	return res;
}

std::ostream& operator<<(std::ostream& out, Vector& vector)
{

	List<double>::Iterator it = vector.coor.begin();


	std::cout << "|";
	for (; it != vector.coor.end(); ++it)
		std::cout << std::setw(3) << *it;
	std::cout << std::setw(3) <<"|";

	return out;
}

std::istream& operator>>(std::istream& in, Vector& vector)
{


	double temp;
	for (size_t i = 0; i < vector.dim; i++)
	{
		std::cin >> temp;
		vector.coor.append(temp);
	}

	return in;
}
