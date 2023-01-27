#pragma once
#include "Piece.h"
class Lady : public Piece
{
public:
	Lady();
	Lady(short, short, char);

	bool moveValid(vector<Piece*>, short, short);
	bool canMove(vector<Piece*>);
};

