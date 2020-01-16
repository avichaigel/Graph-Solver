//
// Created by avichai on 14/01/2020.
//

#include <iostream>

using namespace std;

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H


class ClientHandler {
public:
    virtual void handleCLient(int client_socketfd);
};


#endif //EX4_CLIENTHANDLER_H
