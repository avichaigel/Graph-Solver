//
// Created by avichai on 19/01/2020.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H

#include "State.h"
#include "Point.h"
#include "ISearchable.h"
#include <vector>

using namespace std;

class Matrix : public ISearchable<Point> {
public:

private:
    vector<vector<State<Point>*>> myMatrix;
    State<Point>* initialState;
    State<Point>* goalState;
public:
    vector<vector<State<Point>*>> &getMyMatrix() {
        return myMatrix;
    }
    void setInitialState(State<Point> *initial);
    void setGoalState(State<Point> *goal);
    State<Point>*getInitialState() override;
    bool isGoalState(State<Point> *s) override;
    vector<State<Point> *> getAllPossibleStates(State<Point> *s) override;
    Point getGoalState() override;
    string to_string() override;
};


#endif //EX4_MATRIX_H
