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

        //return vector<State<T> *>();
    }
};

#endif //EX4_BESTFS_H
