#ifndef CHESS_PRINT_H
#define CHESS_PRINT_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Board.h"

class Print{

public:
    Print();
    void printBoardToTerminal(Board gameBoard);
    void printBoardToWindow(Board gameBoard);
    void printOptionsToWindow();
    void initSDL();
    void destroySDL();

    int clientServerToggle{};
    int guiOptionToggle{};
    char* serverPort = "9008";
    std::string clientIP;
    int clientPort{};

};

struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
} SDL_Struct;

#endif //CHESS_PRINT_H

