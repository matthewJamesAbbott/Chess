//
// Created by squig on 18/2/22.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <string>
#include "Board.h"
#include "NetServer.h"
#include "NetClient.h"

class Game{

private:
    std::string playerOne;
    std::string playerTwo;
    Board gameBoard;
    NetServer server;
    NetClient *client;





public:
    Game();
    void setPlayerOne(std::string name);
    void setPlayerTwo(std::string name);
    void initialiseBoard();
    bool movePiece(int xa, char ca, int xb, char cb);
    void printBoardToTerminal();
    bool startServer(int port);
    bool connectToServer(std::string ipAddress, int port);
    void receiveThread();
    int clientServerToggle;



};


#endif //CHESS_GAME_H
