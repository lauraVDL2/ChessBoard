#include "Lady.h"

Lady::Lady() : Piece() {
	;
}

Lady::Lady(short x, short y, char color) : Piece(x, y, color) {
	;
}

bool Lady::moveValid(vector<Piece*> pieces, short x, short y) {
	short i, j;
	//Check if there not a piece where we want to move
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y) return false;
	}
	//Left
	for (i = 0; i < this->positionX; i++) if (i == x && y == this->positionY) return true;
	//Right
	for (i = this->positionX + 1; i < BOARD_SIZE; i++) if (i == x && y == this->positionY) return true;
	//Bottom
	for (j = 0; j < this->positionY; j++) if (x == this->positionX && j == y) return true;
	//Top
	for (j = this->positionY + 1; j < BOARD_SIZE; j++) if (x == this->positionX && j == y) return true;



	//-----
	for (i = this->positionX - 1, j = this->positionY - 1; i >= 0 && j >= 0; i--, j--) if (x == i && y == j) return true;
	//Bottom right
	for (i = this->positionX - 1, j = this->positionY + 1; i >= 0 && j < BOARD_SIZE; i--, j++) if (x == i && y == j) return true;
	//Top left
	for (i = this->positionX + 1, j = this->positionY - 1; i < BOARD_SIZE && j >= 0; i++, j--) if (i == x && j == y) return true;
	//Top right
	for (i = this->positionX + 1, j = this->positionY + 1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) if (i == x && j == y) return true;


	return false;
}



bool Lady::canMove(vector<Piece*> pieces) {
	return true;
}