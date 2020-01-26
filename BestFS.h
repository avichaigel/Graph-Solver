
//
// Created by ofirn93 on 19/01/2020.
//

#ifndef EX4_BESTFS_H
#define EX4_BESTFS_H

#include <algorithm>
#include "SearchByPQ.h"
using namespace std;

template<typename T>
class BestFS: public SearchByPQ<T> {
public:

    vector<State<T>*> search(ISearchable<T> *s) override {
        while (!this->openQueue.empty()) {
            this->openQueue.pop();
        }
        this->myStates.clear();
        this->addOpenQueue(s->getInitialState());
        while (!this->openQueue.empty()) {
            State<T> *n = this->openQueue.top();
            this->openQueue.pop();
            this->nodeEval++;
            this->myStates.push_back(n);
            // if you reached your goal
            if (s->isGoalState(n)) {
                n->setPathCost(n->getFather()->getPathCost() + n->getCost());
                // return best path
                return this->bestPath(n,s);
            }
            vector<State<T>*> states = s->getAllPossibleStates(n);
            for (State<T>* node : states) {
                double newPathCost = n->getPathCost() + node->getCost();
                if (!(this->isInClosed(node, this->myStates)) && !(this->openQueueContains(node))) {
                    node->setCameFrom(n);
//                    node->setPathCost(node->getCost() + node->getFather()->getPathCost());
                    if (node->getFather() != nullptr) {
                        node->setPathCost(node->getCost() + node->getFather()->getPathCost());
                    }
                    this->openQueue.push(node);
                } else {
                    if (newPathCost < node->getPathCost()) {
                        node->setCameFrom(n);
                        node->setPathCost(newPathCost);
                        //if !inOpenList - add
                        if (!this->openQueueContains(node)) {
                            this->openQueue.push(node);
                        } else {
                            this->reloadQ(node);
                        }
                    }
                }
            }
        }
    }
    bool isInClosed(State<T>* s, vector<State<T>*> v) {
        int i;
        for (i = 0; i < v.size(); i++) {
            State<T>* tmp = v[i];
            if (tmp->getState() == s->getState()) {
                return true;
            }
        }
        return false;
    }

    void reloadQ(State<T>* s) {
        State<T>* tmpS;
        // temporary queue
        priority_queue<State<T>*, vector<State<T>*>, CostsCompare<T>>  tmpQ;
        tmpQ.push(s);
        while (!this->openQueue.empty()) {
            tmpS = this->openQueue.top();
            this->openQueue.pop();
            tmpQ.push(tmpS);
        }
        while (!tmpQ.empty()) {
            tmpS = tmpQ.top();
            tmpQ.pop();
            this->openQueue.push(tmpS);
        }
    }
};

#endif //EX4_BESTFS_H