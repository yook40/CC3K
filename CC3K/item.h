#ifndef _ITEM_H_
#define _ITEM_H_
#include "thing.h"
class Item: public Thing {
	public:
		Item(Cell *cell);
		virtual ~Item();
};
#endif
