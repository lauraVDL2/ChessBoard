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
			if (this->collision(pieces, 0, 0, x, y)) return false;
			this->eatPiece(pieces, i, j);
			return true;
		}
	}
	//Bottom right
	for (i = this->positionX - 1, j = this->positionY + 1; i >= 0 && j < BOARD_SIZE; i--, j++) {
		if (x == i && y == j) {
			if (this->collision(pieces, 0, this->positionY + 1, x, y)) return false;
			this->eatPiece(pieces, i, j);
			return true;
		}
	}
	//Top left
	for (i = this->positionX + 1, j = this->positionY - 1; i < BOARD_SIZE && j >= 0; i++, j--) { 
		if (i == x && j == y) {
			if (this->collision(pieces, this->positionX + 1, 0, x, y)) return false;
			this->eatPiece(pieces, i, j);
			return true;
		}
	}
	//Top right
	for (i = this->positionX + 1, j = this->positionY + 1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
		if (i == x && j == y) {
			if (this->collision(pieces, this->positionX + 1, this->positionY + 1, x, y)) return false;
			this->eatPiece(pieces, i, j);
			return true;
		}
	}
	return false;
}

bool Fool::canMove(vector<Piece*> pieces) {
	short i, j;
	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++) {
			if (this->moveValid(pieces, i, j)) return true;
		}
	}
	return false;
}

//Check if there not another piece between you and the destination
bool Fool::collision(vector<Piece*> pieces, short minX, short minY, short maxX, short maxY) {
	short i, j, k;
	for (i = 0; i < pieces.size(); i++) {
		for (j = minX; j < maxX; j++) {
			for (k = minY; k < maxY; k++) {
				if (pieces[i]->getPositionX() == j && pieces[i]->getPositionY() == k) return true;
			}
		}
	}
	return false;
}