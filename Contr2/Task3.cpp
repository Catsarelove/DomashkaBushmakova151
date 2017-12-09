#include <iostream>
#include <string>;
using namespace std;
struct lesson {
	int s;
	int f;
	string n;
	void read() {
		cin >> n;
		cin >> s;
		cin >> f;
	}

};
bool le(lesson a, lesson b) {
	if (a.s < b.s) return true;
	if (a.s > b.s) return false;
	if (a.s == b.s) 
		if (a.f < b.f) return true;
	return false;
}
void Quick(lesson* a, int L, int R)
 {
	int i, j;
	lesson bar;
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
			if (i<j) { lesson t = a[i]; a[i] = a[j]; a[j] = t; }
			i++; j--;
			}
		} while (i <= j);
		if (L<j) Quick(a, L, j);
		if (R>i) Quick(a, i, R);
	}
int main() {
	int c;
	lesson* l;
	cin >> c;
	l = new lesson[c];
	lesson min;
	min.f = 0;
	for (int i = 0; i < c; i++)
		l[i].read();
	Quick(l, 0, c-1);
	for (int i = 0; i < c; i++)
	{
		if (l[i].s >= min.f) {
			cout << l[i].n;
			min = l[i];
		}
	}
	system("pause");
	return 0;
}
