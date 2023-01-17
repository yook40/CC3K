#ifndef _BARRIER_H_
#define _BARRIER_H_
#include "item.h"
class Cell;
class Dragon;

class BarrierSuit: public Item {
	public:
		BarrierSuit(Cell *cell);
		~BarrierSuit();
		Dragon *dragon;
		bool pick;
		void setDragon(Dragon *d);
};
#endif
