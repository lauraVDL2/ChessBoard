#pragma once
#include "Piece.h"

class Fool : public Piece
{
public:
	Fool();
	Fool(short, short, char);

	bool moveValid(vector<Piece*>, short, short);
	bool canMove(vector<Piece*>);
};

