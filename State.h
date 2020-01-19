//
// Created by ofirn93 on 19/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

template <typename T>
class State {
    T state;
    double cost;
    State<T> *cameFrom;

public:
    State(T myState, double myCost) {
        this->state = myState;
        this->cost = myCost;
        this->cameFrom = nullptr;
    }
    void setCost(double myCost) {
        this->cost = myCost;
    }
    void setCameFrom(State<T> *cf) {
        this->cameFrom = cf;
    }
    T getState() {
        return this->state;
    }
    double getCost() {
        return this->cost;
    }
    State<T>* getFather(){
        return this->cameFrom;
    }
    bool equals(State<T> *s) {
        return this->state == s->getState();
    }
    ~State()= default;
};

#endif //EX4_STATE_H
