#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King();
	King(short, short, char);

	bool moveValid(short, short);
	bool canMove(vector<Piece*>);
};

