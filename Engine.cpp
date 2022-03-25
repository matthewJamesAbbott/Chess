//
// Created by Matthew Abbott on 19/3/22.
//

#include "Engine.h"
#include "MoveCalculator.h"
#include <vector>
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
    int base = 0;
    for(int e = 0; e < 8; e++){
        for(int i = 0; i < 8; i++){
            if(gameBoard.returnSquare(e,i).find("Black")) {
                list = calc.possibleSquares2DArray(e, i, gameBoard);
                moveVector = list->returnWeightedVector();
                for(int j = 0; j < moveVector.size()/3;) {
                    int a = moveVector[j];
                    int b = moveVector[j + 1];
                    int c = moveVector[j + 2];
                    if (c > base)
                        base = c;
                    if(c >= MIN && c <= MAX) {
                        moveTree->addTreeNode(c, e, i, a, b);
                    }
                    j = j + 3;
                }
            }
        }
    }

    TreeNode *stepper;
    stepper = moveTree->head;
    this->moveVector(stepper, base);
    int choice = 0;
    if(returnVector.size() >= 4) {
        int test = returnVector.size() / 4;
        srand(time(NULL));
        choice = rand() % test;
        choice = choice * 4;
    }

    int move[4];
    move[0] = returnVector[choice];
    move[1] = returnVector[choice + 1];
    move[2] = returnVector[choice + 2];
    move[3] = returnVector[choice + 3];
    delete [] moveTree;

    int *returnPointer = move;
    return returnPointer;
}

