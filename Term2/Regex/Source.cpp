#include <iostream>
#include <string>
#include <regex>
#include <fstream>
                                   
using namespace std;

string s;
regex e("http://");   

int main() {
	ifstream f1;
	ofstream f2;
	string F1, F2;
	cin >> F1 >> F2;
	f1.open(F1);
	f2.open(F2);
	try{
		if(!f1.is_open()) throw 123;
		if(!f2.is_open()) throw 123; 
    	while(getline(f1, s)){
			f2 << regex_replace(s, e, "https://") << "\r\n";
		}	
	}
	catch(...){
		cout << "Несуществующий файл" << "\r\n";
	}
	return 0;                                                           
}                                 
