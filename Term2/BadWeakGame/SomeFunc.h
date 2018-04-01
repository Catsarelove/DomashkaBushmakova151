#include "People_Things.h"
#include <math.h>
//wizard
void white_rabbit(wizard& wizard, stranger& victim) {
	cout << wizard.name << " looks in the Hat. Big fat rabbit jumps out of it and punches him in the face with it`s tiny paws. What a fail." << endl;
	cout << victim.name << " says: Ha-ha loser!" << endl<<endl;
	if (wizard.name.find("The Loser") == UINT32_MAX)
	wizard.name = wizard.name + " The Loser";
	wizard.mood--;
	victim.mood++;
	system("pause");
}
void oh_piano(wizard& wizard, stranger& victim) {
	cout << wizard.name << " says: OH GREAT ALMIGHTLY GOD OF MUSIC GIVE ME DA POWA TO CRUSH THIS SCUM " << endl;
	cout << "deafly piano sounds" << endl;
	cout << "huge piano falls on " << victim.name << "`s head" << endl;
	cout << victim.name << " says: AAAAAAAAAAA!" << endl;
	cout << victim.name << " loses 10 hp" << endl<<endl;
	victim.health -= 10;
	int coin = rand() % 2;
	if (victim.defence && coin)
	{
		int r = victim.defence + rand() % 5;
		cout << victim.name << " recovers " << r << endl<<endl;
		victim.health++;
		victim.exp++;
	}
	wizard.exp++;
	system("pause");
}
void rattify(wizard& wizard, stranger& victim) {
	cout << wizard.name << " says: THANK YOU, MIGHTY MAGIC HAT. I`LL NOW TURN YOU INTO RAT" << endl;
	cout << victim.name << " says: Wow, so old-fashioned" << endl;
	cout << "********" << endl;
	if(victim.name.find("The Rat") == UINT32_MAX)
	victim.name = victim.name + " The Rat";
	victim.intelligence /= 2;
	victim.strength /= 2;
	victim.health /= 2;
	victim.exp--;
	cout << victim.name << " is now a rat" << endl << endl;
	wizard.exp++;
	system("pause");
}
void insideout(wizard & wizard, stranger& victim) {
	cout << wizard.name << " says: Have you ever thought what your insides color is, " << victim.name << "?" << endl;
	cout << victim.name << " is now inside out. Looks disgusting. Magic is cruel. Please avoid to repeat" << endl;
	if (wizard.name.find("Heartless")==UINT32_MAX)
	wizard.name = "Heartless " + wizard.name;
	cout << victim.name << " loses 18 hp" << endl;
	victim.health -= 18;
	int r = rand() % (victim.defence + 1);
	if (r) {
		cout << victim.name << " recovers " << r << " hp" << endl;
		victim.health += r;
	}
	victim.mood = 0;
	wizard.exp++;
	cout << wizard.name << " says: MWAHAHAHHA!!" << endl<<endl;
	system("pause");
}
void zombify(wizard& wizard, stranger& victim) {
	cout << wizard.name << " says: How about watching a TV?" << endl;
	int coin = rand() % 2;
	if (coin) {
		cout << victim.name << "B-bra-a-ains-s..." << endl;
		cout << wizard.name << " Whait oh shi~ " << endl;
		cout << wizard.name << "AAAAAAAAAAAA" << endl;
		cout << wizard.name << " loses 10 hp and a lil bit of brain" << endl;
		wizard.health -= 10;
		wizard.intelligence -= 5;
		wizard.mood--;
	}
	else {
		cout << victim.name << "Uuugh uurg..." << endl;
		cout << victim.name << " is now dumb. Accidentally beats the head against the wall and loses 5 hp" << endl;
		victim.health -= 5;
		victim.mood = 4;
		victim.intelligence = 0;
		wizard.exp++;
	}
	cout << endl;
	system("pause");
}
void cure(wizard& doctor, stranger& patient) {
	cout << patient.name << " needs help!" << endl;
	cout << "Doctor " << doctor.name << " is doing some magic treatment..." << endl;
	cout << "*******" << endl;
	if (!patient.health) {
		cout << "Doctor " << doctor.name << "Take it easy. You`rnt Jesus, man" << endl;
		cout << patient.name << " dies on " << doctor.name << "`s hands... :^(" << endl;
	}
	else {
		int luck = rand() % 15 + 1;
		cout << patient.name << " recovers " << luck << " hp" << endl;
		patient.health += luck;
		doctor.exp += luck / 15 + (luck / 10 + luck / 5) / 2;
	}
	cout << endl;
	system("pause");
}
//warrior
void wooden_stick(warrior& warrior, stranger& victim) {
	cout << warrior.name << " attacks " << victim.name << " with wooden stick!" << endl;
	cout << warrior.name << ": ARGH!!!" << endl;
	cout << victim.name << ": AAAA!!" << endl;
	int d = (rand() % 10 +5)/ ((warrior.exp < victim.exp) * 2 + (warrior.strength < victim.strength) * 2) - victim.defence;
	if (d > 0) {
		cout << victim.name << " loses " << d << " hp!" << endl << endl;
		victim.health -= d;
		warrior.exp++;
	}
	else cout << victim.name << " leaves unharmed. Lucky day for " << victim.name << endl << endl;
	system("pause");
}
void plastic_sword(warrior& warrior, stranger& victim) {
	cout <<warrior.name<<" says:\n" <<victim.name << ", I will pierce you with my PLASTIC SWORD!!" << endl;
	cout << victim.name << ": AAAA!!" << endl;
	int d = (rand() % 15 + 5) / ((warrior.exp < victim.exp) * 2 + (warrior.strength < victim.strength) * 2) - victim.defence;
	if (d > 0) {
		cout << victim.name << " loses " << d << " hp!" << endl << endl;
		victim.health -= d;
		warrior.exp++;
	}
	else cout << victim.name << " leaves unharmed. Lucky day for " << victim.name << endl << endl;
	system("pause");
}
void sh_sword(warrior& warrior, stranger& victim) {
	cout << victim.name << "is blinded by SUPERSHINING SWORD of" <<warrior.name<<" !"<< endl;
	cout << victim.name << ": AAAA!!" << endl;
	int d = (rand() % 20 + 5) / ((warrior.exp < victim.exp) * 2 + (warrior.strength < victim.strength) * 2) - victim.defence;
	if (d > 0) {
		cout << victim.name << " loses " << d << " hp!" << endl << endl;
		victim.health -= d;
		warrior.exp++;
	}
	else cout << victim.name << " leaves unharmed. Lucky day for " << victim.name << endl << endl;
	system("pause");
}
void excalibur(warrior& Arthur, stranger& victim) {
	cout<<Arthur.name << " unleashes his EXCALIBUR. He brings only death to his enemies!" << endl << endl;
	victim.health = 0;
	system("pause");
}
