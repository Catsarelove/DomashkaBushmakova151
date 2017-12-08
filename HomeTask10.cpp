#include <iostream>
using namespace std;
int path(int n, int k)
{
	if (n == 1) return 1;
	int s = 0;
	for (int i = 0; i<k; i++)
		if (n - k + 1>0)
			s += path(n - k + i, k);
	return s;
}
int main()
{
	int x, k;
	cin >> x >> k;
	cout << path(x,k) << endl;
	system("pause");
	return 0;
}
