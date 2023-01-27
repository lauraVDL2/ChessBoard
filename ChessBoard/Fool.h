#pragma once
#include "Piece.h"
class Fool : public Piece
{
public:
	Fool();
	Fool(short, short, char);
	bool moveValid(short, short);
};

