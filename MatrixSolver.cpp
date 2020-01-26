//
// Created by avichai on 23/01/2020.
//

#include <iostream>
#include "MatrixSolver.h"

// function that get the solution of a problem and convert it to a visible string
string MatrixSolver::solve(ISearchable<Point> *problem) {
    vector<State<Point>*> solution = searcher->search(problem);
    string path, direction;
    vector<string> reversedVec;
    for (int s=0; s < solution.size()-1; s++) {
        auto current = solution[s];
        auto father = solution[s+1];
        auto currI = current->getState().getI();
        auto currJ = current->getState().getJ();
        auto fathI = father->getState().getI();
        auto fathJ = father->getState().getJ();
        if (currI > fathI) {
            direction = "down (" + to_string((int)current->getPathCost()) + "),";
        } else if (currI == fathI) {
            if (currJ > fathJ) {
                direction = "right (" + to_string((int)current->getPathCost()) + "),";
            } else if (currJ < fathJ) {
                direction = "left (" + to_string((int)current->getPathCost()) + "),";
            }
        } else if (currI < fathI){
            direction = "up (" + to_string((int)current->getPathCost()) + "),";
        }
        reversedVec.emplace_back(direction);
    }
    for (auto i = reversedVec.rbegin(); i != reversedVec.rend(); ++i ) {
        path += *i;
    }
    path = path.substr(0, path.size()-1);
    return path;
}