#pragma once
#include <iostream>

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

