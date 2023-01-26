#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Board* board;
    board = new Board(7, 7);
    board->initialization();
    delete board;
}
