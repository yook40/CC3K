#include "game.h"
#include <vector>
#include "textdisplay.h"
#include <iostream>
#include "posn.h"
#include "floor.h"
#include <random>
#include <chrono>
#include <algorithm>
#include "player.h"
#include "potion.h"
using namespace std;

Game::Game(char p, int barrier): floor{new Floor(p, this, barrier)}, td{new TextDisplay(this->floor, this)}, numFloor{1}, barrier{barrier} {
	this->p = floor->p;
}

void Game::moveToCell(Cell *c) {
	floor->p->cell->thing = nullptr;
	floor->p->cell->setType('.');
	floor->p->cell = c;
	floor->p->cell->setType('@');
	floor->p->cell->thing = floor->p;
}

Cell *Game::directionOp(std::string s) {
	Posn posn = floor->p->cell->getPosn();
	if (s == "no") { return floor->floor[posn.x - 1][posn.y]; }
	else if (s == "ea") { return floor->floor[posn.x][posn.y + 1]; }
	else if (s == "we") { return floor->floor[posn.x][posn.y - 1]; }
	else if (s == "so") { return floor->floor[posn.x + 1][posn.y]; }
	else if (s == "se") { return floor->floor[posn.x + 1][posn.y + 1]; }
	else if (s == "sw") { return floor->floor[posn.x + 1][posn.y - 1]; }
	else if (s == "nw") { return floor->floor[posn.x - 1][posn.y - 1]; }
	else { return floor->floor[posn.x - 1][posn.y + 1]; }
}

void Game::play() {
	td->print();
	string cmd;
	while (std::cin >> cmd) {
		if (cmd.length() == 2) {
			if (directionOp(cmd)->getType() == '.' || directionOp(cmd)->getType() == 92 || directionOp(cmd)->getType() == '+' || directionOp(cmd)->getType() == '#') {
				moveToCell(directionOp(cmd));
				if (floor->p->cell->getPosn() == floor->stair) {
					floor->~Floor();
					floor = new Floor(p->race, this, barrier);
					floor->p = p;
					numFloor += 1;
				}
			}
		}
		if (cmd == "a") {
			std::cin >> cmd;
		}
		if (cmd == "u") {
			std::cin >> cmd;
			if (directionOp(cmd)->getType() == 'P') {
				Thing *t = directionOp(cmd)->thing;
				dynamic_cast<Potion *>(t)->effect(p);
			}
		}
		if (cmd == "r") {
			delete floor;
			delete td;
			char r;
			cout << "Select a race: ";
			cin >> r;
			floor = new Floor(r, this, barrier);
			td = new TextDisplay(this->floor, this);
			numFloor = 1;
		}
		if (cmd == "q") {
			cout << "Your score is: " << p->getGold() << endl;
			return;
		}
		td->print();
	}
}

Game::~Game() {
	delete floor;
	delete td;
}
