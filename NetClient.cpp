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



NetClient::NetClient(const char *ipAddress, int port) {


 //   char ipAddress[16] = "81.4.106.68";
  //  scanf("%15s", ipAddress);

  //  int port = 9002;
    // create a socket
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
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

bool NetClient::sendMove(std::string message){
    if(send(server_socket, message.c_str(), message.size(), 0))
        return true;
    else
        return false;
}

std::string NetClient::receivedMove(){
    std::string server_response;
    if(!recv(network_socket, &server_response, server_response.size(), 0));
        server_response = "";
    return server_response;
}

void NetClient::closeConnection(){
    close(network_socket);
}
