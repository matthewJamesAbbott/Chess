//
// Created by Matthew Abbott on 18/2/22.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <string>
#include "Board.h"
#include "MoveRecorder.h"
#include "Engine.h"
#include "Print.h"
#include "MoveCalculator.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
class Game: public Print{

public:

    int playerSide = 0;

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

    void initialiseBoardReverse();

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
/*    void printBoardToTerminal();

    void printBoardToWindow();

    void printOptionsToWindow();

    void initSDL();

    void destroySDL();

*/
    int clientServerToggle{};

    int guiOptionToggle{};

    char* serverPort = "9008";

    std::string clientIP;

    int clientPort{};

    Board gameBoard;
private:
    MoveRecorder rec;
    MoveCalculator calc;
    std::string playerOne;
    std::string playerTwo;
    Engine *moveEngine = new Engine();
};

struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;

#endif //CHESS_GAME_H
