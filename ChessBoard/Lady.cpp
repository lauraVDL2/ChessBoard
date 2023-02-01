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
		if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y && pieces[i]->getColor() == this->color) return false;
	}
	//Left
	for (i = 0; i < this->positionX; i++) {
		if (i == x && y == this->positionY) {
			if (this->collision(pieces, i + 1, y)) return false;
			this->eatPiece(pieces, i, y);
			return true;
		}
	}
	//Right
	for (i = this->positionX + 1; i < BOARD_SIZE; i++) {
		if (i == x && y == this->positionY) {
			if (this->collision(pieces, i - 1, y)) return false;
			this->eatPiece(pieces, i, y);
			return true;
		}
	}
	//Bottom
	for (j = 0; j < this->positionY; j++) {
		if (x == this->positionX && j == y) {
			if (this->collision(pieces, x, j + 1)) return false;
			this->eatPiece(pieces, x, j);
			return true;
		}
	}
	//Top
	for (j = this->positionY + 1; j < BOARD_SIZE; j++) {
		if (x == this->positionX && j == y) {
			if (this->collision(pieces, x, j - 1)) return false;
			this->eatPiece(pieces, x, j);
			return true;
		}
	}
	//Bottom left
	for (i = this->positionX - 1, j = this->positionY - 1; i >= 0 && j >= 0; i--, j--) {
		if (x == i && y == j) {
			if (this->collision(pieces, i + 1 , j + 1)) return false;
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

bool Lady::canMove(vector<Piece*> pieces) {
	return true;
}

//Check if there not another piece between you and the destination
bool Lady::collision(vector<Piece*> pieces, short x, short y) {
	short i, j;
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y) return true;
	}
	return false;
}