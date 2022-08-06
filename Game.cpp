//
// Created by Matthew Abbott on 18/2/22.
//

#include <iostream>
#include <fstream>
#include "Game.h"
#include "Board.h"
#include "Print.h"
#include "MoveCalculator.h"
#include "Engine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

#define BLACK 0
#define WHITE 1

Game::Game(){
    }


void Game::setPlayerOne(std::string name){
    playerOne = name;
}

void Game::setPlayerTwo(std::string name){
    playerTwo = name;
}

void Game::initialiseBoard(){
    gameBoard.setSquare(0,0,"White Left Rook");
    gameBoard.setSquare(0,1,"White Left Knight");
    gameBoard.setSquare(0,2,"White Left Bishop");
    gameBoard.setSquare(0,3,"White King");
    gameBoard.setSquare(0,4,"White Queen");
    gameBoard.setSquare(0,5,"White Right Bishop");
    gameBoard.setSquare(0,6,"White Right Knight");
    gameBoard.setSquare(0,7,"White Right Rook");
    for(int i = 0; i < 8; i++){
        gameBoard.setSquare(1,i,"White Pawn");
    }
    for(int e = 2; e < 6; e++){
        for(int i = 0; i < 8; i++){
            gameBoard.setSquare(e,i,"Empty");
        }
    }
    for(int i = 0; i < 8; i++){
        gameBoard.setSquare(6,i,"Black Pawn");
    }
    gameBoard.setSquare(7,0,"Black Left Rook");
    gameBoard.setSquare(7,1,"Black Left Knight");
    gameBoard.setSquare(7,2,"Black Left Bishop");
    gameBoard.setSquare(7,3,"Black King");
    gameBoard.setSquare(7,4,"Black Queen");
    gameBoard.setSquare(7,5,"Black Right Bishop");
    gameBoard.setSquare(7,6,"Black Right Knight");
    gameBoard.setSquare(7,7,"Black Right Rook");
}

void Game::initialiseBoardReverse(){
    gameBoard.setSquare(0,0,"Black Left Rook");
    gameBoard.setSquare(0,1,"Black Left Knight");
    gameBoard.setSquare(0,2,"Black Left Bishop");
    gameBoard.setSquare(0,3,"Black King");
    gameBoard.setSquare(0,4,"Black Queen");
    gameBoard.setSquare(0,5,"Black Right Bishop");
    gameBoard.setSquare(0,6,"Black Right Knight");
    gameBoard.setSquare(0,7,"Black Right Rook");
    for(int i = 0; i < 8; i++){
        gameBoard.setSquare(1,i,"Black Pawn");
    }
    for(int e = 2; e < 6; e++){
        for(int i = 0; i < 8; i++){
            gameBoard.setSquare(e,i,"Empty");
        }
    }
    for(int i = 0; i < 8; i++){
        gameBoard.setSquare(6,i,"White Pawn");
    }
    gameBoard.setSquare(7,0,"White Left Rook");
    gameBoard.setSquare(7,1,"White Left Knight");
    gameBoard.setSquare(7,2,"White Left Bishop");
    gameBoard.setSquare(7,3,"White King");
    gameBoard.setSquare(7,4,"White Queen");
    gameBoard.setSquare(7,5,"White Right Bishop");
    gameBoard.setSquare(7,6,"White Right Knight");
    gameBoard.setSquare(7,7,"White Right Rook");
}

bool Game::recallMove(){
    std::ifstream inFileHandle;
    inFileHandle.open("Chess.txt");
    int turn;
    std::string line;
    while(std::getline(inFileHandle, line)){
        if(!line.find("["))
            turn = line.at(1) - 48;
    }
    inFileHandle.close();
    if(turn > 2) {
        inFileHandle.open("Chess.txt");
        std::string move = "[";
        move += std::to_string(turn - 2);
        while (std::getline(inFileHandle, line)) {
            if (!line.find(move)) {
                std::getline(inFileHandle, line);
                std::getline(inFileHandle, line);
                std::getline(inFileHandle, line);
                break;
            }
        }
        for (int e = 0; e < 8; e++) {
            int pos = 0;
            int start = 0;
            std::getline(inFileHandle, line);
            for (int i = 0; i < 8; i++) {
                pos = line.find(",", pos + 1);
                int length = pos - start;
                std::string piece = line.substr(start, length);
                start = pos + 1;
                if (piece == "wlR") {
                    gameBoard.setSquare(e, i, "White Left Rook");
                } else if (piece == "wlN") {
                    gameBoard.setSquare(e, i, "White Left Knight");
                } else if (piece == "wlB") {
                    gameBoard.setSquare(e, i, "White Left Bishop");
                } else if (piece == "wK") {
                    gameBoard.setSquare(e, i, "White King");
                } else if (piece == "wQ") {
                    gameBoard.setSquare(e, i, "White Queen");
                } else if (piece == "wrB") {
                    gameBoard.setSquare(e, i, "White Right Bishop");
                } else if (piece == "wrN") {
                    gameBoard.setSquare(e, i, "White Right Knight");
                } else if (piece == "wrR") {
                    gameBoard.setSquare(e, i, "White Right Rook");
                } else if (piece == "wP") {
                    gameBoard.setSquare(e, i, "White Pawn");
                } else if (piece == "blR") {
                    gameBoard.setSquare(e, i, "Black Left Rook");
                } else if (piece == "blN") {
                    gameBoard.setSquare(e, i, "Black Left Knight");
                } else if (piece == "blB") {
                    gameBoard.setSquare(e, i, "Black Left Bishop");
                } else if (piece == "bK") {
                    gameBoard.setSquare(e, i, "Black King");
                } else if (piece == "bQ") {
                    gameBoard.setSquare(e, i, "Black Queen");
                } else if (piece == "brB") {
                    gameBoard.setSquare(e, i, "Black Right Bishop");
                } else if (piece == "brN") {
                    gameBoard.setSquare(e, i, "Black Right Knight");
                } else if (piece == "brR") {
                    gameBoard.setSquare(e, i, "Black Right Rook");
                } else if (piece == "bP") {
                    gameBoard.setSquare(e, i, "Black Pawn");
                } else if (piece == "X") {
                    gameBoard.setSquare(e, i, "Empty");
                }
            }
        }
        inFileHandle.close();
        return true;
    }
    else if(turn == 2){
        this->initialiseBoard();
        return true;
    }
    return false;
}

