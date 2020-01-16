//
// Created by avichai on 14/01/2020.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

#include <string>
#include <list>
#include <unordered_map>

using namespace std;

template <typename P, typename S>
class CacheManager {
protected:
    unordered_map<string, string> cache;
    list<string> lruList;
    unsigned int capacity{};
public:
    virtual void insert(S solution);
    virtual S get(P problem);
};


#endif //EX4_CACHEMANAGER_H
