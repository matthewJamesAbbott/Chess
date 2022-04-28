#include <iostream>
#include "Game.h"
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fstream>
#include <string>
#include <time.h>
#include <experimental/filesystem>

#include <algorithm>
#include <iomanip>
#include <sstream>
#include <ctime>

#define PORT 9008
using namespace std;
using std::experimental::filesystem::directory_iterator;

int main(int argc, char *argv[]){
    Game chess;
    std::experimental::filesystem::create_directory("gamesave");
    std::cout << "Please Enter Name for Player" << std::endl;
    std::string name;
    std::cin >> name;
    chess.setPlayerOne(name);
    if(argc == 1){
        chess.clientServerToggle = 0;
    }
    else{
        for (int i = 0; i < argc; i++){
            if(!strcmp(argv[i], "-s")){
                cout << "Game is now running as server and waiting for a client too connect" << endl;
                chess.clientServerToggle = 1;
            }
            if(!strcmp(argv[i], "-c")){
                    chess.clientServerToggle = 2;
            }
            if(!strcmp(argv[i], "--help")){cout << "Usage: Chess [OPTION] ... [IP ADDRESS]\n" <<
                                                        "Chess will run with no argument as a standalone game or with options as client and server\n" <<
                                                        "   -s                  run Chess as server\n" <<
                                                        "   -c [IP ADDRESS]     run Chess as client connecting to [IP ADDRESS]" << endl;}
        }
    }
    int x, xa;
    char y, ya;
    if(chess.clientServerToggle == 2){
        chess.initialiseBoard();
        chess.printBoardToTerminal();
        int clientSocket;
        clientSocket = socket(AF_INET , SOCK_STREAM , 0);
        if(clientSocket < 0){
            cout << "Creation of client socket failed" << endl;
            return 0;
        }
        struct sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = inet_addr(argv[2]);
        serverAddr.sin_port = htons(PORT);
        if(connect(clientSocket ,  (struct sockaddr*) & serverAddr , sizeof(serverAddr)) < 0){
            cout << "Connection Error..." << endl;
            return 0;
        }
        else{
            cout << "\t\tConnection Established..." << endl;
        }
        while (true){
            while (true){
                cout << "Please enter number for piece you wish to move or 9 too exit" << endl;
                cin >> x;
                if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8){
                    break;
                } 
                else if (x == 9)
                    return 0;
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    x = 0;
                }
            }
            while (true){
                cout << "Please enter letter for piece you wish to move or 9 too exit" << endl;
                cin >> y;
                if (y == 'a' || y == 'A' || y == 'b' || y == 'B' || y == 'c' || y == 'C' || y == 'd' || y == 'D'
                    || y == 'e' || y == 'E' || y == 'f' || y == 'F' || y == 'g' || y == 'G' || y == 'h' || y == 'H'){
                    break;
                } 
                else if (y == '9')
                    return 0;
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    y = 0;
                }
            }
            while (true){
                cout << "Please enter number for were you wish piece to move too or 9 too exit" << endl;
                cin >> xa;
                if (xa == 1 || xa == 2 || xa == 3 || xa == 4 || xa == 5 || xa == 6 || xa == 7 || xa == 8){
                    break;
                } 
                else if (xa == 9)
                    return 0;
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    xa = 0;
                }
            }
            while (true){
                cout << "Please enter letter for were you wish piece to move too or 9 too exit" << endl;
                cin >> ya;
                if (ya == 'a' || ya == 'A' || ya == 'b' || ya == 'B' || ya == 'c' || ya == 'C' || ya == 'd' || ya == 'D'
                    || ya == 'e' || ya == 'E' || ya == 'f' || ya == 'F' || ya == 'g' || ya == 'G' || ya == 'h' ||
                    ya == 'H'){
                    break;
                } else if (ya == '9')
                    return 0;
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    ya = 0;
                }
            }
            chess.movePiece(x, y, xa, ya);
            chess.printBoardToTerminal();
            char input[4];
            input[0] = x + '0';
            input[1] = y;
            input[2] = xa + '0';
            input[3] = ya;
            send(clientSocket , input , strlen(input)+1 , 0);
            char receiveMessage[MAX];
            int rMsgSize = recv(clientSocket , receiveMessage , MAX , 0);
            if(rMsgSize < 0){
                cout << "Packet receive failed." << endl;
                return 0;
            }
            else if(rMsgSize == 0){
                cout << "Server is off." << endl;
                return 0;
            }
            if(receiveMessage[0] == 'b' && receiveMessage[1] == 'y' && receiveMessage[2] == 'e'){
                cout << "\nConnection ended... take care bye bye... " ;
                break;
            }
            int a = receiveMessage[0] - '0';
            int b = receiveMessage[2] - '0';
            chess.movePiece(a,receiveMessage[1],b,receiveMessage[3]);
            chess.printBoardToTerminal();
        }

    }
    if(chess.clientServerToggle == 1){
        chess.initialiseBoard();
        chess.printBoardToTerminal();
        int serverSocketHandler = socket(AF_INET , SOCK_STREAM , 0);
        if(serverSocketHandler < 0){
            cout << "Socket creation has failed.";
            return 0;
        }
        struct sockaddr_in serverAddr , clientAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(PORT);
        serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        int bindStatus = bind(serverSocketHandler , (struct sockaddr*) & serverAddr , sizeof(serverAddr));
        if(bindStatus < 0){
            cout << "Socket binding has failed" << endl;
            return 0;
        }
        int listenStatus = listen(serverSocketHandler , 5);
        if(listenStatus < 0){
            cout << "Listner has failed" << endl;
            return 0;
        }
        cout << "..Waiting for connections.. \n";
        char buff[MAX];
        int clientSocketHandler;
        socklen_t len = sizeof(clientAddr);
        int connection;
        if((connection = accept(serverSocketHandler , (struct sockaddr*) & clientAddr , &len)) < 0){
            cout << "Server didn't accept the request." << endl;
            return 0;
        }
        else{
            cout << "Server accepted the request. \n" ;
        }

        while (true){
            char receiveMessage[MAX];
            int rMsgSize = recv(connection , receiveMessage , MAX , 0);
            if(rMsgSize < 0){
                cout << "Packet receive failed." << endl;
                return 0;
            }
            else if(rMsgSize == 0){
                cout << "Server is off." << endl;
                return 0;
            }
            if(receiveMessage[0] == 'b' && receiveMessage[1] == 'y' && receiveMessage[2] == 'e'){
                cout << "\nConnection ended... take care bye bye... " ;
                break;
            }
            int a = receiveMessage[0] - '0';
            int b = receiveMessage[2] - '0';
            chess.movePiece(a,receiveMessage[1],b,receiveMessage[3]);
            chess.printBoardToTerminal();
            while (true){
                cout << "Please enter number for piece you wish to move or 9 too exit" << endl;
                cin >> x;
                if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8){
                    break;
                } 
                else if (x == 9)
                    return 0;
                else {
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    x = 0;
                }
            }
            while (true){
                cout << "Please enter letter for piece you wish to move or 9 too exit" << endl;
                cin >> y;
                if (y == 'a' || y == 'A' || y == 'b' || y == 'B' || y == 'c' || y == 'C' || y == 'd' || y == 'D'
                    || y == 'e' || y == 'E' || y == 'f' || y == 'F' || y == 'g' || y == 'G' || y == 'h' || y == 'H'){
                    break;
                } 
                else if (y == '9')
                    return 0;
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    y = 0;
                }
            }
            while (true){
                cout << "Please enter number for were you wish piece to move too or 9 too exit" << endl;
                cin >> xa;
                if (xa == 1 || xa == 2 || xa == 3 || xa == 4 || xa == 5 || xa == 6 || xa == 7 || xa == 8){
                    break;
                } 
                else if (xa == 9)
                    return 0;
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    xa = 0;
                }
            }
            while (true){
                cout << "Please enter letter for were you wish piece to move too or 9 too exit" << endl;
                cin >> ya;
                if (ya == 'a' || ya == 'A' || ya == 'b' || ya == 'B' || ya == 'c' || ya == 'C' || ya == 'd' || ya == 'D'
                    || ya == 'e' || ya == 'E' || ya == 'f' || ya == 'F' || ya == 'g' || ya == 'G' || ya == 'h' ||
                    ya == 'H'){
                    break;
                } 
                else if (ya == '9')
                    return 0;
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    ya = 0;
                }
            }
            chess.movePiece(x, y, xa, ya);
            chess.printBoardToTerminal();
            char input[4];
            input[0] = x + '0';
            input[1] = y;
            input[2] = xa + '0';
            input[3] = ya;
            send(connection , input , strlen(input)+1 , 0);
        }
    }
    if(chess.clientServerToggle == 0){
        std::remove("Chess.txt");
        chess.initialiseBoard();
        std::system("clear");
        chess.printBoardToTerminal();
        while (true){
            while (true){
                cout << "Please enter number for piece you wish to move or 9 too exit" << endl;
                cin >> x;
                if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8){
                    break;
                }
                else if (x == 9)
                    return 0;
                else if (x == 11){

                    //char dateTime[80];
                    time_t current = time(nullptr);
                    std::string dateTime = ctime(&current);
                    std::replace(dateTime.begin(), dateTime.end(), ' ', '-');
                    std::replace(dateTime.begin(),dateTime.end(), ':', ',');
                    std::replace(dateTime.begin(),dateTime.end(), '\n', '.');


                    std::ofstream outFileHandle;

                    std::string saveFile = "gamesave/" + dateTime;
                    outFileHandle.open(saveFile ,std::ios_base::app);


                    std::ifstream inFileHandle;
                    std::string line;
                    inFileHandle.open("Chess.txt");
                    while(std::getline(inFileHandle, line)){
                        outFileHandle << line << "\n";
                    }
                    inFileHandle.close();
                    outFileHandle.close();
                    
                }
                else if (x == 12){
                    std::string path = "gamesave/";
                    std::vector<std::string> dir;
                    std::cout << "Please enter the corresponding number to the game you wish to restore" << std::endl;
                    int i = 1;
                    for (const auto & entry : directory_iterator(path)){
                        std::cout << i << " " << entry.path() << std::endl;
                        dir.push_back(entry.path());
                        i++;
                    }
                    std::string loadInput;
                    int index;
                    while(true) {
                        std::cin >> index;
                        if (index > 0 && index <= dir.size()) {
                            loadInput = dir[index - 1];
                            break;
                        }
                        else{
                            cout << "You have entered an illegal character please try again" << endl;
                            cin.clear();
                            cin.ignore(1, '\n');
                        }
                    }
                    chess.loadGame(loadInput);
                    chess.printBoardToTerminal();
                }
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    x = 0;
                }
            }
            while (true){
                cout << "Please enter letter for piece you wish to move or 9 too exit" << endl;
                cin >> y;
                if (y == 'a' || y == 'A' || y == 'b' || y == 'B' || y == 'c' || y == 'C' || y == 'd' || y == 'D'
                    || y == 'e' || y == 'E' || y == 'f' || y == 'F' || y == 'g' || y == 'G' || y == 'h' || y == 'H'){
                    break;
                }
                else if (y == '9')
                    return 0;
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    y = 0;
                }
            }
            while(true){
                cout << "Please enter number for were you wish piece to move too or 9 too exit" << endl;
                cin >> xa;
                if (xa == 1 || xa == 2 || xa == 3 || xa == 4 || xa == 5 || xa == 6 || xa == 7 || xa == 8){
                    break;
                }
                else if (xa == 9)
                    return 0;
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    xa = 0;
                }
            }
            while(true){
                cout << "Please enter letter for were you wish piece to move too or 9 too exit" << endl;
                cin >> ya;
                if (ya == 'a' || ya == 'A' || ya == 'b' || ya == 'B' || ya == 'c' || ya == 'C' || ya == 'd' || ya == 'D'
                    || ya == 'e' || ya == 'E' || ya == 'f' || ya == 'F' || ya == 'g' || ya == 'G' || ya == 'h' || ya == 'H'){
                    break;
                }
                else if(ya == '9')
                    return 0;
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    ya = 0;
                }
            }
            if(chess.movePiece(x, y, xa, ya)){
                std::system("clear");
                chess.printBoardToTerminal();
                chess.engineMove();
                std::system("clear");
                chess.printBoardToTerminal();
            }
        }
    }
    return 0;
}
