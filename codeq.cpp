#include <iostream>
using namespace std;
struct quotient{
	int numerator;
	unsigned int denominator;
} l;

int gcd(int a, int b)
{
	int t;
	while(a*b!=0)
	{
		a=a%b;
		t=a;
		a=b;
		b=a;
	}
	return b;
}
int main()
{
	cin>>l.numerator>>l.denominator;
	if(l.denominator==1) cout<<l.numerator;
	else
	{	
			int d=gcd( l.numerator, l.denominator);
			l.numerator/=d;
			l.denominator/=d;
			if(l.denominator==1) cout<<l.numerator;
			else
				cout<<l.numerator<<'/'<<l.denominator; }
			return 0;
}
