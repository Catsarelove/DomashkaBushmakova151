#include <Windows.h>
#include <iostream>
using namespace std;
int A(int n, int m)
{
	if(m==0) return n+1;
	if(m>0 && n==0) return A(m-1,1);
	if(m>0 && n>0) return A(m-1, A(m, n-1));
}
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<A(n,m);
	system("pause");
	return 0;
}