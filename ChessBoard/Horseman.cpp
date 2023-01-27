#include "Horseman.h"

Horseman::Horseman() : Piece() {
	;
}

Horseman::Horseman(short x, short y, char color) : Piece(x, y, color) {
	;
}

bool Horseman::moveValid(short x, short y) {
	return true;
}

bool Horseman::canMove(vector<Piece*> piece) {
	return true;
}