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
        for(auto it = this->openQueue.begin(); it != this->openQueue.end(); it++){
            if(s->equals(*it))
                return true;
        }
        return false;
    }
    State<T>* popOpenQueue(){
        this->nodeEval++;
        auto it = this->openQueue.begin();
        State<T> *s = *it;
        this->openQueue.erase(it);
        return s;
    }

    void addOpenQueue(State<T> *s){
        this->openQueue.insert(s);
    }
    vector<State<T>*> lastPath(State<T> *s, ISearchable<T> *searchable){
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
