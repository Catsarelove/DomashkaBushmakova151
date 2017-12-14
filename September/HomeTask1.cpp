#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int*a;
    a=new int[n*m];
	for(int i=0, k=0; i<n; i++, k+=m-1)
		for(int j=0; j<m; j++)
          cin>>(*(a+i+j+k));
	for(int i=0, k=0; i<n; i++, k+=m-1)
		{
				for(int j=0; j<m; j++)
				cout<<(*(a+i+j+k))<<' ';
				cout<<'\n';
		}
	
	delete [] a;
	system("pause");
	return 0;
}
