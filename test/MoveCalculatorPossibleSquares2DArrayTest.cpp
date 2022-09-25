#include <iostream>
#include "../Board.h"
#include "../Print.h"
#include "../MoveCalculator.h"

using namespace std;

int main() {

  Board testBoard;
  MoveCalculator calc;
  Print output;
  LinkedList *list;

  for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }

  output.printBoardToTerminal(testBoard);

  testBoard.setSquare(3,3,"White Left Knight");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  vector<int> testVector;
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"Black Left Knight");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
   for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 testBoard.setSquare(3,3,"White Left Rook");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"Black Left Rook");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
    for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 testBoard.setSquare(3,3,"White Left Bishop");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"Black Left Bishop");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
     for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 testBoard.setSquare(3,3,"White Queen");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"Black Queen");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
    for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 testBoard.setSquare(3,3,"White King");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"Black King");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
 
    for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 testBoard.setSquare(3,3,"White Pawn");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"Black Pawn");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
  
    for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 testBoard.setSquare(1,3,"White Pawn");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(1,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"Black Pawn");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
 
/*
 * black side
 *
 *
 */

  for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }

  output.printBoardToTerminal(testBoard);

  testBoard.setSquare(3,3,"Black Left Knight");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"White Left Knight");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
   for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 testBoard.setSquare(3,3,"Black Left Rook");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"White Left Rook");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
    for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 testBoard.setSquare(3,3,"Black Left Bishop");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"White Left Bishop");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
     for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 testBoard.setSquare(3,3,"Black Queen");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"White Queen");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
    for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 testBoard.setSquare(3,3,"Black King");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"White King");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
 
    for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 testBoard.setSquare(3,3,"Black Pawn");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"White Pawn");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);
  
    for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 testBoard.setSquare(6,3,"Black Pawn");

  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(6,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector();
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"White Pawn");
      i = i + 2;
  }

output.printBoardToTerminal(testBoard);

    for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }
 
  list = calc.possibleSquares2DArray(6,3,testBoard,0);
  testVector.clear();
  if (list != nullptr){
      cout << "blah blah" << endl;
  
    testVector = list->returnVector();
  }
output.printBoardToTerminal(testBoard);
}
