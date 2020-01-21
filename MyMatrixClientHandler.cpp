//
// Created by avichai on 19/01/2020.
//

#include "MyMatrixClientHandler.h"
#include "Matrix.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <vector>

MyMatrixClientHandler::MyMatrixClientHandler(Solver<string, string>*, CacheManager<string, string>*):
        solver(solver), cm(cm){}

void MyMatrixClientHandler::handleClient(int client_socketfd) { //todo go over this te see it's correct and full
    vector<string> matrixLines = readFromBuffer(client_socketfd); //every node in the vector is a line of the matrix, except for the last two
    string problem;
    for (const auto &piece : matrixLines) problem += piece;
    string solution = cm->get(problem);

    if (solution.empty()) {
        Matrix* matrix = createMatrix(matrixLines);
        solution = solver->solve(matrix); //todo change solver in this header, so that it receives generic type (or Matrix?)
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
            problem = "";
        }
    }
    return line;
}

Matrix* MyMatrixClientHandler::createMatrix(vector<string> matrixLines) {
    auto* matrix = new Matrix();
    int i=0, j=0, size = matrixLines.size();
    for (string str : matrixLines) {
        i++;
        j=0;
        if (i+2 == size) {
            break;
        }
        vector<State<Point*>*> line;
        matrix->getOuter().push_back(line);
        for (char c : str) {
            if (c == ',' || c == ' ') {
                continue;
            }
            j++;
            Point* p = new Point(i, j);
            State<Point*>* state = new State<Point*>(p, c-48);
            line.push_back(state);
        }
    }
    return matrix;
}


