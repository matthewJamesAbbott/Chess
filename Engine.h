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


class TreeNode{
public:
    int rank, x, y, xa, ya;
    TreeNode *leftTreeNode;
    TreeNode *rightTreeNode;
};

class Tree{
public:
    TreeNode* head;

    /**
     * Add new node to tree using parameters rank, x, y, xa and ya
     *
     * @param rank of square being taken 0 being empty and 10 a king <int>
     * @param x Vertical or numeric co ordinate move origin <int>
     * @param y Horizontal or alpha co ordinate move origin <int>
     * @param xa Vertical or numeric co ordinate move destination <int>
     * @param ya Horizontal or alpha co ordinate move destianation <int>
     */
    void addTreeNode(int rank, int x, int y, int xa, int ya);
    void deleteLeaves(TreeNode *node);
    ~Tree();
};

class Engine{
public:

    /**
     * Main method for Computer Player 
     *
     * @param gameBoard complete Board for computer to generate move from
     * @return pointer to array of integers x, y, xa and ya
     */
    int *resolveMove(Board gameBoard, int computerSide);

    /**
     * Recursive function to read nodes from the tree
     *
     * @param localRoot the starthing node of the tree to traverse
     * @param base the delimiter to place on square rank which is set to max found for now
     *        making it hungry
     */
    void moveVector(TreeNode *localRoot, int base);
    void secondGuess(TreeNode *localRoot);

    std::vector<int> returnVector;
};

#endif //CHESS_ENGINE_H
