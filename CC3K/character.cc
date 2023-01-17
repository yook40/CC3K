#include "character.h"
#include "posn.h"

Character::Character(int hp, int atk, int def, Cell *c): Thing{c}, health{hp}, attack{atk}, defense{def} {}

Character::~Character() {}

Posn Character::getPosn() {
	return cell->getPosn();
}

void Character::setHP(int h) { health += h; }

void Character::setAtk(int a) { attack += a; }

void Character::setDef(int d) { defense += d; }

int Character::getHP() { return health; }

int Character::getAtk() { return attack; }

int Character::getDef() { return defense; }
