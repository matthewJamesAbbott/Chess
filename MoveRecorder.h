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

    /**
     * Record move to temperary log file Chess.txt
     *
     * @param x Vertical or numeric co ordinate for moves origin
     * @param y Horizontal or alpha co ordinate for moves origin
     * @param xa Vertical or numeric co coridnate for moves destination
     * @param ya Horizontal or alpha co ordinate for moves destination
     * @param moveBoard Board to extract information to record from
     */
    void recordMove(int x, int y, int xa, int ya, Board moveBoard);
};

#endif //CHESS_MOVERECORDER_H
