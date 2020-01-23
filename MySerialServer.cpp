//
// Created by avichai on 14/01/2020.
//

#include <thread>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include "MySerialServer.h"


void start(int port, ClientHandler* c) {
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
    //todo change the port to be a variable that receives the port from the python script

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr << "Could not bind the socket to an IP" << endl;
    }
    while (true) { //todo check when and how I end this loop

        //making socket listen to the port
        if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
            cerr << "Error during listening command" << endl;
        } else {
            cout << "Server is now listening ..." << endl;
        }

        /* Start a timer that expires after 2 minutes */
        struct itimerval timer;
        timer.it_value.tv_sec = 120;
        timer.it_value.tv_usec = 0;
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        setitimer (ITIMER_VIRTUAL, &timer, 0);
        //todo check that it expires after 2 minutes sharp

        // accepting a client
        int addrlen = sizeof(address);
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);

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
    start(port, c);
    /*    thread thread1(start, port, c);
    thread1.detach();*/
}

void MySerialServer::close() {
    //todo implement this: change the flag in the while to false, and close the socket
}
