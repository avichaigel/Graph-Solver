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
            State<T> *n = this->openQueue.top();
            this->openQueue.pop();
            this->nodeEval++;
            this->myStates.push_back(n);
//            this->myStates.insert(this->myStates.begin(), n);
//            https://stackoverflow.com/questions/13324431/c-vectors-insert-push-back-difference

            // if you reached your goal
            if (s->isGoalState(n)) {
                // return best path
                return this->bestPath(n,s);
            }
            vector<State<T>*> states = s->getAllPossibleStates(n);
            for (State<T> *node : states) {
                double newPathCost = n->getPathCost() + node->getCost();
                if ((this->myStates.find(node) == this->myStates.cend) && !(this->openQueue.openQueueContains(node))) {
                    //emplace of the neighbors not push
                    // https://stackoverflow.com/questions/35518611/difference-between-queues-emplace-and-push
                    node->setCameFrom(n);
                    if (node->getFather() != nullptr) {
                        node->setPathCost(node->getCost() + node->getFather()->getPathCost());
                    }
                    this->openQueue.emplace(node);
                } else {
                    if (newPathCost < node->getPathCost()) {
                        node->setCameFrom(n);
                        node->setPathCost(newPathCost);
                        this->openQueue.emplace(node);
                        /*if (this->openQueue.openQueueContains(node)) {
                            this->openQueue.emplace(node);
                        } else {
                            this->openQueue.emplace(node);
                        }*/
                    }
                }
            }
        }
    }
};

#endif //EX4_BESTFS_H
