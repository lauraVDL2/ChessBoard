#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King();
	King(short, short, char);

	bool moveValid(vector<Piece*>, short, short);
	bool canMove(vector<Piece*>);
	bool failure(vector<Piece*>, short, short);
};

