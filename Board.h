//
// Created by Matthew Abbott on 18/2/22.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

class Board {

private:

    std::string board[8][8];

public:

    Board();
    ~Board();
    std::string returnSquare(int x, int y);
    void setSquare(int x, int y, std::string piece);
};

#endif //CHESS_BOARD_H
