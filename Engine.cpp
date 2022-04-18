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
                for(int i = 0; i < moveVector.size(); i++){
                    std::cout << moveVector[i] << " ";
                }
                std::cout << std::endl;
                for(int j = 0; j < moveVector.size();j++) {
                    int a = moveVector[j];
                    int b = moveVector[j + 1];
                    int c = moveVector[j + 2];
                    if (c > base)
                        base = c;
                    if(c >= 0 && c <= 10) {
                        moveTree->addTreeNode(c, e, i, a, b);
                        std::cout << "engine moveVector after pruning x " << a << " y " << b << " rank " << c << std::endl;
                    }
                    std::cout << "engine moveVector no pruning x " << a << " y " << b << " rank " << c << std::endl;
                    j = j + 2;
                }
            }
        }
    }
    std::cout << "BASE " << base << std::endl;
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

    for(int i = 0; i < returnVector.size(); i++){
        std::cout << returnVector[i] << " ";
    }
    std::cout << std::endl;
    int move[4];
    move[0] = returnVector[choice];
    move[1] = returnVector[choice + 1];
    move[2] = returnVector[choice + 2];
    move[3] = returnVector[choice + 3];
    std::cout << "move from returnVector x " << move[2] << " y " << move[3] << std::endl;
    delete moveTree;
    returnVector.clear();
    int *returnPointer = move;
    return returnPointer;
}

