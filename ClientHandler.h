//
// Created by avichai on 14/01/2020.
//

#include <iostream>

using namespace std;

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H


class ClientHandler {
    virtual void handleCLient(istream input, fstream output);
};


#endif //EX4_CLIENTHANDLER_H
