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

/*
 * load string representations of pieces into 2D array board black bottom
 * take note that due to the way the terminal prints 0,0 in
 * the array is 7,0 on the board so this intialises "White Left Rook" 
 * to square 8A
 *
 */

void Game::initialiseBoard(){

    /*
     * load white pieces into 2D array starting at 8A
     * finishing at 7H
     *
     */


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

    /*
     * load string representations of empty space into
     * 2D array starting at 6A finishing at 3H
     *
     */


    for(int e = 2; e < 6; e++){
        for(int i = 0; i < 8; i++){
            gameBoard.setSquare(e,i,"Empty");
        }
    }

    /*
     * load black pieces into 2D array starting at 2A
     * finishing at 1H
     * notice pawns in reverse order from white
     *
     */


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


/*
 * load string representations of pieces into 2D array board white bottom
 * take note that due to the way the terminal prints 0,0 in
 * the array is 7,0 on the board so this intialises "Black Left Rook" 
 * to square 8A
 *
 */

void Game::initialiseBoardReverse(){

    /*
     * load black pieces into 2D array starting at 8A
     * finishing at 7H
     *
     */

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

     /*
      * load string representations of empty space into
      * 2D array starting at 6A finishing at 3H
      *
      */

    for(int e = 2; e < 6; e++){
        for(int i = 0; i < 8; i++){
            gameBoard.setSquare(e,i,"Empty");
        }
    }

    /*
     * load white pieces into 2D array starting at 2A
     * finishing at 1H
     * notice pawns in reverse order from black
     *
     */

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

/*
 * read and parse move history from Chess.txt for board layout
 * of last move reset game to board layout giving the user
 * the next turn
 *
 */

bool Game::recallMove(){
    std::ifstream inFileHandle;
    inFileHandle.open("Chess.txt");
    int turn;
    std::string line;
    
    while(std::getline(inFileHandle, line)){ // find last turn in Chess.txt
        if(!line.find("["))
            turn = line.at(1) - 48;
    }
    inFileHandle.close();

    if(turn > 2) { // test if there have been enough turns to have a game state recorded

        /*
         * open Chess.txt extract lines of text until 2 turns
         * before current leaving stream open when finished
         *
         */


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

        /*
         * continue extracting lines of text from Chess.txt parsing them
         * for string representations of the pieces
         * then inserting string representation into correct position in 2D array board
         *
         */
        
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
        inFileHandle.close(); // close file stream
        return true; // did something 
    }
    else if(turn == 2){ // game is in second turn and can be taken back to board initialisation for recallMove
        this->initialiseBoard(); 
        return true; // did something
    }
    return false; // did nothing game is already at base initialisation no move to recall
}

/*
 * using users selection of file open and parse file for last turn and piece positions
 * input string representations of pieces into 2D array board
 *
 */

void Game::loadGame(std::string fileName){

    std::ofstream outFileHandle; // open handle to out stream
    std::remove("Chess.txt"); // remove game state file
    std::string saveFile = "Chess.txt";
    outFileHandle.open(saveFile ,std::ios_base::app); // use out stream handle to open new game state file
    std::ifstream inFileHandle; // open handle to in stream
    std::string line; 
    inFileHandle.open(fileName); // use in stream handle to open fileName supplied via functions input argument

    /*
     * copy contents of fileName to Chess.txt
     * then close both handles to in stream and out stream
     *
     */

    int turn;
    while(std::getline(inFileHandle, line)){
        outFileHandle << line << "\n";
        if(!line.find("["))
            turn = line.at(1) - 48;
    }
    inFileHandle.close();
    outFileHandle.close();

    

    rec.setMove(turn); // set turn in private object for class MoveRecorder

    /*
     * open game state file through handle to in stream
     * move to last turn hook and then over move co ordinates name and delimit
     * ready to extract board state
     *
     */

    inFileHandle.open("Chess.txt");
    while(std::getline(inFileHandle, line)){
        if(!line.find("[" + std::to_string(turn))){
            std::getline(inFileHandle, line);
            std::getline(inFileHandle, line);
            std::getline(inFileHandle, line);
            break;
        }
    }

    /*
     * continue to extract lines from game state file parsing them for piece positions
     * input string representation of piece into correct place in 2D array board
     * close handle to in stream
     *
     */

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

/*
 * test if computer is in checkmate
 * calculate a computer generated move with object moveEngine from class Engine
 * input piece at correct position in 2D array board and replace pieces original position with "Empty"
 * record computers move in game state file through object rec from class MoveRecorder
 *
 */

bool Game::engineMove(){
    int *moveArray;
    int computerSide = WHITE;
    if(this->playerSide == WHITE) // check which side for computer to play
        computerSide = BLACK;

    /*
     * send object gameBoard and colour of computers pieces to object calc of class MoveCalculator
     * to be tested for checkmate by function checkMateTest
     * if test passes print success and exit function returning false
     *
     */

    if(calc.checkMateTest(gameBoard,computerSide)){
        std::cout << "Check Mate You Win" << std::endl;
        return false;
    }

    /*
     * resolve computers move and store it in an array of integers
     * input string representations of piece and empty to correct places in the 2D array board
     * record game state in Chess.txt
     * exit function and return the success of move
     *
     */

    moveArray = moveEngine->resolveMove(gameBoard, computerSide);
    gameBoard.setSquare(moveArray[2], moveArray[3], gameBoard.returnSquare(moveArray[0], moveArray[1]));
    gameBoard.setSquare(moveArray[0], moveArray[1], "Empty");
    rec.recordMove(moveArray[0],moveArray[1],moveArray[2],moveArray[3],gameBoard);
    return true;
}

/*
 * take input arguments for alpha and numeric co-ordinates for pieces orignal position
 * and its resting position after turn
 * convert co-ordinates into numeric positions for 2D array board
 * test for checkmate
 * generate a list of possible moves for piece at co-ordinates with object calc from class MoveCalculator
 * test move against generated list
 * create temporary object checkBoard that is a copy of gameBoard through gameBoard's copy constructor
 * make move in checkBoard and then test if king is in check
 * if test is negative make move in gameBoard record move in Chess.txt else exit function on false
 * to allow play to make a different move
 *
 */

bool Game::movePiece(int ia, char ca, int ib, char cb){
    
    /*
     * convert alpha co-ordinate for piece's origin into numeric co-ordinates
     *
     */

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

    /*
     * reverse numeric co-ordinate for piece's origin to deal with terminal printing
     *
     */

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

    /*
     * convert alpha co-ordinate for piece's destination into numeric co-ordinates 
     *
     */

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

    /*
     * reverse numeric co-ordinate for piece's destination to deal with terminal printing
     *
     */

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

    /*
     * create list and checkBoard object
     * check if opponent has put you in check mate
     * calculate possible moves for piece and store them in list
     *
     */

    LinkedList *list;
    Board checkBoard = gameBoard;
    if(calc.checkMateTest(gameBoard,this->playerSide)){
        std::cout << "Check Mate YOU LOSE" << std::endl;
        return false;
    }
    list = calc.possibleSquares2DArray(xa, ya, gameBoard, playerSide);

    /*
     * serialise list into vector with just x and y co-ordinates and no weight 
     * (weight is used to determine which piece to take when ai is playing and is also stored in list)
     * extract co-ordinates from list to be tested
     * test if players choice is in list
     *
     */

    std::vector<int> moveVector;
    moveVector = list->returnVector();
    for(int i = 0; i < moveVector.size();){
        int a = moveVector[i]; // numeric co-ordinate
        int b = moveVector[i + 1]; // alpha co-ordinate
        i = i + 2;
        if (xb == a && yb == b){ // test if destination co-ordinates are in list of possible moves for piece
            std::string originalSquare = checkBoard.returnSquare(xa, ya); // obtain piece representation as string

            /*
             * castle routine (main checks done in class MoveCalculator)
             * check if king is in right position
             * move king and rook to right positions on checkBoard 
             * set origins as empty
             *
             */

            if(b == 1 && ya == 3 && checkBoard.returnSquare(xa, ya).find("King")){ // needs extra tests
                checkBoard.setSquare(xb,yb,originalSquare);
                checkBoard.setSquare(xb,2, checkBoard.returnSquare(xa,0));
                checkBoard.setSquare(xb,0, "Empty");
                checkBoard.setSquare(xb,ya, "Empty");
            }

            /*
             * enpassant routine (main checks done in class MoveCalculator)
             * check pawn is in right position
             * move pawn to right position on checkboard and replace opponents pawn with empty
             * set origin of pawn to empty
             *
             */

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

            /*
             * normal move routine
             * move piece on checkBoard
             * set origin of piece to empty
             *
             */

            else{
                checkBoard.setSquare(xb, yb, originalSquare);
                checkBoard.setSquare(xa, ya, "Empty");
            }
        }
    }

    /*
     * find position of players king on checkBoard after move
     *
     */

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

    /*
     * check if kings position is in check
     * if test is false record move in Chess.txt
     * return true so move can be made on gameBoard
     *
     */

    if(!calc.checkCalculator(kingX,kingY, checkBoard, this->playerSide)){
        for(int e = 0; e < 8; e++){
            for(int i = 0; i < 8; i++){
                gameBoard.setSquare(e,i, checkBoard.returnSquare(e,i));
            }
        }
        rec.recordMove(xa,ya,xb,yb,gameBoard);
        return true;
    }

    return false; // king is in check return false so player can chose a new move
}
