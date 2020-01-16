//
// Created by avichai on 14/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "Solver.h"

class MyTestClientHandler : public ClientHandler{
private:
    Solver<string, string>* solver;
    CacheManager<string, string>* cm;
public:
    MyTestClientHandler(Solver<string, string>*, CacheManager<string, string>*);
    void handleClient(int client_socketfd) override;
};


#endif //EX4_MYTESTCLIENTHANDLER_H
