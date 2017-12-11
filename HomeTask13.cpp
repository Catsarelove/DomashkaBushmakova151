#include <iostream>
using namespace std;
int squ(int x, int & mini) {
	if (x < 4) {
		mini = 1;
		return x;
	}
	double a = (double)pow(x, (1. / 2));
	if (abs(a - round(a)) < 0.00001) {
		mini = x;
		return 1;
	}
	int temp;
	int min = x;
	mini = 1;
	for (int i = 1; i*i < x; i++) {
		int c = x / (i*i) + squ(x % (i*i), temp);
		if (c <= min) {
			min = c;
			mini = i*i;
		}
    }
		return min;
}
void napisau(int x) {
	int mini = x;
	int t = squ(x, mini);
	for (int i = 0; i < x / mini; i++)
		cout << pow(mini, 1./2) << "^2 ";
	if (x % mini != 0)
		napisau(x % mini);

}
int main()
{
	int x, t, mini;
	cin >> x;
	mini = x;
	napisau(x);
    cout << endl;
	system("pause");
	return 0;
}