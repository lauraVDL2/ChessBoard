#include "Fool.h"

Fool::Fool() : Piece() {
	;
}

Fool::Fool(short x, short y, char color) : Piece(x, y, color) {
	;
}

bool Fool::moveValid(vector<Piece*> pieces, short x, short y) {
	short i, j;
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y && pieces[i]->getColor() == this->color) return false;
	}
	//Bottom left
	for (i = this->positionX - 1, j = this->positionY - 1; i >= 0 && j >= 0; i--, j--) {
		if (x == i && y == j) {
			if (this->collision(pieces, i + 1, j + 1)) return false;
			this->eatPiece(pieces, i, j);
			return true;
		}
	}
	//Bottom right
	for (i = this->positionX - 1, j = this->positionY + 1; i >= 0 && j < BOARD_SIZE; i--, j++) {
		if (x == i && y == j) {
			if (this->collision(pieces, i + 1, j - 1)) return false;
			this->eatPiece(pieces, i, j);
			return true;
		}
	}
	//Top left
	for (i = this->positionX + 1, j = this->positionY - 1; i < BOARD_SIZE && j >= 0; i++, j--) { 
		if (i == x && j == y) {
			if (this->collision(pieces, i - 1, j + 1)) return false;
			this->eatPiece(pieces, i, j);
			return true;
		}
	}
	//Top right
	for (i = this->positionX + 1, j = this->positionY + 1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
		if (i == x && j == y) {
			if (this->collision(pieces, i - 1, j - 1)) return false;
			this->eatPiece(pieces, i, j);
			return true;
		}
	}
	return false;
}

bool Fool::canMove(vector<Piece*> pieces) {
	return true;
}

//Check if there not another piece between you and the destination
bool Fool::collision(vector<Piece*> pieces, short x, short y) {
	short i, j;
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y) return true;
	}
	return false;
}