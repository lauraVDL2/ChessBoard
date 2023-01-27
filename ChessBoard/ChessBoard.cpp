#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Board* board;
    board = new Board();
    board->initialization();
    delete board;
}
