#include <cmath>
#include <iostream>
#include <string>
using namespace std;
static const double g = 9.8;
static const double pi = 3.1415926535;
typedef double(*ft)(double, double, double, double, double);
double x1(double, double, double, double, double);
double x2(double, double, double, double, double);
double x3(double, double, double, double, double);
void Foucault(double, double, double, double, double & , double & );
double K(int);
double I(int, float);
class SimpleMathPendulum {
protected:	
	double x0; // начальная координата
	double m; //масса маятника
	double l; //длина подвеса
	double A; //амплитуда
	double a; //угол начального отклонения
	double T; //период колебаний
	double w; //част ота колебаний
	void def(double x0) {
		T = 2 * pi*pow(l / g, 0.5);
		if (a <= 1) PrT(1);
		w = pow(g / l, 0.5);
		if (sin(a)) {
			A = x0 / sin(a);
		}
		else
			A = 0;
	}
public:
	SimpleMathPendulum() { ; }
	//SimpleMathPendulum() {
	//	cout << "Начальная координата: \n";
	//	cin >> x0;
	//	cout << "Масса маятника: \n";
	//	cin >> m;
	//	cout << "Длина подвеса: \n";
	//	cin >> l;
	//	cout << "Угол отклонения \n";
	//	cin >> a;
	//	def(x0);
	//}
	//а можно как-то сделать, чтобы при создании физического маятника, 
	//вызывался не этот конструктор, а тот, который с параметром? Или объединить cin и fstream, или выкинуть cin?
    SimpleMathPendulum(ifstream & f1) {
	double x0;
	f1 >> x0;
	f1 >> m;
	f1 >> l;
	f1 >> a;
	def(x0);
}
	void PrT(int n) {
		T = T*I(n, a);
	}
	double x(double t) {
		return A*sin(w*t + a);
	}
	void Fou(double &x, double &y, double t, double f) {
		double p = 0; double tt = 0;
		double v0 = A*w*cos(a);
		Foucault(l, f, v0, t, tt, p);
		x = p*cos(tt);
		y = p*sin(tt);
	}
};
class PendulumWFrict {
	double m;
	double l;
	double A;
	double a;
	double T;
	double w0;
	double x0;
	double v0;
	double c;
	double k;
	ft xt;
	void def() {
		w0 = pow(g / l, 0.5);
		c = k / (2 * m);
		if (w0 > c)
			xt = x1;
		if (w0 == c)
			xt = x2;
		if (w0 < c)
			xt = x3;
	}
public:
    PendulumWFrict() {
		cout << "Начальная координата: \n";
		cin >> x0;
		cout << "Масса маятника: \n";
		cin >> m;
		cout << "Длина подвеса: \n";
		cin >> l;
		cout << "Начальная скорость \n";
		cin >> v0;
		cout << "Вязкость \n";
		cin >> k;
		def();
	}
	PendulumWFrict(ifstream & f1) {
		f1 >> x0;
		f1 >> m;
		f1 >> l;
		f1 >> v0;
		f1 >> k;
		def();
	}
	double x(double t) {
		return xt(t, c, v0, w0, x0);
	}
};
typedef enum {ball, cube, cilinder, disk} form;
void getform(form&, ifstream &);
void getform(form&);
class PhPendulum: public SimpleMathPendulum {
	form f;
	double r; //радиус шара, радиус цилиндра, сторона куба, малый радиус диска
	double J;// момент импульса
	double L;//приведенная длина
	void def(double x0) {
		L = l + r + J / ((l + r)*m);
		T = 2 * pi*pow(l / g, 0.5);
		w = pow(g / l, 0.5);
		if (sin(a)) {
			A = x0 / sin(a);
		}
		else
			A = 0;
	}
public:	PhPendulum() {
	    cout << "Начальная координата: \n";
		cin >> x0;
		cout << "Масса маятника: \n";
		cin >> m;
		cout << "Длина подвеса: \n";
		cin >> l;
		cout << "Угол отклонения \n";
		cin >> a;
		cout << "Форма: \n";
		getform(f);
		if (f == ball) {
			cout << "Радиус шара: \n";
			cin >> r;
			J = 0.4*m*r*r;
		}
		if (f == cube) {
			cout << "Сторона куба/2: \n";
			cin >> r;
			J = 2 * m*r*r / 3;
		}
		if (f == cilinder) {
			cout << "Радиус цилиндра: \n";
			cin >> r;
			J = m*r*r / 2;
		}
		if (f == disk) {
			cout << "Малый радиус диска: \n";
			cin >> r;
			J = m*r*r / 4;
		}
		def(x0);		
	}
	PhPendulum(ifstream & f1) {
		double x0;
		f1 >> x0;
		f1 >> m;
		f1 >> l;
		f1 >> a;
		getform(f, f1);
		if (f == ball) {
			f1 >> r;
			J = 0.4*m*r*r;
		}
		if (f == cube) {
			f1 >> r;
			J = 2 * m*r*r / 3;
		}
		if (f == cilinder) {
			f1 >> r;
			J = m*r*r / 2;
		}
		if (f == disk) {
			f1 >> r;
			J = m*r*r / 4;
		}
		def(x0);
	}
};
void output(ofstream &, ifstream &);
