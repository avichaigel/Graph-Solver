//
// Created by avichai on 14/01/2020.
//

#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "MySerialServer.h"


void start(int port, ClientHandler* c) {
    while (true) {
        //create socket
        int socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd == -1) {
            //error
            cerr << "Could not create a socket" << endl;
        }
        //bind socket to IP address
        // we first need to create the sockaddr obj.
        sockaddr_in address; //in means IP4
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
        address.sin_port = htons(port); //we need to convert our number to a number that the network understands

        //the actual bind command
        if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
            cerr << "Could not bind the socket to an IP" << endl;
        }

        //making socket listen to the port
        if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
            cerr << "Error during listening command" << endl;
        } else {
            cout << "Server is now listening ..." << endl;
        }

        // accepting a client
        int addrlen = sizeof(address);
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);

        //todo create timeout (maybe above accept?)

        if (client_socket == -1) {
            cerr << "Error accepting client" << endl;
        } else {
            cout << "Connected" << endl;
        }

        c->handleClient(client_socket);
        close(socketfd); //closing the listening socket
    }
}

void MySerialServer::open(int port, ClientHandler* c) {
    //call the thread that listens to the simulator and updates values
    thread thread1(start, port, c);
    thread1.detach();
}

void MySerialServer::close() {
    //todo implement this: change the flag in the while to false, and close the socket
}
