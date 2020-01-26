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
#include <algorithm>

MyMatrixClientHandler::MyMatrixClientHandler(MatrixSolver* solver1, CacheManager<string, string>* cm1): cm(cm1), solver(solver1) {}

void MyMatrixClientHandler::handleClient(int client_socketfd) {
    vector<string> matrixLines = readFromBuffer(client_socketfd); //every node in the vector is a line of the matrix, except for the last two
    //create a string out of all of the matrix's entries, and check if we have a solution for it in cache
    string problem;
    for (const auto &piece : matrixLines) problem += piece;
    problem.erase(remove(problem.begin(), problem.end(), ' '), problem.end());
    mutex_lock.lock();
    string solution = getCm()->get(problem);
    mutex_lock.unlock();

    //if we don't have a solution, solve it and insert it to cache
    if (solution == "-1") {
        Matrix* matrix = createMatrix(matrixLines);
        solution = this->solver->solve(matrix);
        mutex_lock.lock();
        getCm()->insert(solution);
        mutex_lock.unlock();
    }

    int is_sent = send(client_socketfd, solution.c_str(), solution.length(), 0);
    if (is_sent == -1) {
        cout << "Error while sending data to client" << endl;
    }
    solutionCounter++;
    cout << "solution number " << solutionCounter << " sent to client" << endl;
}

vector<string> MyMatrixClientHandler::readFromBuffer(int client_socketfd) {
    string problem;
    vector<string> line;
    char buffer[1];
    int valread;
    //loop reads char by char until \n, then adds the received string to the vector
    while (true) {
        if (problem != "end") {
            valread = read(client_socketfd, buffer, 1);
            if (valread < 1) {
                cerr << "Error while reading from client" << endl;
            }
            //read until \n, and when string is "end" break loop
            if (buffer[0] != '\n') {
                problem += buffer[0];
            } else {
                line.push_back(problem);
                problem = "";
            }
        } else {
            break;
        }
    }
    return line;
}

//create a vector of vectors of <State<Point>>* of the vector of strings,
//in which each string is a line in the matrix
Matrix* MyMatrixClientHandler::createMatrix(vector<string> matrixLines) {
    Matrix* matrix = new Matrix();
    int i=0, j=0, size = matrixLines.size();
    for (string str : matrixLines) {
        j=0;
        string num;
        //if it's initial state
        if (i+2 == size) {
            size_t comma = str.find(',');
            int x = stoi(str.substr(0, comma));
            int y = stoi(str.substr(comma+1));
            auto p = Point(x,y);
            double cost = matrix->getMyMatrix()[x][y]->getCost();
            auto state = new State<Point>(p, cost);
            matrix->setInitialState(state);
        }
        //if it's goal state
        else if (i+1 == size) {
            size_t comma = str.find(',');
            int x = stoi(str.substr(0, comma));
            int y = stoi(str.substr(comma+1));
            auto p = Point(x,y);
            double cost = matrix->getMyMatrix()[x][y]->getCost();
            auto state = new State<Point>(p, cost);
            matrix->setGoalState(state);
        } else {
            vector<State<Point> *> line;
            int len = str.length();
            //split the string by commas
            for (int c = 0; c < len; c++) {
                if (str[c] == ',') {
                    continue;
                }
                num += str[c];
                if (str[c + 1] != ',' && c+1 != len) {
                    continue;
                }
                auto p = Point(i, j);
                auto state = new State<Point>(p, stoi(num));
                line.push_back(state);
                num = "";
                j++;
            }
            matrix->getMyMatrix().push_back(line);
        }
        i++;
    }
    return matrix;
}

MatrixSolver *MyMatrixClientHandler::getSolver() const {
    return solver;
}

CacheManager<string, string> *MyMatrixClientHandler::getCm() const {
    return cm;
}


