//
// Created by squig on 26/2/22.
//

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

#define MAX 80
#define PORT 9006


NetClient::NetClient(const char *ipAddress, int port) {



    // create a socket
    char buff[MAX];
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(ipAddress);

    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    // check for error with the connection
    if (connection_status == -1){
        printf("There was a problem with the connection");
    }
    else{
        printf("Game is now running as client and is connected\n");
    }

}

bool NetClient::sendMove(char *message){

//    for(int i = 0; i < 4; i++)
//    {
//        std::cout << message[i] << std::endl;
//    }

    message = "this is a test";
    send(server_socket , message , 5 , 0);

        return false;
}

void NetClient::receiveMove(){
    char buff[500];


        int rMsgSize = recv(server_socket, buff, 500, 0);
        std::cout << buff << std::endl;
        if(rMsgSize > 0)
            std::cout << rMsgSize << std::endl;
        if(rMsgSize < 0)
            std::cout << "error" << std::endl;
        if(rMsgSize == 0)
            std::cout << "connection failure" << std::endl;

        std::cout << buff << std::endl;
//
//    int returnArray[4];
//    for (int i = 0; i < 4; i++) {
//        returnArray[i] = buff[i] - 48;
//    }
//
//    return returnArray;
}

void NetClient::closeConnection(){
    close(network_socket);
}
