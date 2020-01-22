//
// Created by ofirn93 on 22/01/2020.
//

#ifndef EX4_IRRELEVANCEPATHCOSTSEARCH_H
#define EX4_IRRELEVANCEPATHCOSTSEARCH_H

#include "Searcher.h"
#include <queue>

template <typename T>
class irrelevancePathCostSearch: public Searcher<T> {
protected:
    // number of nodes visited
    int nodeVisitedNum;
    double pathCost;
    vector<State<T>*> nodesVisited;
    // the path of states we return
    vector<State<T>* > myPath;
//    DS myDataStructure;

public:
    irrelevancePathCostSearch() {
        this->nodeVisitedNum = 0;
        this->pathCost = 0;
//        setDS(myDataStructure);
    }
    virtual void setDS() = 0;
    vector<State<T> *> search(ISearchable<T> *searchable) override {
        // creating the queue
        queue<State<T>* > Q;
        // initializing the beginning node, the current node, and the goal node
        State<T>* firstNode = searchable->getInitialState();
        State<T>* currNode = searchable->getInitialState();
        State<T>* goalNode = searchable->getGoalState();
        this->nodesVisited.push_back(currNode);
        while (!Q.empty()) {
            currNode = Q.front;
            Q.pop();
        this->nodeVisitedNum += 1;
            if (!currNode->equals(goalNode)) {
                for (State<T> *adj : searchable->getAllPossibleStates(currNode)) {
                    if (this->nodesVisited)

                }



            }


            /* else
             * {
                this->pathCost += currNode->getCost();
                this->myPath.insert(this->myPath.begin(), currNode);
                while (!currNode->equals_to(firstNode)) {
                    currNode = currNode->getCameFrom();
                    this->pathCost += currNode->getCost();
                    this->myPath.insert(this->myPath.begin(), currNode);
                }*/

        }

    }

    bool



};


#endif //EX4_IRRELEVANCEPATHCOSTSEARCH_H
