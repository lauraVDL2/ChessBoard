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
	bool castling;
	castling = this->castling;
	//Check if there's not a piece of our own color where we want to move
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y && pieces[i]->getColor() == this->color) return false;
	}
	if (castling) return this->castlingCase(pieces, x, y);
	//Left
	for (i = 0; i < this->positionX; i++) {
		if (i == x && y == this->positionY) {
			this->eatPiece(pieces, i, y);
			return true;
		}
	}
	//Right
	for (i = this->positionX + 1; i < BOARD_SIZE; i++) {
		if (i == x && y == this->positionY) {
			this->eatPiece(pieces, i, y);
			return true;
		}
	}
	//Bottom
	for (j = 0; j < this->positionY; j++) {
		if (x == this->positionX && j == y) {
			this->eatPiece(pieces, x, j);
			return true;
		}
	}
	//Top
	for (j = this->positionY + 1; j < BOARD_SIZE; j++) {
		if (x == this->positionX && j == y) {
			this->eatPiece(pieces, x, j);
			return true;
		}
	}
	return false;
}

bool Tower::canMove(vector<Piece*> pieces) {
	return true;
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