#include <iostream>
using namespace std;
struct art {
	int v;
	int p;
	bool t;
	void read() {
		cin >> v;
		cin >> p;
		t = true;
	}
};
int pr(int V, art* list, int n) {
	if (V == 0) return 0;
	int m = 0;
	int k = -1;
	for (int i = 0; i < n && list[i].v <= V; i++) {
		if (list[i].t) {
			list[i].t = false;
			int r = list[i].p + pr((V - list[i].v), list, n);
			list[i].t = true;
			if (r > m) {
				m = r;
				k = i;
			}
		}
	}
	if(k!=-1)
	cout << m << ' ';
	return m;
}
int main() {
	int V, price, n;
	art* list;
	cin >> V >> n;
	list = new art[n];
	for (int i = 0; i < n; i++) {
		list[i].read();
	}
	cout << pr(V, list, n);
	system("pause");
	return 0;
}