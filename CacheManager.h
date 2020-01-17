//
// Created by ofirn93 on 14/01/2020.
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
    // a map that stores problems solutions (string) as keys, and the value is my way to name the solution
    // the value will be used as a file name of the solution in the disk.
    unordered_map<string, string> prob2str;
//    list<string> lruList;
//    unsigned int capacity{};
public:
    virtual void insert(S solution) = 0;
    virtual S get(P problem) = 0;
};


#endif //EX4_CACHEMANAGER_H
