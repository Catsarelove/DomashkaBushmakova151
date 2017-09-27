#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int**a;
	a=new int*[n];
	a[0]=new int[m];
	for(int i=1; i<m; i++)
		a[i]=a[0]+i;
	for(int i=0; i<n; i++)
		for(int j=0;j<m; j++)
        cin>>a[i][j];
	for(int i=0; i<n; i++)
		{ for(int j=0;j<m; j++)
          cout<<fixed<<setw(10)<<a[i][j]<<' ';
		  cout<<endl;
	    }
	system("pause");
	return 0;
}