#include "King.h"

King::King() : Piece() {
	this->castling = false;
	this->yTower = -1;
}

King::King(short x, short y, char color) : Piece(x, y, color) {
	this->castling = false;
	this->yTower = -1;
}

bool King::moveValid(vector<Piece*> pieces, short x, short y) {
	short i, j;
	bool castling;
	castling = this->castling;
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y && pieces[i]->getColor() == this->color) return false;
	}
	if (this->failure(pieces, this->positionX, this->positionY)) return false;
	if (castling) return this->castlingCase(pieces, x, y);
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
	short i, j;
	for (i = this->positionX - 1; i <= this->positionX + 1; i++) {
		for (j = this->positionY - 1; j <= this->positionY + 1; j++) {
			if (this->moveValid(pieces, i, j)) return true;
		}
	}
	return false;
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

//Small castling
bool King::castlingCase(vector<Piece*> pieces, short x, short y) {
	short i;
	if (this->color == BLACK) {
		if (x == 0 && y == 5) {
			for (i = 0; i < pieces.size(); i++) {
				//Move the tower
				if (pieces[i]->getPositionX() == 0 && pieces[i]->getPositionY() == 7) {
					pieces[i]->setPositionY(6);
					this->yTower = 6;
					this->castling = false;
					return true;
				}
			}
		}
	}
	else if (this->color == WHITE) {
		if (x == 7 && y == 5) {
			for (i = 0; i < pieces.size(); i++) {
				//Move the tower
				if (pieces[i]->getPositionX() == 7 && pieces[i]->getPositionY() == 7) {
					pieces[i]->setPositionY(6);
					this->yTower = 6;
					this->castling = false;
					return true;
				}
			}
		}
	}
}

void King::setCastling(bool castling) {
	this->castling = castling;
}

short King::getYTower() {
	return this->yTower;
}