#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "Piece.h"

using namespace std;

Board* board;
Player* player1, * player2;

void setPlayerPieces(Player *, char);

int main() {
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
        player1 = new Player(name, BLACK);
        cout << "Player 2, enter your name : ";
        cin >> name;
        player2 = new Player(name, WHITE);
        cout << "Welcome " << name << " you are the white player" << endl;
    }
    else if (color == 'w') {
        cout << "Welcome " << name << " you are the white player" << endl;
        player1 = new Player(name, WHITE);
        cout << "Player 2, enter your name : ";
        cin >> name;
        player2 = new Player(name, BLACK);
        cout << "Welcome " << name << " you are the black player" << endl;
    }
    board = new Board();
    board->initialization();
    setPlayerPieces(player1, (color == 'b') ? BLACK : WHITE);
    setPlayerPieces(player2, (color == 'b') ? WHITE : BLACK);
}

void setPlayerPieces(Player * player, char color) {
    vector<Piece*> pieces;
    short i;
    pieces = board->getPieces();
    for (i = 0; i < pieces.size(); i++) {
        if (pieces[i]->getColor() == color) player->pushPiece(pieces[i]);
    }
}