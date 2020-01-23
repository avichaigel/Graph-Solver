//
// Created by avichai on 19/01/2020.
//

#include "Matrix.h"

State<Point> *Matrix::getInitialState() {
    return this->initialState;
}

bool Matrix::isGoalState(State<Point> *s) {
    return s->getState() == this->getGoalState();
}

vector<State<Point>*> Matrix::getAllPossibleStates(State<Point> *s) {
    vector<State<Point> *> allStates;
    auto mat = getMyMatrix();
    int si = s->getState().getI();
    int sj = s->getState().getJ();
    int i = -1, j = 0;
    for (const auto &line : mat) {
        i++;
        if (i == si - 1 || i == si || i == si + 1) {
            for (auto state : line) {
                if ((i == si - 1 || i == si + 1) && (j == sj)) { //if it's on another line but the same column
                    allStates.push_back(state);
                } else if(i == si && (j == sj -1 || j == sj +1 )) {//if it's on the same line and is a neighbor
                    allStates.push_back(state);
                }
                j++;
            }
            j=0;
        }
    }
    return allStates;
}

Point Matrix::getGoalState() {
    return this->goalState->getState();
}
/*
string Matrix::to_string() {

}*/

void Matrix::setInitialState(State<Point> *initial) {
    this->initialState = initial;
}

void Matrix::setGoalState(State<Point> *goal) {
    this->goalState = goal;
}
