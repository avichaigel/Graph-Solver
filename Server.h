//
// Created by avichai on 14/01/2020.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#include "ClientHandler.h"

using namespace std;

namespace server_side {
    class Server {
        virtual void open(int port, ClientHandler c);
        virtual void close();
    };
}

#endif //EX4_SERVER_H
