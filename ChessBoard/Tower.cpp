#include "Tower.h"

Tower::Tower() : Piece() {
	;
}

Tower::Tower(short x, short y, char color) : Piece(x, y, color) {
	;
}

bool Tower::moveValid(vector<Piece*> pieces, short x, short y) {
	short i, j;
	//Check if there not a piece where we want to move
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y && pieces[i]->getColor() == this->color) return false;
	}
	//Left
	for (i = 0; i < this->positionX; i++) if (i == x && y == this->positionY) return true;
	//Right
	for (i = this->positionX + 1; i < BOARD_SIZE; i++) if (i == x && y == this->positionY) return true;
	//Bottom
	for (j = 0; j < this->positionY; j++) if (x == this->positionX && j == y) return true;
	//Top
	for (j = this->positionY + 1; j < BOARD_SIZE; j++) if (x == this->positionX && j == y) return true;
	return false;
}

bool Tower::canMove(vector<Piece*> pieces) {
	return true;
}