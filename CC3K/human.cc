#include "human.h"

Human::Human(Cell *cell): Player{140, 20, 20, cell, 'H'} {}

void Human::setGold(int g) { gold += g; }

Human::~Human() { delete cell; }

void Human::setAtk(int a) {
	attack += a;
}

void Human::setHP(int a) {
	if (health + a >= 140) {
		health = 140;
	} else {
		health += a;
	}
}

void Human::setDef(int d) {
	defense += d;
}

