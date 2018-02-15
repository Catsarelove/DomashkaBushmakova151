#include <string>
#include <iostream>
using namespace std;
struct Koshka{
	string name;
	int weight;
	string color;
	int age;
	Koshka() {
		cin >> name;
		cin >> color;
		age = rand() % 15 ;
		weight = rand()%13;
	}
	void feed() {
		weight+=0,5;
		if (weight > 12)
			cout << "MYARGH NO";
		weight--;
	}
	void seekoshka() {
		if (color == "black")
			cout << "you can`t see the black cat";
		else
			cout << color <<' '<< name << " is a cat " << age << " years old" << " weights " << weight << " kilo" << endl;
	}
};
