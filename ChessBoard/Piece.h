#pragma once

#define BLACK 0
#define WHITE 1

class Piece
{
protected:
	char color;
	short positionX, positionY;
public:
	Piece();
	Piece(short, short, char);
	virtual bool moveValid(short, short) = 0;

	char getColor();
	short getPositionX();
	short getPositionY();
	void setColor(char);
	void setPositionX(short);
	void setPositionY(short);
};

