#include <iostream>
using namespace std;
struct string{
	int length;
	char* s;
} str;

int main()
{
	cin>>str.length;
	str.s=new char[str.length];
	for(int i=0; i<str.length;i++)
		cin.get(str.s[i]);
	for(int i=0; i<str.length;i++)
		cout<<str.s[i];
	return 0;
}