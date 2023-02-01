#include "Board.h"

Board::Board() {
	this->x = this->y = 8;
}

void Board::display() {
	short i, j;
	for (i = 0; i < this->x; i++) {
		for (j = 0; j < this->y; j++) cout << this->board[i][j] << " ";
		cout << endl;
	}
}

void Board::initialization() {
	short i, j;
	for (i = 0; i < this->x; i++) {
		for (j = 0; j < this->y; j++) {
			//Pawns
			if (i == 1) {
				this->pieces.push_back(new Pawn(i, j, BLACK));
				this->board[i][j] = 'P';
			}
			else if (i == 6) {
				this->pieces.push_back(new Pawn(i, j, WHITE));
				this->board[i][j] = 'p';
			}
			//Towers
			else if ((i == 0 && j == 0) || (i == 0 && j == 7)) {
				this->pieces.push_back(new Tower(i, j, BLACK));
				this->board[i][j] = 'T';
			}
			else if ((i == 7 && j == 0) || (i == 7 && j == 7)) {
				this->pieces.push_back(new Tower(i, j, WHITE));
				this->board[i][j] = 't';
			}
			//Horsemen
			else if ((i == 0 && j == 1) || (i == 0 && j == 6)) {
				this->pieces.push_back(new Horseman(i, j, BLACK));
				this->board[i][j] = 'C';
			}
			else if ((i == 7 && j == 1) || (i == 7 && j == 6)) {
				this->pieces.push_back(new Horseman(i, j, WHITE));
				this->board[i][j] = 'c';
			}
			//Fools
			else if ((i == 0 && j == 2) || (i == 0 && j == 5)) {
				this->pieces.push_back(new Fool(i, j, BLACK));
				this->board[i][j] = 'F';
			}
			else if ((i == 7 && j == 2) || (i == 7 && j == 5)) {
				this->pieces.push_back(new Fool(i, j, WHITE));
				this->board[i][j] = 'f';
			}
			//Kings
			else if (i == 0 && j == 3) {
				this->pieces.push_back(new King(i, j, BLACK));
				this->board[i][j] = 'R';
			}
			else if (i == 7 && j == 3) {
				this->pieces.push_back(new King(i, j, WHITE));
				this->board[i][j] = 'r';
			}
			//Queens
			else if (i == 0 && j == 4) {
				this->pieces.push_back(new Lady(i, j, BLACK));
				this->board[i][j] = 'E';
			}
			else if (i == 7 && j == 4) {
				this->pieces.push_back(new Lady(i, j, WHITE));
				this->board[i][j] = 'e';
			}
			else this->board[i][j] = '.';
		}
	}
	this->display();
}

char Board::checkmate() {
	King* wKing = nullptr, * bKing = nullptr;
	short i, j, k, x, y;
	//Get the kings
	for (i = 0; i < this->pieces.size(); i++) {
		if (typeid(*this->pieces[i]) == typeid(King)) {
			if (((King*)this->pieces[i])->getColor() == WHITE) wKing = (King*)this->pieces[i];
			else bKing = (King*)this->pieces[i];
		}
	}
	for (i = 0; i < this->pieces.size(); i++) {
		if (this->pieces[i]->getColor() == WHITE) {
			if(this->checkKing(bKing, i)) return B_WON;
		}
		else if (this->pieces[i]->getColor() == BLACK) {
			if (this->checkKing(wKing, i)) return W_WON;
		}
	}
	return 0;
}

bool Board::checkKing(King* king, short k) {
	short i, j, x, y, xMax, xMin, yMax, yMin;
	bool fail = true;
	x = king->getPositionX();
	y = king->getPositionY();
	xMax = min(x + 1, BOARD_SIZE);
	xMin = max(x - 1, 0);
	yMax = min(y + 1, BOARD_SIZE);
	yMin = max(y - 1, 0);
	//cout << "xMin = " << xMin << " xMax = " << xMax << " yMin = " << yMin << " yMax = " << yMax << endl;
	for (i = xMin; i < xMax; i++) {
		for (j = yMin; j < yMax; j++) {
			if (!this->pieces[k]->moveValid(this->pieces, i, j)) {
				//cout << "ok 2";
				fail = false;
			}
			//else cout << "OK 1" << endl;
		}
	}
	return fail;
}

vector<Piece*> Board::getPieces() {
	return this->pieces;
}

void Board::setBoardValue(short x, short y, char value) {
	this->board[x][y] = value;
}