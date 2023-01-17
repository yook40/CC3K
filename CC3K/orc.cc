#include "orc.h"

Orc::Orc(Cell *c): Player{180, 30, 25, c, 'O'} {}

Orc::~Orc() {}

void Orc::setGold(int g) {
	gold += g / 2;
}

void Orc::setAtk(int a) {
	attack += a;
}

void Orc::setHP(int h) {
	if (health + h >= 180) {
		health = 180;
	} else {
		health += h;
	}
}
void Orc::setDef(int d) {
	defense += d;
}

