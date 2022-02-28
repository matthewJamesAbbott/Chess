//
// Created by squig on 26/2/22.
//

#ifndef CHESS_NETCLIENT_H
#define CHESS_NETCLIENT_H

#include <string>

class NetClient {

public:
    NetClient(char *ip_address, int port);
    bool Send();
    std::string Receive();

};


#endif //CHESS_NETCLIENT_H
