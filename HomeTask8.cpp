#include <iostream>
using namespace std;
void Quick(int* a, int L, int R)
{
	int i, j, bar;
	i = L;
	j = R;
	bar = a[(L + R) / 2];
	do
	{
		while (a[i]<bar)
			i++;
		while (a[j]>bar)
			j--;
		if (i <= j)
		{
			if (i<j) { int t = a[i]; a[i] = a[j]; a[j] = t; }
			i++; j--;
		}
	} while (i <= j);
	if (L<j) Quick(a, L, j);
	if (R>i) Quick(a, i, R);

}
int main()
{
	int*a;
	int n, k;
	cin >> n >> k;
	if (n <= k) { cout << "not found" << endl; return 0; }
	a = new int[n];
	for (int i = 0; i<n; i++)
		cin >> a[i];
	Quick(a, 0, n - 1);
	int j = n - k;
	if (k != 1) {
		while (j != 0 && a[j] == a[j + 1])
			j--;
		if (a[j] == a[j + 1])
			cout << "not found" << endl;
		else cout << a[j] << endl;
	}
	else cout << a[j] << endl;
	system("pause");
	delete[] a;
	return 0;
}
