#ifndef _GAME_H_
#define _GAME_H_
#include <memory>
#include <vector>
#include <sstream>
#include <string>
class TextDisplay;
class Cell;
class Player;
class Floor;

class Game {
	Player *p;
	Floor *floor;
	TextDisplay* td;
	public:
	int numFloor;
	Game(char p, int barrier);
	~Game();
	void play();
	void moveToCell(Cell *c);
	Cell *directionOp(std::string s);
	friend class Floor;
	int barrier;
};
#endif
