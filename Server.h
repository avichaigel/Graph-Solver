//
// Created by avichai on 14/01/2020.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#include "ClientHandler.h"

using namespace std;
// an interface that represent every server that could be used in the program
namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler* c) = 0;
        virtual void close() = 0;
    };
}

#endif //EX4_SERVER_H
