//
// Created by squig on 26/2/22.
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

NetServer::NetServer(char *ip_address, int port){
    char server_message[256] = "You have transferred some data";

    // create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    // bind the socket to our specified IP and port
    bind(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    listen(network_socket, 5);

    int client_socket;
    client_socket = accept(network_socket, NULL, NULL);

    // send message
    send(client_socket, server_message, sizeof(server_message), 0);

    // close the socket
    close(network_socket);
}

bool NetServer::Send(){

}
