#ifndef _DWARF_H_
#define _DWARF_H_

#include "player.h"

class Cell;

class Dwarf: public Player {
	public:
		Dwarf(Cell *c);
		~Dwarf();
		void setGold(int g);
		void setHP(int h) override;
		void setAtk(int a) override;
		void setDef(int d) override;
};

#endif
