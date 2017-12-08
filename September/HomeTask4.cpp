#include <iostream>
using namespace std;
struct quotient {
	int numerator;
	int denominator;
	void rej() {
		
		int t,a,b;
		a = numerator;
		b = denominator;
		
		while (a*b != 0)
		{
			if (a > b)
				a = a%b;
			else
				b = b%a;
		}
		numerator /= (b+a);
		denominator /= (b+a);
	}
	void write() {
		if (denominator == 1) cout << numerator;
		else
		{
			rej();
			if (denominator == 1) cout << numerator;
			else
				cout << numerator << '/' << denominator<<endl;
		}
	}
	void read()
	{

		cin >> numerator >> denominator;
	}
};
int gcd(int a, int b)
{
	while (a*b != 0)
	{
		if(a>b)
		a = a%b;
		else
		b = b%a;
	}
	return b+a;
}
quotient sum(quotient a, quotient b) {
	quotient c;
	int an = a.numerator, ad = a.denominator, bn = b.numerator, bd = b.denominator;
	int d = gcd(ad, bd);
	c.numerator = an*(bd / d) + bn*(ad / d);
	c.denominator = (bd*ad)/d;
	d = gcd(c.numerator, c.denominator);
	c.numerator /= d;
	c.denominator /= d;
	return c;
}
quotient mul(quotient a, quotient b) {
	quotient c;
	int an = a.numerator, ad = a.denominator, bn = b.numerator, bd = b.denominator;
	c.numerator = an*bn;
	c.denominator = bd*ad;
	int d = gcd(c.numerator, c.denominator);
	c.numerator /= d;
	c.denominator /= d;
	return c;
}
int main()
{
	quotient l, m, n;
	l.read();
	m.read();
	l.write();
	m.write();
	n = sum(l, m);
	n.write();
	n = mul(m, l);
	n.write();
	system("pause");
	return 0;
}
