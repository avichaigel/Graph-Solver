//
// Created by avichai on 23/01/2020.
//

#include "MatrixSolver.h"

string MatrixSolver::solve(ISearchable<Point> *problem) {
    vector<State<Point>*> solution = searcher->search(problem);
    string path;
    vector<string> reversedVec;
    for (int s=0; s < solution.size(); s++) {
        auto current = solution[s];
        auto father = solution[s+1];
        auto currI = current->getState().getI();
        auto currJ = current->getState().getJ();
        auto fathI = father->getState().getI();
        auto fathJ = father->getState().getJ();
        if (currI > fathI) {
            reversedVec.emplace_back("down, ");
        } else if (currI == fathI) {
            if (currJ > fathJ) {
                reversedVec.emplace_back("right, ");
            } else if (currJ < fathJ) {
                reversedVec.emplace_back("left, ");
            }
        } else {
            reversedVec.emplace_back("up, ");
        }
    }
    for (auto i = reversedVec.rbegin(); i != reversedVec.rend(); ++i ) {
        path += *i;
    }
    path = path.substr(0, path.size()-2);
    return path;
}