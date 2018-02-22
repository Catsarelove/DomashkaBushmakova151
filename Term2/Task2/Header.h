#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
class SLAE{
	float** lines;
	float* solution;
	int qx;
	int ql;
private:
	int nullor(int j, int t) {
		int flag = -1;
		for (int i = t; i < ql; i++) {
			if (lines[i][j] && flag == -1)
				flag = i;
		}
		return flag;
	}
	void transp1(int i, int i1) {
		float* temp;
		temp = lines[i];
		lines[i] = lines[i1];
		lines[i1] = temp;
	}
	void nuller(int j, int t) {
		float k;
		for (int i = t + 1; i < ql; i++) {
			k = -lines[i][j] / lines[t][j];
			for (int u = 0; u < qx; u++)
				lines[i][u] += k*lines[t][u];
		}
	}
	void write(ofstream &f) {
		for (int i = 0; i<ql; i++) {
			for (int j = 0; j < qx; j++)
				f << lines[i][j] << ' ';
			f << endl;
		}
		f << endl;
	}
    void onesolution(ofstream &f, float* depend) {
		int i = ql - 1;
		solution[qx - 1] = -1;
		for (int j = qx - 2; j >= 0; j--, i--) {
			solution[j] = 0;
			for (int o = j + 1; o < qx; o++)
				solution[j] -= lines[i][o] * solution[o] 
/ lines[i][j];
			f << "x" << j << "= " << solution[j] << endl;
		}
	}
	void manysolutions(ofstream &f, float* depend) {
		f << "many solutions";
	};
public:
	SLAE(ifstream &f) {
		f >> ql >> qx;
		lines = new float*[ql];
		for (int i = 0; i < ql; i++)
			lines[i] = new float[qx];
		solution = new float[qx];
	}
	void read(ifstream &f) {
		for (int i = 0; i < ql; i++)
			for (int j = 0; j < qx; j++)
				f >> lines[i][j];
	}
	void Gauss(ofstream &f) {
		float* depend;
		depend = new float[qx];
		for (int o = 0; o < qx; o++) {
			depend[o] = -1;
		}
		int j = 0, t = 0;
		while (j < qx) {
			int i = nullor(j, t);
			if (i == -1) j++;
			else {
				depend[t] = j;
				transp1(i, t);
				nuller(j, t);
				t++;
				write(f);
			}
		}
		if (depend[t - 1] == qx - 1)
			f << "No solution" << endl;
		else {
			if (t==qx-1)
				onesolution(f, depend);
			else
				manysolutions(f, depend);
		}
	};
    ~SLAE() {
		delete[] solution;
		for (int i = 0; i < ql; i++)
			delete[] lines[i];
		delete[] lines;
	}
};
