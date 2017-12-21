#include <iostream>
using namespace std;
int x, y;
int qcells(int ** a, int ** way, int x, int y, int x1, int y1)
{
	if (a[x][y]==0) return 0;
		way[x][y] = 1;
		for (int i = x; i <= x1; i++) 
			for (int j = y; j <= y1; j++) {
				if (a[i][j]!=0) {
					if (i > 0) way[i][j] += way[i - 1][j];
					if (j > 0) way[i][j] += way[i][j - 1];
					if (j > 0 && i > 0) way[i][j] += way[i - 1][j - 1];
					if (i > 1) way[i][j] += way[i - 2][j];
					if (j > 1) way[i][j] += way[i][j - 2];
					if (j >	1 && i > 1) way[i][j] += way[i - 2][j - 2];
				}
			}
		return way[x1][y1];
}
int main()
{
	int n, m, x1, y1; // A(x, y) >>> B(x1, y1)
	cin >> n >> m;
	int **a;
	int ** way;
	way = new int*[n];
    a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		way[i] = new int[m];
		for (int j = 0; j < m; j++)
			way[i][j] = 0;
	}
	for (int i = 0; i<n;i++)
		for (int j = 0; j<m; j++)
			cin >> a[i][j];
	cin >> x >> y >> x1 >> y1;
	cout << qcells(a, way, x, y, x1, y1);
	system("pause");
	return 0;
}
