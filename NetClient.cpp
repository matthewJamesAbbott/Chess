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

NetClient::NetClient(char *ip_address, int port){
    // char ip_address[16] = "81.4.106.68";
    // scanf("%15s", ip_address);

    // int port = 9002;
    // create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    // check for error with the connection
    if (connection_status == -1){
        printf("There was a problem with the connection");
    }

    // recieve data from the server
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    // print out the server's response
    printf("data sent by server. %s\n", server_response);

    // and then close the socket
    close(network_socket);
}

bool NetClient::Send(){

}

