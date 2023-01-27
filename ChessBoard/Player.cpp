#include "Player.h"

Player::Player() {
	this->color = 0;
	this->name = "";
}

Player::Player(string name, char color) {
	this->name = name;
	this->color = color;
}

string Player::getName() {
	return this->name;
}

char Player::getColor() {
	return this->color;
}

vector<Piece*> Player::getPieces() {
	return this->pieces;
}

void Player::setName(string name) {
	this->name = name;
}

void Player::setColor(char color) {
	this->color = color;
}

void Player::setPieces(vector<Piece*> pieces) {
	this->pieces = pieces;
}

void Player::pushPiece(Piece* piece) {
	this->pieces.push_back(piece);
}