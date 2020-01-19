//
// Created by ofirn93 on 14/01/2020.
//

#include "FileCacheManager.h"
#include <sstream>

void FileCacheManager::insert(string solution) {
    string filename = this->currVal;
    ofstream myFile(filename);
    myFile << solution;
    myFile.close();
    /*this->count++;
    string key;
    key.append("Data");
    key.append(to_string(this->count));
    prob2str.insert(solution, key);*/

    /* pseudo code:
     * first i have a map when the key is a solution and the value is my way to name it
     * then, i


    /*
    //check if key already exists in map, and if so change its list position, and cache value
    auto it = prob2str.find(key);
    if (it != prob2str.end()) {
        lruList.remove(key);
        lruList.push_front(key);
        it->second = obj;
    } else { // if no such key in map
        // if cache is packed, erase lru item
        if (lruList.size() == capacity) {
            string last = lruList.back();
            lruList.pop_back();
            prob2str.erase(last);
        }
        lruList.push_front(key);
        prob2str.insert({key, obj});
    }
    ofstream outFile;
    outFile.open(key+to_string(this->count), ios::binary); // if file exists, overwrites it by default
    outFile.write((char*)&obj, sizeof(obj));
    outFile.close();
     */
}

string FileCacheManager::get(string problem) {
    /* pseudo code:
     * here i check if i have a solution to a problem
     * if i have, i return it
     * otherwise, i have to pass the problem to the solver and he solves it
     * in the meantime, i save in my own map the problem as key and the representative string of it as value.
     * then i add...*/
    if (this->prob2str.empty()) {
        ifstream myFile("mapSaver.txt");
        if (!myFile) {
            // when it's our first run ever
            setCount(0);
            return nullptr;
        }
        //idea from: https://stackoverflow.com/questions/289347/using-strtok-with-a-stdstring
        string line;
        while (getline(myFile, line)) {
            istringstream iss(line);
            string token;
            while (getline(iss, token, '$')) {
                pairSplit(token);
            }
        }
        if (problem == "start") {
            // when we run the program and we have already solved some problems in old runs
            return nullptr;
        }
    }
    if (this->prob2str.find(problem) != this->prob2str.cend()) {
        string filename = this->prob2str.at(problem);
        filename.append(".txt");
        ifstream myFile(filename);
        if (!myFile) {
            cerr << "Error occurred while opening the file";
        }
        string sol;
        if (getline(myFile, sol)) {
            return sol;
        }
    } else {
        string name;
        this->count++;
        name.append("Data" + to_string(this->count) + ".txt");
        this->prob2str.insert({problem, name});
        setCurrVal(name);
        mapSaver(problem);
        return nullptr;
    }

    /*auto it = sol2str.find(key);
    if (it != sol2str.end()) { //if key exists already, move to beginning of list and then return it from cache map
        lruList.remove(key);
        lruList.push_front(key);
        return it->second;
    }

    // if we got here, this means no such key exists in the cache. draw it from file
    ifstream inFile;
    string obj;
    inFile.open(key+to_string(this->count), ios::binary);
    if (!inFile) { // if no such file exists
        throw ("File opening error");
    }
    inFile.read((char*)&obj, sizeof(obj));
    inFile.close();
    // if cache is packed, erase lru item
    if (lruList.size() == capacity) {
        string last = lruList.back();
        lruList.pop_back();
        sol2str.erase(last);
    }
    lruList.push_front(key);
    sol2str.insert({key,obj});
    return obj;*/
}

 /* sets the current value of the map.
  *
  * */
void FileCacheManager::setCurrVal(string val) {
    this->currVal = val;
}

void FileCacheManager::setCount(int num) {
    this->count = num;
}

/*
 * in this function we save the map that connects between problem to
 * */
void FileCacheManager::mapSaver(string problem) {
    string mapFile = "mapSaver.txt";
    string output;
    output.append(this->currVal + "," + problem + "$");
    ofstream myFile(mapFile);
    myFile << output;
    myFile.close();
}


// idea from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
void FileCacheManager::pairSplit(string pair) {
    string delim = ",";
    // key and value
    string k, v;
    size_t pos = 0;
    while ((pos = pair.find(delim)) != string::npos) {
        k = pair.substr(0, pos);
        pair.erase(0, pos + delim.length());
        v = pair.substr(0, pos);
        this->prob2str.insert({k, v});
        this->count++;
    }
    this->count--;
}
