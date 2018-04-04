#include <cmath>
#include <fstream>
#include "Header.h"
using namespace std;
double K(int n) {
	if (n == 0) return 0.5;
	return (2 * n - 1) / (2 * n)*K(n - 1);
}
double I(int n, float a) {
	double S = 1;
	for (int i = 1; i <= n; i ++) {
		double k = K(n);
		S += pow(sin(a / 2), 2 * n)*k*k;
	}
	return S;
}
void Foucault(double l, double f, double v0, double t, double & tt, double & p) {
	double w0 = pow(g / l, 0.5);
	double w1 = pow(w0*w0 + pow(w0*sin(f), 2), 0.5);
	tt = w0*sin(f)*t;
	p = v0*sin(w1*t) / w1;  //x=p*cos(tt), y=p*sin(tt);
}
double x1(double t, double c, double v0, double w0, double x0) {
	double A;
	double w = pow(w0*w0 - c*c, 0.5);
	double a = atan(-(v0 + c) / (w*x0));
	if (sin(a)) {
		A = x0 / sin(a);
	}
	else
		A = 0;
	return A*exp(-c*t)*cos(w*t + a);
}
double x2(double t, double c, double v0, double w0, double x0) {

	double a1 = c + pow(c*c - w0*w0, 0.5);
	double a2 = c - pow(c*c - w0*w0, 0.5);
	double C2 = (v0 + a1*x0) / (a1 - a2);
	double C1 = x0 - C2;
	return C1*exp(-a1*t) + C2*exp(-a2*t);

}
double x3(double t, double c, double v0, double w0, double x0) {
	double C1 = x0*c + v0;
	double C2 = x0;
	return (C1*t + C2)*exp(-c*t);
}
void output(ofstream & f2, ifstream & f1) {
	double t, x = 0, y = 0, f = 0.471239;
	f1 >> t >> f;
	SimpleMathPendulum P1(f1);
	PendulumWFrict P2(f1);
	PhPendulum P3(f1);
	f2 << "Координата простого математического маятника:\n" << P1.x(t) << "\nКоордината маятника с вязким трением:\n" << P2.x(t) << "\nКоордината физического маятника:\n" << P3.x(t) << endl;
	P1.Fou(x, y, t, f);
	f2 << "Координаты маятника Фуко:\nx = " << x << "; y = " << y << endl;
}
void getform(form& f, ifstream &f1) {
	string s;
	f1 >> s;
	if (s == "шар") f = ball;
	if (s == "куб") f = cube;
	if (s == "цилиндр") f = cilinder;
	if (s == "диск") f = disk;
}
void getform(form& f) {
	string s;
	cin >> s;
	if (s == "шар") f = ball;
	if (s == "куб") f = cube;
	if (s == "цилиндр") f = cilinder;
	if (s == "диск") f = disk;
}
