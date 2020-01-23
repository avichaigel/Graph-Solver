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
    double pathCost;
    double hueristicDist;


public:
    State(T myState, double myCost) : state(myState), pathCost(0), cost(0), hueristicDist(0) {
        this->cameFrom = nullptr;
    }

    double getPathCost() {
        return this->pathCost;
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

    void setPathCost(double pc) {
        this->pathCost = pc;
    }

    State<T>* getFather(){
        return this->cameFrom;
    }
    bool equals(State<T> *s) {
        return this->state == s->getState();
    }
    void setMyHueristicDist(double dist) {
        this->hueristicDist = dist;
    }
    double getMyHueristicDist() {
        return  this->hueristicDist;
    }

    ~State()= default;
};

#endif //EX4_STATE_H
