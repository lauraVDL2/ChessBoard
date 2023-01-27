#pragma once
#include <string>
#include <vector>
#include "Piece.h"

using namespace std;

class Player
{
private:
	string name;
	char color;
	vector<Piece *> pieces;
	
public:
	Player();
	Player(string, char);

	string getName();
	char getColor();
	vector<Piece*> getPieces();

	void setName(string);
	void setColor(char);
	void setPieces(vector<Piece*>);

	void pushPiece(Piece *);
};

