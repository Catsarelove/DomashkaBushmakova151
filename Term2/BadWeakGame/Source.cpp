#include "People_Things.h"
#include <iostream>
using namespace std;
int main() {
	MagicHat Hat;
	Armory St_Arm;
	wizard w_1;
	Arthur_Pepenger w_2;
	w_1.stats();
	w_2.stats();
	Hat.cast(0, w_1, w_2);
	w_1.getspell(3);
	Hat.cast(3, w_1, w_2);
	Hat.cast(3, w_1, w_2);
	Hat.cast(3, w_1, w_2);
	w_2.fight(w_1);
	w_2.fight(w_1);
	w_2.fight(w_1);
	St_Arm.attack(3, w_2, w_1);
	w_1.stats();
	w_2.stats();
	return 0;
}
