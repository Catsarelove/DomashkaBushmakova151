#include <iostream>
using namespace std;
int x, y;
int qcells(int ** a, int i, int j)
{
	if(i == x && j == y) return a[i][j];
	if(a[i][j] == 0) return 0;
    int s = 0;
	if(i >= 1) s += qcells(a, i - 1, j);
	if(j >= 1) s += qcells(a, i, j - 1);
	if((i >= 1) && (j >= 1)) s += qcells(a, i - 1, j - 1);
	if(i >= 2) s += qcells(a, i - 2, j);
	if(j >= 2) s += qcells(a, i, j - 2);
	if((i >= 2) && (j >= 2)) s += qcells(a, i - 2, j - 2);
	return s;
}
int main()
{
	int n, m, x1, y1; // A(x, y) >>> B(x1, y1)
	cin>>n>>m;
	int **a;
	a = new int*[n];
	for(int i=0; i<n; i++)
		a[i]=new int[m];
	for(int i=0; i<n;i++)
		for(int j=0; j<m; j++)
			cin>>a[i][j];
	cin>>x>>y>>x1>>y1;
	cout<<qcells(a, x1, y1)<<endl;
	system("pause");
	return 0;
}
