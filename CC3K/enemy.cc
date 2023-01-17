#include <iostream>
#include "enemy.h"
#include "compass.h"
#include "player.h"
#include "gold.h"
Enemy::Enemy(int hp, int atk, int def, Cell *c, Player *p, bool compass): Character{hp, atk, def, c}, compass{compass}, p{p} {}

Enemy::~Enemy() {}

void Enemy::setHP(int h) {
	setHP(h);
}

void Enemy::setAtk(int a) {}

void Enemy::setDef(int d) {}

Werewolf::~Werewolf() {
	if (compass) {
		cell->setType('C');
		cell->thing = new Compass{cell};
	} else {
	    cell->setType('.');
	}
	p->setGold(1);
}

Vampire::~Vampire() {
	if (compass) {
		cell->setType('C');
		cell->thing = new Compass{cell};
	} else {
	    cell->setType('.');
	}
	p->setGold(1);
}

Goblin::~Goblin() {
	if (compass) {
		cell->setType('C');
		cell->thing = new Compass{cell};
	} else {
	    cell->setType('.');
	}
	p->setGold(1);
}

Troll::~Troll() {
	if (compass) {
		cell->setType('C');
		cell->thing = new Compass{cell};
	} else {
	    cell->setType('.');
	}
	p->setGold(1);
}

Phoenix::~Phoenix() {
	if (compass) {
		cell->setType('C');
		cell->thing = new Compass{cell};
	} else {
	    cell->setType('.');
	}
	p->setGold(1);
}

Merchant::~Merchant() {
	if (compass) {
		cell->setType('C');
		cell->thing = new Compass{cell};
		p->setGold(4);
	} else {
	    cell->setType('G');
		cell->thing = new Gold{4, cell};
	}
}

Dragon::~Dragon() {
	if (compass) {
		cell->setType('C');
		cell->thing = new Compass{cell};
	} else {
	    cell->setType('.');
	}
}

Werewolf::Werewolf(Cell *c, Player *p, bool compass): Enemy{120, 30, 5, c, p, compass} {
	c->setType('W');
}

Vampire::Vampire(Cell *c, Player *p, bool compass): Enemy{50, 25, 25, c, p, compass} {
	c->setType('P');
}

void Vampire::stealHP(Player *p) {
	p->setHP(-5);
	this->setHP(5);
}

Goblin::Goblin(Cell *c, Player *p, bool compass): Enemy{70, 5, 10, c, p, compass} {
	c->setType('N');
}

void Goblin::stealGold(Player *p) {
	if (p->getGold() >= 5) {
		p->setGold(-5);
	} else {
		p->setGold(-(p->getGold()));
	}
}

Troll::Troll(Cell *c, Player *p, bool compass): Enemy{120, 25, 15, c, p, compass} {
	c->setType('T');
}

Phoenix::Phoenix(Cell *c, Player *p, bool compass): Enemy{50, 35, 20, c, p, compass} {
	c->setType('X');
}

Merchant::Merchant(Cell *c, Player *p, bool compass): Enemy{30, 70, 5, c, p, compass} {
	c->setType('M');
}


Dragon::Dragon(Cell *c, Player *p, bool compass): Enemy{150, 20, 20, c, p, compass}, hostile{false} {
	c->setType('D');
}

bool Merchant::hostile = false;

