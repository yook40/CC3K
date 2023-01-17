#include "barrier.h"

BarrierSuit::BarrierSuit(Cell *c): Item{c}, pick{false}, dragon{nullptr} {
	c->setType('B');
}

BarrierSuit::~BarrierSuit() {}

void BarrierSuit::setDragon(Dragon *d) {
	dragon = d;
}

