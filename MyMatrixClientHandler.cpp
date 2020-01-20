//
// Created by avichai on 19/01/2020.
//

#include "MyMatrixClientHandler.h"

//
// Created by avichai on 14/01/2020.
//

#include "MyTestClientHandler.h"
#include "Matrix.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <vector>

MyMatrixClientHandler::MyMatrixClientHandler(Solver<string, string>*, CacheManager<string, string>*):
        solver(solver), cm(cm){}

void MyMatrixClientHandler::handleClient(int client_socketfd) {
    vector<string> lineInMatrix = readFromBuffer(client_socketfd);
    Matrix* matrix = createMatrix(lineInMatrix);
    string solution = cm->get(problem);

    if (solution.empty()) {
        solution = solver->solve(problem);
        cm->insert(solution);
    }
    int is_sent = send(client_socketfd, solution.c_str(), solution.length(), 0);
    if (is_sent == -1) {
        cout << "Error while sending data to client" << endl;
    }
}

vector<string> MyMatrixClientHandler::readFromBuffer(int client_socketfd) {
    string problem;
    vector<string> line;
    //loop reads char by char until \n, then adds the received string to the vector
    while (true) {
        char buffer[1];
        int valread = read(client_socketfd, buffer, 1);
        if (valread < 1) {
            cerr << "Error while reading from client" << endl;
        }
        //read until \n, and when string is "end" break loop
        if (buffer[0]!='\n') {
            problem += buffer[0];
        } else {
            if (problem == "end") {
                break;
            }
            line.push_back(problem);
        }
    }
    return line;
}

Matrix* MyMatrixClientHandler::createMatrix(vector<string> line) {

}


