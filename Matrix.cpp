//
// Created by avichai on 19/01/2020.
//

#include "Matrix.h"

State<Point> *Matrix::getInitialState() {
    return nullptr;
}

bool Matrix::isGoalState(State<Point> *s) {
    return false;
}

vector<State<Point>*> Matrix::getAllPossibleStates(State<Point> *s) {
}

Point Matrix::getGoalState() {
    return Point(0, 0);
}

string Matrix::to_string() {
    return std::__cxx11::string();
}

void Matrix::setInitialState(State<Point> *initial) {
    Matrix::initialState = initial;
}

void Matrix::setGoalState(State<Point> *goal) {
    Matrix::goalState = goal;
}
