#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "character.h"
class Player;
class Compass;
class Gold;
class BarrierSuit;

class Enemy: public Character {
	public:
	bool compass;
	Player *p;
	Enemy(int hp, int atk, int def, Cell *c, Player *p, bool compass);
	virtual ~Enemy();
	void setAtk(int a) override;
	void setDef(int d) override;
	void setHP(int h) override;
};

class Werewolf: public Enemy {
	public:
		Werewolf(Cell *c, Player *p, bool compass);
		~Werewolf();
};

class Vampire: public Enemy {
	public:
		Vampire(Cell *c, Player *p, bool compass);
		~Vampire();
		void stealHP(Player *p);
};

class Goblin: public Enemy {
	public:
		Goblin(Cell *c, Player *p, bool compass);
		~Goblin();
		void stealGold(Player *p);
};

class Troll: public Enemy {
	public:
		Troll(Cell *c, Player *p, bool compass);
		~Troll();
};

class Phoenix : public Enemy{
	public:
		Phoenix(Cell *c, Player *p, bool compass);
		~Phoenix();
};

class Merchant: public Enemy {
	public:
		static bool hostile;
		Merchant(Cell *c, Player *p, bool compass);
		~Merchant();
};

class Dragon: public Enemy {
	public:
		bool hostile;
		Dragon(Cell *c, Player *p, bool compass);
		~Dragon();
		Gold *g;
		BarrierSuit *bs;
};

#endif
