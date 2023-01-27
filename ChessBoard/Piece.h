#pragma once
#include <vector>

#define BLACK 0
#define WHITE 1

using namespace std;

class Piece
{
protected:
	char color;
	short positionX, positionY;
public:
	Piece();
	Piece(short, short, char);

	virtual bool moveValid(short, short) = 0;
	virtual bool canMove(vector<Piece *>) = 0;

	char getColor();
	short getPositionX();
	short getPositionY();
	void setColor(char);
	void setPositionX(short);
	void setPositionY(short);
};

