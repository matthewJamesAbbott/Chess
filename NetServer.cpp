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

NetServer::NetServer(){}

void NetServer::start(const char *ip_address, int port){


    // create a socket

    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // bind the socket to our specified IP and port
    bind(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    std::cout << "bound to socket" << std::endl;
    listen(network_socket, 5);
    std::cout << "listening" << std::endl;
    client_socket = accept(network_socket, NULL, NULL);

}

bool NetServer::sendMove(std::string message){

    if(send(client_socket, message.c_str(), message.size(), 0))
        return true;
    else
        return false;
}

void NetServer::closeConnection(){
    close(network_socket);
}

std::string NetServer::receivedMove(){

    std::string server_response;
    recv(network_socket, &server_response, server_response.size(), 0);
    return server_response;
}
