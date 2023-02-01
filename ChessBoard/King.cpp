#include "King.h"

King::King() : Piece() {
	;
}

King::King(short x, short y, char color) : Piece(x, y, color) {
	;
}

bool King::moveValid(vector<Piece*> pieces, short x, short y) {
	short i, j;
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y && pieces[i]->getColor() == this->color) return false;
	}
	if (this->failure(pieces, this->positionX, this->positionY)) return false;
	for (i = x - 1; i <= x + 1; i++) {
		for (j = y - 1; j <= y + 1; j++) {
			if (this->positionX == x && this->positionY == y) return false;
			if (this->positionX == i && this->positionY == j) {
				this->eatPiece(pieces, i, j);
				return true;
			}
		}
	}
	return false;
}

bool King::canMove(vector<Piece*> pieces) {
	return true;
}

bool King::failure(vector<Piece*> pieces, short x, short y) {
	short i,j,k;
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getColor() != this->color) {
			short positionX = pieces[i]->getPositionX();
			short positionY = pieces[i]->getPositionY();
			for (j = x - 1; j <= x + 1; j++) {
				for (k = y - 1; k <= y + 1; k++) {
					if (positionX == j && positionY == k) return true;
				}
			}
		}
	}
	return false;
}