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

class MyMatrixClientHandler : public ClientHandler {
private:
    Solver<string, string>* solver;
    CacheManager<string, string>* cm;
public:
    MyMatrixClientHandler(Solver<string, string>*, CacheManager<string, string>*);
    void handleClient(int client_socketfd) override;
    vector<string> readFromBuffer(int client_socketfd);
    Matrix *createMatrix(vector<string> line);
};


#endif //EX4_MYMATRIXCLIENTHANDLER_H
