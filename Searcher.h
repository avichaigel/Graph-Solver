//
// Created by ofirn93 on 19/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H
#include "State.h"
#include "ISearchable.h"


template <typename T>
class Searcher{
public:
    virtual vector<State<T>*> search (ISearchable<T>* s) = 0;
    virtual ~Searcher()= default;
};

#endif //EX4_SEARCHER_H
