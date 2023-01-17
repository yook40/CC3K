#ifndef _THING_H_
#define _THING_H_
#include "posn.h"
#include "cell.h"

class Thing {
	public:
		Posn getPosn();
		Thing(Cell *c);
		virtual ~Thing();
		Cell *cell;
};
#endif
