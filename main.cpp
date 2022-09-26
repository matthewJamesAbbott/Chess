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
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <numeric>

#define PORT 9008
#define SERVER 1
#define GUI 0
#define CLIENT 2
#define SOLO 3
#define BLACK 0
#define WHITE 1

using namespace std;
using std::experimental::filesystem::directory_iterator;

bool is_number(const std::string& s){ // checks string to see if it contains only numbers
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int main(int argc, char *argv[]){
    Game chess;
    bool clearSwitch = true; // turns clear screen on and off for terminal
    experimental::filesystem::create_directory("gamesave");
    if(argc == 1){ // no arguements straight to XWindows client.
        chess.clientServerToggle = GUI;
    }
    else{ // otherwise collect arguements
        for (int i = 0; i < argc; i++){
            if(!strcmp(argv[i], "-s")){ // game started as server in terminal
                cout << "Please Enter Name for Player" << std::endl;
       string name;
       cin >> name;
       chess.setPlayerOne(name);
                cout << "Game is now running as server and waiting for a client to connect" << endl;
                chess.clientServerToggle = SERVER;
            }
            if(!strcmp(argv[i], "-c")){  // game started as client in terminal
                cout << "Please Enter Name for Player" << std::endl;
       string name;
       cin >> name;
       chess.setPlayerOne(name);
                    chess.clientServerToggle = CLIENT;
            }
            if(!strcmp(argv[i], "-ai")){ // game started with computer player in terminal
                cout << "Please Enter Name for Player" << std::endl;
       string name;
       cin >> name;
       chess.setPlayerOne(name);
                chess.clientServerToggle = SOLO;
            }
            if(!strcmp(argv[i], "--help")){cout << "Usage: Chess [OPTION] ... [IP ADDRESS]\n" <<
                                                        "Chess will run with no arguments as a standalone game in XWindows or with arguements in the terminal as solo, client and server\n" <<
                                                        "   -ai                 run Chess in Terminal and play Computer AI\n" <<
                                                        "   -s                  run Chess as server\n" <<
                                                        "   -c [IP ADDRESS]     run Chess as client connecting to [IP ADDRESS]" << endl; return 0;}
        }
    }
    int x, xa;
    char y, ya;
    char* ipArray = argv[2];
    gotoHandle:




    if(chess.clientServerToggle == CLIENT){ // begin routines for client in terminal


        /*
         * store pieces in 2D array board
         * send object chess.gameBoard to Print via Games inheritance to print to terminal
         *
         */


        chess.initialiseBoard();
        chess.printBoardToTerminal(chess.gameBoard);

        /*
         * network routines for client 
         *
         */


        int clientSocket;
        clientSocket = socket(AF_INET , SOCK_STREAM , 0); // open socket
        if(clientSocket < 0){
            cout << "Creation of client socket failed" << endl;
            return 0;
        }
        struct sockaddr_in serverAddr; // setup sin struct
        serverAddr.sin_family = AF_INET; // family
        serverAddr.sin_addr.s_addr = inet_addr(ipArray); // ip address
        serverAddr.sin_port = htons(PORT); // port

        if(connect(clientSocket ,  (struct sockaddr*) & serverAddr , sizeof(serverAddr)) < 0){ // connect to server
            cout << "Connection Error..." << endl;
            return 0;
        }
        else{
            cout << "\t\tConnection Established..." << endl;
        }

        /*
         * clients game loop
         * take and parse input from user from the terminal
         *
         */


        while (true){
            while (true){
                cout << "Please enter number for piece you wish to move or 9 to exit" << endl;
                cin >> x;
                if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8){ // test input for numeric co ordinate
                    break;
                } 
                else if (x == 9) // test input for game exit
                    return 0;
                else if (x == 10){ // test input for help
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
                         "17 Clear Screen toggle\n" <<
                         "\n" <<
                         "22 Take move Back\n" <<
                         "\n" <<
                         "9 Exit game\n" <<
                         "" << endl;
                }
                else if (x == 11){ // test input for save game

                    /*
                     * create string representation of the time and date for a filename
                     *
                     */

                    time_t current = time(nullptr);
                    string dateTime = ctime(&current);
                    replace(dateTime.begin(),dateTime.end(), ' ', '-');
                    replace(dateTime.begin(),dateTime.end(), ':', ',');
                    replace(dateTime.begin(),dateTime.end(), '\n', '.');

                    /*
                     * copy game state from Chess.txt to file in gamesave 
                     *
                     */


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


                else if (x == 12){ // test input for restore game
                    string path = "gamesave/";
                    vector<string> dir;
                    cout << "Please enter the corresponding number to the game you wish to restore" << endl;
                    
                    /*
                     * display contents of directory gamesave
                     *
                     */


                    int i = 1;
                    for (const auto & entry : directory_iterator(path)){
                        cout << i << " " << entry.path() << endl;
                        dir.push_back(entry.path());
                        i++;
                    }

                    /*
                     * take input of users choice of saved game state
                     *
                     */


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

                    /*
                     * load save state from users choice
                     * send object chess.gameBoard to Print via Game's inheritance to print to terminal
                     * solution to child data member shared with parent.
                     *
                     */

                    chess.loadGame(loadInput);
                    chess.printBoardToTerminal(chess.gameBoard);
                }



                else if (x == 13){ // test input for new game
                    chess.initialiseBoard();
                    chess.printBoardToTerminal(chess.gameBoard);
                }



                else if (x == 14){ // test input for start game as server
                    chess.clientServerToggle = SERVER;
                    goto gotoHandle;
                }


                else if (x == 15){ // test input for start game as client
                    chess.clientServerToggle = CLIENT;
                    cout << "Please enter ip address of server" << endl;
                    string ip_address;
                    cin >> ip_address;
                    char ipAddress[16];
                    strcpy(ipAddress, ip_address.c_str());
                    ipArray = ipAddress;
                    goto gotoHandle;
                }
                else{ // catch bad input
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    x = 0;
                }
            }
            while (true){ // test input for alpha co ordinate
                cout << "Please enter letter for piece you wish to move or 9 to exit" << endl;
                cin >> y;
                if (y == 'a' || y == 'A' || y == 'b' || y == 'B' || y == 'c' || y == 'C' || y == 'd' || y == 'D'
                    || y == 'e' || y == 'E' || y == 'f' || y == 'F' || y == 'g' || y == 'G' || y == 'h' || y == 'H'){
                    break;
                } 
                else if (y == '9') // test input for game exit
                    return 0;

                else{ // catch bad input
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    y = 0;
                }
            }

            while (true){ // test input for numeric co ordinate
                cout << "Please enter number for were you wish piece to move to or 9 to exit" << endl;
                cin >> xa;
                if (xa == 1 || xa == 2 || xa == 3 || xa == 4 || xa == 5 || xa == 6 || xa == 7 || xa == 8){
                    break;
                } 
                else if (xa == 9) // test input for game exit
                    return 0;

                else{ // catch bad input
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    xa = 0;
                }
            }

            while (true){ // test input for alpha co ordinate
                cout << "Please enter letter for were you wish piece to move to or 9 to exit" << endl;
                cin >> ya;
                if (ya == 'a' || ya == 'A' || ya == 'b' || ya == 'B' || ya == 'c' || ya == 'C' || ya == 'd' || ya == 'D'
                    || ya == 'e' || ya == 'E' || ya == 'f' || ya == 'F' || ya == 'g' || ya == 'G' || ya == 'h' ||
                    ya == 'H'){
                    break;
                } else if (ya == '9') // test input for game exit
                    return 0;
                else{ // catch bad input
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    ya = 0;
                }
            }



            /*
             * move piece in 2D array board
             * send object chess.gameBoard to Print via Games inheritance to print to terminal
             * 
             */


            chess.movePiece(x, y, xa, ya);
            chess.printBoardToTerminal(chess.gameBoard);


            /*
             * send move to server
             * wait for server to respond then
             * store reply in array
             *
             */


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

            /*
             * convert numeric chars to integers
             * move piece in 2D array board
             * send object chess.gameBoard to Print via Games inheritance to print to terminal
             *
             */

            int a = receiveMessage[0] - '0';
            int b = receiveMessage[2] - '0';
            chess.movePiece(a,receiveMessage[1],b,receiveMessage[3]);
            chess.printBoardToTerminal(chess.gameBoard);
        }

    }


    if(chess.clientServerToggle == SERVER){ // begin routines for server in terminal


        /*
         * store pieces in 2D array board
         * send object chess.gameBoard to Print via Game's inheritance to print to terminal
         *
         */


        chess.initialiseBoard();
        chess.printBoardToTerminal(chess.gameBoard);


        /*
         * network routines for server
         *
         */

        int serverSocketHandler = socket(AF_INET , SOCK_STREAM , 0); // open socket
        if(serverSocketHandler < 0){
            cout << "Socket creation has failed.";
            return 0;
        }

        struct sockaddr_in serverAddr , clientAddr; // setup sin struct
        serverAddr.sin_family = AF_INET; // family
        serverAddr.sin_port = htons(PORT); // port
        serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // ip address

        int bindStatus = bind(serverSocketHandler , (struct sockaddr*) & serverAddr , sizeof(serverAddr)); // bind to socket
        if(bindStatus < 0){
            cout << "Socket binding has failed" << endl;
            return 0;
        }

        int listenStatus = listen(serverSocketHandler , 5); // set socket to listen
        if(listenStatus < 0){
            cout << "Listener has failed" << endl;
            return 0;
        }
        cout << "..Waiting for connections.. \n";
        
        socklen_t len = sizeof(clientAddr); // get size of socket in bits
        int connection;
        if((connection = accept(serverSocketHandler , (struct sockaddr*) & clientAddr , &len)) < 0){ // accept connection
            cout << "Server didn't accept the request." << endl;
            return 0;
        }
        else{
            cout << "Server accepted the request. \n" ;
        }


        /*
         * servers game loop
         *
         */



        while (true){
            char receiveMessage[MAX]; // intialise array to store clients move
            int rMsgSize = recv(connection , receiveMessage , MAX , 0); // receive clients move
            if(rMsgSize < 0){
                cout << "Packet receive failed." << endl;
                return 0;
            }
            else if(rMsgSize == 0){
                cout << "Server is off." << endl;
                return 0;
            }

            /*
             * extract numeric co ordinates and convert to integers
             *
             */


            int a = receiveMessage[0] - '0';
            int b = receiveMessage[2] - '0';

            /*
             * move piece in 2D array board
             * send object chess.gameBoard to Print via Game's inheritance to print to terminal
             *
             */


            chess.movePiece(a,receiveMessage[1],b,receiveMessage[3]);
            chess.printBoardToTerminal(chess.gameBoard);


            /*
             * take and parse input from user from the terminal
             *
             */



            while (true){ 
                cout << "Please enter number for piece you wish to move or 9 to exit" << endl;
                cin >> x;
                if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8){ // test input for numeric co ordinate
                    break;
                } 
                else if (x == 9) // test input for game exit
                    return 0;
                else if (x == 10){ // test input for help
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
                         "17 Clear Screen toggle\n" <<
                         "\n" <<
                         "22 Take move back\n" <<
                         "\n" <<
                         "9 Exit game\n" <<
                         "" << endl;
                }
                else if (x == 11){ // test input for save game

                    time_t current = time(nullptr);
                    string dateTime = ctime(&current);
                    replace(dateTime.begin(),dateTime.end(), ' ', '-');
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
                else if (x == 12){ // test input for restore game
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
                    chess.printBoardToTerminal(chess.gameBoard);
                }
                else if (x == 13){ // test input for new game
                    chess.initialiseBoard();
                    chess.printBoardToTerminal(chess.gameBoard);
                }
                else if (x == 14){ // test input for start game as server
                    chess.clientServerToggle = SERVER;
                    goto gotoHandle;
                }
                else if (x == 15){ // test input for start game as client
                    chess.clientServerToggle = CLIENT;
                    cout << "Please enter ip address of server" << endl;
                    string ip_address;
                    cin >> ip_address;
                    char ipAddress[16];
                    strcpy(ipAddress, ip_address.c_str());
                    ipArray = ipAddress;
                    goto gotoHandle;
                }
                else { // catch bad input
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    x = 0;
                }
            }
            while (true){ // take input and test for alpha co ordinate
                cout << "Please enter letter for piece you wish to move or 9 to exit" << endl;
                cin >> y;
                if (y == 'a' || y == 'A' || y == 'b' || y == 'B' || y == 'c' || y == 'C' || y == 'd' || y == 'D'
                    || y == 'e' || y == 'E' || y == 'f' || y == 'F' || y == 'g' || y == 'G' || y == 'h' || y == 'H'){
                    break;
                } 
                else if (y == '9') // test input for game exit
                    return 0;
                else{ // catch bad input
                    cout << "You have entered an illegal character please try again" << endl;
                    cin.clear();
                    cin.ignore(1, '\n');
                    y = 0;
                }
            }
            while (true){ // take input and test for numeric co ordinate
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
            chess.printBoardToTerminal(chess.gameBoard);
            char input[4];
            input[0] = x + '0';
            input[1] = y;
            input[2] = xa + '0';
            input[3] = ya;
            send(connection , input , strlen(input)+1 , 0);
        }
    }
    if(chess.clientServerToggle == SOLO){ // begin routines for game with computer player in terminal
        remove("Chess.txt");
        chess.initialiseBoard();
        system("clear");
        chess.printBoardToTerminal(chess.gameBoard);
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
                                 "16 Reset Game and change side/colour\n" <<
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
                    chess.printBoardToTerminal(chess.gameBoard);
                }
                else if (x == 13){
                    chess.initialiseBoard();
                    chess.printBoardToTerminal(chess.gameBoard);
                }
                else if (x == 14){
                    chess.clientServerToggle = SERVER;
                    goto gotoHandle;
                }
                else if (x == 15){
                    chess.clientServerToggle = CLIENT;
                    cout << "Please enter ip address of server" << endl;
                    string ip_address;
                    cin >> ip_address;
                    char ipAddress[16];
                    strcpy(ipAddress, ip_address.c_str());
                    ipArray = ipAddress;
                    goto gotoHandle;
                }
                else if (x == 16){
                    if(chess.playerSide == BLACK) {
                        chess.playerSide = WHITE;
                        chess.initialiseBoardReverse();
                        chess.printBoardToTerminal(chess.gameBoard);
                    }
                    else {
                        chess.playerSide = WHITE;
                        chess.initialiseBoard();
                        chess.printBoardToTerminal(chess.gameBoard);
                    }
                }
                else if (x == 17){
                    if (clearSwitch)
                        clearSwitch = false;
                    else
                        clearSwitch = true;
                }
                else if (x == 22){
                    if(chess.recallMove())
                        chess.printBoardToTerminal(chess.gameBoard);
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
                if(clearSwitch)
                    system("clear");
                chess.printBoardToTerminal(chess.gameBoard);
                chess.engineMove();
                if(clearSwitch)
                    system("clear");
                chess.printBoardToTerminal(chess.gameBoard);
            }
        }
    }

    if(chess.clientServerToggle == GUI){ // begin routines for XWindows interface
        remove("Chess.txt");
        chess.initialiseBoard();
        bool leftMouseButtonDown = false;
        bool quit = false;
        SDL_Event event;
        chess.initSDL();
        chess.printBoardToWindow(chess.gameBoard);
        system("clear");
        chess.printBoardToTerminal(chess.gameBoard);
        bool squareSelected = false;
        int originNumeric, squareNumeric, optionToggle;
        char originAlpha, squareAlpha;
        optionToggle = 0;
        chess.guiOptionToggle = 0;
        int textAreaToggle = 0;
        while (!quit) {
            SDL_WaitEvent(&event);

            switch (event.type) {
                case SDL_KEYDOWN:
                    cout << "key pressed" << endl;    
                case SDL_MOUSEBUTTONDOWN:
                    if(event.motion.y > 679 && event.motion.x < 85){
                        if(optionToggle == 0){
                            chess.printOptionsToWindow();
                            optionToggle = 1;
                            break;
                        }
                        else{
                            chess.printBoardToWindow(chess.gameBoard);
                            optionToggle = 0;
                            break;
                        }
                    }
                    if(optionToggle == 0){
                        if(((event.motion.x / 85) - 1) == 7){
                            squareAlpha = 'H';
                        }
                        if(((event.motion.x / 85) - 1) == 6){
                            squareAlpha = 'G';
                        }
                        if(((event.motion.x / 85) - 1) == 5){
                            squareAlpha = 'F';
                        }
                        if(((event.motion.x / 85) - 1) == 4){
                            squareAlpha = 'E';
                        }
                        if(((event.motion.x / 85) - 1) == 3){
                            squareAlpha = 'D';
                        }
                        if(((event.motion.x / 85) - 1) == 2){
                            squareAlpha = 'C';
                        }
                        if(((event.motion.x / 85) - 1) == 1){
                            squareAlpha = 'B';
                        }
                        if(((event.motion.x / 85) - 1) == 0){
                            squareAlpha = 'A';
                        }
                        if((event.motion.y / 85) == 0)
                            squareNumeric = 8;
                        if((event.motion.y / 85) == 1)
                            squareNumeric = 7;
                        if((event.motion.y / 85) == 2)
                            squareNumeric = 6;
                        if((event.motion.y / 85) == 3)
                            squareNumeric = 5;
                        if((event.motion.y / 85) == 4)
                            squareNumeric = 4;
                        if((event.motion.y / 85) == 5)
                            squareNumeric = 3;
                        if((event.motion.y / 85) == 6)
                            squareNumeric = 2;
                        if((event.motion.y / 85) == 7)
                            squareNumeric = 1;

                        if(squareSelected){
                            squareSelected = false;
                            if(chess.movePiece(originNumeric, originAlpha, squareNumeric, squareAlpha)){
                                if(!chess.engineMove()){
                                    chess.initialiseBoard();
                                }
                                chess.printBoardToWindow(chess.gameBoard);
                                system("clear");
                                chess.printBoardToTerminal(chess.gameBoard);
                            }

                        }
                        else{
                            squareSelected = true;
                            originAlpha = squareAlpha;
                            originNumeric = squareNumeric;
                        }
                    }

                    // Option Window
                    else{
                        // Set text input to none if not selected.
                        if(!(event.motion.x >= 100 && (event.motion.x <= 100 + 85) && (event.motion.y >= 85 + 50*    2) && (event.motion.y <= 85 + 50*2 + 40)) || !(event.motion.x >= 85 && (event.motion.x <= 85*3) && (event.motion.y >= 85 + 50*4) &&    (event.motion.y <= 85 + 50*4 + 40)) || !((event.motion.x >= 85*6) && (event.motion.x <= 85*7) && (event.motion.y >= 85 + 50*     4) && (event.motion.y <= 85 + 50*4 + 40)))
                            textAreaToggle = 0;
                        // Play game against the computer
                        if((event.motion.x >= 85*8) && (event.motion.x <= 85*8 + 40) && event.motion.y >= 85 && event.motion.y <= 85 + 40){
                            chess.guiOptionToggle = 0;   
                            chess.printOptionsToWindow();
                        }
                        // Start game as server
                        if((event.motion.x >= 85*8) && (event.motion.x <= 85*8 + 40) && (event.motion.y >= 85 + 50) && (event.motion.y <= 85 + 50 + 40)){
                            chess.guiOptionToggle = SERVER;
                            chess.printOptionsToWindow();
                        }
                        // Connect to server as client
                        if((event.motion.x >= 85*8) && (event.motion.x <= 85*8 + 40) && (event.motion.y >= 45 + 50*3) && (event.motion.y <= 85 + 50*3 + 40)){
                            chess.guiOptionToggle = CLIENT;
                            chess.printOptionsToWindow();
                        }
                        // Text area for server port
                        if(event.motion.x >= 100 && (event.motion.x <= 100 + 85) && (event.motion.y >= 85 + 50*2) && (event.motion.y <= 85 + 50*2 + 40)){
                            textAreaToggle = 1;
                        }
                        // Text area for client ip
                        if(event.motion.x >= 85 && (event.motion.x <= 85*3) && (event.motion.y >= 85 + 50*4) && (event.motion.y <= 85 + 50*4 + 40)){
                            textAreaToggle = 2;
                        }
                        // Text are for client port
                        if((event.motion.x >= 85*6) && (event.motion.x <= 85*7) && (event.motion.y >= 85 + 50*4) && (event.motion.y <= 85 + 50*4 + 40)){
                            textAreaToggle = 3;
                        }
                        // Change Sides
                        if((event.motion.x >= 85*6 + 15) && (event.motion.x <= 85*6 + 15 + 40) && (event.motion.y >= 85 + 50*5) && (event.motion.y <= 85 + 50*5 + 40)){
                            if(chess.playerSide == BLACK) {
                                chess.playerSide = WHITE;
                                chess.initialiseBoardReverse();
                            }
                            else {
                                chess.playerSide = WHITE;
                                chess.initialiseBoard();
                            }

                        }
                        // Start new game
                        if((event.motion.x >= 85*6 + 15) && (event.motion.x <= 85*6 + 15 + 40) && (event.motion.y >= 85 + 50*6) && (event.motion.y <= 85 + 50*6 + 40)){
                            if(chess.playerSide == BLACK)
                                chess.initialiseBoard();
                            else
                                chess.initialiseBoardReverse();
                        }
                        // Save game
                        if((event.motion.x >= 85*6 + 15) && (event.motion.x <= 85*6 + 15 + 40) && (event.motion.y >= 85 + 50*7) && (event.motion.y <= 85 + 50*7 + 40)){
                            time_t current = time(nullptr);
                            string dateTime = ctime(&current);
                            replace(dateTime.begin(), dateTime.end(), ' ', '-');
                            replace(dateTime.begin(), dateTime.end(), ':', ',');
                            replace(dateTime.begin(), dateTime.end(), '\n', '.');
      
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
                        // Recall move
                        if((event.motion.x >= 85*6 + 15) && (event.motion.x <= 85*6 + 15 + 40) && (event.motion.y >= 85 + 50*8) && (event.motion.y <= 85 + 50*8 + 40)){
                
                        }
                        // Load save game
                        if((event.motion.x >= 85*6 + 15) && (event.motion.x <= 85*6 + 15 + 40) && (event.motion.y >= 85 + 50*9) && (event.motion.y <= 85 + 50*9 + 40)){
   
                        }


                    }
                    break;
                  /* 
                case SDL_TEXTINPUT:
                    if(textAreaToggle == 1){
                        
                        char *input;
                        strcat(input, event.text.text);
                        string test = "";
                        test.append(input);
                        if(is_number(test)){
                           // chess.serverPort = input;
                        }

                        break;
                    }
                    else if(textAreaToggle == 2){

                    }
                    else if(textAreaToggle == 3){

                    }*/
                case SDL_QUIT:
                    quit = true;
                    break;

            }
        }
    chess.destroySDL();
    SDL_Quit();
    }
    return 0;
}
