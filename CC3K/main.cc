#include "floor.h"
#include "game.h"
#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	char r;
	std::cout << "Select a race: ";
	std::cin >> r;
	vector<int> barrier = {1, 2, 3, 4, 5};
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(barrier.begin(), barrier.end(), std::default_random_engine(seed));
	Game g = Game(r, barrier[0]);
	g.play();
}
