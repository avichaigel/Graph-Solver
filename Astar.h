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
            return ((s1->getMyHueristicDist() + s1->getPathCost()) >
                    (s2->getMyHueristicDist() + s2->getPathCost()));
        }
    };
    priority_queue<State<T>*, vector<State<T>*>, CostsCompareAstar> pQ;

public:
    vector<State<T>*> search(ISearchable<T> *s) override {
        while (!this->pQ.empty()) {
            this->pQ.pop();
        }
        this->myStates.clear();
        this->setNodeEval(0);
        this->pQ.push((s->getInitialState()));
        this->pQ.top()->setCameFrom(s->getInitialState());
        State<T> *n = this->pQ.top();
        n->setMyHueristicDist(s->findDistance(n, s->getGoalState()));
        while (!this->pQ.empty()) {
            n = this->pQ.top();
            this->pQ.pop();
            this->nodeEval++;
            this->myStates.push_back(n);
            // if you reached your goal
            if (s->isGoalState(n)) {
                n->setPathCost(n->getFather()->getPathCost() + n->getCost());
                // return best path
                return this->bestPath(n,s);
            }
//            n->setMyHueristicDist(s->findDistance(n, s->getGoalState()));
            vector<State<T>*> states = s->getAllPossibleStates(n);
            for (State<T>* node : states) {
                double newPathCost = n->getPathCost() + node->getCost();
                double heuristicDist = s->findDistance(node, s->getGoalState());
                double aStarCost = heuristicDist + newPathCost;
                if (!(this->isInClosed(node, this->myStates)) && !(this->pQContains(node))) {
                    node->setCameFrom(n);
//                    node->setPathCost(node->getCost() + node->getFather()->getPathCost());
                    if (node->getFather() != nullptr) {
                        node->setPathCost(node->getCost() + node->getFather()->getPathCost());
                    }
                    node->setMyHueristicDist(heuristicDist);
                    this->pQ.push(node);
                } else {
                    if (aStarCost < node->getPathCost() + node->getMyHueristicDist()) {
                        node->setCameFrom(n);
                        node->setPathCost(newPathCost);
                        node->setMyHueristicDist(heuristicDist);
                        //if !inOpenList - add
                        if (!this->pQContains(node)) {
                            this->pQ.push(node);
                        } else {
                            this->pQContains(node);
                        }
                    }
                }
            }
        }
    }

    /*vector<State<T>*> search(ISearchable<T> *s) override {
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
    }*/

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
        priority_queue<State<T> *, vector<State<T> *>, CostsCompareAstar> tmpQ;
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

#endif //EX4_ASTAR_H
