#include <iostream>
#include <iomanip>
using namespace std;
void wind(int**a, int m,int n, int t){
	int i=n-1;
	int o;
	int j=m-1;
	for(o=j-1; o>=t; o--)
		a[i][o]=a[i][o+1]+1;
	j=t;
	for(o=i-1; o>=t; o--)
		  a[o][j]=a[o+1][j]+1;
	i=t;	
	for(o=j+1; o<m; o++)
		a[i][o]=a[i][o-1]+1;
     j=m-1;
	for(o=i+1; o<n-1; o++)
		a[o][j]=a[o-1][j]+1;
     i=n-1;
}

int main()
{
	int**a;
	int n, m;
	cin >> n >> m;
	a=new int*[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];
	a[n-1][m-1]=1;
	int tn=n; int tm=m;
	int min=tm>tn?tn:tm;
	int t=0;
	while(tn!=(min+1)/2 && tm!=(min+1)/2)
	{
		wind(a, tm, tn,t);
		if(tn!=(min+2)/2 && tm!=(min+2)/2)
		a[tn-2][tm-2]=a[tn-2][tm-1]+1;
		tn--; tm--;
		t++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout<<a[i][j]<<'\t';
		cout << endl;
	}
	system ("pause");
	delete [] a;
	return 0;
}