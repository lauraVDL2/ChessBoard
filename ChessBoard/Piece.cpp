#include "Piece.h"

Piece::Piece() {
	this->color = -1;
	this->positionX = this->positionY = 0;
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