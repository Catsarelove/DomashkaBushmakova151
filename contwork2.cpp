#include <iostream>
using namespace std;
struct complex{
	float Im;
	float Re;
};
complex sum(complex a, complex b)
{ 
	complex c;
	c.Im=a.Im+b.Im;
	c.Re=a.Re+b.Re;
	return c;
}
complex mul(complex a, complex b)
{
	complex c;
	c.Im=a.Re*b.Im+b.Re*a.Im;
	c.Re=a.Re*b.Re-a.Im*b.Im;
	return c;
}
complex abssq(complex a)
{
	complex c;
	c.Im=2*a.Im*a.Re;
	c.Re=a.Re*a.Re-a.Im*a.Im;
	return c;
}
int main()
{
	complex x,y;
	cin>>x.Re>>x.Im>>y.Re>>y.Im;
	cout<<"x = "<<x.Re<<showpos<<x.Im<<noshowpos<<"i"<<endl;
	cout<<"y = "<<y.Re<<showpos<<y.Im<<noshowpos<<"i"<<endl;
	cout<<"x + y = "<<(sum(x,y).Re)<<showpos<<(sum(x,y).Im)<<noshowpos<<"i"<<endl;
	cout<<"x * y = "<<(mul(x,y).Re)<<showpos<<(mul(x,y).Im)<<noshowpos<<"i"<<endl;
	cout<<"x^2 = "<<(abssq(x).Re)<<showpos<<(abssq(x).Im)<<noshowpos<<"i"<<endl<<"y^2 = "<<(abssq(y).Re)<<showpos<<(abssq(y).Im)<<noshowpos<<"i"<<endl;
	system("pause");
	return 0;
}