//
// Created by squig on 29/3/22.
//

#ifndef CHESS_MOVERECORDER_H
#define CHESS_MOVERECORDER_H
#include "Board.h"


class MoveRecorder {

private:
    int move = 0;



public:
    MoveRecorder();
    void recordMove(int x, int y, int xa, int ya, Board moveBoard);
};



#endif //CHESS_MOVERECORDER_H
