//
// Created by ofirn93 on 22/01/2020.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H

#include "Searcher.h"
#include <stack>

template <typename T>
class DFS: public Searcher<T> {
    int nodeVisitedNum;
    double pathCost;
    // the nodes we already visited
    vector<State<T>*> nodesVisited;
    // the path of states we return
    vector<State<T>*> myPath;

    vector<State<T> *> search(ISearchable<T> *searchable) override {
        this->nodesVisited.clear();
        this->myPath.clear();
        this->nodeVisitedNum = 0;
        this->pathCost = 0;
        stack<State<T>*> myStack;
        // initializing the beginning node, the current node, and the goal node
        State<T>* firstNode = searchable->getInitialState();
        State<T>* currNode = searchable->getInitialState();
        State<T>* goalNode = searchable->getGoalState();
        this->nodesVisited.push_back(currNode);
        myStack.push(currNode);
        currNode->setCameFrom(currNode);
        while (!myStack.empty()) {
            currNode = myStack.top();
            myStack.pop();
            this->nodeVisitedNum += 1;
            if (!currNode->equals(goalNode)) {
                for (State<T> *adj : searchable->getAllPossibleStates(currNode)) {
                    if (!(this->isVisited(adj))) {
                        adj->setCameFrom(currNode);
                        this->nodesVisited.emplace_back(adj);
                        myStack.push(adj);
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

    bool isVisited(State<T>* node) {
        auto it = find(this->nodesVisited.begin(), this->nodesVisited.end(), node);
        if (it != this->nodesVisited.end()) {
            return true;
        }
        else {
            return false;
        }
    }

    vector<State<T>*> bestPath(){
        vector<State<T>*> path;
        int i;
        for (i = this->myPath.size() - 1; i > 0; i--) {
            path.push_back(this->myPath.at(i));
        }
        return path;
    }
};


#endif //EX4_DFS_H
