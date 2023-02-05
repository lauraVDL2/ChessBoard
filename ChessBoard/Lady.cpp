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
	//Top
	for (i = 0; i < this->positionX; i++) {
		if (i == x && y == this->positionY) {
			if (this->collision(pieces, x, this->positionY, this->positionX, this->positionY)) return false;
			this->eatPiece(pieces, i, y);
			return true;
		}
	}
	//Bottom
	for (i = this->positionX + 1; i < BOARD_SIZE; i++) {
		if (i == x && y == this->positionY) {
			if (this->collision(pieces, this->positionX + 1, this->positionY, x, this->positionY)) return false;
			this->eatPiece(pieces, i, y);
			return true;
		}
	}
	//Left
	for (j = 0; j < this->positionY; j++) {
		if (x == this->positionX && j == y) {
			if (this->collision(pieces, this->positionX, y, this->positionX, this->positionY)) return false;
			this->eatPiece(pieces, x, j);
			return true;
		}
	}
	//Right
	for (j = this->positionY + 1; j < BOARD_SIZE; j++) {
		if (x == this->positionX && j == y) {
			if (this->collision(pieces, this->positionX, this->positionY + 1, this->positionX, y)) return false;
			this->eatPiece(pieces, x, j);
			return true;
		}
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

bool Lady::canMove(vector<Piece*> pieces) {
	short i, j;
	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++) {
			if (this->moveValid(pieces, i, j)) return true;
		}
	}
	return false;
}

//Check if there are not another piece between you and the destination
bool Lady::collision(vector<Piece*> pieces, short minX, short minY, short maxX, short maxY) {
	short i, j, k;
	for (i = 0; i < pieces.size(); i++) {
		if (minX == maxX && minY == maxY) {
			if (pieces[i]->getPositionX() == minX && pieces[i]->getPositionY() == minY) return true;
		}
		else if (minX == maxX) {
			for (j = minY; j < maxY; j++) {
				if (pieces[i]->getPositionX() == minX && pieces[i]->getPositionY() == j) return true;
			}
		}
		else if (minY == maxY) {
			for (j = minX; j < maxX; j++) {
				if (pieces[i]->getPositionX() == j && pieces[i]->getPositionY() == minY) return true;
			}
		}
		else {
			for (j = minX; j < maxX; j++) {
				for (k = minY; k < maxY; k++) {
					if (pieces[i]->getPositionX() == j && pieces[i]->getPositionY() == k) return true;
				}
			}
		}
	}
	return false;
}