#include <iostream>
using namespace std;
int cubeee(int x) {
	if (x < 5) {
		return x;
	}
	double a = (double)pow(x - 1, (1. / 2));
	if (a - (int)a == 0) {
		return 1;
	}
	int min = x;
	for (int i = 1; i*i + 1 < x; i++) {
		int c = x / (i*i + 1) + cubeee(x % (i*i + 1));
		if (c <= min)
			min = c;
	}
	return min;
}
int main()
{
	int x, t, mini;
	cin >> x;
	mini = x;
	t = cubeee(x);
	cout << "quantity = " << t << endl;
	system("pause");
	return 0;
}