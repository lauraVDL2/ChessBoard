#include "Board.h"

Board::Board() {
	this->x = this->y = 0;
}

Board::Board(short x, short y) {
	this->x = x;
	this->y = y;
}

//TODO: Replace "." with Pieces
void Board::initialization() {
	short i, j;
	for (i = 0; i < this->x; i++) {
		for (j = 0; j < this->y; j++) cout << ".";
		cout << endl;
	}
}