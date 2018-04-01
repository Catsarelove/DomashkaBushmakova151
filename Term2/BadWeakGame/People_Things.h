#include <string>
#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
class stranger {
public:
    int exp = 1;
    int intelligence = 45;
    int strength = 20;
    int defence = 0;
	int mood = 0;
    int health = 75;
	string name = "Complete Stranger_";
	stranger() {
		cout << "Somebody appears" << endl;
		for (int i = 0; i < 6; i++) {
			char num = '0' + rand() % 10;
			name = name + num;
		}
	}
	void kill() {
		cout << endl << "RIP " << name << "..." << endl;
		health = 0;
		exp = 0;
		intelligence = 0;
		strength = 0;
		defence = 0;
		mood = 7;
		name = "Dead body of " + name;
		system("pause");
	}
	void stats() {
		cout << name << " characteristics: \n" <<"EXP: "<< exp << endl;
		cout << "Health: " << health << endl;
		cout << "Intelligence: " << intelligence << endl;
		cout << "Strength: " << strength << endl;
		cout << "Defence: " << defence << endl;
		cout << "Mood: " << mood << endl << endl;
		system("pause");
	}
    void fight(stranger& fiend) {
		cout << name << " attacks " << fiend.name << " with bare hands "<< endl;
		int d= rand() % 31/((fiend.exp>exp)*2+(fiend.strength>strength)*2+fiend.defence*2+1);
		fiend.health -= d;
		if (d)
		exp++;
		cout << fiend.name << " loses " << d << " hp" << endl << endl;
		if (fiend.health <= 0) {
			fiend.kill();
			exp += 5;
		}
		system("pause");
	}
	void support(stranger ally) {
		cout << "My respect, bro" << endl;
	}
};
class warrior :public stranger {
protected:
	friend class Armory;
	bool* Av;
public:
	warrior() {
		Av = new bool[4];
		for (int i = 0; i < 4; i++) {
			Av[i] = 0;
		}
		Av[0] = 1;
		cout << "HERE COMES THE WARRIA" << endl;
		cout << "What is your glorious name?" << endl;
		getline(cin, name);
		cout << "Hail, " << name << '!' << endl << endl;
	    mood = 3;
		strength = 30;
		defence = 1;
	}
	void gettool(int t){
		cout << name << " tries to unlock new weapon" << endl;
		if(Av[t])
			cout << "Spell is already in your Armory, " << name << endl;
		else {
			if (t != 3 && exp) {
				cout <<"The Lake Lady asks "<< name << " for a 1 exp per weapon. Print 1 if allright; 0 to cancel" << endl;
				int x;
				cin >> x;
				if (x) {
					exp--;
					Av[t] = 1;
					cout<< name << " sees hands of mermaids giving them brand new weapon \n" << "Nice doing business with you, " <<name<< endl << endl;
				}
				else cout << "The Lake Lady tries to drown " << name <<". Them barely manages to escape." << endl << endl;

			}
		}

	}
	~warrior() {
		delete[] Av;
	}
};
class Arthur_Pepenger : public warrior {
public:	Arthur_Pepenger() {
		defence = 7;
		strength = 55;
		string pn = name;
		name = "Arthur Pepenger ";
		Av[3] = 1;
		for (int i = 0; i < 3; i++) {
			char s = '0' + rand() % 10;
			name += s;
		}
		cout << pn << " uncovers his face! You see the Great King " << name << " !" << endl << endl;
	}

};
class wizard : public stranger {
protected:
	friend class MagicHat;
	bool * Av;
public:	wizard() {
		Av = new bool[6];
		for (int i = 1; i < 6; i++)
			Av[i] = 0;
		Av[0] = 1;
		cout << "Stranger with sharp-pointed HAT materializes here. What is your name, stranger?" << endl;
		getline(cin, name);
		cout << "Merlin bless you, " << name << '!' << endl<<endl;
		intelligence = 60;
		strength = 15;
	}
	void getspell(int s) {
		cout << name << " tries to unlock new spell" << endl;
		if (Av[s]) {
			cout << "Spell is already in your Hat, " <<name<<endl;
		}
		else
			if(exp){
				cout<<name <<" hears humbling voice of the HAT: \n"<<"I offer you a deal, "<< name<<". "<< "You will lose 1 exp. Print 1 if allright; 0 to cancel" << endl;
				int x;
				cin >> x;
				if (x) {
					exp--;
					Av[s] = 1;
					cout <<"The HAT is much more powerful now. IT gratefully says:" <<"That was a bargain!" << endl<<endl;
				}
				else cout << "The HAT is mad at " << name << ". It yells: \n" << "Scrooge!" << endl << endl;
		}
	}
	~wizard() {
		delete[] Av;
	}
};
typedef void(*spell) (wizard&, stranger&);
typedef void(*tool)(warrior&, stranger&);
//wizard
void white_rabbit(wizard&, stranger&);
void oh_piano(wizard&, stranger&);
void rattify(wizard&, stranger&);
void insideout(wizard&, stranger&);
void zombify(wizard&, stranger&);
void cure(wizard&, stranger&);
//warrior
void wooden_stick(warrior&, stranger&);
void plastic_sword(warrior&, stranger&);
void sh_sword(warrior&, stranger&);
//Arthur Pepenger
void excalibur(warrior&, stranger&);
class MagicHat {
	int size = 6;
public:
	spell* collection;
	MagicHat() {
		collection = new spell[6];
		spell f = &white_rabbit;
		collection[0] = f;
		f = &oh_piano;
		collection[1] = f;
		f = &rattify;
		collection[2] = f;
		f = &insideout;
		collection[3] = f;
		f = &zombify;
		collection[4] = f;
		f = &cure;
		collection[5] = f;
	}
	void cast(int s, wizard& w, stranger& victim) {
		if (w.Av[s]) {
			collection[s](w, victim);
			if (victim.health<=0) victim.kill();
			if (w.health<=0) w.kill();
		}
		else {
			cout <<w.name<<" can`t remember the spell. " <<w.name<<" cries out and throws the HAT on the dusty ground. Then he tramples it in a fury" << endl<<endl;
		}
	}
};
class Armory {

public: 
	tool* collection;
	Armory() {
		collection = new tool[4];
		collection[0] = &wooden_stick;
		collection[1] = &plastic_sword;
		collection[2] = &sh_sword;
		collection[3] = &excalibur;
	}
	void attack(int t, warrior& warrior, stranger & victim) {
		if (warrior.Av[t]) {
			collection[t](warrior, victim);
			if (victim.health <= 0) victim.kill();
		}
		else {
			cout << warrior.name << " tries to beat " << victim.name << " with imaginary weapon. Somebody call 911." << endl << endl;
			warrior.mood--;
		}
	}
};
