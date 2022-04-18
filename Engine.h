//
// Created by Matthew Abbott on 19/3/22.
//

#ifndef CHESS_ENGINE_H
#define CHESS_ENGINE_H

#include "Board.h"
#include <vector>


#define SIDE "White"
#define PAWN 2
#define KNIGHT 3
#define BISHOP 4
#define ROOK 5
#define QUEEN 9
#define KING 10
#define EMPTY 0
#define MIN  0
#define MAX  10


class TreeNode {
public:
    int rank, x, y, xa, ya;
    TreeNode *leftTreeNode;
    TreeNode *rightTreeNode;


};

class Tree {
public:
    TreeNode* head;

    /**
     *
     * @param rank
     * @param x
     * @param y
     * @param xa
     * @param ya
     */
    void addTreeNode(int rank, int x, int y, int xa, int ya);


};

class Engine {
public:

    /**
     *
     * @param gameBoard
     * @return
     */
    int *resolveMove(Board gameBoard);

    /**
     *
     * @param localRoot
     * @param base
     */
    void moveVector(TreeNode *localRoot, int base);

    std::vector<int> returnVector;

};


#endif //CHESS_ENGINE_H
