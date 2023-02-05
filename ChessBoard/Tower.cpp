#include "Tower.h"

Tower::Tower() : Piece() {
	this->castling = false;
	this->yKing = -1;
}

Tower::Tower(short x, short y, char color) : Piece(x, y, color) {
	this->castling = false;
	this->yKing = -1;
}

bool Tower::moveValid(vector<Piece*> pieces, short x, short y) {
	short i, j;
	bool castling, result = false;
	castling = this->castling;
	//Check if there's not a piece of our own color where we want to move
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y && pieces[i]->getColor() == this->color) return false;
	}
	if (castling) return this->castlingCase(pieces, x, y);
	//Top
	for (i = 0; i < this->positionX; i++) {
		if (i == x && y == this->positionY) {
			if (this->collision(pieces, x, this->positionY, this->positionX, this->positionY)) return false;
			this->eatPiece(pieces, i, y);
			result = true;
		}
	}
	//Bottom
	for (i = this->positionX + 1; i < BOARD_SIZE; i++) {
		if (i == x && y == this->positionY) {
			if (this->collision(pieces, this->positionX + 1, this->positionY, x, this->positionY)) return false;
			this->eatPiece(pieces, i, y);
			result = true;
		}
	}
	//Left
	for (j = 0; j < this->positionY; j++) {
		if (x == this->positionX && j == y) {
			if (this->collision(pieces, this->positionX, y, this->positionX, this->positionY)) return false;
			this->eatPiece(pieces, x, j);
			result = true;
		}
	}
	//Right
	for (j = this->positionY + 1; j < BOARD_SIZE; j++) {
		if (x == this->positionX && j == y) {
			if (this->collision(pieces, this->positionX, this->positionY + 1, this->positionX, y)) return false;
			this->eatPiece(pieces, x, j);
			result = true;
		}
	}
	return result;
}

bool Tower::canMove(vector<Piece*> pieces) {
	short i;
	for (i = 0; i < BOARD_SIZE; i++) {
		if (this->moveValid(pieces, i, this->positionY)) return true;
	}
	for (i = 0; i < BOARD_SIZE; i++) {
		if (this->moveValid(pieces, this->positionX, i)) return true;
	}
	return false;
}

void Tower::setCastling(bool castling) {
	this->castling = castling;
}

short Tower::getYKing() {
	return this->yKing;
}

//Big castling
bool Tower::castlingCase(vector<Piece*> pieces, short x, short y) {
	short i;
	if (this->color == BLACK) {
		if (x == 0 && y == 4) {
			for (i = 0; i < pieces.size(); i++) {
				//Move the king
				if (pieces[i]->getPositionX() == 0 && pieces[i]->getPositionY() == 7) {
					pieces[i]->setPositionY(5);
					this->yKing = 5;
					this->castling = false;
					return true;
				}
			}
		}
	}
	else if (this->color == WHITE) {
		if (x == 7 && y == 4) {
			for (i = 0; i < pieces.size(); i++) {
				//Move the king
				if (pieces[i]->getPositionX() == 7 && pieces[i]->getPositionY() == 7) {
					pieces[i]->setPositionY(5);
					this->yKing = 5;
					this->castling = false;
					return true;
				}
			}
		}
	}
}

//Check if there not another piece between you and the destination
bool Tower::collision(vector<Piece*> pieces, short minX, short minY, short maxX, short maxY) {
	short i, j;
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
	}
	return false;
}