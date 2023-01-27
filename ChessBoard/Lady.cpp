#include "Lady.h"

Lady::Lady() : Piece() {
	;
}

Lady::Lady(short x, short y, char color) : Piece(x, y, color) {
	;
}

bool Lady::moveValid(short x, short y) {
	return true;
}