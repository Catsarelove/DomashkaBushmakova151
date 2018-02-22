#include <fstream>
#include <iostream>
#include "Header.h"
#include <string>
using namespace std;
int main() {
	string F1, F2;
	cin >> F1 >> F2;
	ifstream f1(F1);
	ofstream f2(F2);
	SLAE Myslae(f1);
	Myslae.read(f1);
	Myslae.Gauss(f2);
	return 0;
}
