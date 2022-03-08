//
// Created by Matthew Abbott on 19/2/22.
//

#ifndef CHESS_MOVECALCULATOR_H
#define CHESS_MOVECALCULATOR_H
#include <string>
#include <vector>
#include "Board.h"

class Node {
public:

    int x;
    int y;
    Node *next;

};

class LinkedList{
private:
    Node* head;

public:
    LinkedList() { // constructor
        head = NULL;
    }


    virtual ~LinkedList();; // destructor
    void addNode(int x, int y);
    std::vector<int> returnVector();

};


class MoveCalculator{

private:
    int whiteKingX = 0;
    int whiteKingY = 0;
    int blackKingX = 0;
    int blackKingY = 0;

public:

    MoveCalculator();
    LinkedList *possibleSquares2DArray(int x, int y,Board moveBoard);
    bool checkCalculator(int x,int y,Board moveBoard);

};


#endif //CHESS_MOVECALCULATOR_H
