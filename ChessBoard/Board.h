#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Piece.h"
#include "Fool.h"
#include "Horseman.h"
#include "King.h"
#include "Lady.h"
#include "Pawn.h"
#include "Tower.h"
#include "AllDefines.h"

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
	char checkmate();
	bool checkKing(King*, short);

	vector<Piece*> getPieces();

	void setBoardValue(short, short, char);
};

