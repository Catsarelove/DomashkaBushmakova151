#include "Header.h"
using namespace std;
int main() {
	Matrix<int, 3, 1> A;
	Matrix<int, 1, 3> B;
	Matrix<int, 3, 1> C;
	A.read();
	B.read();
	C = A + B;
	C.write();
	system("pause");
	return 0;
}
