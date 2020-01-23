//
// Created by avichai on 16/01/2020.
//

#ifndef EX4_BOOT_H
#define EX4_BOOT_H

#include "MySerialServer.h"
#include "Solver.h"
#include "CacheManager.h"
#include "StringReverser.h"
#include "MyMatrixClientHandler.h"
#include "MatrixSolver.h"
#include "BestFS.h"
#include "MyParallelServer.h"

namespace boot {
    class Main {
    public:
        void main(int port) {
            Searcher<Point>* searcher = new BestFS<Point>(); //todo change to be all of the options
            MatrixSolver* solver = new MatrixSolver(searcher);
            CacheManager<string, string>* cm = new FileCacheManager();
            ClientHandler* handler = new MyMatrixClientHandler(solver, cm);
            server_side::Server* server = new MyParallelServer();
            server->open(port, handler);
        }
    };
}


#endif //EX4_BOOT_H
