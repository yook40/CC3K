#include "posn.h"

Posn::Posn(int x, int y): x{x}, y{y} {}

bool Posn::operator==(const Posn &o) {
	return x == o.x && y == o.y;
}

Posn Posn::operator=(const Posn &o) {
	return Posn{o.x, o.y};
}

