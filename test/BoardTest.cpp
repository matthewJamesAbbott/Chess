//
// Created by Matthew Abbott on 24/9/22
//

#include <iostream>
#include "../Board.h"

using namespace std;

int main (){

  Board testBoard;
  int index = 0;
  for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      testBoard.setSquare(xIterator,yIterator,to_string(index));
      index++;
    }
  }
  for (int xIterator = 0; xIterator < 8; xIterator++){
    for (int yIterator = 0; yIterator < 8; yIterator++){
      cout << testBoard.returnSquare(xIterator,yIterator) << endl;
    }
  }
}
