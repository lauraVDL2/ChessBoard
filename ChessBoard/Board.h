#pragma once
#include <iostream>
#include <vector>
#include "Piece.h"
#include "Fool.h"
#include "Horseman.h"
#include "King.h"
#include "Lady.h"
#include "Pawn.h"
#include "Tower.h"

using namespace std;

class Board
{
private:
	short x, y;
	vector<Pawn*> pawns;
	char ** board;
public:
	Board();
	Board(short, short);
	~Board();
	
	void display();
	void initialization();
};

