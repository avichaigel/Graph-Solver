//
// Created by ofirn93 on 22/01/2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H

#include "Searcher.h"
#include <queue>


template <typename T>
class BFS: public Searcher<T> {
    // number of nodes visited
    int nodeVisitedNum;
    double pathCost;
    // the nodes we already visited
    vector<State<T>*> nodesVisited;
    // the path of states we return
    vector<State<T>*> myPath;

public:
//    BFS() {
//        vector<State<T>*> a;
//        vector<State<T>*> b;
//        this->nodesVisited = a;
//        this->myPath = b;
//        this->nodeVisitedNum = 0;
//        this->pathCost = 0;
//    }

    vector<State<T> *> search(ISearchable<T> *searchable) override {
        this->nodeVisitedNum = 0;
        this->pathCost = 0;
        // creating the queue
        queue<State<T>* > Q;
        // initializing the beginning node, the current node, and the goal node
        State<T>* firstNode = searchable->getInitialState();
        State<T>* currNode = searchable->getInitialState();
        State<T>* goalNode = searchable->getGoalState();
        this->nodesVisited.push_back(currNode);
        Q.push(currNode);
        while (!Q.empty()) {
            currNode = Q.front();
            Q.pop();
            this->nodeVisitedNum += 1;
            if (!currNode->equals(goalNode)) {
                for (State<T> *adj : searchable->getAllPossibleStates(currNode)) {
                    if (!(this->isVisited(adj))) {
                        adj->setCameFrom(currNode);
                        this->nodesVisited.emplace_back(adj);
                        Q.push(adj);
                    }
                }
            } else {
                this->pathCost += currNode->getCost();
                this->myPath.insert(this->myPath.begin(), currNode);
                while (!currNode->equals(firstNode)) {
                    currNode = currNode->getFather();
                    this->pathCost += currNode->getCost();
                    this->myPath.insert(this->myPath.begin(), currNode);
                }
                return this->myPath;
            }
        }
        // returns an empty vector if there is no path
        vector<State<T>*> v;
        return v;
    }

    bool isVisited(State<T>* node) {
        auto it = find(this->nodesVisited.begin(), this->nodesVisited.end(), node);
        if (it != this->nodesVisited.end()) {
            return true;
        }
        else {
            return false;
        }
    }
};


#endif //EX4_BFS_H
