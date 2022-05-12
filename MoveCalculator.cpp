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

void LinkedList::addNode(int x, int y, int squareRank){
    auto* newnode = new Node();
    newnode->x = x;
    newnode->y = y;
    newnode->squareRank= squareRank;
    newnode->next = nullptr;
    if (head == nullptr){
        head = newnode;
    }
    else{
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

std::vector<int> LinkedList::returnVector(){
    Node* temp = head;
    std::vector<int> moveVector;
    while (temp != nullptr){
        moveVector.push_back(temp->x);
        moveVector.push_back(temp->y);
        temp = temp->next;
    }
    return moveVector;
}

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

LinkedList::~LinkedList() = default;

MoveCalculator::MoveCalculator() = default;

int MoveCalculator::evaluatePiece(int x, int y, Board moveBoard, int side){
    if(side == 1) {
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

bool MoveCalculator::castleCheck(int side){
    std::ifstream fileHandle;
    std::string line;
    fileHandle.open("Chess.txt");
    while(std::getline(fileHandle, line)){
        if(side == 1){
            if(!line.find("(0,3") || !line.find("(0,0")){
                fileHandle.close();
                return false;
            }
        }
        else if(side == 0){
            if(!line.find("(7,3") || !line.find("(7,0")){
                fileHandle.close();
                return false;
            }
        }
    }
    fileHandle.close();
    return true;
}

int MoveCalculator::enPassantCheck(int side){
    std::ifstream fileHandle;
    std::string line;
    int turn = 0;
    fileHandle.open("Chess.txt");
    while(std::getline(fileHandle, line)){
        if(!line.find("["))
            turn = line.at(1) - 48;
    }
    fileHandle.close();
    fileHandle.open("Chess.txt");
    while(std::getline(fileHandle, line)){
        if(!line.find("[" + std::to_string(turn))){
            std::getline(fileHandle, line);
            break;
        }
    }
    if(line.empty() == 0){
        int x = line.at(1) - 48;
        int y = line.at(3) - 48;
        int xa = line.at(5) - 48;
        int ya = line.at(7) - 48;

        if (side == 0 && x == 1 && xa == 3 && y == ya){
            return y;

        }
        if (side == 1 && x == 6 && xa == 4 && y == ya){
            return y;
        }
    }
    return 10;
}


LinkedList *MoveCalculator::possibleSquares2DArray(int x, int y, Board moveBoard, int side){
    std::string piece = moveBoard.returnSquare(x,y);
    int switchedPiece = 0;
    if(piece == "White Left Rook")
        switchedPiece = 1;
    if(piece == "White Left Knight")
        switchedPiece = 2;
    if(piece == "White Left Bishop")
        switchedPiece = 3;
    if(piece == "White Queen")
        switchedPiece = 4;
    if(piece == "White King")
        switchedPiece = 5;
    if(piece == "White Right Bishop")
        switchedPiece = 6;
    if(piece == "White Right Knight")
        switchedPiece = 7;
    if(piece == "White Right Rook")
        switchedPiece = 8;
    if(piece == "White Pawn")
        switchedPiece = 9;
    if(piece == "Black Left Rook")
        switchedPiece = 10;
    if(piece == "Black Left Knight")
        switchedPiece = 11;
    if(piece == "Black Left Bishop")
        switchedPiece = 12;
    if(piece == "Black Queen")
        switchedPiece = 13;
    if(piece == "Black King")
        switchedPiece = 14;
    if(piece == "Black Right Bishop")
        switchedPiece = 15;
    if(piece == "Black Right Knight")
        switchedPiece = 16;
    if(piece == "Black Right Rook")
        switchedPiece = 17;
    if(piece == "Black Pawn")
        switchedPiece = 18;
    if(piece == "Empty")
        switchedPiece = 19;
    auto* list = new LinkedList();
    switch(switchedPiece){
        case 1: // White Left Rook Moves
            for(int i = x + 1; i < 8; i++){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, 1));
                else if((x < 8) && (!moveBoard.returnSquare(i,y).find("Black"))){
                    list->addNode(i, y, this->evaluatePiece(i,y, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = x -1; i >= 0; i--){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, 1));
                else if((x >= 0 ) && (!moveBoard.returnSquare(i,y).find("Black"))){
                    list->addNode(i, y,this->evaluatePiece(i,y, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = y +1; i < 8; i++){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, 1));
                else if((x >= 0 ) && (!moveBoard.returnSquare(x,i).find("Black"))){
                    list->addNode(x, i, this->evaluatePiece(x,i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            for(int i = y -1; i >= 0; i--){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, 1));
                else if((x >= 0 ) && (!moveBoard.returnSquare(x,i).find("Black"))){
                    list->addNode(x, i, this->evaluatePiece(x,i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            return list;

        case 2: // White Left Knight Moves
            if(x < 6 && y < 7 && moveBoard.returnSquare(x+2, y+1) == "Empty")
                list->addNode(x+2,y+1, this->evaluatePiece(x+2,y+1, moveBoard, 1));
            else if(x < 6 && y < 7 && (!moveBoard.returnSquare(x+2,y+1).find("Black")))
                list->addNode(x+2,y+1, this->evaluatePiece(x+2, y+1, moveBoard, 1));
            if(x < 6 && y > 0 && moveBoard.returnSquare(x+2, y-1) == "Empty")
                list->addNode(x+2,y-1, this->evaluatePiece(x+2, y-1, moveBoard, 1));
            else if(x < 6 && y > 0 && (!moveBoard.returnSquare(x+2,y-1).find("Black")))
                list->addNode(x+2,y-1, this->evaluatePiece(x+2, y-1, moveBoard, 1));
            if(x < 7 && y < 6 && moveBoard.returnSquare(x+1, y+2) == "Empty")
                list->addNode(x+1,y+2, this->evaluatePiece(x+1, y+2, moveBoard, 1));
            else if(x < 7 && y < 6 && (!moveBoard.returnSquare(x+1,y+2).find("Black")))
                list->addNode(x+1,y+2, this->evaluatePiece(x+1, y+2, moveBoard,1 ));
            if(x < 7 && y > 1 && moveBoard.returnSquare(x+1, y-2) == "Empty")
                list->addNode(x+1,y-2, this->evaluatePiece(x+1, y-2, moveBoard, 1));
            else if(x < 7 && y > 1 && (!moveBoard.returnSquare(x+1,y-2).find("Black")))
                list->addNode(x+1,y-2, this->evaluatePiece(x+1, y-2, moveBoard, 1));
            if(x > 1 && y < 7 && moveBoard.returnSquare(x-2, y+1) == "Empty")
                list->addNode(x-2,y+1, this->evaluatePiece(x-2, y+1, moveBoard, 1));
            else if(x > 1 && y < 7 && (!moveBoard.returnSquare(x-2,y+1).find("Black")))
                list->addNode(x-2,y+1, this->evaluatePiece(x-2,y+1, moveBoard, 1));
            if(x > 1 && y < 0 && moveBoard.returnSquare(x-2, y-1) == "Empty")
                list->addNode(x-2,y-1, this->evaluatePiece(x-2, y-1, moveBoard, 1));
            else if(x > 1 && y > 0 && (!moveBoard.returnSquare(x-2,y-1).find("Black")))
                list->addNode(x-2,y-1, this->evaluatePiece(x-2, y-1, moveBoard, 1));
            if(x > 0 && y < 6 && moveBoard.returnSquare(x-1, y+2) == "Empty")
                list->addNode(x-1,y+2, this->evaluatePiece(x-1, y+2, moveBoard, 1));
            else if(x > 0 && y < 6 && (!moveBoard.returnSquare(x-1,y+2).find("Black")))
                list->addNode(x-1,y+2, this->evaluatePiece(x-1, y+2, moveBoard, 1));
            if(x > 0 && y > 1 && moveBoard.returnSquare(x-1, y-2) == "Empty")
                list->addNode(x-1,y-2, this->evaluatePiece(x-2, y-2, moveBoard, 1));
            else if(x > 0 && y > 1 && (!moveBoard.returnSquare(x-1,y-2).find("Black")))
                list->addNode(x-1,y-2, this->evaluatePiece(x-1, y-2, moveBoard, 1));
            return list;

        case 3: // White Left Bishop Moves
            for(int e = x+1, i = y+1;e < 8 && i < 8; e++, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("Black"))){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x+1, i = y-1;e < 8 && i >= 0; e++, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("Black"))){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y+1;e >= 0 && i < 8;e--, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("Black"))){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y-1;e >= 0 && i >= 0;e--, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(x, i, moveBoard, 1));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("Black"))){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            return list;

        case 4: // White Queen Moves
            for(int i = x + 1; i < 8; i++){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i, y, moveBoard, 1));
                else if((x < 8) && (!moveBoard.returnSquare(i,y).find("Black"))){
                    list->addNode(i, y, this->evaluatePiece(i, y, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = x -1; i >= 0; i--){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, 1));
                else if((x >= 0 ) && (!moveBoard.returnSquare(i,y).find("Black"))){
                    list->addNode(i, y, this->evaluatePiece(i, y, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }

            for(int i = y +1; i < 8; i++){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x, i, moveBoard, 1));
                else if((x >= 0 ) && (!moveBoard.returnSquare(x,i).find("Black"))){
                    list->addNode(x, i, this->evaluatePiece(x, i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            for(int i = y -1; i >= 0; i--){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x, i, moveBoard, 1));
                else if((x >= 0 ) && (!moveBoard.returnSquare(x,i).find("Black"))){
                    list->addNode(x, i, this->evaluatePiece(x, i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            for(int e = x+1, i = y+1;e < 8 && i < 8; e++, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("Black"))){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x+1, i = y-1;e < 8 && i >= 0; e++, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                else if (e < 8 && i >=0 && (!moveBoard.returnSquare(e,i).find("Black"))){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y+1;e >= 0 && i < 8;e--, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                else if ( e >= 0 && i < 8 && (!moveBoard.returnSquare(e,i).find("Black"))){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y-1;e >= 0 && i >= 0;e--, i--){
                if (moveBoard.returnSquare(e, i) == "Empty")
                    list->addNode(e, i, this->evaluatePiece(e, i, moveBoard, 1));
                else if (e > 0 && i > 0 && (!moveBoard.returnSquare(e, i).find("Black"))){
                    list->addNode(e, i, this->evaluatePiece(e, i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            return list;

        case 5: // White King Moves
            if(x < 7 && moveBoard.returnSquare(x+1,y) == "Empty")
                list->addNode(x+1, y, this->evaluatePiece(x+1, y, moveBoard, 1));
            else if(x < 7 &&(!moveBoard.returnSquare(x+1,y).find("Black")))
                list->addNode(x+1,y, evaluatePiece(x+1,y, moveBoard, 1));
            if(x > 0 && moveBoard.returnSquare(x-1,y) == "Empty")
                list->addNode(x-1,y, evaluatePiece(x-1, y, moveBoard, 1));
            else if(x > 0 && (!moveBoard.returnSquare(x-1,y).find("Black")))
                list->addNode(x-1,y, this->evaluatePiece(x-1,y, moveBoard, 1));
            if(y < 7 && moveBoard.returnSquare(x,y+1) == "Empty")
                list->addNode(x,y+1, this->evaluatePiece(x,y+1, moveBoard, 1));
            else if(y < 8 && (!moveBoard.returnSquare(x,y+1).find("Black")))
                list->addNode(x,y+1, this->evaluatePiece(x,y+1, moveBoard, 1));
            if(y > 0 && moveBoard.returnSquare(x,y-1) == "Empty")
                list->addNode(x,y-1, this->evaluatePiece(x,y-1, moveBoard, 1));
            else if(y > 0 && (!moveBoard.returnSquare(x,y-1).find("Black")))
                list->addNode(x,y-1, this->evaluatePiece(x,y-1, moveBoard, 1));
            if(x < 7 && y < 8 && moveBoard.returnSquare(x+1,y+1) == "Empty")
                list->addNode(x+1,y+1, this->evaluatePiece(x+1,y+1, moveBoard, 1));
            else if(x < 7 && y < 8 && (!moveBoard.returnSquare(x+1,y+1).find("Black")))
                list->addNode(x+1,y+1, this->evaluatePiece(x+1,y+1, moveBoard, 1));
            if(x < 7 && y > 0 && moveBoard.returnSquare(x+1,y-1) == "Empty")
                list->addNode(x+1,y-1, this->evaluatePiece(x+1,y-1, moveBoard, 1));
            else if(x < 7 && y > 0 && (!moveBoard.returnSquare(x+1,y-1).find("Black")))
                list->addNode(x+1,y-1, this->evaluatePiece(x+1,y-1, moveBoard, 1));
            if(x > 0 && y < 8 && moveBoard.returnSquare(x-1,y+1) == "Empty")
                list->addNode(x-1,y+1, this->evaluatePiece(x-1,y+1, moveBoard, 1));
            else if(x > 0 && y < 8 && (!moveBoard.returnSquare(x-1,y+1).find("Black")))
                list->addNode(x-1,y+1, this->evaluatePiece(x-1,y+1, moveBoard, 1));
            if(x > 0 && y > 0 && moveBoard.returnSquare(x-1,y-1) == "Empty")
                list->addNode(x-1,y-1, this->evaluatePiece(x-1,y-1, moveBoard, 1));
            else if(x > 0 && y > 0 && (!moveBoard.returnSquare(x-1,y-1).find("Black")))
                list->addNode(x-1,y-1, this->evaluatePiece(x-1,y-1, moveBoard, 1));
            else if(this->castleCheck(1) && moveBoard.returnSquare(1,1) == "Empty" && moveBoard.returnSquare(1,2) == "Empty")
                list->addNode(x,y-2,1);
            return list;

        case 6: // White Right Bishop Moves
            for(int e = x+1, i = y+1;e < 8 && i < 8; e++, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("Black"))){
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x+1, i = y-1;e < 8 && i >= 0; e++, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e, i, moveBoard, 1));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("Black"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y+1;e >= 0 && i < 8;e--, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 1));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("Black"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y-1;e >= 0 && i >= 0;e--, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 1));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("Black"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            return list;

        case 7: // White Right Knight Moves
            if(x < 6 && y < 7 && moveBoard.returnSquare(x+2, y+1) == "Empty")
                list->addNode(x+2,y+1, this->evaluatePiece(x+2,y+1,moveBoard, 1));
            else if(x < 6 && y < 7 && (!moveBoard.returnSquare(x+2,y+1).find("Black")))
                list->addNode(x+2,y+1, this->evaluatePiece(x+2,y+1, moveBoard, 1));
            if(x < 6 && y > 0 && moveBoard.returnSquare(x+2, y-1) == "Empty")
                list->addNode(x+2,y-1, this->evaluatePiece(x+2,y-1, moveBoard, 1));
            else if(x < 6 && y > 0 && (!moveBoard.returnSquare(x+2,y-1).find("Black")))
                list->addNode(x+2,y-1, this->evaluatePiece(x+2,y-1, moveBoard, 1));
            if(x < 7 && y < 6 && moveBoard.returnSquare(x+1, y+2) == "Empty")
                list->addNode(x+1,y+2, this->evaluatePiece(+1,y+2, moveBoard, 1));
            else if(x < 7 && y < 6 && (!moveBoard.returnSquare(x+1,y+2).find("Black")))
                list->addNode(x+1,y+2, this->evaluatePiece(x+1,y+2, moveBoard, 1));
            if(x < 7 && y > 1 && moveBoard.returnSquare(x+1, y-2) == "Empty")
                list->addNode(x+1,y-2, this->evaluatePiece(x+1,y-2, moveBoard, 1));
            else if(x < 7 && y > 1 && (!moveBoard.returnSquare(x+1,y-2).find("Black")))
                list->addNode(x+1,y-2, this->evaluatePiece(x+1,y-2, moveBoard, 1));
            if(x > 1 && y < 7 && moveBoard.returnSquare(x-2, y+1) == "Empty")
                list->addNode(x-2,y+1, this->evaluatePiece(x-2,y+1, moveBoard, 1));
            else if(x > 1 && y < 7 && (!moveBoard.returnSquare(x-2,y+1).find("Black")))
                list->addNode(x-2,y+1, this->evaluatePiece(x-2,y+1, moveBoard, 1));
            if(x > 1 && y < 0 && moveBoard.returnSquare(x-2, y-1) == "Empty")
                list->addNode(x-2,y-1, this->evaluatePiece(x-2,y-1, moveBoard, 1));
            else if(x > 1 && y > 0 && (!moveBoard.returnSquare(x-2,y-1).find("Black")))
                list->addNode(x-2,y-1, this->evaluatePiece(x-2,y-1, moveBoard, 1));
            if(x > 0 && y < 6 && moveBoard.returnSquare(x-1, y+2) == "Empty")
                list->addNode(x-1,y+2, this->evaluatePiece(x-1,y+2, moveBoard, 1));
            else if(x > 0 && y < 6 && (!moveBoard.returnSquare(x-1,y+2).find("Black")))
                list->addNode(x-1,y+2, this->evaluatePiece(x-1, y+2, moveBoard, 1));
            if(x > 0 && y > 1 && moveBoard.returnSquare(x-1, y-2) == "Empty")
                list->addNode(x-1,y-2, this->evaluatePiece(x-1,y-2, moveBoard, 1));
            else if(x > 0 && y > 1 && (!moveBoard.returnSquare(x-1,y-2).find("Black")))
                list->addNode(x-1,y-2, this->evaluatePiece(x-1,y-2, moveBoard, 1));
            return list;


        case 8: // White Right Rook Moves
            for(int i = x + 1; i < 8; i++){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, 1));
                else if((x < 8) && (!moveBoard.returnSquare(i,y).find("Black"))){
                    list->addNode(i, y, this->evaluatePiece(i,y, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = x -1; i >= 0; i--){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, 1));
                else if((x >= 0 ) && (!moveBoard.returnSquare(i,y).find("Black"))){
                    list->addNode(i, y, this->evaluatePiece(i,y, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = y +1; i < 8; i++){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, 1));
                else if((x >= 0 ) && (!moveBoard.returnSquare(x,i).find("Black"))){
                    list->addNode(x, i, this->evaluatePiece(x,i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            for(int i = y -1; i >= 0; i--){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, 1));
                else if((x >= 0 ) && (!moveBoard.returnSquare(x,i).find("Black"))){
                    list->addNode(x, i, this->evaluatePiece(x,i, moveBoard, 1));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            return list;

        case 9: // White Pawn Moves
            if(side == 0) {
                if (x != 7 && moveBoard.returnSquare(x + 1, y) == "Empty")
                    list->addNode(x + 1, y, this->evaluatePiece(x + 1, y, moveBoard, 1));
                if (x == 1 && moveBoard.returnSquare(x + 1, y) == "Empty" &&
                    moveBoard.returnSquare(x + 2, y) == "Empty")
                    list->addNode(x + 2, y, this->evaluatePiece(x + 2, y, moveBoard, 1));
                if (x != 7 && y != 7 && (!moveBoard.returnSquare(x + 1, y + 1).find("Black")))
                    list->addNode(x + 1, y + 1, this->evaluatePiece(x + 1, y + 1, moveBoard, 1));
                if (x != 7 && y != 0 && (!moveBoard.returnSquare(x + 1, y - 1).find("Black")))
                    list->addNode(x + 1, y - 1, this->evaluatePiece(x + 1, y - 1, moveBoard, 1));
            }
            else{
                if (x != 0 && moveBoard.returnSquare(x - 1, y) == "Empty")
                    list->addNode(x - 1, y, this->evaluatePiece(x - 1, y, moveBoard, 1));
                if (x == 6 && moveBoard.returnSquare(x - 1, y) == "Empty" &&
                    moveBoard.returnSquare(x - 2, y) == "Empty")
                    list->addNode(x - 2, y, this->evaluatePiece(x - 2, y, moveBoard, 1));
                if (x != 0 && y != 7 && moveBoard.returnSquare(x - 1, y + 1) != "Empty")
                    list->addNode(x - 1, y + 1, this->evaluatePiece(x - 1, y + 1, moveBoard, 1));
                if (x != 0 && y != 0 && moveBoard.returnSquare(x - 1, y - 1) != "Empty")
                    list->addNode(x - 1, y - 1, this->evaluatePiece(x - 1, y - 1, moveBoard, 1));
            }
            return list;

        case 10: // Black Left Rook Moves
            for(int i = x + 1; i < 8; i++){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, 0));
                else if((x < 8) && (!moveBoard.returnSquare(i,y).find("White"))){
                    list->addNode(i, y, this->evaluatePiece(i,y, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = x -1; i >= 0; i--){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, 0));
                else if((x >= 0 ) && (!moveBoard.returnSquare(i,y).find("White"))){
                    list->addNode(i, y, this->evaluatePiece(i,y, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = y +1; i < 8; i++){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, 0));
                else if((x >= 0 ) && (!moveBoard.returnSquare(x,i).find("White"))){
                    list->addNode(x, i, this->evaluatePiece(x,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            for(int i = y -1; i >= 0; i--){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, 0));
                else if((x >= 0 ) && (!moveBoard.returnSquare(x,i).find("White"))){
                    list->addNode(x, i, this->evaluatePiece(x,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            return list;

        case 11: // Black Left Knight Moves
            if(x < 6 && y < 7 && moveBoard.returnSquare(x+2, y+1) == "Empty")
                list->addNode(x+2,y+1, this->evaluatePiece(x+2,y+1, moveBoard, 0));
            else if(x < 6 && y < 7 && (!moveBoard.returnSquare(x+2,y+1).find("White")))
                list->addNode(x+2,y+1, this->evaluatePiece(x+2,y+1, moveBoard, 0));
            if(x < 6 && y > 0 && moveBoard.returnSquare(x+2, y-1) == "Empty")
                list->addNode(x+2,y-1, this->evaluatePiece(x+2,y-1, moveBoard, 0));
            else if(x < 6 && y > 0 && (!moveBoard.returnSquare(x+2,y-1).find("White")))
                list->addNode(x+2,y-1, this->evaluatePiece(x+2,y-1, moveBoard, 0));
            if(x < 7 && y < 6 && moveBoard.returnSquare(x+1, y+2) == "Empty")
                list->addNode(x+1,y+2, this->evaluatePiece(x+1,y+2, moveBoard, 0));
            else if(x < 7 && y < 6 && (!moveBoard.returnSquare(x+1,y+2).find("White")))
                list->addNode(x+1,y+2, this->evaluatePiece(x+1,y+2, moveBoard, 0));
            if(x < 7 && y > 1 && moveBoard.returnSquare(x+1, y-2) == "Empty")
                list->addNode(x+1,y-2, this->evaluatePiece(x+1,y-2, moveBoard, 0));
            else if(x < 7 && y > 1 && (!moveBoard.returnSquare(x+1,y-2).find("White")))
                list->addNode(x+1,y-2, this->evaluatePiece(x+1,y-2, moveBoard, 0));
            if(x > 1 && y < 7 && moveBoard.returnSquare(x-2, y+1) == "Empty")
                list->addNode(x-2,y+1, this->evaluatePiece(x-2,y+1, moveBoard, 0));
            else if(x > 1 && y < 7 && (!moveBoard.returnSquare(x-2,y+1).find("White")))
                list->addNode(x-2,y+1, this->evaluatePiece(x-2,y+1, moveBoard, 0));
            if(x > 1 && y > 0 && moveBoard.returnSquare(x-2, y-1) == "Empty")
                list->addNode(x-2,y-1, this->evaluatePiece(x-2,y-1, moveBoard, 0));
            else if(x > 1 && y > 0 && (!moveBoard.returnSquare(x-2,y-1).find("White")))
                list->addNode(x-2,y-1, this->evaluatePiece(x-2,y-1, moveBoard, 0));
            if(x > 0 && y < 6 && moveBoard.returnSquare(x-1, y+2) == "Empty")
                list->addNode(x-1,y+2, this->evaluatePiece(x-1,y+2, moveBoard, 0));
            else if(x > 0 && y < 6 && (!moveBoard.returnSquare(x-1,y+2).find("White")))
                list->addNode(x-1,y+2, this->evaluatePiece(x-1,y+2, moveBoard, 0));
            if(x > 0 && y > 1 && moveBoard.returnSquare(x-1, y-2) == "Empty")
                list->addNode(x-1,y-2, this->evaluatePiece(x-1,y-2, moveBoard, 0));
            else if(x > 0 && y > 1 && (!moveBoard.returnSquare(x-1,y-2).find("White")))
                list->addNode(x-1,y-2, this->evaluatePiece(x-1,y-2, moveBoard, 0));
            return list;

        case 12: // Black Left Bishop Moves
            for(int e = x+1, i = y+1;e < 8 && i < 8; e++, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("White"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x+1, i = y-1;e < 8 && i >= 0; e++, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("White"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y+1;e >= 0 && i < 8;e--, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("White"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y-1;e >= 0 && i >= 0;e--, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("White"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            return list;

        case 13: // Black Queen Moves
            for(int i = x + 1; i < 8; i++){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, 0));
                else if((x < 8) && (!moveBoard.returnSquare(i,y).find("White"))){
                    list->addNode(i, y, this->evaluatePiece(i,y, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = x -1; i >= 0; i--){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, 0));
                else if((x >= 0 ) && (!moveBoard.returnSquare(i,y).find("White"))){
                    list->addNode(i, y, this->evaluatePiece(i,y, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = y +1; i < 8; i++){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, 0));
                else if((x >= 0 ) && (!moveBoard.returnSquare(x,i).find("White"))){
                    list->addNode(x, i, this->evaluatePiece(x,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            for(int i = y -1; i >= 0; i--){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, 0));
                else if((x >= 0 ) && (!moveBoard.returnSquare(x,i).find("White"))){
                    list->addNode(x, i, this->evaluatePiece(x,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            for(int e = x+1, i = y+1;e < 8 && i < 8; e++, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("White"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x+1, i = y-1;e < 8 && i >= 0; e++, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                else if (e < 8 && i >=0 && (!moveBoard.returnSquare(e,i).find("White"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y+1;e >= 0 && i < 8;e--, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                else if ( e >= 0 && i < 8 && (!moveBoard.returnSquare(e,i).find("White"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y-1;e >= 0 && i >= 0;e--, i--){
                if (moveBoard.returnSquare(e, i) == "Empty")
                    list->addNode(e, i, this->evaluatePiece(e,i, moveBoard, 0));
                else if (e > 0 && i > 0 && (!moveBoard.returnSquare(e, i).find("White"))){
                    list->addNode(e, i, this->evaluatePiece(e,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            return list;

        case 14: // Black King Moves
            if(x < 7 && moveBoard.returnSquare(x+1,y) == "Empty")
                list->addNode(x+1,y, this->evaluatePiece(x+1,y, moveBoard, 0));
            else if(x < 7 &&(!moveBoard.returnSquare(x+1,y).find("White")))
                list->addNode(x+1,y, this->evaluatePiece(x+1,y, moveBoard, 0));
            if(x > 0 && moveBoard.returnSquare(x-1,y) == "Empty")
                list->addNode(x-1,y, this->evaluatePiece(x-1,y, moveBoard, 0));
            else if(x > 0 && (!moveBoard.returnSquare(x-1,y).find("White")))
                list->addNode(x-1,y, this->evaluatePiece(x-1,y, moveBoard, 0));
            if(y < 7 && moveBoard.returnSquare(x,y+1) == "Empty")
                list->addNode(x,y+1, this->evaluatePiece(x,y+1, moveBoard, 0));
            else if(y < 7 && (!moveBoard.returnSquare(x,y+1).find("White")))
                list->addNode(x,y+1, this->evaluatePiece(x,y+1, moveBoard, 0));
            if(y > 0 && moveBoard.returnSquare(x,y-1) == "Empty")
                list->addNode(x,y-1, this->evaluatePiece(x,y-1, moveBoard, 0));
            else if(y > 0 && (!moveBoard.returnSquare(x,y-1).find("White")))
                list->addNode(x,y-1, this->evaluatePiece(x,y-1, moveBoard, 0));
            if(x < 7 && y < 8 && moveBoard.returnSquare(x+1,y+1) == "Empty")
                list->addNode(x+1,y+1, this->evaluatePiece(x+1,y+1, moveBoard, 0));
            else if(x < 7 && y < 8 && (!moveBoard.returnSquare(x+1,y+1).find("White")))
                list->addNode(x+1,y+1, this->evaluatePiece(x+1,y+1, moveBoard, 0));
            if(x < 7 && y > 0 && moveBoard.returnSquare(x+1,y-1) == "Empty")
                list->addNode(x+1,y-1, this->evaluatePiece(x+1,y-1, moveBoard, 0));
            else if(x < 7 && y > 0 && (!moveBoard.returnSquare(x+1,y-1).find("White")))
                list->addNode(x+1,y-1, this->evaluatePiece(x+1,y-1, moveBoard, 0));
            if(x > 0 && y < 8 && moveBoard.returnSquare(x-1,y+1) == "Empty")
                list->addNode(x-1,y+1, this->evaluatePiece(x-1,y+1, moveBoard, 0));
            else if(x > 0 && y < 8 && (!moveBoard.returnSquare(x-1,y+1).find("White")))
                list->addNode(x-1,y+1, this->evaluatePiece(x-1,y+1, moveBoard, 0));
            if(x > 0 && y > 0 && moveBoard.returnSquare(x-1,y-1) == "Empty")
                list->addNode(x-1,y-1, this->evaluatePiece(x-1,y-1, moveBoard, 0));
            else if(x > 0 && y > 0 && (!moveBoard.returnSquare(x-1,y-1).find("White")))
                list->addNode(x-1,y-1, this->evaluatePiece(x-1,y-1, moveBoard, 0));
            else if(this->castleCheck(0) && moveBoard.returnSquare(7,1) == "Empty" && moveBoard.returnSquare(7,2) == "Empty")
                list->addNode(x, y - 2, 1);
            return list;

        case 15: // Black Right Bishop Moves
            for(int e = x+1, i = y+1;e < 8 && i < 8; e++, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("White"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x+1, i = y-1;e < 8 && i >= 0; e++, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("White"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y+1;e >= 0 && i < 8;e--, i++){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("White"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            for(int e = x-1, i = y-1;e >= 0 && i >= 0;e--, i--){
                if(moveBoard.returnSquare(e,i) == "Empty")
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                else if (e < 8 && i < 8 && (!moveBoard.returnSquare(e,i).find("White"))){
                    list->addNode(e,i, this->evaluatePiece(e,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(e,i) != "Empty")
                    break;
            }
            return list;

        case 16: // Black Right Knight Moves
            if(x < 6 && y < 7 && moveBoard.returnSquare(x+2, y+1) == "Empty")
                list->addNode(x+2,y+1, this->evaluatePiece(x+2,y+1, moveBoard, 0));
            else if(x < 6 && y < 7 && (!moveBoard.returnSquare(x+2,y+1).find("White")))
                list->addNode(x+2,y+1, this->evaluatePiece(x+2,y+1, moveBoard, 0));
            if(x < 6 && y > 0 && moveBoard.returnSquare(x+2, y-1) == "Empty")
                list->addNode(x+2,y-1, this->evaluatePiece(x+2,y-1, moveBoard, 0));
            else if(x < 6 && y > 0 && (!moveBoard.returnSquare(x+2,y-1).find("White")))
                list->addNode(x+2,y-1, this->evaluatePiece(x+2,y-1, moveBoard, 0));
            if(x < 7 && y < 6 && moveBoard.returnSquare(x+1, y+2) == "Empty")
                list->addNode(x+1,y+2, this->evaluatePiece(x+1,y+2, moveBoard, 0));
            else if(x < 7 && y < 6 && (!moveBoard.returnSquare(x+1,y+2).find("White")))
                list->addNode(x+1,y+2, this->evaluatePiece(x+1,y+2, moveBoard, 0));
            if(x < 7 && y > 1 && moveBoard.returnSquare(x+1, y-2) == "Empty")
                list->addNode(x+1,y-2, this->evaluatePiece(x+1,y-2, moveBoard, 0));
            else if(x < 7 && y > 1 && (!moveBoard.returnSquare(x+1,y-2).find("White")))
                list->addNode(x+1,y-2, this->evaluatePiece(x+1,y-2, moveBoard, 0));
            if(x > 1 && y < 7 && moveBoard.returnSquare(x-2, y+1) == "Empty")
                list->addNode(x-2,y+1, this->evaluatePiece(x-2,y+1, moveBoard, 0));
            else if(x > 1 && y < 7 && (!moveBoard.returnSquare(x-2,y+1).find("White")))
                list->addNode(x-2,y+1, this->evaluatePiece(x-2,y+1, moveBoard, 0));
            if(x > 1 && y > 0 && moveBoard.returnSquare(x-2, y-1) == "Empty")
                list->addNode(x-2,y-1, this->evaluatePiece(x-2,y-1, moveBoard, 0));
            else if(x > 1 && y > 0 && (!moveBoard.returnSquare(x-2,y-1).find("White")))
                list->addNode(x-2,y-1, this->evaluatePiece(x-2,y-1, moveBoard, 0));
            if(x > 0 && y < 6 && moveBoard.returnSquare(x-1, y+2) == "Empty")
                list->addNode(x-1,y+2, this->evaluatePiece(x-1,y+2, moveBoard, 0));
            else if(x > 0 && y < 6 && (!moveBoard.returnSquare(x-1,y+2).find("White")))
                list->addNode(x-1,y+2, this->evaluatePiece(x-1,y+2, moveBoard, 0));
            if(x > 0 && y > 1 && moveBoard.returnSquare(x-1, y-2) == "Empty")
                list->addNode(x-1,y-2, this->evaluatePiece(x-1,y-2, moveBoard, 0));
            else if(x > 0 && y > 1 && (!moveBoard.returnSquare(x-1,y-2).find("White")))
                list->addNode(x-1,y-2, this->evaluatePiece(x-1,y-2, moveBoard, 0));
            return list;

        case 17: // Black Right Rook Moves
            for(int i = x + 1; i < 8; i++){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, 0));
                else if((x < 8) && (!moveBoard.returnSquare(i,y).find("White"))){
                    list->addNode(i, y, this->evaluatePiece(i,y, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = x -1; i >= 0; i--){
                if(moveBoard.returnSquare(i,y) == "Empty")
                    list->addNode(i,y, this->evaluatePiece(i,y, moveBoard, 0));
                else if((x >= 0 ) && (!moveBoard.returnSquare(i,y).find("White"))){
                    list->addNode(i, y, this->evaluatePiece(i,y, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(i,y) != "Empty")
                    break;
            }
            for(int i = y +1; i < 8; i++){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, 0));
                else if((x >= 0 ) && (!moveBoard.returnSquare(x,i).find("White"))){
                    list->addNode(x, i, this->evaluatePiece(x,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            for(int i = y -1; i >= 0; i--){
                if(moveBoard.returnSquare(x,i) == "Empty")
                    list->addNode(x,i, this->evaluatePiece(x,i, moveBoard, 0));
                else if((x >= 0 ) && (!moveBoard.returnSquare(x,i).find("White"))){
                    list->addNode(x, i, this->evaluatePiece(x,i, moveBoard, 0));
                    break;
                }
                else if(moveBoard.returnSquare(x,i) != "Empty")
                    break;
            }
            return list;

        case 18: // Black Pawn Moves
            if(side == 0) {
                if (x != 0 && moveBoard.returnSquare(x - 1, y) == "Empty")
                    list->addNode(x - 1, y, this->evaluatePiece(x - 1, y, moveBoard, 0));
                if (x == 6 && moveBoard.returnSquare(x - 1, y) == "Empty" &&
                    moveBoard.returnSquare(x - 2, y) == "Empty")
                    list->addNode(x - 2, y, this->evaluatePiece(x - 2, y, moveBoard, 0));
                if (x != 0 && y != 7 && moveBoard.returnSquare(x - 1, y + 1) != "Empty")
                    list->addNode(x - 1, y + 1, this->evaluatePiece(x - 1, y + 1, moveBoard, 0));
                if (x != 0 && y != 0 && moveBoard.returnSquare(x - 1, y - 1) != "Empty")
                    list->addNode(x - 1, y - 1, this->evaluatePiece(x - 1, y - 1, moveBoard, 0));
                if (x == 3 && this->enPassantCheck(0) != 10)
                    list->addNode(x - 1, this->enPassantCheck(0), 2);
            }
            else {

                if(x != 7 && moveBoard.returnSquare(x+1,y) == "Empty")
                    list->addNode(x+1,y, this->evaluatePiece(x+1,y, moveBoard, 0));
                if(x == 1 && moveBoard.returnSquare(x+1,y) == "Empty" && moveBoard.returnSquare(x+2,y) == "Empty")
                    list->addNode(x+2,y, this->evaluatePiece(x+2,y, moveBoard, 0));
                if(x != 7 && y != 7 && (!moveBoard.returnSquare(x+1,y+1).find("White")))
                    list->addNode(x+1,y+1, this->evaluatePiece(x+1,y+1, moveBoard, 0));
                if(x != 7 && y != 0 && (!moveBoard.returnSquare(x+1,y-1).find("White")))
                    list->addNode(x+1,y-1, this->evaluatePiece(x+1,y-1, moveBoard, 0));

                return list;
            }
        case 19: // Empty Square
            return list;
    }
}

bool MoveCalculator::checkMateTest(Board gameBoard, int side){
    Board testBoard = gameBoard;
    MoveCalculator calc;
    LinkedList *temp;
    std::vector<int> moveVector;
    std::vector<int> returnedVector;
    std::string piece;
    int kingX;
    int kingY;
    if(side == 0){
        for (int e = 0; e < 8; e++){
            for (int i = 0; i < 8; i++){
                if (!gameBoard.returnSquare(e, i).find("Black")){
                    temp = possibleSquares2DArray(e, i, gameBoard, side);
                    returnedVector = temp->returnVector();
                    for (int k = 0; k < returnedVector.size() / 2; k++){
                        int a = returnedVector[k];
                        int b = returnedVector[k + 1];
                        piece = testBoard.returnSquare(e, i);
                        testBoard.setSquare(e, i, "Empty");
                        testBoard.setSquare(a, b, piece);
                        for (int e2 = 0; e2 < 8; e2++){
                            for (int i2 = 0; i2 < 8; i2++){
                                if (testBoard.returnSquare(e2, i2) == "Black King"){
                                    kingX = e2;
                                    kingY = i2;
                                }
                            }
                        }
                        if (!this->checkCalculator(kingX, kingY, testBoard, side)){
                            return false;
                        }
                        k = k + 1;
                    }
                }
            }
        }
    }
    else{
        for (int e = 0; e < 8; e++){
            for (int i = 0; i < 8; i++){
                if (!gameBoard.returnSquare(e, i).find("White")){
                    temp = possibleSquares2DArray(e, i, gameBoard, side);
                    returnedVector = temp->returnVector();
                    for (int k = 0; k < returnedVector.size() / 2; k++){
                        int a = returnedVector[k];
                        int b = returnedVector[k + 1];
                        piece = testBoard.returnSquare(e, i);
                        testBoard.setSquare(e, i, "Empty");
                        testBoard.setSquare(a, b, piece);
                        for (int e2 = 0; e < 8; e++){
                            for (int i2 = 0; i < 8; i++){
                                if (testBoard.returnSquare(e2, i2) == "White King"){
                                    kingX = e2;
                                    kingY = i2;
                                }
                            }
                        }
                        if (!this->checkCalculator(kingX, kingY, testBoard, side))
                            return false;
                        k = k + 1;
                    }
                }
            }
        }
    }
    return true;
}

bool MoveCalculator::checkCalculator(int x, int y, Board moveBoard, int side){
    LinkedList *temp;
    std::vector<int> moveVector;
    std::vector<int> returnedVector;
    if(side == 0){
        for (int e = 0; e < 8; e++){
            for (int i = 0; i < 8; i++){
                if (!moveBoard.returnSquare(e, i).find("White")){
                    temp = possibleSquares2DArray(e, i, moveBoard, side);
                    returnedVector = temp->returnVector();
                    moveVector.insert(moveVector.end(), returnedVector.begin(), returnedVector.end());
                }
            }
        }
    }
    else{
        for (int e = 0; e < 8; e++){
            for (int i = 0; i < 8; i++){
                if (!moveBoard.returnSquare(e, i).find("Black")){
                    temp = possibleSquares2DArray(e, i, moveBoard, side);
                    returnedVector = temp->returnVector();
                    moveVector.insert(moveVector.end(), returnedVector.begin(), returnedVector.end());
                }
            }
        }
    }
    for(int k = 0; k < moveVector.size(); k++){
        int a = moveVector[k];
        int b = moveVector[k+1];
        k = k+1;
        if(x == a && y == b){
            std::cout << "check baby !!!" << std::endl;
            moveVector.clear();
            return true;
        }
    }
    moveVector.clear();
    return false;
}

