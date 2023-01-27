#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Board* board;
    board = new Board(8, 8);
    board->initialization();
    delete board;
}
