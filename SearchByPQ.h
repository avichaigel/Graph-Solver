//
// Created by ofirn93 on 19/01/2020.
//

#ifndef EX4_SEARCHBYPQ_H
#define EX4_SEARCHBYPQ_H

#include <queue>
#include "Searcher.h"
#include "CostsCompare.h"

template <typename T>
class SearchByPQ: public Searcher<T> {
protected:
    // node evaluation
    int nodeEval;
    vector<State<T>*> myStates;
    priority_queue<State<T>*, vector<State<T>*>, CostsCompare<T>> openQueue;

public:
    SearchByPQ() {
        this->nodeEval = 0;
    }

    void setNodeEval(int eval) {
        this->nodeEval = eval;
    }

    int getNodesEval() {
        return this->nodeEval;
    }

    int openQueueSize(){
        return this->openQueue.size();
    }

    bool openQueueContains(State<T> *s) {
        int flag = 0;
        State<T>* tmpS;
        // temporary queue
        priority_queue<State<T>*, vector<State<T>*>, CostsCompare<T>>  tmpQ;
        while (!this->openQueue.empty()) {
            tmpS = this->openQueue.top();
            this->openQueue.pop();
            tmpQ.push(tmpS);
            if(s->equals(tmpS)) {
                flag = 1;
            }
        }
        while (!tmpQ.empty()) {
            tmpS = tmpQ.top();
            tmpQ.pop();
            this->openQueue.push(tmpS);
        }
        if (flag) {
            return true;
        }
        return false;
    }

    void addOpenQueue(State<T> *s){
        this->openQueue.push(s);
    }

    vector<State<T>*> bestPath(State<T> *s, ISearchable<T> *searchable){
        vector<State<T>*> path;
        State<T> *startState = searchable->getInitialState();
        State<T> *currState = s;
        while(!(currState->equals(startState))){
            path.push_back(currState);
            currState = currState->getFather();
        }
        path.push_back(currState);
        return path;
    }

};

#endif //EX4_SEARCHBYPQ_H
