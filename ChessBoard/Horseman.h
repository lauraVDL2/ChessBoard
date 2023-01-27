#pragma once
#include "Piece.h"
class Horseman : public Piece
{
public:
	Horseman();
	Horseman(short, short, char);

	bool moveValid(short, short);
	bool canMove(vector<Piece*>);
};

