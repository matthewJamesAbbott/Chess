//
// Created by Matthew Abbott on 18/2/22.
//

#include <string>
#include <utility>
#include "Board.h"

Board::Board()= default;

Board::Board(Board const &copy){
    for(int e = 0; e < 8; e++){
        for(int i = 0; i < 8; i++){
            board[e][i] = copy.board[e][i];
        }
    }
}
Board::~Board()= default;

std::string Board::returnSquare(int x, int y){
    return board[x][y];
}

void Board::setSquare(int x, int y, std::string piece){
    board[x][y] = std::move(piece);
}
