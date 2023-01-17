#include "cell.h"
#include "posn.h"

Cell::Cell(int x, int y, char type): x{x}, y{y}, type{type}, thing{nullptr} {}

Posn Cell::getPosn() { return Posn{x, y}; }

void Cell::setType(char t) { type = t; }

Cell::~Cell() {}

char Cell::getType() { return type; }
