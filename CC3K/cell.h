#ifndef _CELL_H_
#define _CELL_H_
#include <memory>
class Posn;
class Thing;

class Cell {
	int x, y;
	char type;
	public:
	Cell(int x, int y, char type);
	~Cell();
	Posn getPosn();
	char getType();
	void setType(char t);
	Thing *thing;
};

#endif
