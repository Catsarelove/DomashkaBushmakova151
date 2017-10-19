#include <iostream>
using namespace std;
int path (int n)
{
	if(n<=3) return 1;
	return path(n-1) + path(n-3);
}
int main()
{
	int x;
	cin>>x;
	cout<<path(x)<<endl;
	system("pause");
	return 0;
}