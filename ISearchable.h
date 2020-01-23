//
// Created by ofirn93 on 19/01/2020.
//

#ifndef EX4_ISEARCHABLE_H
#define EX4_ISEARCHABLE_H

#include "State.h"
#include <string>
#include <vector>
using namespace std;

template <typename T>
class ISearchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>* s) = 0;
    virtual vector<State<T>*> getAllPossibleStates(State<T> *s) = 0;
    virtual T getGoalState() = 0;
    virtual string to_string() = 0;
    virtual double findDistance(State<T> *s1, State<T> *s2) = 0;
    virtual ~ISearchable()= default;
};


#endif //EX4_ISEARCHABLE_H
