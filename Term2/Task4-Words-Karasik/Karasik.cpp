#include <fstream>
#include <Windows.h>
#include <map>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <string>
#include "HeadKaras.h"
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	mymap Voc;
	mychmap ChVoc;
	string F, OF;
	cin >> F;
	ifstream f(F);
	cin >> OF;
	ofstream of(OF);
	string word;
	fill(Voc, f);
	fill(ChVoc, f);
	cout << "Введите слово\n";
	cin >> word;
	cout <<"Частота = "<< freq(Voc, word) << endl;
	int n;
  cout<<"Введите количество слов\n";
  cin>>n;
	for(int i=0; i<n; i++) {
		cout<<"Введите слово\n";
		cin >> word;
		findinfile(f, word); //теперь Карасик находит слова с лишними символами!!
  }
	seevoc(Voc, of);
	seevoc(ChVoc, of);
	cout << "буль-буль\n";
	system("pause");
	return 0;
}
