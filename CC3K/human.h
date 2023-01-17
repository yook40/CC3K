#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "player.h"

class Cell;

class Human: public Player {
	public:
		void setGold(int g) override;
		Human(Cell *cell);
		~Human();
		void setAtk(int a) override;
		void setHP(int h) override;
		void setDef(int d) override;
};

#endif
