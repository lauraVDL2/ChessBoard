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

void Player::setName(string name) {
	this->name = name;
}

void Player::setColor(char color) {
	this->color = color;
}