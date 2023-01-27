#include "Pawn.h"

Pawn::Pawn() : Piece() {
	;
}

Pawn::Pawn(short positionX, short positionY, char color) : Piece(positionX, positionY, color) {
	;
}

bool Pawn::moveValid(vector<Piece*> pieces, short x, short y) {
	return true;
}

bool Pawn::canMove(vector<Piece*> piece) {
	return true;
}