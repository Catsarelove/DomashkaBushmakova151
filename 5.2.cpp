#include <iostream>
using namespace std;
typedef struct str1 {
	int length;
	char* s;
    str1(int l) {
		length = l;
		s = new char[l];
	}
	void read() {
		for (int i = 0; i<length;i++)
			cin >> s[i];
	}
	void write() {
		for (int i = 0; i<length;i++)
			cout << (s[i]);
		cout << endl;
	}
	~str1() {
			delete[]s;
	}
}str1;
void conc(str1 &a, str1 &b, str1 &s3) {
	for (int i = 0; i < a.length;i++)
		s3.s[i] = a.s[i];
	for (int i = 0; i < b.length;i++)
		s3.s[i + a.length] = b.s[i];
}

int main()
{
	int l1, l2;
	cin >> l1 >> l2;
	str1 s1(l1), s2(l2);
	s1.read();
	s2.read();
	s1.write();
	s2.write();
	str1 s3(s1.length+s2.length);
	conc(s1, s2, s3);
	s3.write();
	system("pause");
	return 0;
}