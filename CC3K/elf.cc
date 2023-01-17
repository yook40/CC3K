#include "elf.h"

Elf::Elf(Cell *c): Player{140, 30, 10, c, 'E'} {}

Elf::~Elf() {}

void Elf::setGold(int g) {
	gold += g;
}

void Elf::setAtk(int a) {
	attack += a;
}

void Elf::setHP(int h) {
	if (health + h > 140) {
		health = 140;
	} else {
		health += h;
	}
}

void Elf::setDef(int d) {
	defense += d;
}

