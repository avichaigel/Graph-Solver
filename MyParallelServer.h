//
// Created by avichai on 23/01/2020
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H


#include "Server.h"
// please see the comments in the cpp file
class MyParallelServer : public server_side::Server {
private:
    int socketCounter = 0;
public:
    void callThread(int client_socketfd, ClientHandler* c);
    void open(int port, ClientHandler* c) override ;
    void close() override ;
    void start(int port, ClientHandler* c);
};


#endif //EX4_MYPARALLELSERVER_H
