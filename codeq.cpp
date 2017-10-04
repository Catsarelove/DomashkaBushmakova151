#include <iostream>
using namespace std;
struct quotient{
	int numerator;
	unsigned int denominator;
	int d;
} qqq;

int gcd(int a, int b)
{
	while(a!=b)
	{
		if(a>b)
		a=a-b;
		else b=b-a;
	}
	return a;
}
int main()
{
	quotient l;
	cin>>l.numerator>>l.denominator;
	if(l.denominator==1) cout<<l.numerator;
	else
	{	
			l.d=gcd( l.numerator, l.denominator);
			l.numerator/=l.d;
			l.denominator/=l.d;
			if(l.denominator==1) cout<<l.numerator;
			else
				cout<<l.numerator<<'/'<<l.denominator; }
			return 0;
}