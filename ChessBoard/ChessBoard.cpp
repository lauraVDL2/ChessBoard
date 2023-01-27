#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include "Piece.h"

using namespace std;

int main() {
    Board* board;
    Player* player;
    string name;
    char color;
    cout << "Enter you name : ";
    cin >> name;
    ask:
    cout << "Black or white player ? (b/w) : ";
    cin >> color;
    if (color != 'b' && color != 'w') goto ask;
    if (color == 'b') {
        cout << "Welcome " << name << " you are the black player" << endl;
        player = new Player(name, BLACK);
    }
    else if (color == 'w') {
        cout << "Welcome " << name << " you are the white player" << endl;
        player = new Player(name, WHITE);
    }
    board = new Board();
    board->initialization();
}
