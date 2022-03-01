//
// Created by Matthew Abbott on 18/2/22.
//
#include <string>
#include "Board.h"

Board::Board(){}

Board::~Board(){}

std::string Board::returnSquare(int x, int y){
    return board[x][y];
}

void Board::setSquare(int x, int y, std::string piece){
    board[x][y] = piece;
}
