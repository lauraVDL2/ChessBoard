#pragma once
#include "Piece.h"
class Horseman : public Piece
{
public:
	Horseman();
	Horseman(short, short, char);

	bool moveValid(vector<Piece*>, short, short);
	bool canMove(vector<Piece*>);
};

