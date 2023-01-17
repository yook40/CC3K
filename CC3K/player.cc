#include "player.h"

Player::Player(int hp, int atk, int def, Cell *c, char race): Character{hp, atk, def, c}, gold{0}, race{race} {
	c->setType('@');
}

Player::~Player() {}

int Player::getGold() {
	return gold;
}

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

Dwarf::Dwarf(Cell *c): Player{100, 20, 30, c, 'D'} {}

Dwarf::~Dwarf() {}

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

