#include <fstream>
#include <cstdio>
#include <string>
#include "Header.h"
using namespace std;
int main() {
    fstream f;
	f.open("out.txt");
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
        Koshka cat;
		if (cat.color == "black") {
			f << "you can`t see the black cat"<<endl;
		}
		else
			f << cat.color <<" "<< cat.name << " is a cat " << cat.age << " years old" << " weights " << cat.weight << " kilo" << endl;
	}
	f.seekg(0, ios_base::beg);
	for (int i = 0; i < n; i++)
	{
		string str;
		getline(f, str);
		cout << str << endl;
	}
	f.close();
	system("pause");
	return 0;
}
