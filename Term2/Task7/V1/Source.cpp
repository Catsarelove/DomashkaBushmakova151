#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	string F1, F2, F;
	cin >> F1 >> F2;
	ifstream f1(F1);
	ofstream f2(F2);
	F = "NewFile.txt";
	Smth A;
	A.trtobin(f1);
	A.backtonorm(f2);
	f1.close();
	f2.close();
    return 0;
}
