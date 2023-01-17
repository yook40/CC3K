#include "dwarf.h"

Dwarf::Dwarf(Cell *c): Player{100, 20, 30, c, 'D'} {}

Dwarf::~Dwarf() { delete cell; }

void Dwarf::setGold(int g) {
	gold += 2 * g;
}

void Dwarf::setHP(int h) {
	if (health + h >= 100) {
		health = 100;
	} else {
		health += h;
	}
}
void Dwarf::setAtk(int a) {
	if (attack + a >= 0) {
		attack += a;
	} else {
		attack = 0;
	}
}

void Dwarf::setDef(int d) {
	if (defense + d >= 0) {
		defense += d;
	} else {
		defense = 0;
	}
}

