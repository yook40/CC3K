#ifndef _POTION_H_
#define _POTION_H_
#include "item.h"
#include "player.h"

class Potion: public Item {
	public:
		Potion(Cell *c);
		virtual ~Potion();
		virtual void effect(Player *p) = 0;
};

class RH: public Potion {
	static bool visible;
	public:
	RH(Cell *c);
	~RH();
	void effect(Player *p);
};

class BA: public Potion {
	static bool visible;
	public:
		BA(Cell *c);
		void effect(Player *p);
		~BA();
};

class BD: public Potion {
	static bool visible;
	public:
		BD(Cell *c);
		void effect(Player *p);
		~BD();
};

class PH: public Potion {
	static bool visible;
	public:
		PH(Cell *c);
		void effect(Player *p);
		~PH();
};

class WA: public Potion {
	static bool visible;
	public:
		WA(Cell *c);
		void effect(Player *p);
		~WA();
};

class WD: public Potion {
	static bool visible;
	public:
		WD(Cell *c);
		void effect(Player *p);
		~WD();
};

#endif
