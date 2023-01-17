#include "textdisplay.h"
#include <vector>
#include "game.h"
#include "player.h"
using namespace std;

TextDisplay::TextDisplay(Floor *floor, Game *g): floor{floor}, g{g} {}

void TextDisplay::print() {
	for (auto &row:floor->floor) {
		for (auto &cell:row) {
			if (cell->getPosn().x == floor->stair.x && cell->getPosn().y == floor->stair.y && floor->visible) {
				std::cout << '\\';
			} else {
				std::cout << cell->getType();
			}
		}
		cout << std::endl;
	}
	std::cout << "Race: ";
	if (floor->p->race == 'H') {
		std::cout << "Human ";
	} else if (floor->p->race == 'E') {
		std::cout << "Elf ";
	} else if (floor->p->race == 'O') {
		std::cout << "Orc ";
	} else if (floor->p->race == 'D') {
		std::cout << "Dwarf ";
	}
	std::cout << "Gold: " << floor->p->getGold() << "                                                  " << "Floor " << g->numFloor << std::endl;
	std::cout << "HP: " << floor->p->getHP() << std::endl;
	std::cout << "Atk: " << floor->p->getAtk() << std::endl;
	std::cout << "Def: " << floor->p->getDef() << std::endl;
	std::cout << "Action: Floor generated" << std::endl;
}
