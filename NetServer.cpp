//
// Created by Matthew Abbott on 26/2/22.
//

#include "NetServer.h"
#include "NetClient.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <cstring>

#define MAX 80
#define PORT 9006


NetServer::NetServer(){    }

void NetServer::start(const char *ip_address, int port){
    char buff[MAX];
    struct sockaddr_in server_address;
    // create a socket

    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    bzero(&server_address, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // bind the socket to our specified IP and port
    bind(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    std::cout << "bound to socket" << std::endl;
    listen(network_socket, 5);
    std::cout << "listening" << std::endl;
    client_socket = accept(network_socket, NULL, NULL);



}

bool NetServer::sendMove(char* message){

//    for(int i = 0; i < 4; i++)
//    {
//        std::cout << message[i] << std::endl;
//    }
    message = "this is a test";
    send(client_socket , message , 5 , 0);
        return false;
}

void NetServer::closeConnection(){
    close(network_socket);
}

void NetServer::receiveMove(){

    char buff[500];


            int rMsgSize = recv(client_socket, buff, 500, 0);
            std::cout << buff << std::endl;
            if (rMsgSize > 0)
                std::cout << rMsgSize << std::endl;
            if (rMsgSize < 0)
                std::cout << "error" << std::endl;
            std::cout << buff << std::endl;

            if (rMsgSize == 0)
            std::cout << "connection failure" << std::endl;
//
//    int returnArray[4];
//    std::cout << returnArray << std::endl;
//    for (int i = 0; i < 4; i++) {
//        returnArray[i] = buff[i] - 48;
//    }
//
//    return returnArray;
}
