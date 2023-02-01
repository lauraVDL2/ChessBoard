#pragma once
#include "Piece.h"
class Tower : public Piece
{
private:
	bool castling;
	short yKing;
public:
	Tower();
	Tower(short, short, char);

	bool moveValid(vector<Piece*>, short, short);
	bool canMove(vector<Piece*>);
	bool castlingCase(vector<Piece*>, short, short);
	bool collision(vector<Piece*>, short, short);

	void setCastling(bool);
	short getYKing();
};

