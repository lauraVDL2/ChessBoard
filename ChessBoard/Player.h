#pragma once
#include <string>

using namespace std;

class Player
{
private:
	string name;
	char color;

public:
	Player();
	Player(string, char);

	string getName();
	char getColor();
	void setName(string);
	void setColor(char);
};

