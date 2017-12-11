#include <iostream>
using namespace std;
int cubeee(int x, int & mini) {
	if (x < 8) {
		mini = 1;
		return x;
	}
	double a = (double)pow(x, (1. / 3));
	if (a - (int)a == 0) {
		mini = x;
		return 1;
	}
	int temp;
	int min = x;
	mini = 1;
	for (int i = 1; i*i*i < x; i++) {
		int c = x / (i*i*i) + cubeee(x % (i*i*i), temp);
		if (c <= min) {
			min = c;
			mini = i*i*i;
		}
    }
		return min;
}
void napisau(int x) {
	int mini = x;
	int t = cubeee(x, mini);
	for(int i=0; i<x/mini; i++)
	cout << " + " << mini ;
	if (x % mini != 0)
		napisau(x % mini);

}
int main()
{
	int x, t, mini;
	cin >> x;
	mini = x;
	t = cubeee(x, mini);
	cout << "quantity = " << t << endl;
	for (int i = 0; i < x / mini; i++) {
		if (i > 0) cout << " + ";
		cout << mini;
	}
	napisau(x % mini);
	cout << endl;
	system("pause");
	return 0;
}
