#include <iostream>
#include <algorithm>
using namespace std;
class Matrix {
public:
	double** Mat;
	int size;
	Matrix(int N = 0) {
		if(N > 0){
			size = N;
			Mat = new double*[N];
			for (int i = 0; i < N; i++){
				Mat[i] = new double[N];
			}
		}
		else{
			size = 0;
			Mat = NULL;
		}
	}
	matcpy(Matrix M, int row_s, int row_e, int col_s, int col_e){
		if(size != 0) free();
		int N = row_e - row_s;
		size = N;
		Mat = new double*[N];
		for(int i = 0; i<N; i++)
			Mat[i] = new double[N]; 
		for(int i = 0; i < N; i++)
			copy(&(M.Mat[row_s+i][col_s]), &(M.Mat[row_s+i][col_e]), Mat[i]);
		
		}      
	void free(){
			for (int i = 0; i < size; i++)
				delete[]Mat[i];
			delete[]Mat;
			Mat = NULL;
			size = 0;
	}                                                              
	void read() {
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> Mat[i][j];
	}
	void write(FILE * f) {
		if (Mat == NULL) fprintf(f,"Матрицы не существует\n");
		else {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++)
					fprintf(f,"%.1f\t", Mat[i][j]);
				fprintf(f,"\n\n");
			}
			fprintf(f,"\n\n----------------------------------------------------------------------------\n\n");
		}
	}
	double* operator[](int i){
		return Mat[i];
	}
	Matrix operator = (const Matrix & B) {
		try {
			if (!B.Mat) throw 13;
			if (this == &B) throw 14;
			free();
			size = B.size;
			Mat = new double*[size];
         	for (int i = 0; i < size; i++) {
				Mat[i] = new double[size];
			}			
			for (int i = 0; i < size; i++)
				copy(&(B.Mat[i][0]), &(B.Mat[i][size]), Mat[i]);
			return *this;
		}
		catch (int err) {
			if (err == 13) {
				cout << "Присваиваемой матрицы не существует \n";
				Mat = NULL;
				size = 0;
			}
				if (err == 14) cout << "Равно самому себе\n";
			}
		return*this;
	}
	Matrix (const Matrix & B) {
		if (B.Mat) {
			size = B.size;
			Mat = new double*[size];
			for (int i = 0; i < size; i++)
				Mat[i] = new double[size];
			for (int i = 0; i < size; i++)
				copy(&(B.Mat[i][0]), &(B.Mat[i][size]), Mat[i]);
        }
		else{
			Mat = NULL;
			size = 0;
		}
	}
	~Matrix() {
		if(Mat && this)
		free();
	}

};

Matrix matmerge(Matrix A, Matrix B, Matrix C, Matrix D){
	Matrix res;
	int N = A.size;
	res.size = 2 * N;
	res.Mat = new double*[N*2];
	for(int i = 0; i < N*2; i++)
		res.Mat[i] = new double[N*2];
	for(int i = 0; i < N; i++){
		copy(&(A.Mat[i][0]), &(A.Mat[i][N]), res.Mat[i]);
		copy(&(B.Mat[i][0]), &(B.Mat[i][N]), res.Mat[i] + N);
		copy(&(C.Mat[i][0]), &(C.Mat[i][N]), res.Mat[i + N]);
		copy(&(D.Mat[i][0]), &(D.Mat[i][N]), res.Mat[i + N] + N);
	}
	return res;
}

void mul(Matrix A, Matrix B, Matrix & C){
	int N = A.size;
	for(int i = 0 ; i < N; i++)
    	for(int j = 0; j < N; j++)
    	{
        	C[i][j] = 0;
        	for(int k = 0; k < N; k++)
            	C[i][j] += A[i][k] * B[k][j];
    	}
}

Matrix operator + (Matrix A, Matrix B) {
	int N = A.size;
	Matrix C(N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			C[i][j] = A[i][j] + B[i][j];
	return C;
}


Matrix operator - (Matrix A, Matrix B) {
	int N = A.size;
	Matrix C(N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			C[i][j] = A[i][j] - B[i][j];
	return C;
}
