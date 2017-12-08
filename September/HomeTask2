#include <iostream>
using namespace std;
int A(int n, int m)
{
	if(n==0) return m+1;
	if(n>0 && m==0) return A(n-1,1);
	if(m>0 && n>0) return A(n-1, A(n, m-1));
}
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<A(n,m);
	system("pause");
	return 0;
}
