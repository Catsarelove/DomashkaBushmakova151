
#include <iostream>
using namespace std;
void Quick(int* a, int L, int R, int k)
{
	int i, j, bar;
	i = L;
	j = R;
	bar = a[(L + R) / 2];
	do
	{
		while (a[i]>bar)
			i++;
		while (a[j]<bar)
			j--;
		if (i <= j)
		{
			if (i<j) { int t = a[i]; a[i] = a[j]; a[j] = t; }
			i++; j--;
		}
	} while (i <= j);
	if (L<j && k >= L && k <=j) Quick(a, L, j, k);
	if (R>i && k <=R && k>=i ) Quick(a, i, R, k);

}
int main()
{
	int*a;
	int n, k;
	cin >> n >> k;
	if (n <= k) { cout << "not found" << endl; return 0; }
	k = k - 1;
	a = new int[n];
	for (int i = 0; i<n; i++)
		cin >> a[i];
	Quick(a, 0, n - 1, k);
        cout << a[k] << endl;
	system("pause");
	delete[] a;
	return 0;
}
