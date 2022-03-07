//
// Created by squig on 26/2/22.
//

#ifndef CHESS_NETSERVER_H
#define CHESS_NETSERVER_H
#include <string>


class NetServer {
private:
    int network_socket;
    int client_socket;
    std::string server_message;
    std::string client_message;

public:
    NetServer();
    void start(const char *ip_address, int port);
    bool sendMove(char* message);
    void receiveMove();
    void closeConnection();


};


#endif //CHESS_NETSERVER_H
