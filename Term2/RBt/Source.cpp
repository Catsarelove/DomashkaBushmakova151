#include <iostream>
#include "Header.h"
void HELP(RBt s, int n) {
	if (n == 0) cout << "empty";
	for (int i = 0; i < n; i++) {
		cout << s.root->data<<' ';
		s.eraser(s.root);
	}
	cout << endl;
}
using namespace std;
int main() {
	RBt a, b, s, p;
	int n,m;
	cin >> n>>m;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.insert(x);
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		b.insert(x);
	}
	s = a + b;
	HELP(s, s.size);
	p = a*b;
	HELP(p, p.size);
	system("pause");
	return 0;
}
