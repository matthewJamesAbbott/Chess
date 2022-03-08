//
// Created by Matthew Abbott on 18/2/22.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <string>
#include "Board.h"

class Game{

private:
    std::string playerOne;
    std::string playerTwo;
    Board gameBoard;

public:
    Game();
    void setPlayerOne(std::string name);
    void setPlayerTwo(std::string name);
    void initialiseBoard();
    bool movePiece(int xa, char ca, int xb, char cb);
    void printBoardToTerminal();
    int clientServerToggle;
};


#endif //CHESS_GAME_H
