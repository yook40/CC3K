#ifndef _GOLD_H_
#define _GOLD_H_
#include "thing.h"

class Gold: public Thing {
	int value;
	public:
	Gold(int v, Cell *c);
	int getValue();
};

#endif
