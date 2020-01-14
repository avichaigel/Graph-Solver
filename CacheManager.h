//
// Created by avichai on 14/01/2020.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

template <typename P, typename S>
class CacheManager {
    virtual void add(S solution);
    virtual void search(P problem);
    virtual void get(S solution);
};


#endif //EX4_CACHEMANAGER_H
