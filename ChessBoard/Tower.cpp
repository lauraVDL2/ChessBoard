#include "Tower.h"

Tower::Tower() : Piece() {
	;
}

Tower::Tower(short x, short y, char color) : Piece(x, y, color) {
	;
}

bool Tower::moveValid(short x, short y) {
	return true;
}

bool Tower::canMove(vector<Piece*> pieces) {
	return true;
}