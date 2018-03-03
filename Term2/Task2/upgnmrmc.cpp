#include <stdio.h>
#include <iostream>
#include "Header.h"
#include <string>
using namespace std;
int main() {
	char F1[100];
	char F2[100];
	fgets(F1, 100, stdin);
	d(F1);
	fgets(F2, 100, stdin);
	d(F2);
	FILE* f1;
    FILE* f2;
	cout << F1;
	f1=fopen(F1, "r");
    f2=fopen(F2, "w");
	int qx, ql;
	float** lines;
	float* solution;
	fscanf(f1, "%d %d", &ql, &qx);
	solution = new float[qx];
	lines = new float*[ql];
	for (int i = 0; i < ql; i++) {
		lines[i] = new float[qx];
	}
	read(f1, ql, qx, lines);
	Gauss(f2, lines, qx, ql, solution);
	system("pause");
	return 0;
}
