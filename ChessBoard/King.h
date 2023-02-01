#pragma once
#include "Piece.h"
class King : public Piece
{
private:
	bool castling;
	short yTower;
public:
	King();
	King(short, short, char);

	bool moveValid(vector<Piece*>, short, short);
	bool canMove(vector<Piece*>);
	bool failure(vector<Piece*>, short, short);
	bool castlingCase(vector<Piece*>, short, short);

	void setCastling(bool);
	short getYTower();
};

