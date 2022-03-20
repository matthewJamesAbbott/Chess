//
// Created by Matthew Abbott on 19/3/22.
//

#include "Engine.h"
#include "MoveCalculator.h"
#include <iostream>

void Tree::addTreeNode(int rank, int x, int y, int xa, int ya){
    TreeNode *newTreeNode = new TreeNode();
    newTreeNode->rank = rank;
    newTreeNode->x = x;
    newTreeNode->y = y;
    newTreeNode->xa = xa;
    newTreeNode->ya = ya;
    if(head==nullptr) {
        head = newTreeNode;
        std::cout << "root null " << std::endl;
    }
    else{
        std::cout << "traversing tree to insert" << std::endl;
        TreeNode *current = head;
        TreeNode *parent;
        while(true){
            parent = current;
            if(rank < current->rank){
                std::cout << "left path taken" << std::endl;
                current = current->leftTreeNode;
                if(current == nullptr){
                    parent->leftTreeNode = newTreeNode;
                    break;
                }
            }
            else{
                std::cout << "right path taken" << std::endl;
                current = current->rightTreeNode;
                if(current == nullptr)
                {
                    parent->rightTreeNode = newTreeNode;
                    break;
                }
            }
        }
    }
}
 TreeNode *Engine::moveAhead(Tree *returnTree, TreeNode *localHead, Board gameBoard){

    MoveCalculator calc;
    LinkedList *list;
    std::vector<int> moveVector;
    Board moveBoard = gameBoard;
    if(localHead != nullptr){
        moveBoard.setSquare(localHead->xa,localHead->ya,gameBoard.returnSquare(localHead->x,localHead->y));
        moveBoard.setSquare(localHead->x,localHead->y,"Empty");
        std::cout << "we are about to check for check baby" << std::endl;
        int counter = 0;
        int weight = 0;
        for (int e = 0; e < 8; e++) {
            for (int i = 0; i < 8; i++) {
                if (moveBoard.returnSquare(e, i).find(SIDE)) {
                    list = calc.possibleSquares2DArray(e, i, moveBoard);
                    moveVector = list->returnWeightedVector();
                    for (int j = 0; j < moveVector.size();) {
                        int a = moveVector[j];
                        int b = moveVector[j + 1];
                        int c = moveVector[j + 2];
                        if (calc.checkCalculator(a, b, moveBoard)) {
                            if (moveBoard.returnSquare(e, i).find("Pawn"))
                                c = c - PAWN;
                            else if (moveBoard.returnSquare(e, i).find("Knight"))
                                c = c - KNIGHT;
                            else if (moveBoard.returnSquare(e, i).find("Bishop"))
                                c = c - BISHOP;
                            else if (moveBoard.returnSquare(e, i).find("Rook"))
                                c = c - ROOK;
                            else if (moveBoard.returnSquare(e, i).find("Queen"))
                                c = c - QUEEN;
                            else if (moveBoard.returnSquare(e, i).find("King"))
                                c = c - KING;
                        }
                        weight = weight + c;
                        counter++;
                        i = i + 3;
                    }
                }
            }
            std::cout << "we are about to check for check" << std::endl;
            if (weight / counter > 0)
                returnTree->addTreeNode((weight + localHead->rank) / (counter + 1), localHead->x, localHead->y,localHead->xa, localHead->ya);
            moveAhead(returnTree, localHead->leftTreeNode, gameBoard);
            moveAhead(returnTree, localHead->rightTreeNode, gameBoard);
        }
    }
    return returnTree->head;
}



int *Engine::resolveMove(Board gameBoard){
    Tree *moveTree = new Tree();
    MoveCalculator calc;
    LinkedList *list;
    std::vector<int> moveVector;
    for(int e = 0; e < 8; e++){
        for(int i = 0; i < 8; i++){
            if(gameBoard.returnSquare(e,i).find("Black")) {



                list = calc.possibleSquares2DArray(e, i, gameBoard);
                std::cout << "after check" << std::endl;

                moveVector = list->returnWeightedVector();
                for(int j = 0; j < moveVector.size()/3;) {
                    std::cout << "we are about" << std::endl;

                     int a = moveVector[j];
                     int b = moveVector[j + 1];
                     int c = moveVector[j + 2];
                     if(calc.checkCalculator(a,b, gameBoard)){
                        if(gameBoard.returnSquare(e,i).find("Pawn"))
                            c = c - PAWN;
                        else if(gameBoard.returnSquare(e,i).find("Knight"))
                            c = c - KNIGHT;
                        else if(gameBoard.returnSquare(e,i).find("Bishop"))
                            c = c - BISHOP;
                        else if(gameBoard.returnSquare(e,i).find("Rook"))
                            c = c - ROOK;
                        else if(gameBoard.returnSquare(e,i).find("Queen"))
                            c = c - QUEEN;
                        else if(gameBoard.returnSquare(e,i).find("King"))
                            c = c - KING;
                    }

                    std::cout << "Rank " << c << std::endl;
                    if(c >= MIN && c <= 10) {
                        moveTree->addTreeNode(c, e, i, a, b);
                        std::cout << "adding Node " << std::endl;
                    }
                    j = j + 3;
                }


            }
        }
    }
    std::cout << "out of loop" << std::endl;
/*
    Tree *returnTree = new Tree();

    TreeNode *stepper;
    stepper = moveAhead(returnTree, moveTree->head, gameBoard);
*/
    TreeNode *stepper;
    stepper = moveTree->head;
    std::cout << "on the road again " << std::endl;
    while(stepper->rightTreeNode != nullptr){
        stepper = stepper->rightTreeNode;


    }
    int move[4];
    move[0] = stepper->x;
    move[1] = stepper->y;
    move[2] = stepper->xa;
    move[3] = stepper->ya;
    delete [] moveTree;

    int *returnPointer = move;


    for(int r = 0; r < 4; r++) {
        std::cout << move[r] << std::endl;
    }
    return returnPointer;
}

