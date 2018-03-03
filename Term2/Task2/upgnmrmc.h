#include <stdio.h>
#include <iostream>
using namespace std;
void d(char* F) {
	char *pos = strrchr(F, '\n');
	if (*pos)
		F[pos - F] = '\0';
}
int nullor(int j, int t, float** lines, int ql) {
	int flag = -1;
	for (int i = t; i < ql; i++) {
		if (lines[i][j] && flag == -1)
			flag = i;
	}
	return flag;
}
void transp1(int i, int i1, float** lines) {
	float* temp;
	temp = lines[i];
	lines[i] = lines[i1];
	lines[i1] = temp;
}
void nuller(int j, int t, float** lines, int ql, int qx) {
	float k;
	for (int i = t + 1; i < ql; i++) {
		k = -lines[i][j] / lines[t][j];
		for (int u = 0; u < qx; u++)
			lines[i][u] += k*lines[t][u];
	}
}
void write(FILE* f, float** lines, int ql, int qx) {
	for (int i = 0; i<ql; i++) {
		for (int j = 0; j < qx; j++)
			fprintf(f,"%f ", &(lines[i][j]));
		fprintf(f, "\n");
	}
	fprintf(f, "\n");
}
void onesolution(FILE* f, float* depend, float* solution, float** lines, int ql, int qx) {
	int i = ql - 1;
	solution[qx - 1] = -1;
	for (int j = qx - 2; j >= 0; j--, i--) {
		solution[j] = 0;
		for (int o = j + 1; o < qx; o++)
			solution[j] -= lines[i][o] * solution[o] / lines[i][j];
		fprintf(f, "x%d = %f \n", &j, &(solution[j]));
	}
}
void manysolutions(FILE* f, float* depend) {
	fprintf(f,"many solutions");
};
void read(FILE* f, int ql, int qx, float** lines)
{ 
	for (int i = 0; i < ql; i++) 
		for (int j = 0; j < qx; j++)
			fscanf(f,"%f", &(lines[i][j]));
}
void Gauss(FILE* f, float** lines, int qx, int ql, float* solution) {
	float* depend;
	depend = new float[qx];
	for (int o = 0; o < qx; o++) {
		depend[o] = -1;
	}
	int j = 0, t = 0;
	while (j < qx) {
		int i = nullor(j, t, lines, ql);
		if (i == -1) j++;
		else {
			depend[t] = j;
			transp1(i, t, lines);
			nuller(j, t, lines, ql, qx);
			t++;
			write(f, lines, ql, qx);
		}
	}
	if (depend[t - 1] == qx - 1)
		fprintf(f, "no solution");
	else {
		if (t == qx - 1)
			onesolution(f, depend,solution,lines,ql,qx);
		else
			manysolutions(f, depend);
	}
};
