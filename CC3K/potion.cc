#include "potion.h"
using namespace std;

bool RH::visible = false;

bool BA::visible = false;

bool BD::visible = false;

bool PH::visible = false;

bool WA::visible = false;

bool WD::visible = false;

Potion::Potion(Cell *c): Item{c} {
	c->setType('P');
}

Potion::~Potion() {}

RH::RH(Cell *c): Potion{c} {}


void RH::effect(Player *p) {
	p->setHP(10);
}

RH::~RH() {}

BA::BA(Cell *c): Potion{c} {}

void BA::effect(Player *p) { p->setAtk(5); }

BA::~BA() {}

BD::BD(Cell *c): Potion{c} {}

void BD::effect(Player *p) { p->setDef(5); }

BD::~BD() {}

PH::PH(Cell *c): Potion{c} {}

void PH::effect(Player *p) {
	if (p->race == 'E') {
		p->setHP(10);
	} else {
		p->setHP(-10);
	}
}

PH::~PH() {}

WA::WA(Cell *c): Potion{c} {}

void WA::effect(Player *p) {
	if (p->race == 'E') {
		p->setAtk(5);
	} else {
		p->setAtk(-5);
	}
}

WA::~WA() {}

WD::WD(Cell *c): Potion{c} {}

void WD::effect(Player *p) {
	if (p->race == 'E') {
		p->setDef(5);
	} else {
		p->setDef(-5);
	}
}

WD::~WD() {}

