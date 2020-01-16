//
// Created by avichai on 14/01/2020.
//

#include "MyTestClientHandler.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>

MyTestClientHandler::MyTestClientHandler(Solver<string, string>, CacheManager<string, string>):
solver(solver), cm(cm){} //todo handle these warnings

void MyTestClientHandler::handleCLient(int client_socketfd) {
    while (isReading) {
        char buffer[1024];
        int valread = read(client_socketfd, buffer, 1024);
        if (valread < 1) {
            cerr << "Error while reading from client" << endl;
        }
        string problem(buffer);

        if (problem == "end") {
            isReading = false;
        }

        string solution = cm.get(problem);

        if (solution != NULL) {
            int is_sent = send(client_socketfd, solution.c_str(), solution.length(), 0);
            if (is_sent == -1) {
                cout << "Error while sending data to client" << endl;
            }
        } else {
            solver.solve(problem);
        }
    }
}


