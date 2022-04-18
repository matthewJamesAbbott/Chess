//
// Created by Matthew Abbott on 18/2/22.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include <string>

class Board {

public:

    Board();
    Board(Board const &copy);
    ~Board();

    /**
     * Return String representation of square on chess board.
     *
     * @param x  Vertical axis or Numeric value for board <int>
     * @param y  Horizontal axis or Alpha value for board <int>
     * @return   String representation of square <std::string>
     */
    std::string returnSquare(int x, int y);

    /**
     * Input String representation of square to chess board
     * @param x   Vertical axis or Numeric value for board
     * @param y   Horizontal axis or Alpha value for board
     * @param piece  String representation of piece to be placed on board
     */
    void setSquare(int x, int y, std::string piece);

private:

    std::string board[8][8];

};

#endif //CHESS_BOARD_H
