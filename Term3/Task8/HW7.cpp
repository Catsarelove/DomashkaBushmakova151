#include <thread>
#include <stdio.h>
#include <iostream>
#include "Matrix.h"
#include <cmath>
void strasen(Matrix A, Matrix B, Matrix &C){
	int N = A.size;
	if(N <= 16){
	mul(A,B,C);
		return;
	}
	Matrix A11, A12, A21, A22, B11, B12, B21, B22, C11, C12, C21, C22;
	A11.matcpy(A, 0, N/2, 0, N/2);
	A12.matcpy(A, 0, N/2, N/2, N);
	A21.matcpy(A, N/2, N, 0, N/2);
	A22.matcpy(A, N/2, N, N/2, N);
	B11.matcpy(B, 0, N/2, 0, N/2);
	B12.matcpy(B, 0, N/2, N/2, N);
	B21.matcpy(B, N/2, N, 0, N/2);
	B22.matcpy(B, N/2, N, N/2, N);
	Matrix P1(N/2), P2(N/2), P3(N/2), P4(N/2), P5(N/2), P6(N/2), P7(N/2);
	thread t1(strasen, A11 + A22, B11 + B22,ref(P1));
	thread t2(strasen, A21 + A22, B11, ref(P2));
	thread t3(strasen, A11, B12 - B22, ref(P3));
	thread t4(strasen, A22, B21 - B11, ref(P4));
	thread t5(strasen, A11 + A12, B22, ref(P5));
	thread t6(strasen, A21 - A11, B11 + B12, ref(P6));
	thread t7(strasen, A12 - A22, B21 + B22, ref(P7));
	t1.join(); t2.join(); t3.join(); t4.join(); t5.join(); t6.join(); t7.join();
	C11 = P1 + P4 - P5 + P7;
	C12 = P3 + P5;
	C21 = P2 + P4;
	C22 = P1 - P2 + P3 + P6;
	C = matmerge(C11, C12, C21, C22);
	return;  
}

int main(){
	int n;
	cin >> n;
	double p = (log(n)/((double)log(2)));
	const int m = pow(2, (int)p + 1*((p - (int)p) > 0.0001));
	Matrix A(m);
	Matrix B(m);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++){
			if( i >= n || j >= n){
				A[i][j] =0; B[i][j] = 0;
			}
		/*	else{
				A[i][j] = rand()%10 + 0.1*(rand()%10) - 5;
				B[i][j] = rand()%10 + 0.1*(rand()%10) - 5;
			}
		*/
			else{
				j == i ? A[i][j] = 2 : A[i][j] = 0; 
				j == i ? B[i][j] = 0.5 : B[i][j] = 1; 
			}	
	   }

	FILE* f;
	f = fopen("out.txt", "w");
	A.write(f);
	B.write(f);
	Matrix C;
	strasen(A,B,C); 
	C.write(f);
	fclose(f);
	return 0;
}

