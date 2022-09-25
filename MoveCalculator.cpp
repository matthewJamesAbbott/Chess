//
// Created by Matthew Abbott on 19/2/22.
//

#include <vector>
#include "MoveCalculator.h"
#include "Board.h"
#include <iostream>
#include <fstream>
#include <string>


#define PAWN 2
#define KNIGHT 3
#define BISHOP 4
#define ROOK 5
#define QUEEN 9
#define KING 10
#define EMPTY 0
#define BLACK 0
#define WHITE 1

/*
 * add node to list returned from possibleSquares2Darray function
 *
 */

void LinkedList::addNode(int x, int y, int squareRank){
    auto* newnode = new Node(); // create new node on heap
    newnode->x = x; // store squares numeric co-ordinate in list
    newnode->y = y; // store squares alpha co-ordinate in list
    newnode->squareRank= squareRank; // store pieces rank in list
    newnode->next = nullptr; // set Node pointer next to nullptr
    if (head == nullptr){ // test if head of list is empty if so make new node head
        head = newnode;
    }

    /*
     * else create Node pointer and point it to head
     * then step through list and insert node when next is nullptr
     *
     */

    else{ 
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

/*
 * serialise possibleSquares list into vector moveVector
 *
 */

std::vector<int> LinkedList::returnVector(){

    std::vector<int> moveVector;
    Node* temp = head;
    while (temp != nullptr){
        moveVector.push_back(temp->x);
        moveVector.push_back(temp->y);
        temp = temp->next;
    }
    
    return moveVector;
    

    
}

/*
 * serialise possibleSquares list into vector moveVector with piece weights included 
 *
 */

std::vector<int> LinkedList::returnWeightedVector(){
    Node* temp = head;
    std::vector<int> moveVector;
    while (temp != nullptr){
        moveVector.push_back(temp->x);
        moveVector.push_back(temp->y);
        moveVector.push_back(temp->squareRank);
        temp = temp->next;
    }
    return moveVector;
}

LinkedList::~LinkedList(){
    
    Node *temp;
    while (head){
        temp = head;
        head = temp->next;
        delete temp;
    }
}

MoveCalculator::MoveCalculator() = default; // default constructor for MoveCalculator

/*
 * evaluate square on moveBoard for pieces rank
 *
 */

int MoveCalculator::evaluatePiece(int x, int y, Board moveBoard, int side){
    if(side == WHITE) {
        if (moveBoard.returnSquare(x, y) == "Black Pawn") {
            return PAWN;
        } else if (moveBoard.returnSquare(x, y) == "Black Left Knight" ||
                   moveBoard.returnSquare(x, y) == "Black Right Knight") {
            return KNIGHT;
        } else if (moveBoard.returnSquare(x, y) == "Black Left Bishop" ||
                   moveBoard.returnSquare(x, y) == "Black Right Bishop") {
            return BISHOP;
        } else if (moveBoard.returnSquare(x, y) == "Black Left Rook" ||
                   moveBoard.returnSquare(x, y) == "Black Right Rook") {
            return ROOK;
        } else if (moveBoard.returnSquare(x, y) == "Black Queen") {
            return QUEEN;
        } else if (moveBoard.returnSquare(x, y) == "Black King") {
            return KING;
        } else if (moveBoard.returnSquare(x, y) == "Empty") {
            return EMPTY;
        }
    }
    else{
        if(moveBoard.returnSquare(x,y) == "White Pawn"){
            return PAWN;
        }
        else if(moveBoard.returnSquare(x,y) == "White Left Knight" || moveBoard.returnSquare(x,y) == "White Right Knight"){
            return KNIGHT;
        }
        else if(moveBoard.returnSquare(x,y) == "White Left Bishop" || moveBoard.returnSquare(x,y) == "White Right Bishop"){
            return BISHOP;
        }
        else if(moveBoard.returnSquare(x,y) == "White Left Rook" || moveBoard.returnSquare(x,y) == "White Right Rook"){
            return ROOK;
        }
        else if(moveBoard.returnSquare(x,y) == "White Queen"){
            return QUEEN;
        }
        else if(moveBoard.returnSquare(x,y) == "White King"){
            return KING;
        }
        else if(moveBoard.returnSquare(x,y) == "Empty"){
            return EMPTY;
        }
    }
}

/*
 * check if king or left rook has been moved
 * by looking through past moves in Chess.txt
 * return false if king or left rook has been moved
 * else return true to allow castle move to continue
 *
 */

bool MoveCalculator::castleCheck(int side){
    std::ifstream fileHandle;
    std::string line;
    fileHandle.open("Chess.txt");
    while(std::getline(fileHandle, line)){
        if(side == WHITE){
            if(line.find("(0,3") != std::string::npos || line.find("(0,0") != std::string::npos){
                fileHandle.close();
                return false;
            }
        }
        else if(side == BLACK){
            if(line.find("(7,3") != std::string::npos || line.find("(7,0") != std::string::npos){
                fileHandle.close();
                return false;
            }
        }
    }
    fileHandle.close();
    return true;
}

/*
 * check if oppositions pawn has moved two spaces from its starting
 * position in the last turn
 * return alpha co-ordinate on success and 10 on failure
 *
 */

int MoveCalculator::enPassantCheck(int side){
    std::ifstream fileHandle;
    std::string line;
    int turn = 0;
    fileHandle.open("Chess.txt");
    while(std::getline(fileHandle, line)){
        if(line.find("[") != std::string::npos)
            turn = line.at(1) - 48;
    }
    fileHandle.close();
    fileHandle.open("Chess.txt");
    while(std::getline(fileHandle, line)){
        if(line.find("[" + std::to_string(turn)) != std::string::npos){
            std::getline(fileHandle, line);
            break;
        }
    }
    if(line.empty() == 0){
        int x = line.at(1) - 48;
        int y = line.at(3) - 48;
        int xa = line.at(5) - 48;
        int ya = line.at(7) - 48;

        if (side == BLACK && x == 1 && xa == 3 && y == ya){
            return y;

        }
        if (side == WHITE && x == 6 && xa == 4 && y == ya){
            return y;
        }
    }
    return 10;
}

/*
 * calculate all possible moves for a piece at co-ordiantes passed to function
 * save co-ordinates in Linkedlist and return the list on completion
 *
 */

LinkedList *MoveCalculator::possibleSquares2DArray(int x, int y, Board moveBoard, int side){

    /*
     * extract string representation of piece
     * convert piece into numeric representation
     * evaluate each piece for rank then store the moves co-ordinates and rank in list
     * return list
     *
     */

    std::string piece = moveBoard.returnSquare(x,y);

    int switchedPiece = 0;
    if(piece.find("Rook") != std::string::npos)
        switchedPiece = 1;
    if(piece.find("Knight") != std::string::npos)
        switchedPiece = 2;
    if(piece.find("Bishop") != std::string::npos)
        switchedPiece = 3;
    if(piece.find("Queen") != std::string::npos)
        switchedPiece = 4;
    if(piece.find("King") != std::string::npos)
        switchedPiece = 5;
    if(piece == "White Pawn")
        switchedPiece = 6;
    if(piece == "Black Pawn")
        switchedPiece = 7;
    if(piece == "Empty")
        switchedPiece = 8;

    /*
     * create list to return on the heap
     * take input of piece and find possible moves from switch
     *
     */
    std::string opponentColour;
    if (side == BLACK)
        opponentColour = "White";
    else 
        opponentColour = "Black";

            int kingNumericStart = 0;
    auto* list = new LinkedList();
    switch(switchedPiece){
        case 1: // Rooks Moves
            for(int i = x + 1; i < 8; i++){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, side));
                else if(moveBoard.returnSquare(i,y).find(opponentColour) == 0){
                    list->addNode(i, y, this->evaluatePiece(i,y, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = x -1; i >= 0; i--){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, side));
                else if(moveBoard.returnSquare(i,y).find(opponentColour) == 0){
                    list->addNode(i, y,this->evaluatePiece(i,y, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = y +1; i < 8; i++){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, side));
                else if(moveBoard.returnSquare(x,i).find(opponentColour) == 0){
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            for(int i = y -1; i >= 0; i--){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, side));
                else if(moveBoard.returnSquare(x,i).find(opponentColour) == 0){
                    list->addNode(x, i, this->evaluatePiece(x,i, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            return list;
            
        case 2: // Knights Moves
            if(x < 6 && y < 7 && moveBoard.returnSquare(x+2, y+1) == "Empty")
                list->addNode(x+2,y+1, this->evaluatePiece(x+2,y+1, moveBoard, side));
            else if(x < 6 && y < 7 && (moveBoard.returnSquare(x+2,y+1).find(opponentColour) == 0))
                list->addNode(x+2,y+1, this->evaluatePiece(x+2, y+1, moveBoard, side));
            if(x < 6 && y > 0 && moveBoard.returnSquare(x+2, y-1) == "Empty")
                list->addNode(x+2,y-1, this->evaluatePiece(x+2, y-1, moveBoard, side));
            else if(x < 6 && y > 0 && (moveBoard.returnSquare(x+2,y-1).find(opponentColour) == 0))
                list->addNode(x+2,y-1, this->evaluatePiece(x+2, y-1, moveBoard, side));
            if(x < 7 && y < 6 && moveBoard.returnSquare(x+1, y+2) == "Empty")
                list->addNode(x+1,y+2, this->evaluatePiece(x+1, y+2, moveBoard, side));
            else if(x < 7 && y < 6 && (moveBoard.returnSquare(x+1,y+2).find(opponentColour) == 0))
                list->addNode(x+1,y+2, this->evaluatePiece(x+1, y+2, moveBoard, side));
            if(x < 7 && y > 1 && moveBoard.returnSquare(x+1, y-2) == "Empty")
                list->addNode(x+1,y-2, this->evaluatePiece(x+1, y-2, moveBoard, side));
            else if(x < 7 && y > 1 && (moveBoard.returnSquare(x+1,y-2).find(opponentColour) == 0))
                list->addNode(x+1,y-2, this->evaluatePiece(x+1, y-2, moveBoard, side));
            if(x > 1 && y < 7 && moveBoard.returnSquare(x-2, y+1) == "Empty")
                list->addNode(x-2,y+1, this->evaluatePiece(x-2, y+1, moveBoard, side));
            else if(x > 1 && y < 7 && (moveBoard.returnSquare(x-2,y+1).find(opponentColour) == 0))
                list->addNode(x-2,y+1, this->evaluatePiece(x-2,y+1, moveBoard, side));
            if(x > 1 && y > 0 && moveBoard.returnSquare(x-2, y-1) == "Empty")
                list->addNode(x-2,y-1, this->evaluatePiece(x-2, y-1, moveBoard, side));
            else if(x > 1 && y > 0 && (moveBoard.returnSquare(x-2,y-1).find(opponentColour) == 0))
                list->addNode(x-2,y-1, this->evaluatePiece(x-2, y-1, moveBoard, side));
            if(x > 0 && y < 6 && moveBoard.returnSquare(x-1, y+2) == "Empty")
                list->addNode(x-1,y+2, this->evaluatePiece(x-1, y+2, moveBoard, side));
            else if(x > 0 && y < 6 && (moveBoard.returnSquare(x-1,y+2).find(opponentColour) == 0))
                list->addNode(x-1,y+2, this->evaluatePiece(x-1, y+2, moveBoard, side));
            if(x > 0 && y > 1 && moveBoard.returnSquare(x-1, y-2) == "Empty")
                list->addNode(x-1,y-2, this->evaluatePiece(x-2, y-2, moveBoard, side));
            else if(x > 0 && y > 1 && (moveBoard.returnSquare(x-1,y-2).find(opponentColour) == 0))
                list->addNode(x-1,y-2, this->evaluatePiece(x-1, y-2, moveBoard, side));
            return list;

        case 3: // Bishops Moves
            for(int e = x+1, i = y+1;e < 8 && i < 8; e++, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                else if (moveBoard.returnSquare(e,i).find(opponentColour) == 0){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x+1, i = y-1;e < 8 && i >= 0; e++, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                else if (moveBoard.returnSquare(e,i).find(opponentColour) == 0){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y+1;e >= 0 && i < 8;e--, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                else if (moveBoard.returnSquare(e,i).find(opponentColour) == 0){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y-1;e >= 0 && i >= 0;e--, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                else if (moveBoard.returnSquare(e,i).find(opponentColour) == 0){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            return list;
            
        case 4: // Queens Moves
            for(int i = x + 1; i < 8; i++){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i, y, moveBoard, side));
                else if(moveBoard.returnSquare(i,y).find(opponentColour) == 0){
                    list->addNode(i, y, this->evaluatePiece(i, y, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = x -1; i >= 0; i--){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, side));
                else if(moveBoard.returnSquare(i,y).find(opponentColour) == 0){
                    list->addNode(i, y, this->evaluatePiece(i, y, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }

            for(int i = y +1; i < 8; i++){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x, i, moveBoard, side));
                else if(moveBoard.returnSquare(x,i).find(opponentColour) == 0){
                    list->addNode(x, i, this->evaluatePiece(x, i, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            for(int i = y -1; i >= 0; i--){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x, i, moveBoard, side));
                else if(moveBoard.returnSquare(x,i).find(opponentColour) == 0){
                    list->addNode(x, i, this->evaluatePiece(x, i, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            for(int e = x+1, i = y+1;e < 8 && i < 8; e++, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                else if (moveBoard.returnSquare(e,i).find(opponentColour) == 0){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x+1, i = y-1;e < 8 && i >= 0; e++, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                else if (moveBoard.returnSquare(e,i).find(opponentColour) == 0){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y+1;e >= 0 && i < 8;e--, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                else if (moveBoard.returnSquare(e,i).find(opponentColour) == 0){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y-1;e >= 0 && i >= 0;e--, i--){
                if (moveBoard.returnSquare(e, i) == "Empty")
                    list->addNode(e, i, this->evaluatePiece(e, i, moveBoard, side));
                else if (moveBoard.returnSquare(e, i).find(opponentColour) == 0){
                    list->addNode(e, i, this->evaluatePiece(e, i, moveBoard, side));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            return list;
        
        case 5: // Kings Moves
            if (side == 0)
                kingNumericStart = 7;
            if(x < 7 && moveBoard.returnSquare(x+1,y) == "Empty")
                list->addNode(x+1, y, this->evaluatePiece(x+1, y, moveBoard, side));
            else if(x < 7 &&(moveBoard.returnSquare(x+1,y).find(opponentColour) == 0))
                list->addNode(x+1,y, evaluatePiece(x+1,y, moveBoard, side));
            if(x > 0 && moveBoard.returnSquare(x-1,y) == "Empty")
                list->addNode(x-1,y, evaluatePiece(x-1, y, moveBoard, side));
            else if(x > 0 && (moveBoard.returnSquare(x-1,y).find(opponentColour) == 0))
                list->addNode(x-1,y, this->evaluatePiece(x-1,y, moveBoard, side));
            if(y < 7 && moveBoard.returnSquare(x,y+1) == "Empty")
                list->addNode(x,y+1, this->evaluatePiece(x,y+1, moveBoard, side));
            else if(y < 7 && (moveBoard.returnSquare(x,y+1).find(opponentColour) == 0))
                list->addNode(x,y+1, this->evaluatePiece(x,y+1, moveBoard, side));
            if(y > 0 && moveBoard.returnSquare(x,y-1) == "Empty")
                list->addNode(x,y-1, this->evaluatePiece(x,y-1, moveBoard, side));
            else if(y > 0 && (moveBoard.returnSquare(x,y-1).find(opponentColour) == 0))
                list->addNode(x,y-1, this->evaluatePiece(x,y-1, moveBoard, side));
            if(x < 7 && y < 7 && moveBoard.returnSquare(x+1,y+1) == "Empty")
                list->addNode(x+1,y+1, this->evaluatePiece(x+1,y+1, moveBoard, side));
            else if(x < 7 && y < 7 && (moveBoard.returnSquare(x+1,y+1).find(opponentColour) == 0))
                list->addNode(x+1,y+1, this->evaluatePiece(x+1,y+1, moveBoard, side));
            if(x < 7 && y > 0 && moveBoard.returnSquare(x+1,y-1) == "Empty")
                list->addNode(x+1,y-1, this->evaluatePiece(x+1,y-1, moveBoard, side));
            else if(x < 7 && y > 0 && (moveBoard.returnSquare(x+1,y-1).find(opponentColour) == 0))
                list->addNode(x+1,y-1, this->evaluatePiece(x+1,y-1, moveBoard, side));
            if(x > 0 && y < 7 && moveBoard.returnSquare(x-1,y+1) == "Empty")
                list->addNode(x-1,y+1, this->evaluatePiece(x-1,y+1, moveBoard, side));
            else if(x > 0 && y < 7 && (moveBoard.returnSquare(x-1,y+1).find(opponentColour) == 0))
                list->addNode(x-1,y+1, this->evaluatePiece(x-1,y+1, moveBoard, side));
            if(x > 0 && y > 0 && moveBoard.returnSquare(x-1,y-1) == "Empty")
                list->addNode(x-1,y-1, this->evaluatePiece(x-1,y-1, moveBoard, side));
            else if(x > 0 && y > 0 && (moveBoard.returnSquare(x-1,y-1).find(opponentColour) == 0))
                list->addNode(x-1,y-1, this->evaluatePiece(x-1,y-1, moveBoard, side));
            if (this->castleCheck(side) && moveBoard.returnSquare(kingNumericStart,1) == "Empty" && moveBoard.returnSquare(kingNumericStart,2) == "Empty")
                list->addNode(x,y-2,side);
            return list;

        case 6: // White Pawn Moves
            if(side == WHITE) {
                if (x != 7 && moveBoard.returnSquare(x + 1, y) == "Empty")
                    list->addNode(x + 1, y, this->evaluatePiece(x + 1, y, moveBoard, WHITE));
                if (x == 1 && moveBoard.returnSquare(x + 1, y) == "Empty" &&
                    moveBoard.returnSquare(x + 2, y) == "Empty")
                    list->addNode(x + 2, y, this->evaluatePiece(x + 2, y, moveBoard, WHITE));
                if (x != 7 && y != 7 && (moveBoard.returnSquare(x + 1, y + 1).find("Black") == 0))
                    list->addNode(x + 1, y + 1, this->evaluatePiece(x + 1, y + 1, moveBoard, WHITE));
                if (x != 7 && y != 0 && (moveBoard.returnSquare(x + 1, y - 1).find("Black") == 0))
                    list->addNode(x + 1, y - 1, this->evaluatePiece(x + 1, y - 1, moveBoard, WHITE));
            }
            return list;
 
        case 7: // Black Pawn Moves
            if(side == BLACK) {
                if (x != 0 && moveBoard.returnSquare(x - 1, y) == "Empty")
                    list->addNode(x - 1, y, this->evaluatePiece(x - 1, y, moveBoard, BLACK));
                if (x == 6 && moveBoard.returnSquare(x - 1, y) == "Empty" &&
                    moveBoard.returnSquare(x - 2, y) == "Empty")
                    list->addNode(x - 2, y, this->evaluatePiece(x - 2, y, moveBoard, BLACK));
                if (x != 0 && y != 7 && moveBoard.returnSquare(x - 1, y + 1).find(opponentColour) == 0)
                    list->addNode(x - 1, y + 1, this->evaluatePiece(x - 1, y + 1, moveBoard, BLACK));
                if (x != 0 && y != 0 && moveBoard.returnSquare(x - 1, y - 1).find(opponentColour) == 0)
                    list->addNode(x - 1, y - 1, this->evaluatePiece(x - 1, y - 1, moveBoard, BLACK));
                if (x == 3 && this->enPassantCheck(BLACK) != 10)
                    list->addNode(x - 1, this->enPassantCheck(BLACK), 2);
            }
                return list;
            
       case 8: // Empty Square
            return nullptr;
            
    }
}

/*
 * test gameBoard for checkmate of the colour passed argument side
 * return false if not in checkmate and continue game or return true and end game if in checkmate
 *
 */

bool MoveCalculator::checkMateTest(Board gameBoard, int side){
    Board testBoard = gameBoard;
    LinkedList *temp;
    std::vector<int> returnedVector;
    int kingX;
    int kingY;
    std::string sideColour;
    std::string sideKing;
    if (side == 0){
        sideColour = "Black";
        sideKing = "Black King";
    }
    else{
        sideColour = "White";
        sideKing = "White King";
    }
        for (int e = 0; e < 8; e++){
            for (int i = 0; i < 8; i++){
                if (gameBoard.returnSquare(e, i).find(sideColour) == 0){
                    temp = possibleSquares2DArray(e, i, gameBoard, side);
                    if (temp != nullptr){
                        returnedVector = temp->returnVector();
                        delete temp;
                    }
                    for (int k = 0; k < returnedVector.size() / 2; k=k+2){
                        testBoard = gameBoard;
                        int a = returnedVector[k];
                        int b = returnedVector[k + 1];
                        testBoard.setSquare(a, b, testBoard.returnSquare(e, i));
                        testBoard.setSquare(e, i, "Empty");
                        for (int e2 = 0; e2 < 8; e2++){
                            for (int i2 = 0; i2 < 8; i2++){
                                if (testBoard.returnSquare(e2, i2) == sideKing){
                                    kingX = e2;
                                    kingY = i2;
                                }
                            }
                        }
                        if (!this->checkCalculator(kingX, kingY, testBoard, side)){
                            return false;
                        }
                    }
                }
            }
        }
    return true;
}

/*
 * check if co-ordinates on moveBoard can be attacked by the oposition in the next turn
 * return true if co-ordinates can be attacked and false if they are not
 */

bool MoveCalculator::checkCalculator(int x, int y, Board moveBoard, int side){
    LinkedList *temp;
    std::vector<int> moveVector;
    std::vector<int> returnedVector;
    std::string opponentColour;
    int opponentSide;;

    if(side == BLACK){
        opponentSide = WHITE;
        opponentColour = "White";
    }
    else{
        opponentSide = BLACK;
        opponentColour = "Black";
    }
        for (int e = 0; e < 8; e++){
            for (int i = 0; i < 8; i++){
                if (moveBoard.returnSquare(e, i).find(opponentColour) == 0){
                    temp = possibleSquares2DArray(e, i, moveBoard, opponentSide);
                    if (temp != nullptr){
                        returnedVector = temp->returnVector();
                        delete temp;
                    }
                    moveVector.insert(moveVector.end(), returnedVector.begin(), returnedVector.end());
                }
            }
        }
    for(int k = 0; k < moveVector.size(); k=k+2){
        int a = moveVector[k];
        int b = moveVector[k+1];
        if(x == a && y == b){
            std::cout << "check baby !!!" << std::endl;
            moveVector.clear();
            return true;
        }
    }
    moveVector.clear();
    return false;
}

