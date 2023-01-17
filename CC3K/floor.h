#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <string>
#include <vector>
#include "posn.h"

class Player;
class Cell;
class Chamber;
class Game;

class Floor {
	std::string layout;
	std::vector<Chamber *> chambers;
	static int numFloor;
	Game *g;
	public:
	std::vector<Cell *> row;
	std::vector<std::vector<Cell *>> floor;
		Floor(char p, Game *g, int barrier);
		void spawn(std::vector<std::string> thing, bool compass);
		~Floor();
		int enemyNum;
		Player *p;
		Posn stair;
		bool visible;
		friend class Game;
};

#endif
