//Completed at home
#include <iostream>
#include <iomanip>
using namespace std;
int min(int i, int j, int ni, int mj)
{
	if(i <= j && i <= ni && i <= mj) return i + 1;
	if(j <= i && j <= ni && j <= mj) return j + 1;
	if(ni <= i && ni <= j && ni <= mj) return ni + 1;
	return mj + 1;
}

int main()
{
	int**a;
	int n, m;
	cin >> n >> m;
	a=new int*[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			a[i][j]=min(i, j, n-i-1, m-j-1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << setw(5) << a[i][j] << ' ';
		cout << endl;
	}
	system ("pause");
	delete [] a;
	return 0;
}
