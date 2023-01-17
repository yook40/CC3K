#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include "thing.h"

class Character: public Thing {
	protected:
	int health, attack, defense;
	public:
	Character(int hp, int atk, int def, Cell *c);
	virtual ~Character();
	int getAtk();
	int getHP();
	int getDef();
	virtual void setAtk(int a) = 0;
	virtual void setHP(int h) = 0;
	virtual void setDef(int d) = 0;
	virtual Posn getPosn();
};
#endif
