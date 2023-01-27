#include "Pawn.h"

Pawn::Pawn() : Piece() {
	;
}

Pawn::Pawn(short positionX, short positionY, char color) : Piece(positionX, positionY, color) {
	;
}

bool Pawn::moveValid(short x, short y) {
	return true;
}