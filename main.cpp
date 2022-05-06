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

#define PORT 9008

using namespace std;
using std::experimental::filesystem::directory_iterator;

int main(int argc, char *argv[]){
    Game chess;
    experimental::filesystem::create_directory("gamesave");
    cout << "Please Enter Name for Player" << std::endl;
    string name;
    cin >> name;
    chess.setPlayerOne(name);
    if(argc == 1){
        chess.clientServerToggle = 0;
    }
    else{
        for (int i = 0; i < argc; i++){
            if(!strcmp(argv[i], "-s")){
                cout << "Game is now running as server and waiting for a client to connect" << endl;
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
    char* ipArray = argv[2];
    gotoHandle:
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
        serverAddr.sin_addr.s_addr = inet_addr(ipArray);
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
                cout << "Please enter number for piece you wish to move or 9 to exit" << endl;
                cin >> x;
                if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8){
                    break;
                } 
                else if (x == 9)
                    return 0;
                else if (x == 10){
                    cout << "Welcome to Abbotts Chess \n" <<
                         "\n" <<
                         "Chess allows all regulation moves by asking the user for input of the four co-ordinates in succession\n"
                         "required for the move. Numeric and then alpha co-ordinates for the piece player wishes to move and then\n"
                         "numeric followed by alpha co-oridnates for square piece is to be moved to.\n" <<
                         "\n" <<
                         "Castling is accomplished by using the kings starting position followed by the position the king would\n"
                         "land after move as co-ordinates. Rook will move to position next to king automatically. Castling is only\n"
                         "available if both left rook and king have not been moved over the game.\n" <<
                         "\n" <<
                         "Enpassant is accomplished when a pawn is in correct position and an opposing pawn one square to the\n" <<
                         "left or right in its starting position moves two squares therefor overtaking the player pawns position.\n" <<
                         "The square that the opposing pawn moved over will become available as a move for the players pawn\n"
                         "allowing enpassant taking of pawns.\n" <<
                         "\n" <<
                         "10 Help Screen you are seeing now \n" <<
                         "11 Save Game State\n" <<
                         "12 Restore Game State\n" <<
                         "13 Reinitialize Board (new game)\n" <<
                         "14 Set Server to wait for Client\n" <<
                         "15 Connect to Server as Client\n" <<
                         "16 Change sides colour\n" <<
                         "17 Clear Screen toggle\n" <<
                         "\n" <<
                         "22 Take move Back\n" <<
                         "\n" <<
                         "9 Exit game\n" <<
                         "" << endl;
                }
                else if (x == 11){

                    time_t current = time(nullptr);
                    string dateTime = ctime(&current);
                    replace(dateTime.begin(), dateTime.end(), ' ', '-');
                    replace(dateTime.begin(),dateTime.end(), ':', ',');
                    replace(dateTime.begin(),dateTime.end(), '\n', '.');


                    ofstream outFileHandle;

                    string saveFile = "gamesave/" + dateTime;
                    outFileHandle.open(saveFile ,ios_base::app);


                    ifstream inFileHandle;
                    string line;
                    inFileHandle.open("Chess.txt");
                    while(getline(inFileHandle, line)){
                        outFileHandle << line << "\n";
                    }
                    inFileHandle.close();
                    outFileHandle.close();

                }
                else if (x == 12){
                    string path = "gamesave/";
                    vector<string> dir;
                    cout << "Please enter the corresponding number to the game you wish to restore" << endl;
                    int i = 1;
                    for (const auto & entry : directory_iterator(path)){
                        cout << i << " " << entry.path() << endl;
                        dir.push_back(entry.path());
                        i++;
                    }
                    string loadInput;
                    int index;
                    while(true) {
                        cin >> index;
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
                else if (x == 13){
                    chess.initialiseBoard();
                    chess.printBoardToTerminal();
                }
                else if (x == 14){
                    chess.clientServerToggle = 1;
                    goto gotoHandle;
                }
                else if (x == 15){
                    chess.clientServerToggle = 2;
                    cout << "Please enter ip address of server" << endl;
                    string ip_address;
                    cin >> ip_address;
                    char ipAddress[16];
                    strcpy(ipAddress, ip_address.c_str());
                    ipArray = ipAddress;
                    goto gotoHandle;
                }
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    x = 0;
                }
            }
            while (true){
                cout << "Please enter letter for piece you wish to move or 9 to exit" << endl;
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
                cout << "Please enter number for were you wish piece to move to or 9 to exit" << endl;
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
                cout << "Please enter letter for were you wish piece to move to or 9 to exit" << endl;
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
                cout << "Please enter number for piece you wish to move or 9 to exit" << endl;
                cin >> x;
                if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8){
                    break;
                } 
                else if (x == 9)
                    return 0;
                else if (x == 10){
                    cout << "Welcome to Abbotts Chess \n" <<
                         "\n" <<
                         "Chess allows all regulation moves by asking the user for input of the four co-ordinates in succession\n"
                         "required for the move. Numeric and then alpha co-ordinates for the piece player wishes to move and then\n"
                         "numeric followed by alpha co-oridnates for square piece is to be moved to.\n" <<
                         "\n" <<
                         "Castling is accomplished by using the kings starting position followed by the position the king would\n"
                         "land after move as co-ordinates. Rook will move to position next to king automatically. Castling is only\n"
                         "available if both left rook and king have not been moved over the game.\n" <<
                         "\n" <<
                         "Enpassant is accomplished when a pawn is in correct position and an opposing pawn one square to the\n" <<
                         "left or right in its starting position moves two squares therefor overtaking the player pawns position.\n" <<
                         "The square that the opposing pawn moved over will become available as a move for the players pawn\n"
                         "allowing enpassant taking of pawns.\n" <<
                         "\n" <<
                         "10 Help Screen you are seeing now \n" <<
                         "11 Save Game State\n" <<
                         "12 Restore Game State\n" <<
                         "13 Reinitialize Board (new game)\n" <<
                         "14 Set Server to wait for Client\n" <<
                         "15 Connect to Server as Client\n" <<
                         "16 Change sides colour\n" <<
                         "17 Clear Screen toggle\n" <<
                         "\n" <<
                         "22 Take move back\n" <<
                         "\n" <<
                         "9 Exit game\n" <<
                         "" << endl;
                }
                else if (x == 11){

                    time_t current = time(nullptr);
                    string dateTime = ctime(&current);
                    replace(dateTime.begin(), dateTime.end(), ' ', '-');
                    replace(dateTime.begin(),dateTime.end(), ':', ',');
                    replace(dateTime.begin(),dateTime.end(), '\n', '.');


                    ofstream outFileHandle;

                    string saveFile = "gamesave/" + dateTime;
                    outFileHandle.open(saveFile ,ios_base::app);


                    ifstream inFileHandle;
                    string line;
                    inFileHandle.open("Chess.txt");
                    while(getline(inFileHandle, line)){
                        outFileHandle << line << "\n";
                    }
                    inFileHandle.close();
                    outFileHandle.close();

                }
                else if (x == 12){
                    string path = "gamesave/";
                    vector<string> dir;
                    cout << "Please enter the corresponding number to the game you wish to restore" << endl;
                    int i = 1;
                    for (const auto & entry : directory_iterator(path)){
                        cout << i << " " << entry.path() << endl;
                        dir.push_back(entry.path());
                        i++;
                    }
                    string loadInput;
                    int index;
                    while(true) {
                        cin >> index;
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
                else if (x == 13){
                    chess.initialiseBoard();
                    chess.printBoardToTerminal();
                }
                else if (x == 14){
                    chess.clientServerToggle = 1;
                    goto gotoHandle;
                }
                else if (x == 15){
                    chess.clientServerToggle = 2;
                    cout << "Please enter ip address of server" << endl;
                    string ip_address;
                    cin >> ip_address;
                    char ipAddress[16];
                    strcpy(ipAddress, ip_address.c_str());
                    ipArray = ipAddress;
                    goto gotoHandle;
                }
                else {
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    x = 0;
                }
            }
            while (true){
                cout << "Please enter letter for piece you wish to move or 9 to exit" << endl;
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
                cout << "Please enter number for were you wish piece to move to or 9 to exit" << endl;
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
                cout << "Please enter letter for were you wish piece to move to or 9 to exit" << endl;
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
        remove("Chess.txt");
        chess.initialiseBoard();
        system("clear");
        chess.printBoardToTerminal();
        while (true){
            while (true){
                cout << "Please enter number for piece you wish to move or 10 for help" << endl;
                cin >> x;
                if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8){
                    break;
                }
                else if (x == 9)
                    return 0;
                else if (x == 10){
                    cout << "Welcome to Abbotts Chess \n" <<
                                 "\n" <<
                                 "Chess allows all regulation moves by asking the user for input of the four co-ordinates in succession\n"
                                 "required for the move. Numeric and then alpha co-ordinates for the piece player wishes to move and then\n"
                                 "numeric followed by alpha co-oridnates for square piece is to be moved to.\n" <<
                                 "\n" <<
                                 "Castling is accomplished by using the kings starting position followed by the position the king would\n"
                                 "land after move as co-ordinates. Rook will move to position next to king automatically. Castling is only\n"
                                 "available if both left rook and king have not been moved over the game.\n" <<
                                 "\n" <<
                                 "Enpassant is accomplished when a pawn is in correct position and an opposing pawn one square to the\n" <<
                                 "left or right in its starting position moves two squares therefor overtaking the player pawns position.\n" <<
                                 "The square that the opposing pawn moved over will become available as a move for the players pawn\n"
                                 "allowing enpassant taking of pawns.\n" <<
                                 "\n" <<
                                 "10 Help Screen you are seeing now \n" <<
                                 "11 Save Game State\n" <<
                                 "12 Restore Game State\n" <<
                                 "13 Reinitialize Board (new game)\n" <<
                                 "14 Set Server to wait for Client\n" <<
                                 "15 Connect to Server as Client\n" <<
                                 "16 Change sides colour\n" <<
                                 "17 Clear Screen toggle\n" <<
                                 "\n" <<
                                 "22 Take move back\n" <<
                                 "\n" <<
                                 "9 Exit game\n" <<
                                 "" << endl;
                }
                else if (x == 11){

                    time_t current = time(nullptr);
                    string dateTime = ctime(&current);
                    replace(dateTime.begin(), dateTime.end(), ' ', '-');
                    replace(dateTime.begin(),dateTime.end(), ':', ',');
                    replace(dateTime.begin(),dateTime.end(), '\n', '.');


                    ofstream outFileHandle;

                    string saveFile = "gamesave/" + dateTime;
                    outFileHandle.open(saveFile ,ios_base::app);


                    ifstream inFileHandle;
                    string line;
                    inFileHandle.open("Chess.txt");
                    while(getline(inFileHandle, line)){
                        outFileHandle << line << "\n";
                    }
                    inFileHandle.close();
                    outFileHandle.close();
                    
                }
                else if (x == 12){
                    string path = "gamesave/";
                    vector<string> dir;
                    cout << "Please enter the corresponding number to the game you wish to restore" << endl;
                    int i = 1;
                    for (const auto & entry : directory_iterator(path)){
                        cout << i << " " << entry.path() << endl;
                        dir.push_back(entry.path());
                        i++;
                    }
                    string loadInput;
                    int index;
                    while(true) {
                        cin >> index;
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
                else if (x == 13){
                    chess.initialiseBoard();
                    chess.printBoardToTerminal();
                }
                else if (x == 14){
                    chess.clientServerToggle = 1;
                    goto gotoHandle;
                }
                else if (x == 15){
                    chess.clientServerToggle = 2;
                    cout << "Please enter ip address of server" << endl;
                    string ip_address;
                    cin >> ip_address;
                    char ipAddress[16];
                    strcpy(ipAddress, ip_address.c_str());
                    ipArray = ipAddress;
                    goto gotoHandle;
                }
                else if (x == 22){
                    if(chess.recallMove())
                        chess.printBoardToTerminal();
                    else
                        cout << "There are no move moves to recall." << endl;
                }
                else{
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    x = 0;
                }

            }
            while (true){
                cout << "Please enter letter for piece you wish to move or 9 to exit" << endl;
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
                cout << "Please enter number for were you wish piece to move to or 9 to exit" << endl;
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
                cout << "Please enter letter for were you wish piece to move to or 9 to exit" << endl;
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
                system("clear");
                chess.printBoardToTerminal();
                chess.engineMove();
                system("clear");
                chess.printBoardToTerminal();
            }
        }
    }
    return 0;
}
