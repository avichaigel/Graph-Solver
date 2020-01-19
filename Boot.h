//
// Created by avichai on 16/01/2020.
//

#ifndef EX4_BOOT_H
#define EX4_BOOT_H

#include "MySerialServer.h"
#include "Solver.h"
#include "CacheManager.h"
#include "StringReverser.h"
#include "MyTestClientHandler.h"

namespace boot {
    class Main {
    public:
        void main(int port) {
            Solver<string, string>* solver = new StringReverser();
            CacheManager<string, string>* cm = new FileCacheManager();
            ClientHandler* handler = new MyTestClientHandler(solver, cm);
           server_side::Server* server = new MySerialServer();
           server->open(port, handler);
        }
    };
}


#endif //EX4_BOOT_H
