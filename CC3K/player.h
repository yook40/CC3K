#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "character.h"

class Cell;

class Player: public Character {
	protected:
		int gold;
	public:
		char race;
		virtual void setGold(int g) = 0;
		int getGold();
		Player(int hp, int atk, int def, Cell *c, char race);
		virtual ~Player();
};

class Human: public Player {
	public:
		void setGold(int g) override;
		Human(Cell *cell);
		~Human();
		void setAtk(int a) override;
		void setHP(int h) override;
		void setDef(int d) override;
};

class Elf: public Player {
	public:
		void setGold(int g) override;
		Elf(Cell *c);
		~Elf();
		void setAtk(int a) override;
		void setHP(int h) override;
		void setDef(int d) override;
};

class Orc: public Player {
	public:
		Orc(Cell *c);
		~Orc();
		void setGold(int g) override;
		void setHP(int h) override;
		void setAtk(int a) override;
		void setDef(int d) override;
};


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
