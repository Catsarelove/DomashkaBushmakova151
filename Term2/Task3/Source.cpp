#include <iostream>
#include "Header.h"
using namespace std;
int main() {
	quat x, y;
	x.getquat();
	y.getquat();
	cout <<"x + y = "<< (x + y) << endl;
	cout <<"x * y = "<< (x*y) << endl;
	if (x < y)
		cout << abs(x) << endl;
	else
		cout << !x << endl;
	system("pause");
	return 0;
}
