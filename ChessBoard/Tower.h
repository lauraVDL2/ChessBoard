#pragma once
#include "Piece.h"
class Tower : public Piece
{
public:
	Tower();
	Tower(short, short, char);
	bool moveValid(short, short);
};

