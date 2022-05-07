//
// Created by Matthew Abbott on 18/2/22.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <string>
#include "Board.h"
#include "MoveRecorder.h"
#include "Engine.h"
#include "MoveCalculator.h"

class Game{

public:
    Game();

    /**
     * Set players name
     *
     * @param name <std::string>
     */
    void setPlayerOne(std::string name);

    /**
     * Set Network players name
     *
     * @param name <std::string>
     */
    void setPlayerTwo(std::string name);

    /**
     * Insert String representations of pieces and empty squares into board array
     */
    void initialiseBoard();

    bool recallMove();

    void loadGame(std::string fileName);

    /**
     * Move piece on the board
     *
     * @param xa Vertical or Numeric value for original location of piece on board <int>
     * @param ca Horizontal or Alpha value for original location of piece on board <char>
     * @param xb Vertical or Numeric value for destination of piece on board <int>
     * @param cb Horizontal of Alpha value for destination of piece on board <char>
     * @return   Boolean return value true on successful move false on error <bool>
     */
    bool movePiece(int xa, char ca, int xb, char cb);

    /**
     * Calculate Computers Move
     */
    bool engineMove();

    /**
     * Print unicode representation of board and pieces to terminal
     */
    void printBoardToTerminal();

    int clientServerToggle{};

private:
    MoveRecorder rec;
    MoveCalculator calc;
    std::string playerOne;
    std::string playerTwo;
    Board gameBoard;
    Engine *moveEngine = new Engine();

};


#endif //CHESS_GAME_H
