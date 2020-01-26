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

    vector<State<T> *> search(ISearchable<T> *searchable) override {
        this->nodesVisited.clear();
        this->myPath.clear();
        this->nodeVisitedNum = 0;
        this->pathCost = 0;
        // creating the queue
        queue<State<T>* > Q;
        // initializing the beginning node, the current node, and the goal node
        State<T>* firstNode = searchable->getInitialState();
        State<T>* currNode = searchable->getInitialState();
        State<T>* goalNode = searchable->getGoalState();
        this->nodesVisited.push_back(currNode);
        currNode->setCameFrom(currNode);
        Q.push(currNode);
        while (!Q.empty()) {
            currNode = Q.front();
            Q.pop();
            this->nodeVisitedNum += 1;
            if (!currNode->equals(goalNode)) {
                vector<State<T>*> states = searchable->getAllPossibleStates(currNode);
                for (State<T> *adj : states) {
                    if (!(this->isVisited(adj, this->nodesVisited))) {
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
                return bestPath();
            }
        }
        // returns an empty vector if there is no path
        vector<State<T>*> v;
        return v;
    }

    bool isVisited(State<T>* s, vector<State<T>*> v) {
        int i;
        for (i = 0; i < v.size(); i++) {
            State<T>* tmp = v[i];
            if (tmp->getState() == s->getState()) {
                return true;
            }
        }
        return false;
    }

    vector<State<T>*> bestPath(){
        vector<State<T>*> path;
        int i;
        for (i = this->myPath.size() - 1; i >= 0; i--) {
            path.push_back(this->myPath.at(i));
        }
        return path;
    }
};


#endif //EX4_BFS_H
