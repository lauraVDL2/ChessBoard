#pragma once
#include "Piece.h"
class Lady : public Piece
{
public:
	Lady();
	Lady(short, short, char);

	bool moveValid(short, short);
};

