#include <iostream>
using namespace std;
struct string {
	int length;
	char* s;
	void read() {
		for (int i = 0; i<length;i++)
			cin >> s[i];
	}
	void write() {
		for (int i = 0; i<length;i++)
			cout<< (s[i]);
	}
	~string() {
		delete[]s;
	}
}str;

int main()
{
	cin >> str.length;
	str.s = new char[str.length];
	str.read();
	str.write();
	str.~string();
	system("pause");
	return 0;
}
