#include "Fool.h"

Fool::Fool() : Piece() {
	;
}

Fool::Fool(short x, short y, char color) : Piece(x, y, color) {
	;
}

bool Fool::moveValid(short x, short y) {
	return true;
}

bool Fool::canMove(vector<Piece*> pieces) {
	return true;
}