#include <iostream>
#include "Game.h"
#include<cstring>

int main(int argc, char *argv[]) {
    Game test;
    test.initialiseBoard();
    test.printBoardToTerminal();

    if(argc == 1){
    }
    else {
        for (int i = 0; i < argc; i++) {
            if(!std::strcmp(argv[i], "-s")){


                test.startServer(9002);
                std::cout << "Game is now running as server and waiting for a client too connect" << std::endl;
            }
            if(!std::strcmp(argv[i], "-c")) {

                test.connectToServer(argv[i + 1], 9002);



            }
            if(!strcmp(argv[i], "--help")){

            }


        }
    }

    int x, xa;
    char y, ya;
    while(true) {
        while(true){
            std::cout << "Please enter number for piece you wish to move or 9 too exit" << std::endl;
            std::cin >> x;
            if(x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8){
                break;
            }
            else if(x == 9)
                return 0;
            else {
                std::cout << "You have entered an illegal character please try again" << std::endl;
                std::cin.clear();
                std::cin.ignore(1, '\n');
                x = 0;
            }
        }
        while(true){
            std::cout << "Please enter letter for piece you wish to move or 9 too exit" << std::endl;
            std::cin >> y;
            if(y == 'a' || y == 'A' || y == 'b' || y == 'B' || y == 'c' || y == 'C' || y == 'd' || y == 'D'
                || y == 'e' || y == 'E' || y == 'f' || y == 'F' || y == 'g' || y == 'G' || y == 'h' || y == 'H'){
                break;
            }
            else if(y == '9')
                return 0;
            else {
                std::cout << "You have entered an illegal character please try again" << std::endl;
                std::cin.clear();
                std::cin.ignore(1, '\n');
                y = 0;
            }
        }
        while(true){
            std::cout << "Please enter number for were you wish piece to move too or 9 too exit" << std::endl;
            std::cin >> xa;
            if(xa == 1 || xa == 2 || xa == 3 || xa == 4 || xa == 5 || xa == 6 || xa == 7 || xa == 8){
                break;
            }
            else if(xa == 9)
                return 0;
            else {
                std::cout << "You have entered an illegal character please try again" << std::endl;
                std::cin.clear();
                std::cin.ignore(1, '\n');
                xa = 0;
            }
        }
        while(true) {
            std::cout << "Please enter letter for were you wish piece to move too or 9 too exit" << std::endl;
            std::cin >> ya;
            if (ya == 'a' || ya == 'A' || ya == 'b' || ya == 'B' || ya == 'c' || ya == 'C' || ya == 'd' || ya == 'D'
                || ya == 'e' || ya == 'E' || ya == 'f' || ya == 'F' || ya == 'g' || ya == 'G' || ya == 'h' ||
                ya == 'H') {
                break;
            } else if (ya == '9')
                return 0;
            else {
                std::cout << "You have entered an illegal character please try again" << std::endl;
                std::cin.clear();
                std::cin.ignore(1, '\n');
                ya = 0;
            }
        }
        test.movePiece(x, y, xa, ya);
        test.printBoardToTerminal();
    }
    return 0;
}
