#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "Exception.h"
using namespace std;


void AddVectors() {
	int m, n;
	cout << "������� ����������� ������� �������: ";
	cin >> m;
	cout << "������� ���������� ������� �������: ";
	Vector vector1(m);
	cin >> vector1;

	cout << "������� ����������� ������� �������: ";
	cin >> n;
	cout << "������� ���������� ������� �������: ";
	Vector vector2(n);
	cin >> vector2;
	cout << "������ ������: " << vector1 << endl;
	cout << "������ ������: " << vector2 << endl;
	Vector res(m);
	res = vector1 + vector2;
	cout << "��������� �� ��������: " << res << endl;
}

void SubtractVectors() {
	int m, n;
	cout << "������� ����������� ������� �������: ";
	cin >> m;
	cout << "������� ���������� ������� �������: ";
	Vector vector1(m);
	cin >> vector1;

	cout << "������� ����������� ������� �������: ";
	cin >> n;
	cout << "������� ���������� ������� �������: ";
	Vector vector2(n);
	cin >> vector2;
	cout << "������ ������: " << vector1 << endl;
	cout << "������ ������: " << vector2 << endl;
	Vector res(m);
	res = vector1 - vector2;
	cout << "��������� �� ���������: " << res << endl;
}

void MultiplyVectors() {
	int m, n;
	cout << "������� ����������� ������� �������: ";
	cin >> m;
	cout << "������� ���������� ������� �������: ";
	Vector vector1(m);
	cin >> vector1;

	cout << "������� ����������� ������� �������: ";
	cin >> n;
	cout << "������� ���������� ������� �������: ";
	Vector vector2(n);
	cin >> vector2;
	cout << "������ ������: " << vector1 << endl;
	cout << "������ ������: " << vector2 << endl;
	double res = vector1 * vector2;
	cout << "��������� �� ���������: " << res << endl;
}

void MultiplyByNumberVectors() {
	int m;
	cout << "������� ����������� ������� �������: ";
	cin >> m;
	cout << "������� ���������� ������� �������: ";
	Vector vector1(m);
	cin >> vector1;

	double a;

	cout << "������� �����, �� ������� ������ ��������: ";
	cin >> a;

	Vector res(m);
	res = vector1 * a;
	cout << "��������� ��������� �� �����: " << res << endl;
}

void AddMatrix() {
	int m1, n1, m2, n2;
	cout << "������� ����������� ������ �������: ";
	cin >> m1 >> n1;
	cout << "������� ���������� ������ �������: " << endl;
	Matrix matrix1(m1, n1);
	cin >> matrix1;

	cout << "������� ����������� ������ �������: ";
	cin >> m2 >> n2;
	cout << "������� ���������� ������ �������: " << endl;
	Matrix matrix2(m2, n2);
	cin >> matrix2;
	cout << "������ �������: " << matrix1 << endl;
	cout << "������ �������: " << matrix2 << endl;
	Matrix res(m1, n1);
	res = matrix1 + matrix2;
	cout << "��������� �� ��������: " << res << endl;


}


void SubtractMatrix() {
	int m1, n1, m2, n2;
	cout << "������� ����������� ������ �������: ";
	cin >> m1 >> n1;
	cout << "������� ���������� ������ �������: " << endl;
	Matrix matrix1(m1, n1);
	cin >> matrix1;

	cout << "������� ����������� ������ �������: ";
	cin >> m2 >> n2;
	cout << "������� ���������� ������ �������: " << endl;
	Matrix matrix2(m2, n2);
	cin >> matrix2;
	cout << "������ �������: " << endl << matrix1 << endl;
	cout << "������ �������: " << endl << matrix2 << endl;
	Matrix res(m1, n1);
	res = matrix1 - matrix2;
	cout << "��������� �� ���������: " << res << endl;


}


void MultiplyMatrix() {
	int m1, n1, m2, n2;
	cout << "������� ����������� ������ �������: ";
	cin >> m1 >> n1;
	cout << "������� ���������� ������ �������: " << endl;
	Matrix matrix1(m1, n1);
	cin >> matrix1;

	cout << "������� ����������� ������ �������: ";
	cin >> m2 >> n2;
	cout << "������� ���������� ������ �������: " << endl;
	Matrix matrix2(m2, n2);
	cin >> matrix2;
	cout << "������ �������: " << endl << matrix1 << endl;
	cout << "������ �������: " << endl << matrix2 << endl;
	Matrix res(m1, n2);
	res = matrix1 * matrix2;
	cout << "��������� �� ���������: " << res << endl;


}


void MultiplyByNumberMatrix() {
	int m1, n1;
	cout << "������� ����������� ������ �������: ";
	cin >> m1 >> n1;
	cout << "������� ���������� ������ �������: " << endl;
	Matrix matrix1(m1, n1);
	cin >> matrix1;

	cout << "������� �����, �� ������� ������ ��������: ";
	double a;
	cin >> a;
	cout << "������ �������: " << endl << matrix1 << endl;
	Matrix res(m1, n1);
	res = matrix1 * a;
	cout << "��������� ��������� �� ��c��: " << res << endl;


}

int main(int argc, char *argv[]) {

	setlocale(LC_ALL, "Russian");

	while (true) {
		cout << "�������� ������, � ������� �� ������ ��������." << endl;
		cout << "V - ������, � - �������" << endl;
		char temp;
		cin >> temp;

		if (temp == 'V') {
			cout << "�������� ��������, ������� ������ ���������:" << endl;
			cout << "1 - �������� ��������." << endl;
			cout << "2 - ��������� ��������." << endl;
			cout << "3 - ��������� ��������." << endl;
			cout << "4 - ��������� ������� �� �����." << endl;
			cout << "������� ����� ��������: ";
			cin >> temp;
			try {
				switch (temp) {
				case '1':
					AddVectors();
					break;
				case '2':
					SubtractVectors();
					break;
				case '3':
					MultiplyVectors();
					break;
				case '4':
					MultiplyByNumberVectors();
					break;

				}
			}
			catch (const VectorException &ex) {
				cout << ex.getException() << endl;
			}



		}
		else{
		cout << "�������� ��������, ������� ������ ���������:" << endl;
		cout << "1 - �������� ������." << endl;
		cout << "2 - ��������� ������." << endl;
		cout << "3 - ��������� ������." << endl;
		cout << "4 - ��������� ������� �� �����." << endl;
		cout << "������� ����� ��������: ";
		cin >> temp;

		try {
			switch (temp) {
			case '1':
				AddMatrix();
				break;
			case '2':
				SubtractMatrix();
				break;
			case '3':
				MultiplyMatrix();
				break;
			case '4':
				MultiplyByNumberMatrix();
				break;

			}
		}
		catch (const MatrixException& ex) {
			cout << ex.getException() << endl;
		}


		cout << "������ ���������� ������? [Y/N]: ";
		cin >> temp;

		if (temp != 'Y')break;

	}


	}



	/*try {
		int length;

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


		cout << "Their sum: " << c;
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
	}*/


}