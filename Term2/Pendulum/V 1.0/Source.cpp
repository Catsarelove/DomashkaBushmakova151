#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	string F1, F2;
	cin >> F1 >> F2;
	ifstream f1(F1);
	ofstream f2(F2);
	output(f2, f1);
	system("pause");
}
