#include <iostream>
#include "player.h"
#include "floor.h"
#include "potion.h"
#include "game.h"
#include <vector>
#include <sstream>
#include "posn.h"
#include <algorithm>
#include <random>
#include "barrier.h"
#include <chrono>
#include <iostream>
#include "enemy.h"
#include "chamber.h"
#include "gold.h"
using namespace std;

void Floor::spawn(vector<string> thing, bool compass) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    shuffle(chambers.begin(), chambers.end(), rng);
    shuffle(chambers[0]->cells.begin(), chambers[0]->cells.end(), rng);
    while (chambers[0]->cells[0]->thing) {
		shuffle(chambers[0]->cells.begin(), chambers[0]->cells.end(), rng);
    }
    shuffle(thing.begin(), thing.end(), rng);
    if (thing[0] == "human") {
		p = new Human{chambers[0]->cells[0]};
        chambers[0]->cells[0]->thing = p;
    } else if (thing[0] == "elf") {
		p = new Elf{chambers[0]->cells[0]};
        chambers[0]->cells[0]->thing = p;
    } else if (thing[0] == "orc") {
		p = new Orc{chambers[0]->cells[0]};
        chambers[0]->cells[0]->thing = p;
    } else if (thing[0] == "dwarf") {
		p = new Dwarf{chambers[0]->cells[0]};
        chambers[0]->cells[0]->thing = p;
    } else if (thing[0] == "werewolf") {
        chambers[0]->cells[0]->thing = new Werewolf{chambers[0]->cells[0], p, compass};
    } else if (thing[0] == "vampire") {
        chambers[0]->cells[0]->thing = new Vampire{chambers[0]->cells[0], p, compass};
    } else if (thing[0] == "goblin") {
        chambers[0]->cells[0]->thing = new Goblin{chambers[0]->cells[0], p, compass};
    } else if (thing[0] == "troll") {
        chambers[0]->cells[0]->thing = new Troll{chambers[0]->cells[0], p, compass};
    } else if (thing[0] == "phoenix") {
        chambers[0]->cells[0]->thing = new Phoenix{chambers[0]->cells[0], p, compass};
    } else if (thing[0] == "merchant") {
        chambers[0]->cells[0]->thing = new Merchant{chambers[0]->cells[0], p, compass};
    } else if (thing[0] == "dragon") {
        chambers[0]->cells[0]->thing = new Dragon{chambers[0]->cells[0], p, compass};
	} else if (thing[0] == "RH") {
		chambers[0]->cells[0]->thing = new RH{chambers[0]->cells[0]};
	} else if (thing[0] == "BA") {
		chambers[0]->cells[0]->thing = new BA{chambers[0]->cells[0]};
	} else if (thing[0] == "BD") {
		chambers[0]->cells[0]->thing = new BD{chambers[0]->cells[0]};
	} else if (thing[0] == "PH") {
		chambers[0]->cells[0]->thing = new PH{chambers[0]->cells[0]};
	} else if (thing[0] == "WA") {
		chambers[0]->cells[0]->thing = new WA{chambers[0]->cells[0]};
	} else if (thing[0] == "WD") {
		chambers[0]->cells[0]->thing = new WD{chambers[0]->cells[0]};
    } else if (thing[0] == "1") {
        chambers[0]->cells[0]->thing = new Gold{1, chambers[0]->cells[0]};
    } else if (thing[0] == "2") {
        chambers[0]->cells[0]->thing = new Gold{2, chambers[0]->cells[0]};
    } else if (thing[0] == "6") {
        chambers[0]->cells[0]->thing = new Gold{6, chambers[0]->cells[0]};
		enemyNum -= 1;
		Posn po = chambers[0]->cells[0]->getPosn();
		vector<Cell *> neighbours;
		for (int i = po.x - 1; i < po.x + 2; i++) {
			for (int j = po.y - 1; j < po.y + 2; j++) {
				if (floor[i][j]->getType() == '.') {
					neighbours.emplace_back(floor[i][j]);
				}
			}
		}
		shuffle(neighbours.begin(), neighbours.end(), rng);
		neighbours[0]->thing = new Dragon{neighbours[0], p, compass};
    } else if (thing[0] == "barrier") {
        chambers[0]->cells[0]->thing = new BarrierSuit{chambers[0]->cells[0]};
        Posn po = chambers[0]->cells[0]->getPosn();
		vector<Cell *> neighbours;
		for (int i = po.x - 1; i < po.x + 2; i++) {
		    for (int j = po.y - 1; j < po.y + 2; j++) {
		        if (floor[i][j]->getType() == '.') {
		            neighbours.emplace_back(floor[i][j]);
		        }
		    }
		}
		shuffle(neighbours.begin(), neighbours.end(), rng);
		neighbours[0]->thing = new Dragon{neighbours[0], p, compass};
		enemyNum -= 1;
    } else if (thing[0] == "stair") {
		this->stair = chambers[0]->cells[0]->getPosn();
	}
}

