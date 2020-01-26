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
        void main(int port) {
//            Searcher<Point>* searcher = new BestFS<Point>(); //todo change to be all of the options
            Searcher<Point>* searcher = new AStar<Point>();
//            Searcher<Point>* searcher = new BFS<Point>();
//            Searcher<Point>* searcher = new DFS<Point>();
            MatrixSolver* solver = new MatrixSolver(searcher);
            CacheManager<string, string>* cm = new FileCacheManager();
            cm->get("start");
            ClientHandler* handler = new MyMatrixClientHandler(solver, cm);
            server_side::Server* server = new MySerialServer(); //todo change to parallel
            server->open(port, handler);
        }
    };
}


#endif //EX4_BOOT_H
