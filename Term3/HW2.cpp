#include <iostream>
#include <string>

using namespace std;
class strtest{

string test;

public: strtest(string s, int t){
	test = s;
	switch (t)
	{	
		case 1: test1(); break;
		case 2: test2(); break;
		case 3: test3(); break;
		case 4: test4(); break;
		case 5: test5(); break;
		case 6: test6(); break;
		case 7: test7(); break;
		case 8: test8(); break;
	}
}

private: 
void test1(){
	cout << test[test.length()-1];
}
void test2(){
	int i;
	cin >> i;
	cout << test[i];
}
void test3(){
	float f = -0.0123;
	cout << test[f];
}
void test4(){
	test[0] = '2';
	cout << test;
}
void test5(){
	test[0] = 2;
	cout << test;
}
void test7(){
	string test;
	string test2;
	cin >> test2;
	test = test2;
	cout << test << '\n';
	test2 = test2;
	cout << test2 << '\n';	
}
void test6(){
	char* p = &test[0];
	delete p;
	cout << test;
}
void test8(){
	cout << test.capacity() << '\n';
	test.reserve(2*test.capacity());
	cout << test.capacity();
}
};



int main(){
	int x;
	string test;
	cin >> x >> test;
	strtest bt(test, x);
	return 0;
}

