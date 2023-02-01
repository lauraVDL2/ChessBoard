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
void turn(Player*);

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
    do {
        cout << "Player 1, this is your turn" << endl;
        turn(player1);
        cout << "Player 2, this is your turn" << endl;
        turn(player2);
    } while (player1->getPieces().size() != 0 && player2->getPieces().size() != 0);
    return 0;
}

void setPlayerPieces(Player * player, char color) {
    vector<Piece*> pieces;
    short i;
    pieces = board->getPieces();
    player->clearPieces();
    for (i = 0; i < pieces.size(); i++) {
        if (pieces[i]->getColor() == color) player->pushPiece(pieces[i]);
    }
}

void turn(Player* player) {
    vector<Piece*> pieces;
    short x, y, i, xMove = 0, yMove = 0, initialX, initialY;
    bool c;
    c = false;
    pieces = player->getPieces();
    do {
        cout << "Enter the coordinate (x) of your piece : ";
        cin >> x;
        cout << "Enter the coordinate (y) of your piece : ";
        cin >> y;
        for (i = 0; i < pieces.size(); i++) {
            if (pieces[i]->getPositionX() == x && pieces[i]->getPositionY() == y && pieces[i]->canMove(board->getPieces())) {
                initialX = x;
                initialY = y;
                c = true;
                break; //We need the state of i outside the loop
            }
        }
    } while (!c);
    do {
        cout << "Enter the coordinate (x) where you want to move : ";
        cin >> xMove;
        cout << "Enter the coordinate (y) where you want to move : ";
        cin >> yMove;
        setPlayerPieces(player, player->getColor());
    } while (!pieces[i]->moveValid(board->getPieces(), xMove, yMove));
    board->setBoardValue(initialX, initialY, '.'); //The old place of the piece
    //Check types
    if (typeid(*pieces[i]) == typeid(Horseman)) {
        if (player->getColor() == WHITE) board->setBoardValue(xMove, yMove, 'c');
        else board->setBoardValue(xMove, yMove, 'C');
    }
    else if (typeid(*pieces[i]) == typeid(Fool)) {
        if (player->getColor() == WHITE) board->setBoardValue(xMove, yMove, 'f');
        else board->setBoardValue(xMove, yMove, 'F');
    }
    else if (typeid(*pieces[i]) == typeid(King)) {
        if (player->getColor() == WHITE) board->setBoardValue(xMove, yMove, 'r');
        else board->setBoardValue(xMove, yMove, 'R');
    }
    else if (typeid(*pieces[i]) == typeid(Lady)) {
        if (player->getColor() == WHITE) board->setBoardValue(xMove, yMove, 'e');
        else board->setBoardValue(xMove, yMove, 'E');
    }
    else if (typeid(*pieces[i]) == typeid(Pawn)) {
        if (player->getColor() == WHITE) board->setBoardValue(xMove, yMove, 'p');
        else board->setBoardValue(xMove, yMove, 'P');
    }
    else if (typeid(*pieces[i]) == typeid(Tower)) {
        if (player->getColor() == WHITE) board->setBoardValue(xMove, yMove, 't');
        else board->setBoardValue(xMove, yMove, 'T');
    }
    pieces[i]->setPositionX(xMove);
    pieces[i]->setPositionY(yMove);
    board->display(); //Update board with the move
}