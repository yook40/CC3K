#ifndef _ORC_H_
#define _ORC_H_
#include "player.h"

class Cell;

class Orc: public Player {
	public:
		Orc(Cell *c);
		~Orc();
		void setGold(int g) override;
		void setHP(int h) override;
		void setAtk(int a) override;
		void setDef(int d) override;
};
#endif
