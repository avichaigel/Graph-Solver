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
#include "BFS.h"
#include "DFS.h"
#include "Astar.h"

namespace boot {
    class Main {
    public:
        // initiate all the necessary classes to run the program
        void main(int port) {
            Searcher<Point>* searcher = new AStar<Point>();
            MatrixSolver* solver = new MatrixSolver(searcher);
            CacheManager<string, string>* cm = new FileCacheManager();
            cm->get("start");
            ClientHandler* handler = new MyMatrixClientHandler(solver, cm);
            server_side::Server* server = new MyParallelServer();
            server->open(port, handler);
        }
    };
}


#endif //EX4_BOOT_H
