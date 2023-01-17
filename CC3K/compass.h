#ifndef _COMPASS_H_
#define _COMPASS_H_
#include "item.h"
class Cell;

class Compass: public Item {
	public:
		Compass(Cell *c);
		~Compass();
};
#endif
