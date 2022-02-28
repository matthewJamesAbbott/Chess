#include <iostream>
#include "Game.h"


int main() {

    Game test;
    test.initialiseBoard();
    test.printBoardToTerminal();

    int x, xa;
    char y, ya;
    while(true) {
        std::cout << "Please enter number for piece you wish to move" << std::endl;
        std::cin >> x;
        if(x == 10)
            break;
        std::cout << "Please enter letter for piece you wish to move" << std::endl;
        std::cin >> y;
        std::cout << "Please enter number for were you wish piece to move too" << std::endl;
        std::cin  >> xa;
        std::cout << "Please enter letter for were you wish piece to move too" << std::endl;
        std::cin >> ya;
        test.movePiece(x, y, xa, ya);
        test.printBoardToTerminal();


    }
}
