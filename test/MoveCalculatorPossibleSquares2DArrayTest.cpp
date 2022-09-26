#include <iostream>
#include "../Board.h"
#include "../Print.h"
#include "../MoveCalculator.h"

/*
 * Test of all pieces for both sides checking for generation of correct moves
 * by MoveCalculator.possibleSquares2DArray
 * first piece is displayed on board then were it can move in the opposite colour
 * Tests for blocking of pieces by there own colour are also provided.
 *
 *
 */

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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  testVector = list->returnVector(); delete list;
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
  
    testVector = list->returnVector(); delete list;
  }
output.printBoardToTerminal(testBoard);

for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
        testBoard.setSquare(xIterator,yIterator,"Empty");
    }
  }

/*
 * white test if piece will take its own colour
 *
 */

  testBoard.setSquare(3,3,"White Left Knight");
  testBoard.setSquare(1,2,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Knight");
  testBoard.setSquare(1,4,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Knight");
  testBoard.setSquare(2,1,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Knight");
  testBoard.setSquare(2,5,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Knight");
  testBoard.setSquare(4,1,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Knight");
  testBoard.setSquare(4,5,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Knight");
  testBoard.setSquare(5,2,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Knight");
  testBoard.setSquare(5,4,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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
  testBoard.setSquare(3,5,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Rook");
  testBoard.setSquare(3,1,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Rook");
  testBoard.setSquare(5,3,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Rook");
  testBoard.setSquare(1,3,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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

  testBoard.setSquare(3,3,"Black Left Rook");
  testBoard.setSquare(3,5,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"Black Left Rook");
  testBoard.setSquare(3,1,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"Black Left Rook");
  testBoard.setSquare(5,3,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"Black Left Rook");
  testBoard.setSquare(1,3,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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

  testBoard.setSquare(3,3,"White Left Bishop");
  testBoard.setSquare(5,5,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Bishop");
  testBoard.setSquare(5,1,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Bishop");
  testBoard.setSquare(1,1,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Left Bishop");
  testBoard.setSquare(1,5,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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

  testBoard.setSquare(3,3,"Black Left Bishop");
  testBoard.setSquare(5,5,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"Black Left Bishop");
  testBoard.setSquare(5,1,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"Black Left Bishop");
  testBoard.setSquare(1,1,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"Black Left Bishop");
  testBoard.setSquare(1,5,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Queen");
  testBoard.setSquare(3,5,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"White Queen");
  testBoard.setSquare(5,5,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White Queen");
  testBoard.setSquare(5,3,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White Queen");
  testBoard.setSquare(5,1,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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




  testBoard.setSquare(3,3,"White Queen");
  testBoard.setSquare(3,1,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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




  testBoard.setSquare(3,3,"White Queen");
  testBoard.setSquare(1,1,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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




  testBoard.setSquare(3,3,"White Queen");
  testBoard.setSquare(1,3,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White Queen");
  testBoard.setSquare(1,5,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"Black Queen");
  testBoard.setSquare(3,5,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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


  testBoard.setSquare(3,3,"Black Queen");
  testBoard.setSquare(5,5,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black Queen");
  testBoard.setSquare(5,3,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black Queen");
  testBoard.setSquare(5,1,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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




  testBoard.setSquare(3,3,"Black Queen");
  testBoard.setSquare(3,1,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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




  testBoard.setSquare(3,3,"Black Queen");
  testBoard.setSquare(1,1,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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




  testBoard.setSquare(3,3,"Black Queen");
  testBoard.setSquare(1,3,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black Queen");
  testBoard.setSquare(1,5,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White King");
  testBoard.setSquare(3,4,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White King");
  testBoard.setSquare(4,4,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White King");
  testBoard.setSquare(4,3,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White King");
  testBoard.setSquare(4,2,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White King");
  testBoard.setSquare(3,2,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White King");
  testBoard.setSquare(2,2,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White King");
  testBoard.setSquare(2,3,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White King");
  testBoard.setSquare(2,4,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black King");
  testBoard.setSquare(3,4,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black King");
  testBoard.setSquare(4,4,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black King");
  testBoard.setSquare(4,3,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black King");
  testBoard.setSquare(4,2,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black King");
  testBoard.setSquare(3,2,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black King");
  testBoard.setSquare(2,2,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black King");
  testBoard.setSquare(2,3,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black King");
  testBoard.setSquare(2,4,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White Pawn");
  testBoard.setSquare(4,3,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White Pawn");
  testBoard.setSquare(4,4,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White Pawn");
  testBoard.setSquare(4,2,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White Pawn");
  testBoard.setSquare(4,3,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White Pawn");
  testBoard.setSquare(4,4,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"White Pawn");
  testBoard.setSquare(4,2,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,1);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black Pawn");
  testBoard.setSquare(2,3,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black Pawn");
  testBoard.setSquare(2,4,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black Pawn");
  testBoard.setSquare(2,2,"Black Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black Pawn");
  testBoard.setSquare(2,3,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black Pawn");
  testBoard.setSquare(2,4,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
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



  testBoard.setSquare(3,3,"Black Pawn");
  testBoard.setSquare(2,2,"White Pawn");
  output.printBoardToTerminal(testBoard);
  list = calc.possibleSquares2DArray(3,3,testBoard,0);
  testVector.clear();
  testVector = list->returnVector(); delete list;
  for (int i = 0; i < testVector.size();){
      testBoard.setSquare(testVector[i],testVector[i+1],"Black Pawn");
      i = i + 2;
  }

  output.printBoardToTerminal(testBoard);








}
