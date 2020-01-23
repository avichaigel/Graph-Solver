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
    //todo implement - all of the matrix states as a vector
}

Point Matrix::getGoalState() {
    return this->goalState->getState();
}

string Matrix::to_string() {
    //todo implement
}

void Matrix::setInitialState(State<Point> *initial) {
    this->initialState = initial;
}

void Matrix::setGoalState(State<Point> *goal) {
    this->goalState = goal;
}
