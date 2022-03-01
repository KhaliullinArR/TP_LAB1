#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "Exception.h"
using namespace std;


void AddVectors() {
	int m, n;
	cout << "Введите размерность первого вектора: ";
	cin >> m;
	cout << "Введите координаты первого вектора: ";
	Vector vector1(m);
	cin >> vector1;

	cout << "Введите размерность второго вектора: ";
	cin >> n;
	cout << "Введите координаты второго вектора: ";
	Vector vector2(n);
	cin >> vector2;
	cout << "Первый вектор: " << vector1 << endl;
	cout << "Второй вектор: " << vector2 << endl;
	Vector res(m);
	res = vector1 + vector2;
	cout << "Результат их сложения: " << res << endl;
}

void SubtractVectors() {
	int m, n;
	cout << "Введите размерность первого вектора: ";
	cin >> m;
	cout << "Введите координаты первого вектора: ";
	Vector vector1(m);
	cin >> vector1;

	cout << "Введите размерность второго вектора: ";
	cin >> n;
	cout << "Введите координаты второго вектора: ";
	Vector vector2(n);
	cin >> vector2;
	cout << "Первый вектор: " << vector1 << endl;
	cout << "Второй вектор: " << vector2 << endl;
	Vector res(m);
	res = vector1 - vector2;
	cout << "Результат их вычитания: " << res << endl;
}

void MultiplyVectors() {
	int m, n;
	cout << "Введите размерность первого вектора: ";
	cin >> m;
	cout << "Введите координаты первого вектора: ";
	Vector vector1(m);
	cin >> vector1;

	cout << "Введите размерность второго вектора: ";
	cin >> n;
	cout << "Введите координаты второго вектора: ";
	Vector vector2(n);
	cin >> vector2;
	cout << "Первый вектор: " << vector1 << endl;
	cout << "Второй вектор: " << vector2 << endl;
	double res = vector1 * vector2;
	cout << "Результат их умножения: " << res << endl;
}

void MultiplyByNumberVectors() {
	int m;
	cout << "Введите размерность первого вектора: ";
	cin >> m;
	cout << "Введите координаты первого вектора: ";
	Vector vector1(m);
	cin >> vector1;

	double a;

	cout << "Введите число, на которое хотите умножить: ";
	cin >> a;

	Vector res(m);
	res = vector1 * a;
	cout << "Результат умножения на число: " << res << endl;
}

void AddMatrix() {
	int m1, n1, m2, n2;
	cout << "Введите размерность первой матрицы: ";
	cin >> m1 >> n1;
	cout << "Введите координаты первой матрицы: " << endl;
	Matrix matrix1(m1, n1);
	cin >> matrix1;

	cout << "Введите размерность второй матрицы: ";
	cin >> m2 >> n2;
	cout << "Введите координаты второй матрицы: " << endl;
	Matrix matrix2(m2, n2);
	cin >> matrix2;
	cout << "Первая матрица: " << matrix1 << endl;
	cout << "Вторая матрица: " << matrix2 << endl;
	Matrix res(m1, n1);
	res = matrix1 + matrix2;
	cout << "Результат их сложения: " << res << endl;


}


void SubtractMatrix() {
	int m1, n1, m2, n2;
	cout << "Введите размерность первой матрицы: ";
	cin >> m1 >> n1;
	cout << "Введите координаты первой матрицы: " << endl;
	Matrix matrix1(m1, n1);
	cin >> matrix1;

	cout << "Введите размерность второй матрицы: ";
	cin >> m2 >> n2;
	cout << "Введите координаты второй матрицы: " << endl;
	Matrix matrix2(m2, n2);
	cin >> matrix2;
	cout << "Первая матрица: " << endl << matrix1 << endl;
	cout << "Вторая матрица: " << endl << matrix2 << endl;
	Matrix res(m1, n1);
	res = matrix1 - matrix2;
	cout << "Результат их вычитания: " << res << endl;


}


void MultiplyMatrix() {
	int m1, n1, m2, n2;
	cout << "Введите размерность первой матрицы: ";
	cin >> m1 >> n1;
	cout << "Введите координаты первой матрицы: " << endl;
	Matrix matrix1(m1, n1);
	cin >> matrix1;

	cout << "Введите размерность второй матрицы: ";
	cin >> m2 >> n2;
	cout << "Введите координаты второй матрицы: " << endl;
	Matrix matrix2(m2, n2);
	cin >> matrix2;
	cout << "Первая матрица: " << endl << matrix1 << endl;
	cout << "Вторая матрица: " << endl << matrix2 << endl;
	Matrix res(m1, n2);
	res = matrix1 * matrix2;
	cout << "Результат их умножения: " << res << endl;


}


void MultiplyByNumberMatrix() {
	int m1, n1;
	cout << "Введите размерность первой матрицы: ";
	cin >> m1 >> n1;
	cout << "Введите координаты первой матрицы: " << endl;
	Matrix matrix1(m1, n1);
	cin >> matrix1;

	cout << "Введите число, на которое хотите умножить: ";
	double a;
	cin >> a;
	cout << "Первая матрица: " << endl << matrix1 << endl;
	Matrix res(m1, n1);
	res = matrix1 * a;
	cout << "Результат умножения на чиcло: " << res << endl;


}

int main(int argc, char *argv[]) {

	setlocale(LC_ALL, "Russian");

	while (true) {
		cout << "Выберите объект, с которым вы хотите работать." << endl;
		cout << "V - вектор, М - матрица" << endl;
		char temp;
		cin >> temp;

		if (temp == 'V') {
			cout << "Выберите операцию, которую хотите выполнить:" << endl;
			cout << "1 - Сложение векторов." << endl;
			cout << "2 - Вычитание векторов." << endl;
			cout << "3 - Умножение векторов." << endl;
			cout << "4 - Умножение вектора на число." << endl;
			cout << "Введите номер операции: ";
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
		cout << "Выберите операцию, которую хотите выполнить:" << endl;
		cout << "1 - Сложение матриц." << endl;
		cout << "2 - Вычитание матриц." << endl;
		cout << "3 - Умножение матриц." << endl;
		cout << "4 - Умножение матрицы на число." << endl;
		cout << "Введите номер операции: ";
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


		cout << "Хотите продолжить работу? [Y/N]: ";
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