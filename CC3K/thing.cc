#include "thing.h"
class Cell;

Thing::Thing(Cell *cell): cell{cell} {}

Posn Thing::getPosn() { return cell->getPosn(); }

Thing::~Thing() {}
