//
// Created by avichai on 14/01/2020.
//

#include <thread>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include "MyParallelServer.h"

#define TIMEOUT 120

void MyParallelServer::start(int port, ClientHandler* c) {

    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        cerr << "Could not create a socket" << endl;
    }
    //bind socket to IP address
    // we first need to create the sockaddr obj.i
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port); //we need to convert our number to a number that the network understands

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr << "Could not bind the socket to an IP" << endl;
    }

    //making socket listen to the port
    if (listen(socketfd, 10) == -1) { //can also set to SOMAXCON (max connections)
        cerr << "Error during listening command" << endl;
    } else {
        cout << "Server is now listening ..." << endl;
    }

    struct timeval tv;
    int timeout_in_seconds = TIMEOUT;
    tv.tv_sec = timeout_in_seconds;
    tv.tv_usec = 0;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);

    bool isConnected = true;
    while (isConnected) { //todo check how to stop it
        if (this->socketCounter < 10) {
            // accepting a client
            int addrlen = sizeof(address);
            int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);

            if (client_socket == -1) {
                cerr << "Error accepting new client, time is out" << endl;
                break;
            } else {
                cout << "Connected to a new client" << endl;
            }
            thread thread(&MyParallelServer::callThread, this, client_socket, c);
            thread.detach();
        }
    }
    ::close(socketfd);
}

void MyParallelServer::open(int port, ClientHandler* c) {
    //call the thread that listens to the simulator and updates values
    start(port, c);
}

void MyParallelServer::close() {
    //todo implement this: change the flag in the while to false, and close the socket
}

void MyParallelServer::callThread(int client_socketfd, ClientHandler* c) {
    this->socketCounter++;
    cout << "thread " << socketCounter << " opened" << endl;
    c->handleClient(client_socketfd);
    ::close(client_socketfd); //closing the client socket //todo check what's the deal with the "::" and if it works or not
    this->socketCounter--;
    cout << "thread " << socketCounter << " closed" << endl;
}
