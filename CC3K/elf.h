#ifndef _ELF_H_
#define _ELF_H_
#include "player.h"

class Cell;

class Elf: public Player {
	public:
		void setGold(int g) override;
		Elf(Cell *c);
		~Elf();
		void setAtk(int a) override;
		void setHP(int h) override;
		void setDef(int d) override;
};

#endif