void Game::loadGame(std::string fileName){
    std::ofstream outFileHandle;
    std::remove("Chess.txt");
    std::string saveFile = "Chess.txt";
    outFileHandle.open(saveFile ,std::ios_base::app);
    std::ifstream inFileHandle;
    std::string line;
    inFileHandle.open(fileName);
    int turn;
    while(std::getline(inFileHandle, line)){
        outFileHandle << line << "\n";
        if(!line.find("["))
            turn = line.at(1) - 48;
    }
    inFileHandle.close();
    outFileHandle.close();

    rec.setMove(turn);

    inFileHandle.open("Chess.txt");
    while(std::getline(inFileHandle, line)){
        if(!line.find("[" + std::to_string(turn))){
            std::getline(inFileHandle, line);
            std::getline(inFileHandle, line);
            std::getline(inFileHandle, line);
            break;
        }
    }
    for(int e = 0; e < 8; e++){
        int pos = 0;
        int start = 0;
        std::getline(inFileHandle, line);
        for(int i = 0; i < 8; i++){
            pos = line.find(",", pos + 1);
            int length = pos - start;
            std::string piece = line.substr(start, length);
            start = pos + 1;
            if(piece == "wlR"){
                gameBoard.setSquare(e,i, "White Left Rook");
            }
            else if(piece == "wlN"){
                gameBoard.setSquare(e,i, "White Left Knight");
            }
            else if(piece == "wlB"){
                gameBoard.setSquare(e,i, "White Left Bishop");
            }
            else if(piece == "wK"){
                gameBoard.setSquare(e,i, "White King");
            }
            else if(piece == "wQ"){
                gameBoard.setSquare(e,i, "White Queen");
            }
            else if(piece == "wrB"){
                gameBoard.setSquare(e,i, "White Right Bishop");
            }
            else if(piece == "wrN"){
                gameBoard.setSquare(e,i, "White Right Knight");
            }
            else if(piece == "wrR"){
                gameBoard.setSquare(e,i, "White Right Rook");
            }
            else if(piece == "wP"){
                gameBoard.setSquare(e,i, "White Pawn");
            }
            else if(piece == "blR"){
                gameBoard.setSquare(e,i, "Black Left Rook");
            }
            else if(piece == "blN"){
                gameBoard.setSquare(e,i, "Black Left Knight");
            }
            else if(piece == "blB"){
                gameBoard.setSquare(e,i, "Black Left Bishop");
            }
            else if(piece == "bK"){
                gameBoard.setSquare(e,i, "Black King");
            }
            else if(piece == "bQ"){
                gameBoard.setSquare(e,i, "Black Queen");
            }
            else if(piece == "brB"){
                gameBoard.setSquare(e,i, "Black Right Bishop");
            }
            else if(piece == "brN"){
                gameBoard.setSquare(e,i, "Black Right Knight");
            }
            else if(piece == "brR"){
                gameBoard.setSquare(e,i, "Black Right Rook");
            }
            else if(piece == "bP"){
                gameBoard.setSquare(e,i, "Black Pawn");
            }
            else if(piece == "X"){
                gameBoard.setSquare(e,i, "Empty");
            }
        }
    }
    inFileHandle.close();
}

bool Game::engineMove(){
    int *moveArray;
    int computerSide = WHITE;
    if(this->playerSide == WHITE)
        computerSide = BLACK;
    if(calc.checkMateTest(gameBoard,computerSide)){
        std::cout << "Check Mate You Win" << std::endl;
        return false;
    }
    moveArray = moveEngine->resolveMove(gameBoard, computerSide);
    gameBoard.setSquare(moveArray[2], moveArray[3], gameBoard.returnSquare(moveArray[0], moveArray[1]));
    gameBoard.setSquare(moveArray[0], moveArray[1], "Empty");
    rec.recordMove(moveArray[0],moveArray[1],moveArray[2],moveArray[3],gameBoard);
    return true;
}

