//
// Created by squig on 26/2/22.
//

#ifndef CHESS_NETSERVER_H
#define CHESS_NETSERVER_H
#include <string>

class NetServer {
    NetServer(char *ip_address, int port);
    bool Send();
    std::string Receive();


};


#endif //CHESS_NETSERVER_H
