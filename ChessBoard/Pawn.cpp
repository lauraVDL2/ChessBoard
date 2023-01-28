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
		for (i = this->positionX + 1; i < this->positionX + 3; i++) if (i == x && y == this->positionY) return true;
	}
	//White player
	else if (this->color == WHITE) {
		for (i = this->positionX - 1; i > this->positionX - 3; i--) if (i == x && y == this->positionY) return true;
	}
	return false;
}

bool Pawn::canMove(vector<Piece*> piece) {
	return true;
}