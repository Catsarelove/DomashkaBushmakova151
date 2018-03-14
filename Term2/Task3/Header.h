#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class quat {

private:
	int a;
	int b;
	int c;
	int d;
	friend quat operator + (quat, quat);
	friend quat operator - (quat);
	friend quat operator ! (quat);
	friend quat operator -(quat, quat);
	friend quat operator * (quat, quat);
	friend bool operator == (quat, quat);
	friend bool operator > (quat, quat);
	friend ostream& operator <<(ostream&, quat);
	friend int abs(quat);
	;

public:
	quat(const int &qa = 1, const int &qb = 0, const int& qc = 0, const int& qd = 0) {
		a = qa;
		b = qb;
		c = qc;
		d = qd;
	}
	void getquat() {
		cin >> a >> b >> c >> d;
	}

};
quat operator * (quat x, quat y) {
	quat z(x.a*y.a - x.b*y.b - x.c*y.c - x.d*y.d, x.a*y.b + x.b*y.a + x.c*y.d - x.d*y.c, x.a*y.c + x.c*y.a + x.d*y.b - x.b*y.d, x.a*y.d + x.b*y.c + x.d*y.a - x.c*y.b);
	return z;
}
quat operator + (quat x, quat y) {
	quat z(x.a+y.a,x.b+y.b, x.c+y.c, x.d+y.d);
	return z;
}
quat operator - (quat x, quat y) {
	quat z(x.a - y.a, x.b - y.b, x.c - y.c, x.d - y.d);
	return z;
}
quat operator - (quat x) {
	quat z(-x.a, -x.b, -x.c, -x.d);
	return z;
}
quat operator ! (quat x) {
	quat z(x.a, -x.b, -x.c, -x.d);
	return z;
}
int abs(quat x) {
	return (x * !x).a;
}
bool operator == (quat x, quat y) {
	return(x.a == y.a && x.b == y.b && x.c == y.c && x.d == y.d);
}
bool operator > (quat x, quat y) {
	return (abs(x) > abs(y))*(!(x.a<0 && x==-y));
}
bool operator >= (quat x, quat y) {
	return (x == y || x > y);
}
bool operator <= (quat x, quat y) {
	return (!(x>y));
}
bool operator < (quat x, quat y) {
	return (y > x);
}
ostream& operator <<(ostream& os, quat x) {
	os << x.a << showpos << x.b << "i" << showpos << x.c << "j" << showpos << x.d << "k"<<noshowpos;
	return os;
}
