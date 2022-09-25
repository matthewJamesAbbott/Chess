//
// Created by Matthew Abbott on 19/3/22.
//

#include "Engine.h"
#include "MoveCalculator.h"
#include "Game.h"
#include <vector>
#include <iostream>
#define BLACK 0
#define WHITE 1

/*
 * add pieces rank, origin co-ordinates and destination co-ordinates to decision tree
 *
 */

void Tree::addTreeNode(int rank, int x, int y, int xa, int ya){

    auto *newTreeNode = new TreeNode(); // create new node on tree
    newTreeNode->rank = rank; // input piece rank
    newTreeNode->x = x; // input origin numeric
    newTreeNode->y = y; // input origin alpha
    newTreeNode->xa = xa; // input destination numeric
    newTreeNode->ya = ya; // input destination alpha

    if(head==nullptr){ // if head of tree is empty make the new node the head
        head = newTreeNode;
    }
    else{ // else if head of tree is not empty 
        TreeNode *current = head; // create and point TreeNode pointer current towards head
        TreeNode *parent; // create TreeNode pointer parent

        /*
         * sort and place TreeNodes into tree based on value of rank
         * if new TreeNode's rank is less than the current nodes rank move to the left
         * if new TreeNode's rank is more than the current nodes rank move to the right
         * if current node after move is empty insert newTreeNode
         */

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

Tree::~Tree(){
    this->deleteLeaves(head);
}

void Tree::deleteLeaves(TreeNode *node){
    if (node == nullptr){ 
        return;
    }
    deleteLeaves(node->leftTreeNode); 
    deleteLeaves(node->rightTreeNode); 
    delete node;
}
/*
 * recursive function to extract and serialise possible moves
 * from the decision tree
 * note that return of function is void and it works on a
 * global vector called returnVector
 *
 */

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

/*
 * recursive function to extract a second move without taking
 * the highest possible piece available
 * this is called in the case of the first recursive function 
 * results in check against the computer
 *
 */

void Engine::secondGuess(TreeNode *localRoot){
    if(localRoot != nullptr){
        secondGuess(localRoot->leftTreeNode);
//        if(localRoot->rank >= 0){
            returnVector.insert(returnVector.begin(), localRoot->x);
            returnVector.insert(returnVector.begin(), localRoot->y);
            returnVector.insert(returnVector.begin(), localRoot->xa);
            returnVector.insert(returnVector.begin(), localRoot->ya);

//        }
        secondGuess(localRoot->rightTreeNode);
    }
}

/*
 * function to take gameBoard and computers colour and 
 * return a pointer to an array with the co-ordinates of the computers move
 *
 */

int *Engine::resolveMove(Board gameBoard, int computerSide){

    /*
     * create tree to store possible moves in
     * create object calc from MoveCalculator
     * create LinkedList pointer
     * Create vector to store serialised moves from list
     *
     */

    Tree *moveTree = new Tree();
    MoveCalculator calc;
    LinkedList *list;
    std::vector<int> moveVector;

    int base = 0;
    int playerSide;
    
    /*
     * set variable for players colour
     *
     */
    std::string compSideColour;
    std::string compKing;
    if(computerSide == BLACK){
        playerSide = WHITE;
	compSideColour = "Black";
    compKing = "Black King";
    }
    else{
        playerSide = BLACK;
	compSideColour = "White";
    compKing = "White King";
    }

    /*
     * test all squares for the computer colour and when found calculate all possible moves for piece 
     * save to a LinkedList that pointer list points to
     * extract and serialise weighted co-ordinates from list
     * insert co-ordinates into decision tree
     *
     */

        for (int e = 0; e < 8; e++) {
            for (int i = 0; i < 8; i++) {
                if (gameBoard.returnSquare(e, i).find(compSideColour) != std::string::npos) {
                    list = calc.possibleSquares2DArray(e, i, gameBoard, computerSide);
                    moveVector.clear();
                    if (list != nullptr){
                    moveVector = list->returnWeightedVector();
                    delete list;
                    }
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

    /*
     * create TreeNode pointer and point it to the head of moveTree
     * call function moveVector to extract and serialise co-ordinates in moveTree
     * keeping only those that are equal to the highest value of rank
     * test if tree returns more than one move/set of co-ordinates
     * pick at random which move to make from what was returned 
     *
     */

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
    
    /*
     * make Board object and use copy constructor to copy gameBoard
     * make selected move on testBoard
     * test testBoard for check against the computer if false load array move with co-ordinates for computers move
     *
     */

    int *move = new int[4];
    Board testBoard;
    testBoard = gameBoard;
    testBoard.setSquare(returnVector[choice+2], returnVector[choice+3],testBoard.returnSquare(returnVector[choice], returnVector[choice+1]));
    testBoard.setSquare(returnVector[choice], returnVector[choice+1], "Empty");
    int kingX, kingY;
    for(int e = 0; e < 8; e++){
        for(int i = 0; i < 8; i++)
        {
            if(testBoard.returnSquare(e,i) == compKing){
                kingX = e;
                kingY = i;
            }

        }
    }
    if(!calc.checkCalculator(kingX, kingY, testBoard, computerSide)){
        move[0] = returnVector[choice];
        move[1] = returnVector[choice + 1];
        move[2] = returnVector[choice + 2];
        move[3] = returnVector[choice + 3];
    }

    else{ // move results in check against computer

    /*
     * move TreeNode pointer to head of moveTree
     * clear the vector that was used by recursive function moveVector
     * pass secondGuess TreeNode pointer stepper to pull a move from
     * moveTree that has a lower value than base found in the input argument
     * of moveVector (not the maximum value for rank found in moveTree)
     *
     */


        stepper = moveTree->head;
        returnVector.clear();
        this->secondGuess(stepper);

        /*
         * set testBoard to be the same as gameBoard
         * make move on testBoard
         * search the board for computers king
         * test testBoard after move for computer being in check
         * if test is false fill move array with co-ordinates of move
         *
         */

        for(int i = 0; i < returnVector.size(); i=i+4){
            testBoard = gameBoard;
            testBoard.setSquare(returnVector[i+2], returnVector[i+3],testBoard.returnSquare(returnVector[i], returnVector[i+1]));
            testBoard.setSquare(returnVector[i], returnVector[i+1], "Empty");
            for (int e = 0; e < 8; e++){
                for (int i2 = 0; i2 < 8; i2++){
                    if (testBoard.returnSquare(e, i2) == compKing){
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
        }
    }
    

    /*
     * remove moveTree from heap
     * clear vector used in recursive functions
     * return pointer to move array
     *
     */

    delete moveTree;
    returnVector.clear();
    
    return move;

}

