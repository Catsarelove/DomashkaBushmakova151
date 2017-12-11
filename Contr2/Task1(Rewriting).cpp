#include <iostream>
using namespace std;
int cubeee(int x, int & mini) {
	if (x == 0) {
		mini = 0;
		return 0;
	}
	double a = (double)pow(x - 1, (1. / 2));
	if (a - (int)a == 0) {
		return 1;
		mini = x;
	}
	int temp = 1;
	mini = 1;
	int min = x;
	for (int i = 1; i*i + 1 < x; i++) {
		int c = x / (i*i + 1) + cubeee(x % (i*i + 1), temp);
		if (c <= min) {
			min = c;
			mini = i*i + 1;
		}
	}
	return min;
}
void sum(int x, int & s)
{
	int mini = x;
	int t = cubeee(x, mini);
	s = s + pow((mini-1),(1./2));
	if (x % mini)
		sum(x % mini, s);
}
int main()
{
	int x, mini, s=0;
	cin >> x;
	mini = x;
	sum(x, s);
	cout << s;
	system("pause");
	return 0;
}