void Game::initSDL(){
    output.initSDL();
}

void Game::printBoardToWindow(){
    output.printBoardToWindow(gameBoard);
}

void Game::printOptionsToWindow(){
    output.printOptionsToWindow();
}

void Game::destroySDL(){
    output.destroySDL();
}

void Game::printBoardToTerminal(){
    output.printBoardToTerminal(gameBoard);
}
bool Game::movePiece(int ia, char ca, int ib, char cb){
    int ya;
    if(ca == 'A' || ca == 'a')
        ya = 0;
    else if(ca == 'B' || ca == 'b')
        ya = 1;
    else if(ca == 'C' || ca == 'c')
        ya = 2;
    else if(ca == 'D' || ca == 'd')
        ya = 3;
    else if(ca == 'E' || ca == 'e')
        ya = 4;
    else if(ca == 'F' || ca == 'f')
        ya = 5;
    else if(ca == 'G' || ca == 'g')
        ya = 6;
    else if(ca == 'H' || ca == 'h')
        ya = 7;
    int xa;
    if(ia == 1)
        xa = 7;
    else if(ia == 2)
        xa = 6;
    else if(ia == 3)
        xa = 5;
    else if(ia == 4)
        xa = 4;
    else if(ia == 5)
        xa = 3;
    else if(ia == 6)
        xa = 2;
    else if(ia == 7)
        xa = 1;
    else if(ia == 8)
        xa = 0;
    int yb;
    if(cb == 'A' || cb == 'a')
        yb = 0;
    else if(cb == 'B' || cb == 'b')
        yb = 1;
    else if(cb == 'C' || cb == 'c')
        yb = 2;
    else if(cb == 'D' || cb == 'd')
        yb = 3;
    else if(cb == 'E' || cb == 'e')
        yb = 4;
    else if(cb == 'F' || cb == 'f')
        yb = 5;
    else if(cb == 'G' || cb == 'g')
        yb = 6;
    else if(cb == 'H' || cb == 'h')
        yb = 7;
    int xb;
    if(ib == 1)
        xb = 7;
    else if(ib == 2)
        xb = 6;
    else if(ib == 3)
        xb = 5;
    else if(ib == 4)
        xb = 4;
    else if(ib == 5)
        xb = 3;
    else if(ib == 6)
        xb = 2;
    else if(ib == 7)
        xb = 1;
    else if(ib == 8)
        xb = 0;
    LinkedList *list;
    Board checkBoard = gameBoard;
    if(calc.checkMateTest(gameBoard,this->playerSide)){
        std::cout << "Check Mate Computer Wins" << std::endl;
        return false;
    }
    list = calc.possibleSquares2DArray(xa, ya, gameBoard, playerSide);
    std::vector<int> moveVector;
    moveVector = list->returnVector();
    for(int i = 0; i < moveVector.size();){
        int a = moveVector[i];
        int b = moveVector[i + 1];
        i = i + 2;
        if (xb == a && yb == b){
            std::string originalSquare = checkBoard.returnSquare(xa, ya);
            if(b == 1 && ya == 3 && checkBoard.returnSquare(xa, ya).find("King")){
                checkBoard.setSquare(xb,yb,originalSquare);
                checkBoard.setSquare(xb,2, checkBoard.returnSquare(xa,0));
                checkBoard.setSquare(xb,0, "Empty");
                checkBoard.setSquare(xb,ya, "Empty");
            }
            else if(a == 2 && originalSquare == "Black Pawn" && checkBoard.returnSquare(a,b) == "Empty" || a == 5 &&
            originalSquare == "White Pawn" && checkBoard.returnSquare(a,b) == "Empty"){
                checkBoard.setSquare(xb,yb, originalSquare);
                checkBoard.setSquare(xa,ya, "Empty");
                if(a == 2){
                     checkBoard.setSquare(xb+1,yb, "Empty");
                }
                if(a == 5)
                    checkBoard.setSquare(xb-1,yb, "Empty");
            }
            else{
                checkBoard.setSquare(xb, yb, originalSquare);
                checkBoard.setSquare(xa, ya, "Empty");
            }
        }
    }
    int kingX;
    int kingY;
    for(int e = 0; e < 8; e++){
        for(int i = 0; i < 8; i++){
            if(checkBoard.returnSquare(e,i) == "Black King"){
                kingX = e;
                kingY = i;
            }
        }
    }
    if(!calc.checkCalculator(kingX,kingY, checkBoard, this->playerSide)){
        for(int e = 0; e < 8; e++){
            for(int i = 0; i < 8; i++){
                gameBoard.setSquare(e,i, checkBoard.returnSquare(e,i));
            }
        }
        rec.recordMove(xa,ya,xb,yb,gameBoard);
        return true;
    }
    return false;
}
