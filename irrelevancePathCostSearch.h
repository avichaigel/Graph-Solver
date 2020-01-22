//
// Created by ofirn93 on 22/01/2020.
//

#ifndef EX4_IRRELEVANCEPATHCOSTSEARCH_H
#define EX4_IRRELEVANCEPATHCOSTSEARCH_H

#include "Searcher.h"

template <typename T, typename DS>
class irrelevancePathCostSearch: public Searcher<T> {
protected:
    // number of nodes visited
    int nodeVisited;
    vector<State<T>*> myStates;
    DS myDataStructure;


#endif //EX4_IRRELEVANCEPATHCOSTSEARCH_H
