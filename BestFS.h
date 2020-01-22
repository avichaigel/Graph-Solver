//
// Created by ofirn93 on 19/01/2020.
//

#ifndef EX4_BESTFS_H
#define EX4_BESTFS_H

#include "SearchByPQ.h"

template<typename T>
class BestFS: public SearchByPQ<T> {
public:

    vector<State<T>*> search(ISearchable<T> *s) override {
        this->myStates.clear();
        this->setNodeEval(0);
        while (!this->openQueue.empty()) {
            this->openQueue.pop();
        }
        this->addOpenQueue(s->getInitialState());
        while (this->openQueueSize() > 0) {
            State<T> *n = this->openQueue.top(); //todo changed from pop to top
            this->myStates.push_back(n);
            if (s->isGoalState(n)) {
                // return best path
                return this->bestPath(n,s);
            }

        }



    }
};

#endif //EX4_BESTFS_H
