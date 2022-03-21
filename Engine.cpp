//
// Created by Matthew Abbott on 19/3/22.
//

#include "Engine.h"
#include "MoveCalculator.h"
#include <iostream>
#include <vector>

void Tree::addTreeNode(int rank, int x, int y, int xa, int ya){
    TreeNode *newTreeNode = new TreeNode();
    newTreeNode->rank = rank;
    newTreeNode->x = x;
    newTreeNode->y = y;
    newTreeNode->xa = xa;
    newTreeNode->ya = ya;
    if(head==nullptr) {
        head = newTreeNode;
    }
    else{
        TreeNode *current = head;
        TreeNode *parent;
        while(true){
            parent = current;
            if(rank < current->rank){
                current = current->leftTreeNode;
                if(current == nullptr){
                    parent->leftTreeNode = newTreeNode;
                    break;
                }
            }
            else{
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
        int counter = 0;
        int weight = 0;
        for (int e = 0; e < 8; e++) {
            for (int i = 0; i < 8; i++) {
                std::cout << " in loop" << std::endl;
                if (moveBoard.returnSquare(e, i).find("White")) {
                    std::cout << "if white" << std::endl;
                    list = calc.possibleSquares2DArray(e, i, moveBoard);
                    std::cout << "x " << e << " i " << i << std::endl;
                    moveVector = list->returnWeightedVector();
                    std::cout << "returned vector" << std::endl;
                    std::cout << moveVector.size() << std::endl;
                    for (int j = 1; j < moveVector.size();j++) {
                        std::cout << "j loop" << std::endl;
                        int a = moveVector[j-1];
                        int b = moveVector[j];
                        int c = moveVector[j+1];
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
                        j = j + 2;
                    }
                }
            }
            if (weight / counter > 0)
                returnTree->addTreeNode((weight + localHead->rank) / (counter + 1), localHead->x, localHead->y,
                                        localHead->xa, localHead->ya);
        }
        moveAhead(returnTree, localHead->leftTreeNode, gameBoard);
        moveAhead(returnTree, localHead->rightTreeNode, gameBoard);

    }
    return returnTree->head;
}

void Engine::moveVector(TreeNode *localRoot, int base)
{
    if(localRoot != nullptr)
    {
        moveVector(localRoot->leftTreeNode, base);
        if(localRoot->rank == base) {
            returnVector.push_back(localRoot->x);
            returnVector.push_back(localRoot->y);
            returnVector.push_back(localRoot->xa);
            returnVector.push_back(localRoot->ya);
        }
        moveVector(localRoot->rightTreeNode, base);
    }
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
                moveVector = list->returnWeightedVector();
                for(int j = 0; j < moveVector.size()/3;) {
                     int a = moveVector[j];
                     int b = moveVector[j + 1];
                     int c = moveVector[j + 2];
                     std::cout << "rank test " << c << std::endl;
                     if(!calc.checkCalculator(a,b, gameBoard)){
                        if(gameBoard.returnSquare(a,b).find("Pawn"))
                            c = c - PAWN;
                        else if(gameBoard.returnSquare(a,b).find("Knight"))
                            c = c - KNIGHT;
                        else if(gameBoard.returnSquare(a,b).find("Bishop"))
                            c = c - BISHOP;
                        else if(gameBoard.returnSquare(a,b).find("Rook"))
                            c = c - ROOK;
                        else if(gameBoard.returnSquare(a,b).find("Queen"))
                            c = c - QUEEN;
                        else if(gameBoard.returnSquare(a,b).find("King"))
                            c = c - KING;
                        std::cout << "if" << std::endl;
                    }
                     else{
                         std::cout << "else" << std::endl;
                         if(!gameBoard.returnSquare(a,b).find("Pawn")) {
                             c = c + PAWN;
                             std::cout << "else pawn" << std::endl;
                         }
                         else if(!gameBoard.returnSquare(a,b).find("Knight")) {
                             c = c + KNIGHT;
                             std::cout << "knight" << std::endl;
                         }
                         else if(!gameBoard.returnSquare(a,b).find("Bishop")) {
                             c = c + BISHOP;
                             std::cout << "bishop" << std::endl;
                         }
                         else if(!gameBoard.returnSquare(a,b).find("Rook")) {
                             c = c + ROOK;
                             std::cout << "rook" << std::endl;
                         }
                         else if(!gameBoard.returnSquare(a,b).find("Queen")) {
                             c = c + QUEEN;
                             std::cout << "queen" << std::endl;
                         }
                         else if(!gameBoard.returnSquare(a,b).find("King")) {
                             c = c + KING;
                             std::cout << "king" << std::endl;
                         }
                         else if(!gameBoard.returnSquare(a,b).find("Empty")) {
                             c = 0;
                             std::cout << "empty" << std::endl;
                         }
                     }
                    if(c >= MIN && c <= 10) {
                        std::cout << "add node rank " << c << std::endl;
                        moveTree->addTreeNode(c, e, i, a, b);
                    }
                    j = j + 3;
                }


            }
        }
    }
/*
    Tree *returnTree = new Tree();

    TreeNode *stepper;
    stepper = moveAhead(returnTree, moveTree->head, gameBoard);

*/
    TreeNode *stepper;
    stepper = moveTree->head;
    while(stepper->rightTreeNode != nullptr){
        stepper = stepper->rightTreeNode;

        std::cout << stepper->rank << std::endl;
    }
    int base = stepper->rank;
    stepper = moveTree->head;
    this->moveVector(stepper, base);
    int test = returnVector.size()/4;
    srand(time(NULL));
    int choice = rand() % test;
    choice = choice * 4;


    int move[4];
    move[0] = returnVector[choice];
    move[1] = returnVector[choice + 1];
    move[2] = returnVector[choice + 2];
    move[3] = returnVector[choice + 3];
    delete [] moveTree;

    int *returnPointer = move;
    return returnPointer;
}

