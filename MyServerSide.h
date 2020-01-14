//
// Created by avichai on 14/01/2020.
//

#ifndef EX4_MYSERVERSIDE_H
#define EX4_MYSERVERSIDE_H

#include "Server.h"

class MySerivalServer : public server_side::Server {
    void open(int port, ClientHandler c) override ;
    void close() override ;
};

#endif //EX4_MYSERVERSIDE_H
