//
// Created by ofirn93 on 22/01/2020.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H

#include "SearchByPQ.h"

template<class T>
class AStar : public SearchByPQ<T> {
    // compare between costs including their heuristics
    class CostsCompareAstar {
    public:
        bool operator()(State<T> *s1, State<T> *s2) {
            return ((s1->getHeuristicDistance() + s1->getPathCost()) <
                    (s2->getHeuristicDistance() + s2->getPathCost()));
        }
    };
    priority_queue<State<T>*, vector<State<T>*>, CostsCompareAstar> pQ;

public:
    vector<State<T>*> search(ISearchable<T> *s) override {
        this->myStates.clear();
        this->setNodeEval(0);
        while (!this->pQ.empty()) {
            this->pQ.pop();
        }
        this->pQ.push((s->getInitialState()));
        while (!this->pQ.empty()) {
            State<T> *n = this->pQ.top();
            this->pQ.pop();
            this->nodeEval++;
            this->myStates.push_back(n);
            // if you reached your goal
            if (s->isGoalState(n)) {
                // return best path
                return this->bestPath(n,s);
            }
            vector<State<T>*> states = s->getAllPossibleStates(n);
            for (State<T>* node : states) {
                double newPathCost = n->getPathCost() + node->getCost();
                // heuristic dist from the current node to our goal.
                double heuristicDist = s->findDistance(node, s->getGoalState());
                // the combined cost that matters to Astar algorithm
                double aStarCost = heuristicDist + newPathCost;
                if ((this->myStates.find(node) == this->myStates.end) && !(this->pQContains(node))) {
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
                    }
                }
            }
        }
    }

    bool pQContains(State<T> *s) {
        int flag = 0;
        State<T> *tmpS;
        // temporary queue
        priority_queue<State<T> *, vector<State<T> *>, CostsCompareAstar> tmpQ;
        while (!this->pQ.empty()) {
            tmpS = this->pQ.top();
            this->pQ.pop();
            tmpQ.push(tmpS);
            if (s->equals(tmpS)) {
                flag = 1;
            }
        }
        while (!tmpQ.empty()) {
            tmpS = tmpQ.top();
            tmpQ.pop();
            this->pQ.push(tmpS);
        }
        return flag != 0;
    }

};

#endif //EX4_ASTAR_H
