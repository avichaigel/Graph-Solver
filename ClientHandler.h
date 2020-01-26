//
// Created by avichai on 14/01/2020.
//

#include <iostream>
#include <mutex>

using namespace std;

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H


class ClientHandler {
protected:
    mutex mutex_lock;
public:
    // function that guides every client in the program how to act
    virtual void handleClient(int client_socketfd) = 0;
};


#endif //EX4_CLIENTHANDLER_H
