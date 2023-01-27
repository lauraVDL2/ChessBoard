#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn();
	Pawn(short, short, char);

	bool moveValid(vector<Piece*>, short, short);
	bool canMove(vector<Piece*>);
};

