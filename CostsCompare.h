//
// Created by ofirn93 on 20/01/2020.
//

#ifndef EX4_COSTSCOMPARE_H
#define EX4_COSTSCOMPARE_H

#include "State.h"

using namespace std;

template<class T>
struct CostsCompare {
public:
    bool operator()(State<T> *s1,State<T>  *s2) const {
        return s1->getCost() < s2->getCost();
    }
};

#endif //EX4_COSTSCOMPARE_H
