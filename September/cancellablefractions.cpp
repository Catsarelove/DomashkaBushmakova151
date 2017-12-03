#include <iostream>
using namespace std;
bool prim(int n)
{
	bool flag = true;
	if(n==2) return true;
	if(n % 2 == 0) return false;
	if (n<8) return true;
	for(int i=3; i<=pow(n,0.5) && flag; i++)
 		if(n%i==0) flag=0; 
	return flag;
 }
int prost(int n)
 {
	if(n % 2 == 0) return 2;
	for(int i=3; i<=pow(n,0.5); i++)
		if(prim(i) && n%i==0) return i;
 }
int kek (int n)
{
	if(n == 1) return 1;
	if(prim(n)) return n-1;
	int p = prost(n);
	int t = n;
	t = t/p;
	int k = kek(p);
	while(t % p == 0)
	{
		k*=p;
		t/=p;
	}
	return k*kek(t);
}
 int main()
{
	int n;
	cin>>n;
	cout<<(n - (kek(n)) - 1)<<endl;
	system("pause");
	return 0;
}
