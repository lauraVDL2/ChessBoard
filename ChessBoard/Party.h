#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "AllDefines.h"

using namespace std;

class Party
{
private:
	Board* board;
	Player* currentPlayer;
public:
	Party(Board*, Player*);
	
	Player* getPlayer();
	void setPlayer(Player*);

	bool castling();
};

