#pragma once
#include <iostream>
#include <vector>
#include "AllDefines.h"

using namespace std;

class Piece
{
protected:
	char color;
	short positionX, positionY;
public:
	Piece();
	Piece(short, short, char);

	virtual bool moveValid(vector<Piece *>, short, short) = 0;
	//See if not surrounded
	virtual bool canMove(vector<Piece *>) = 0;

	char getColor();
	short getPositionX();
	short getPositionY();
	void setColor(char);
	void setPositionX(short);
	void setPositionY(short);
};

