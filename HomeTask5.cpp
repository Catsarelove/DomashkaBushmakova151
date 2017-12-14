#include <iostream>
using namespace std;
typedef struct str1{
	int length;
	char* s;
	void read() {
		for (int i = 0; i<length;i++)
			cin >> s[i];
	}
	void write() {
		for (int i = 0; i<length;i++)
			cout << (s[i]);
	}
	~str1() {
		delete[]s;
	}
} str1;

int main()
{
	 str1 str;
	cin >> str.length;
	str.s = new char[str.length];
	str.read();
	str.write();
	system("pause");
	return 0;
}