Floor::Floor(char p, Game *g, int barrier): g{g}, enemyNum{20}, visible{false} {
    layout = "|-----------------------------------------------------------------------------||                                                                             || |--------------------------|        |-----------------------|               || |..........................|        |.......................|               || |..........................+########+.......................|-------|       || |..........................|   #    |...............................|--|    || |..........................|   #    |..................................|--| || |----------+---------------|   #    |----+----------------|...............| ||            #                 #############                |...............| ||            #                 #     |-----+------|         |...............| ||            #                 #     |............|         |...............| ||            ###################     |............|   ######+...............| ||            #                 #     |............|   #     |...............| ||            #                 #     |-----+------|   #     |--------+------| ||  |---------+-----------|     #           #          #              #        ||  |.....................|     #           #          #         |----+------| ||  |.....................|     ########################         |...........| ||  |.....................|     #           #                    |...........| ||  |.....................|     #    |------+--------------------|...........| ||  |.....................|     #    |.......................................| ||  |.....................+##########+.......................................| ||  |.....................|          |.......................................| ||  |---------------------|          |---------------------------------------| ||                                                                             ||-----------------------------------------------------------------------------|";
    istringstream iss{layout};
	for (int i = 0; i < 25; i++) {
		char symb = '|';
		int y = 0;
		while (y < 79) {
		    iss >> noskipws >> symb;
		    row.emplace_back(new Cell{i, y, symb});
		    y += 1;
		}
		floor.emplace_back(row);
		row.clear();
	}
	g->numFloor += 1;
	Chamber *chamber1 = new Chamber();
	Chamber *chamber2 = new Chamber();
	Chamber *chamber3 = new Chamber();
	Chamber *chamber4 = new Chamber();
	Chamber *chamber5 = new Chamber();
	chambers = {chamber1, chamber2, chamber3, chamber4, chamber5};
    for (int i = 3; i < 6; i++) {
        for (int j = 3; j < 29; j++) {
            chamber1->cells.emplace_back(new Cell{i, j, '.'});
			delete floor[i][j];
			floor[i][j] = chamber1->cells[chamber1->cells.size() - 1];
        }
        for (int k = 39; k < (i == 5? 70:62); k++) {
			chamber2->cells.emplace_back(new Cell{i, k, '.'});
			delete floor[i][k];
			floor[i][k] = chamber2->cells[chamber2->cells.size() - 1];
        }
    }
    for (int i = 6; i < 13; i++) {
        if (i == 6) {
            for (int j = 3; j < 29; j++) {
				chamber1->cells.emplace_back(new Cell{i, j, '.'});
				delete floor[i][j];
				floor[i][j] = chamber1->cells[chamber1->cells.size() - 1];
            }
        }
        for (int k = (i == 6? 39:61); k < (i == 6? 73:76); k++) {
			chamber2->cells.emplace_back(new Cell{i, k, '.'});
			delete floor[i][k];
			floor[i][k] = chamber2->cells[chamber2->cells.size() - 1];
        }
        if (i > 9) {
            for (int j = 38; j < 50; j++) {
				chamber3->cells.emplace_back(new Cell{i, j, '.'});
				delete floor[i][j];
				floor[i][j] = chamber3->cells[chamber3->cells.size() - 1];
            }
        }
    }
    for (int i = 4; i < 25; i++) {
		chamber4->cells.emplace_back(new Cell{15, i, '.'});
		delete floor[15][i];
		floor[15][i] = chamber4->cells[chamber4->cells.size() - 1];
    }
    for (int i = 16; i < 22; i++) {
        for (int j = 4; j < 25; j++) {
			chamber4->cells.emplace_back(new Cell{i, j, '.'});
			delete floor[i][j];
			floor[i][j] = chamber4->cells[chamber4->cells.size() - 1];
        }
        for (int j = (i < 19? 65:37); j < 76; j++) {
			chamber5->cells.emplace_back(new Cell{i, j, '.'});
			delete floor[i][j];
			floor[i][j] = chamber5->cells[chamber5->cells.size() - 1];
        }
    }
    if (p == 'h') {
		spawn({"human"}, false);
    } else if (p == 'e') {
        spawn({"elf"}, false);
    } else if (p == 'd') {
        spawn({"dwarf"}, false);
    } else {
        spawn({"orc"}, false);
    }
	spawn({"stair"}, false);
	vector<string> select_potion = {"RH", "BA", "BD", "PH", "WA", "WD"};
    vector<string> select_gold = {"1", "1", "1", "1", "1", "2", "2", "6"};
	vector<string> select_enemy = {"werewolf", "werewolf", "werewolf", "werewolf", "vampire", "vampire", "vampire", "goblin", "goblin", "goblin", "goblin", "goblin", "troll", "troll", "phoenix", "phoenix", "merchant", "merchant"};
	for (int i = 0; i < 10; i++) {
		spawn(select_potion, false);
	}
	for (int i = 0; i < 10; i++) {
		spawn(select_gold, false);
	}
	if (barrier == g->numFloor) {
		spawn({"barrier"}, false);
	}
	vector<int> compass_holder;
	for (int i = 0; i < enemyNum; i++) {
		compass_holder.emplace_back(i);
	}
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine rng{seed};
	shuffle(compass_holder.begin(), compass_holder.end(), rng);
	for (int i = 0; i < enemyNum; i++) {
		if (i == compass_holder[0]) {
			spawn(select_enemy, true);
		} else {
			spawn(select_enemy, false);
		}
	}
}

Floor::~Floor() {
	for (auto &row:floor) {
		for (auto &cell:row) {
			if (cell->thing) {
				delete cell->thing;
			}
			delete cell;
		}
	}
}

