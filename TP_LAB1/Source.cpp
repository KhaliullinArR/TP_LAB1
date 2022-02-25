#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "Exception.h"
using namespace std;




int main(int argc, char *argv[]) {

	try {
		/*int length;

		cout << "Input a vector's length: ";
		cin >> length;
		Vector a(length);
		List<double> list;
		list.append(1);
		list.append(2);
		list.append(3);
		a.setCoor(list);*/
		/*cout << "Input vectors' coordinates: ";
		cin >> a;*/

		//cout << "Your vector: " << a << endl;

		/*cout << "Input a vector's length: ";
		cin >> length;
		Vector b(length);
		cout << "Input vectors' coordinates: ";
		cin >> b;

		cout << "Your vector: " << b << endl;

		Vector c = a - b;


		cout << "Their sum: " << c;*/
		int m, n;

		cin >> m >> n;
		Matrix matrix1(m, n);


		cout << endl;

		cin >> matrix1;

		cout << endl;
		cout << matrix1 << endl;

		cin >> m >> n;

		Matrix matrix2(m, n);
		cout << endl;

		cin >> matrix2;

		cout << endl;
		cout << matrix2 << endl;

		Matrix matrix3(3, 4);

		matrix3 = matrix1 * matrix2;

		cout << matrix3;
		


	}
	catch (VectorException& ex) {
		cout << ex.getException();
	}


}