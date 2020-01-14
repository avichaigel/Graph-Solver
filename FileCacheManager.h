//
// Created by avichai on 14/01/2020.
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
    public:
        void insert(string key, string obj);
        string get(string key) override;
//        void foreach(const function<void(string&)>);
    };

    void FileCacheManager::insert(string key, string obj) {
        //check if key already exists in map, and if so change its list position, and cache value
        auto it = cache.find(key);
        if (it != cache.end()) {
            lruList.remove(key);
            lruList.push_front(key);
            it->second = obj;
        } else { // if no such key in map
            // if cache is packed, erase lru item
            if (lruList.size() == capacity) {
                string last = lruList.back();
                lruList.pop_back();
                cache.erase(last);
            }
            lruList.push_front(key);
            cache.insert({key, obj});
        }
        ofstream outFile;
        outFile.open(key+string::class_name, ios::binary); // if file exists, overwrites it by default
        outFile.write((char*)&obj, sizeof(obj));
        outFile.close();
    }

    string FileCacheManager::get(string key) {
        auto it = cache.find(key);
        if (it != cache.end()) { //if key exists already, move to beginning of list and then return it from cache map
            lruList.remove(key);
            lruList.push_front(key);
            return it->second;
        }

        // if we got here, this means no such key exists in the cache. draw it from file
        ifstream inFile;
        string obj;
        inFile.open(key+string::class_name, ios::binary);
        if (!inFile) { // if no such file exists
            throw ("File opening error");
        }
        inFile.read((char*)&obj, sizeof(obj));
        inFile.close();
        // if cache is packed, erase lru item
        if (lruList.size() == capacity) {
            string last = lruList.back();
            lruList.pop_back();
            cache.erase(last);
        }
        lruList.push_front(key);
        cache.insert({key,obj});
        return obj;
    }

/*    void FileCacheManager::foreach(const function<void(string&)> func) {
        for (string i : lruList) {
            auto it = cache.find(i);
            if (it != cache.end()) {
                func(it->second);
            } else {
                continue;
            }
        }
    }*/

#endif //EX4_FILECACHEMANAGER_H
