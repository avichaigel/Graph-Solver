//
// Created by avichai on 14/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include "Server.h"
#include "Solver.h"
#include "CacheManager.h"
#include "FileCacheManager.h"

class MySerialServer : public server_side::Server {
private:
public:
    void open(int port, ClientHandler* c) override ;
    void close() override ;
};

#endif //EX4_MYSERIALSERVER_H
