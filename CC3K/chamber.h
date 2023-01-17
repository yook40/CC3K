#ifndef _CHAMBER_H_
#define _CHAMBER_H_
#include <vector>
#include <memory>
#include "cell.h"

class Chamber {
	public:
	Chamber();
	~Chamber();
	std::vector<Cell *> cells;
};
#endif
