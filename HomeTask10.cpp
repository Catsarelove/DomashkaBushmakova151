#include <iostream>
using namespace std;
int path(int* a, int n, int k)
{
	a[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i && j <= k; j++)
			a[i] += a[i - j];

	}
	return a[n - 1];
}
int main()
{
	int n, k;
	int* a;
	cin >> n >> k;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
	cout << path(a, n, k) << endl;
	system("pause");
	return 0;
}
