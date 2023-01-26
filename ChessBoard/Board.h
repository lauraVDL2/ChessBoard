#pragma once
#include <iostream>
#include "Piece.h"
#include "Fool.h"
#include "Horseman.h"
#

using namespace std;

class Board
{
private:
	short x, y;

public:
	Board();
	Board(short, short);

	void initialization();
};

