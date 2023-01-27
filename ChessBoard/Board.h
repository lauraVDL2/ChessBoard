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

#define BOARD_SIZE 8

using namespace std;

class Board
{
private:
	short x, y;
	vector<Piece*> pieces;
	char board[BOARD_SIZE][BOARD_SIZE];
public:
	Board();
	
	void display();
	void initialization();
};

