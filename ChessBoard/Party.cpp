#include "Party.h"

Party::Party(Board* board, Player * player) {
	this->board = board;
	this->currentPlayer = player;
}

Player* Party::getPlayer() {
	return this->currentPlayer;
}

void Party::setPlayer(Player* player) {
	this->currentPlayer = player;
}

bool Party::castling() {
	King* king = nullptr;
	Tower* tower = nullptr;
	vector<Piece*> pieces, allPieces;
	short i, x = 0;
	pieces = this->currentPlayer->getPieces();
	allPieces = this->board->getPieces();
	//Check Tower and King Positions
	for (i = 0; i < pieces.size(); i++) {
		if (this->currentPlayer->getColor() == BLACK) {
			if (typeid(*pieces[i]) == typeid(King)) {
				if (pieces[i]->getPositionX() == 0 && pieces[i]->getPositionY() == 3) {
					x = 0;
					king = (King*)pieces[i];
				}
			}
			if (typeid(*pieces[i]) == typeid(Tower)) {
				if (pieces[i]->getPositionX() == 0 && pieces[i]->getPositionY() == 7) tower = (Tower*)pieces[i];
			}
		}
		else if (this->currentPlayer->getColor() == WHITE) {
			if (typeid(*pieces[i]) == typeid(King)) {
				if (pieces[i]->getPositionX() == 7 && pieces[i]->getPositionY() == 3) {
					x = 7;
					king = (King*)pieces[i];
				}
			}

			if (typeid(*pieces[i]) == typeid(Tower)) {
				if (pieces[i]->getPositionX() == 7 && pieces[i]->getPositionY() == 7) tower = (Tower*)pieces[i];
			}
		}
	}
	if (king == nullptr || tower == nullptr) return false;
	//Check is there are not pieces between them
	for (i = 0; i < allPieces.size(); i++) {
		if (allPieces[i]->getPositionX() == x && allPieces[i]->getPositionY() == 4) return false;
		if (allPieces[i]->getPositionX() == x && allPieces[i]->getPositionY() == 5) return false;
		if (allPieces[i]->getPositionX() == x && allPieces[i]->getPositionY() == 6) return false;
	}
	//Set the castling variable in pieces
	for (i = 0; i < pieces.size(); i++) {
		if (this->currentPlayer->getColor() == BLACK) {
			if (typeid(*pieces[i]) == typeid(King)) {
				if (pieces[i]->getPositionX() == 0 && pieces[i]->getPositionY() == 3) ((King*)pieces[i])->setCastling(true);
			}
			if (typeid(*pieces[i]) == typeid(Tower)) {
				if (pieces[i]->getPositionX() == 0 && pieces[i]->getPositionY() == 7) ((Tower*)pieces[i])->setCastling(true);
			}
		}
		else if (this->currentPlayer->getColor() == WHITE) {
			if (typeid(*pieces[i]) == typeid(King)) {
				if (pieces[i]->getPositionX() == 7 && pieces[i]->getPositionY() == 3) ((King*)pieces[i])->setCastling(true);
			}

			if (typeid(*pieces[i]) == typeid(Tower)) {
				if (pieces[i]->getPositionX() == 7 && pieces[i]->getPositionY() == 7) ((Tower*)pieces[i])->setCastling(true);
			}
		}
	}
	return true;
}