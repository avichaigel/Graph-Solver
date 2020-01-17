//
// Created by ofirn93 on 14/01/2020.
//

#include "FileCacheManager.h"

void FileCacheManager::insert(string solution) {
    string filename = this->currVal;
    ofstream myFile(filename);
    myFile << solution;
    myFile.close();
    mapSaver(solution);



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
        return NULL;
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
        return NULL;
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

void FileCacheManager::mapSaver(string solution) {
    string mapFile = "mapSaver.txt";
    string output;
    output.append("{" + )
    ofstream myFile(mapFile);



}
