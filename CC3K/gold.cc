#include "gold.h"

Gold::Gold(int v, Cell *c): Thing{c}, value{v} {
	c->setType('G');
}

int Gold::getValue() { return value; }

