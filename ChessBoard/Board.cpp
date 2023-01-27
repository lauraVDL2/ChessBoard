#include "Board.h"

Board::Board() {
	this->x = this->y = 0;
	this->board = nullptr;
}

Board::Board(short x, short y) {
	short i;
	this->x = x;
	this->y = y;
	this->board = (char **)malloc(sizeof(char*) * x);
	for (i = 0; i < x; i++) this->board[i] = (char*)malloc(y);
}

Board::~Board() {
	short i;
	free(this->board);
	//for (i = 0; i < this->x; i++) free(this->board[i]);
}

void Board::display() {
	short i, j;
	for (i = 0; i < this->x; i++) {
		for (j = 0; j < this->y; j++) cout << this->board[i][j];
		cout << endl;
	}
}

void Board::initialization() {
	short i, j;
	for (i = 0; i < this->x; i++) {
		for (j = 0; j < this->y; j++) {
			if (i == 1) {
				this->pawns.push_back(new Pawn(i, j, BLACK));
				this->board[i][j] = 'P';
			}
			else if (i == 6) {
				this->pawns.push_back(new Pawn(i, j, WHITE));
				this->board[i][j] = 'p';
			}
			else this->board[i][j] = '.';
		}
	}
	this->display();
}

