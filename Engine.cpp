//
// Created by Matthew Abbott on 19/3/22.
//

#include "Engine.h"
#include "MoveCalculator.h"
#include <vector>

void Tree::addTreeNode(int rank, int x, int y, int xa, int ya){
    auto *newTreeNode = new TreeNode();
    newTreeNode->rank = rank;
    newTreeNode->x = x;
    newTreeNode->y = y;
    newTreeNode->xa = xa;
    newTreeNode->ya = ya;
    if(head==nullptr){
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
                if(current == nullptr){
                    parent->rightTreeNode = newTreeNode;
                    break;
                }
            }
        }
    }
}

void Engine::moveVector(TreeNode *localRoot, int base)
{
    if(localRoot != nullptr){
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

void Engine::secondGuess(TreeNode *localRoot){
    if(localRoot != nullptr){
        secondGuess(localRoot->leftTreeNode);
        if(localRoot->rank >= 0){
            returnVector.insert(returnVector.begin(), localRoot->ya);
            returnVector.insert(returnVector.begin(), localRoot->xa);
            returnVector.insert(returnVector.begin(), localRoot->y);
            returnVector.insert(returnVector.begin(), localRoot->x);

        }
        secondGuess(localRoot->rightTreeNode);
    }
}

int *Engine::resolveMove(Board gameBoard, int computerSide){
    Tree *moveTree = new Tree();
    MoveCalculator calc;
    LinkedList *list;
    std::vector<int> moveVector;
    int base = 0;
    int playerSide;
    if(computerSide == 0)
        playerSide = 1;
    else
        playerSide = 0;
    if(computerSide == 0) {
        for (int e = 0; e < 8; e++) {
            for (int i = 0; i < 8; i++) {
                if (gameBoard.returnSquare(e, i).find("White")) {
                    list = calc.possibleSquares2DArray(e, i, gameBoard, playerSide);
                    moveVector = list->returnWeightedVector();
                    for (int j = 0; j < moveVector.size(); j++) {
                        int a = moveVector[j];
                        int b = moveVector[j + 1];
                        int c = moveVector[j + 2];
                        if (c > base)
                            base = c;
                        if (c >= 0 && c <= 10) {
                            moveTree->addTreeNode(c, e, i, a, b);
                        }
                        j = j + 2;
                    }
                }
            }
        }
    }
    else
    {
        for (int e = 0; e < 8; e++) {
            for (int i = 0; i < 8; i++) {
                if (gameBoard.returnSquare(e, i).find("Black")) {
                    list = calc.possibleSquares2DArray(e, i, gameBoard, playerSide);
                    moveVector = list->returnWeightedVector();
                    for (int j = 0; j < moveVector.size(); j++) {
                        int a = moveVector[j];
                        int b = moveVector[j + 1];
                        int c = moveVector[j + 2];
                        if (c > base)
                            base = c;
                        if (c >= 0 && c <= 10) {
                            moveTree->addTreeNode(c, e, i, a, b);
                        }
                        j = j + 2;
                    }
                }
            }
        }
    }
    TreeNode *stepper;
    stepper = moveTree->head;
    this->moveVector(stepper, base);
    int choice = 0;
    if(returnVector.size() >= 4){
        int test = returnVector.size() / 4;
        srand(time(NULL));
        choice = rand() % test;
        choice = choice * 4;
    }
    int move[4];
    Board testBoard;
    testBoard = gameBoard;
    testBoard.setSquare(returnVector[choice+2], returnVector[choice+3],testBoard.returnSquare(returnVector[choice], returnVector[choice+1]));
    testBoard.setSquare(returnVector[choice], returnVector[choice+1], "Empty");
    if(!calc.checkCalculator(returnVector[choice + 2], returnVector[choice + 3], testBoard, computerSide)){
        move[0] = returnVector[choice];
        move[1] = returnVector[choice + 1];
        move[2] = returnVector[choice + 2];
        move[3] = returnVector[choice + 3];
    }
    else{

        stepper = moveTree->head;
        returnVector.clear();
        this->secondGuess(stepper);
        int kingX, kingY;
        for(int i = 0; i < returnVector.size();){
            testBoard = gameBoard;
            testBoard.setSquare(returnVector[i+2], returnVector[i+3],testBoard.returnSquare(returnVector[i], returnVector[i+1]));
            testBoard.setSquare(returnVector[i], returnVector[i+1], "Empty");
            for (int e = 0; e < 8; e++){
                for (int i2 = 0; i2 < 8; i2++){
                    if (testBoard.returnSquare(e, i2) == "Black King"){
                        kingX = e;
                        kingY = i2;
                    }
                }
            }
            if(!calc.checkCalculator(kingX, kingY, testBoard, computerSide)){
                move[0] = returnVector[i];
                move[1] = returnVector[i + 1];
                move[2] = returnVector[i + 2];
                move[3] = returnVector[i + 3];
                break;
            }
            i = i + 4;
        }
    }
    //std::cout << "move " << move[0] << " " << move[1] << " " << move[2] << " " << move[3] << std::endl;
    delete moveTree;
    returnVector.clear();
    int *returnPointer = move;
    return returnPointer;

}
