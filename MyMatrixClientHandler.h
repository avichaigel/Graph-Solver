//
// Created by avichai on 19/01/2020.
//

#ifndef EX4_MYMATRIXCLIENTHANDLER_H
#define EX4_MYMATRIXCLIENTHANDLER_H


#include <vector>
#include "ClientHandler.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "Solver.h"
#include "Matrix.h"
#include "MatrixSolver.h"

class MyMatrixClientHandler : public ClientHandler {
private:
    MatrixSolver* solver;
    CacheManager<string, string>* cm;
public:
    MatrixSolver* getSolver() const;

    CacheManager<string, string> *getCm() const;

public:
    MyMatrixClientHandler(MatrixSolver* solver1, CacheManager<string, string>* cm1);
    void handleClient(int client_socketfd) override;
    static vector<string> readFromBuffer(int client_socketfd);
    Matrix* createMatrix(vector<string> line);
};


#endif //EX4_MYMATRIXCLIENTHANDLER_H
