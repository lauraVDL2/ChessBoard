#include "Lady.h"

Lady::Lady() : Piece() {
	;
}

Lady::Lady(short x, short y, char color) : Piece(x, y, color) {
	;
}

bool Lady::moveValid(vector<Piece*> pieces, short x, short y) {
	return true;
}

bool Lady::canMove(vector<Piece*> pieces) {
	return true;
}