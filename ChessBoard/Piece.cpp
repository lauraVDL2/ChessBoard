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