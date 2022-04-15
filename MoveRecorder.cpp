//
// Created by squig on 29/3/22.
//

#include "MoveRecorder.h"
#include "Board.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>


MoveRecorder::MoveRecorder() {

}

void MoveRecorder::recordMove(int x, int y, int xa, int ya, Board moveBoard) {
    move++;
    time_t current = time(0);
    std::string dateTime = ctime(&current);
    std::string piece;
    std::ofstream fileHandle;
    fileHandle.open("Chess.txt",std::ios_base::app);
    fileHandle << "[" << move << "]" << "\n";
    fileHandle << "(" << x << "," << y << ":" << xa << "," << ya << ")" <<"\n" << "<" << moveBoard.returnSquare(xa,ya) << ">" << "\n" ;
    fileHandle << "*****" << "\n";



    for(int e = 0; e < 8; e++) {
        for(int i = 0; i < 8; i++){
            piece = moveBoard.returnSquare(e,i);
            if(piece == "White Left Rook")
                fileHandle << "wlR,";
            if(piece == "White Left Knight")
                fileHandle << "wlN,";
            if(piece == "White Left Bishop")
                fileHandle << "wlB,";
            if(piece == "White Queen")
                fileHandle << "wQ,";
            if(piece == "White King")
                fileHandle << "wK,";
            if(piece == "White Right Bishop")
                fileHandle << "wrB,";
            if(piece == "White Right Knight")
                fileHandle << "wrN,";
            if(piece == "White Right Rook")
                fileHandle << "wrR,";
            if(piece == "White Pawn")
                fileHandle << "wP,";
            if(piece == "Black Left Rook")
                fileHandle << "blR,";
            if(piece == "Black Left Knight")
                fileHandle << "blN,";
            if(piece == "Black Left Bishop")
                fileHandle << "blB,";
            if(piece == "Black Queen")
                fileHandle << "bQ,";
            if(piece == "Black King")
                fileHandle << "bK,";
            if(piece == "Black Right Bishop")
                fileHandle << "brB,";
            if(piece == "Black Right Knight")
                fileHandle << "brN,";
            if(piece == "Black Right Rook")
                fileHandle << "brR,";
            if(piece == "Black Pawn")
                fileHandle << "bP,";
            if(piece == "Empty")
                fileHandle << "X,";
        }
        fileHandle << "\n";
    }
    fileHandle << "+++++" << "\n";
    fileHandle.close();

}



