#include "Horseman.h"

Horseman::Horseman() : Piece() {
	;
}

Horseman::Horseman(short x, short y, char color) : Piece(x, y, color) {
	;
}

//The horseman moves in two times. It makes a "L"
bool Horseman::moveValid(vector<Piece*> pieces, short x, short y) {
	short i;
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y && pieces[i]->getColor() == this->color) return false;
	}
	//Top left
	if (x == this->positionX + 2 && y == this->positionY - 1) {
		this->eatPiece(pieces, x, y);
		return true;
	}
	else if (x == this->positionX + 1 && y == this->positionY - 2) {
		this->eatPiece(pieces, x, y);
		return true;
	}
	//Top right
	else if (x == this->positionX + 2 && y == this->positionY + 1) {
		this->eatPiece(pieces, x, y);
		return true;
	}
	else if (x == this->positionX + 1 && y == this->positionY + 2) {
		this->eatPiece(pieces, x, y);
		return true;
	}
	//Bottom left
	else if (x == this->positionX - 2 && y == this->positionY - 1) {
		this->eatPiece(pieces, x, y);
		return true;
	}
	else if (x == this->positionX - 1 && y == this->positionY - 2) {
		this->eatPiece(pieces, x, y);
		return true;
	}
	//Bottom right
	else if (x == this->positionX - 2 && y == this->positionY + 1) {
		this->eatPiece(pieces, x, y);
		return true;
	}
	else if (x == this->positionX - 1 && y == this->positionY + 2) {
		this->eatPiece(pieces, x, y);
		return true;
	}
	return false;
}

bool Horseman::canMove(vector<Piece*> pieces) {
	short i, j;
	for (i = this->positionX - 2; i < this->positionX + 2; i++) {
		for (j = this->positionY - 2; j < this->positionY + 2; j++) {
			if (this->moveValid(pieces, i, j)) return true;
		}
	}
	return false;
}