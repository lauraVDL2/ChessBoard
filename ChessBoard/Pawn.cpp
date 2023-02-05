#include "Pawn.h"

Pawn::Pawn() : Piece() {
	;
}

Pawn::Pawn(short positionX, short positionY, char color) : Piece(positionX, positionY, color) {
	;
}

bool Pawn::moveValid(vector<Piece*> pieces, short x, short y) {
	short i, j;
	//Check if there not a piece where we want to move
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y && pieces[i]->getColor() == this->color) return false;
	}
	//Black player
	if (this->color == BLACK) {
		for (i = this->positionX + 1; i < this->positionX + 3; i++) {
			if (i == x && y == this->positionY) {
				this->eatPiece(pieces, i, y);
				return true;
			}
		}
	}
	//White player
	else if (this->color == WHITE) {
		for (i = this->positionX - 1; i > this->positionX - 3; i--) {
			if (i == x && y == this->positionY) {
				this->eatPiece(pieces, i, y);
				return true;
			}
		}
	}
	return false;
}

bool Pawn::canMove(vector<Piece*> pieces) {
	short i;
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getColor() == this->color) {
			if (this->color == BLACK) {
				if (pieces[i]->getPositionX() == this->positionX + 1 && pieces[i]->getPositionY() == this->positionY) return false;
				else if (this->positionX == 7) return false;
			}
			else {
				if (pieces[i]->getPositionX() == this->positionX - 1 && pieces[i]->getPositionY() == this->positionY) return false;
				else if (this->positionX == 0) return false;
			}
		}
	}
	return true;
}