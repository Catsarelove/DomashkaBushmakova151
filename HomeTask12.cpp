#include <iostream>
#include <string>;
using namespace std;
struct segment {
	double a;
	double b;
	void read() {
		cin >> a;
		cin >> b;
	}

};
bool le(segment x, segment y) {
	if (x.a < y.a) return true;
	if (x.a > y.a) return false;
	if (x.a == y.a)
		if (x.b < y.b) return true;
	return false;
}
void Quick(segment* a, int L, int R)
{
	int i, j;
	segment bar;
	i = L;
	j = R;
	bar = a[(L + R) / 2];
	do
	{
		while (le(a[i], bar))
			i++;
		while (le(bar, a[j]))
			j--;
		if (i <= j)
		{
			if (i<j) { segment t = a[i]; a[i] = a[j]; a[j] = t; }
			i++; j--;
		}
	} while (i <= j);
	if (L<j) Quick(a, L, j);
	if (R>i) Quick(a, i, R);
}
int main() {
	int c, s=0;
	segment* l;
	cin >> c;
	l = new segment[c];
	segment min;
	min.b = 0;
	for (int i = 0; i < c; i++)
		l[i].read();
	Quick(l, 0, c - 1);
	for (int i = 0; i < c; i++)
	{
		if (l[i].a >= min.b) {
			s++;
			min = l[i];
		}
	}
	cout << s;
	delete[] l;
	system("pause");
	return 0;
}