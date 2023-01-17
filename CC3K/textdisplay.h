#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include <iostream>
#include "floor.h"

class TextDisplay {
	Floor *floor;
	Game *g;
	public:
	TextDisplay(Floor *floor, Game *g);
	void print();
};
#endif
