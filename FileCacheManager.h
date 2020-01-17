//
// Created by ofirn93 on 14/01/2020.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

using namespace std;

#include <string>
#include "CacheManager.h"
#include "string.h"
#include <string>
#include <unordered_map>
#include <list>
#include <fstream>
#include <iostream>
#include <map>
#include <functional>

class FileCacheManager : public CacheManager<string, string> {
    int count;
public:
    void setCount(int count);

private:
    string currVal;
public:
    void setCurrVal(string val);

public:
    void insert(string solution) override ;
    string get(string problem) override;

    void mapSaver(string solution);
};



#endif //EX4_FILECACHEMANAGER_H
