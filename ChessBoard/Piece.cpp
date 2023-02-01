#include "Piece.h"

Piece::Piece() {
	this->color = -1;
	this->positionX = this->positionY = 0;
}

Piece::Piece(short positionX, short positionY, char color) {
	this->positionX = positionX;
	this->positionY = positionY;
	this->color = color;
}

void Piece::eatPiece(vector<Piece*> pieces, short x, short y) {
	short i;
	for (i = 0; i < pieces.size(); i++) {
		if (pieces[i]->positionX == x && pieces[i]->positionY == y && pieces[i]->color != this->color) {
			pieces.erase(pieces.begin() + i);
		}
	}
}

char Piece::getColor() {
	return this->color;
}

short Piece::getPositionX() {
	return this->positionX;
}

short Piece::getPositionY() {
	return this->positionY;
}

void Piece::setColor(char color) {
	this->color = color;
}

void Piece::setPositionX(short positionX) {
	this->positionX = positionX;
}

void Piece::setPositionY(short positionY) {
	this->positionY = positionY;
}