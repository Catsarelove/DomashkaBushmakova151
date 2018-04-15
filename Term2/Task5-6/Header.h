#pragma once
#include <iostream>
#include <string>
using namespace std;
template <typename T, unsigned int N, unsigned int M>
class Matrix {
public:
	T** Mat;
	Matrix() {
		Mat = new T*[N];
		for (int i = 0; i < N; i++) {
			Mat[i] = new T[M];
		}
	}
	void free(){
			for (int i = 0; i < N; i++)
				delete[]Mat[i];
			delete[]Mat;
	}
	void read() {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> Mat[i][j];
	}
	void write() {
		if (Mat == NULL) cout << "Матрицы не существует\n";
		else {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++)
					cout << Mat[i][j] << ' ';
				cout << "\n";
			}
		}
	}
	T& getn(int i, int j){
		return Mat[i][j];
	}
	Matrix<T, N, M> & operator = (Matrix<T, N, M> & B) {
		try {
			if (!&B || !B.Mat) throw 13;
			if (this == &B) throw 14;
			free();
			Mat = new T*[N];
         	for (int i = 0; i < N; i++) {
				Mat[i] = new T[M];
			}			
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					Mat[i][j] = B.Mat[i][j];
			return *this;
		}
		catch (int err) {
			if (err == 13) {
				cout << "Присваиваемой матрицы не существует \n";
				Mat = NULL;
			}
				if (err == 14) cout << "Равно самому себе\n";
			}
		return*this;
	}
	Matrix<T, N, M>(Matrix<T, N, M> & B) {
		if (B.Mat) {
			Mat = new T*[N];
			for (int i = 0; i < N; i++)
				Mat[i] = new T[M];
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					Mat[i][j] = B.Mat[i][j];
		}
		else
			Mat = NULL;

	}
	~Matrix() {
		if(Mat && this)
		free();
	}

};
template <typename T, unsigned int M> class Matrix <T,1, M>{
public:	
	T*Mat;
	Matrix() {

		Mat = new T[M];

	}
	void read() {
		if (!Mat) {
			Mat = new T[M];
		}
		for (int i = 0; i < M; i++)
			cin >> Mat[i];
	}
	void write() {
		if (Mat) {
			for (int i = 0; i < M; i++)
				cout << Mat[i] << ' ';
			cout << "\n";
		}
		else
			cout << "Матрицы не существует\n";
	}
	Matrix<T, 1, M> & operator = (Matrix<T, 1, M> & B) {
		try {
			if (!&B || !B.Mat) throw 13;
			if (this == &B) throw 14;
			for (int i = 0; i < M; i++)
				Mat[i] = B.Mat[i];
			return *this;
		}
		catch (int err) {
			if (err == 13) {
				cout << "Присваиваемой матрицы не существует \n";
				Mat = NULL;
			}
			if (err == 14) cout << "Равно самому себе\n";
		}
		return*this;
	}
	Matrix<T, 1, M>(Matrix<T, 1, M> & B) {
		if (B.Mat) {
			Mat = new T[M];
			for (int i = 0; i < M; i++)
				Mat[i] = B.Mat[i];
		}
		else
			Mat = NULL;
	}
	T& getn(int i, int j){
		return Mat[i];
	}
	T& getn(int i) {
		return Mat[i];
	}
	~Matrix() {
		if(this&&Mat)
		delete[]Mat;
	}
};
template <typename T, unsigned int N, unsigned int M, unsigned int N1, unsigned int M1>
Matrix<T, N, M> operator + (Matrix<T, N, M> A, Matrix<T, N1, M1> B) {
	Matrix<T, N, M> C;
	try {
		if (N1 != N || M1 != M)
			throw 11;
		else {
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					C.getn(i, j) = A.getn(i, j) + B.getn(i, j);
			return C;
		}
	}
	catch (int err) {
		setlocale(0, "");
		cout << "Ошибка сложения: разные размеры матриц\n";
		C.Mat = NULL;
	}
	return C;
}
template <typename T, unsigned int M, unsigned int N1, unsigned int M1>
Matrix<T, 1, M> operator + (Matrix<T, 1, M> A, Matrix<T, N1, M1> B) {
	Matrix<T, 1, M> C;
	try {
		if (N1 != 1 || M1 != M)
			throw 11;
		for (int i = 0; i < M; i++)
			C.Mat[i] = A.Mat[i] + B.Mat[i];
		return C;
	}
	catch (int err) {
		setlocale(0, "");
		cout << "Ошибка сложения: разные размеры матриц\n";
		C.Mat = NULL;
	}
	return C;
}
