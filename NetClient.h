//
// Created by squig on 26/2/22.
//

#ifndef CHESS_NETCLIENT_H
#define CHESS_NETCLIENT_H

#include <string>


class NetClient {

private:
    int network_socket;
    int server_socket;
    std::string client_message;

public:
    NetClient(const char *ipAddress, int port);

    bool sendMove(std::string message);
    std::string receivedMove();
    void closeConnection();
    char *ipAddress;



};


#endif //CHESS_NETCLIENT_H
