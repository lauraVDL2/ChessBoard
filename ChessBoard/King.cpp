#include "King.h"

King::King() : Piece() {
	;
}

King::King(short x, short y, char color) : Piece(x, y, color) {
	;
}

bool King::moveValid(short x, short y) {
	return true;
}

bool King::canMove(vector<Piece*> pieces) {
	return true;
}