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
}

string FileCacheManager::get(string problem) {
    /* pseudo code:
     * here i check if i have a solution to a problem
     * if i have, i return it
     * otherwise, i have to pass the problem to the solver and he solves it
     * in the meantime, i save in my own map the problem as key and the representative string of it as value.
     * then i add...*/
    if (this->prob2str.empty()) {
        startMap();
    }
    if (this->prob2str.find(problem) != this->prob2str.cend()) {
        string filename = this->prob2str.at(problem);
        ifstream myFile(filename);
        if (!myFile) {
            cerr << "Error occurred while opening the file\n";
        }
        string sol;
        if (getline(myFile, sol)) {
            return sol;
        }
    } else {
        if (problem == "start") {
            return "-1";
        }
        string name;
        this->count++;
        name.append("Data" + to_string(this->count) + ".txt");
        this->prob2str.insert({problem, name});
        setCurrVal(name);
        mapSaver(problem);
        return "-1";
    }
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
    output.append(this->currVal + "~" + problem + "$\n");
    ofstream myFile(mapFile, fstream::app);
    myFile << output;
    myFile.close();
}


void FileCacheManager::startMap() {
    ifstream myFile("mapSaver.txt");
    if (!myFile) {
        // when it's our first run ever
        setCount(0);
        return;
    }
    //idea from: https://stackoverflow.com/questions/289347/using-strtok-with-a-stdstring
    string line;
    while (getline(myFile, line)) {
        istringstream iss(line);
        string token;
        while (getline(iss, token, '$')) {
            pairSplit(token);
            this-> count += 1;
        }
    }
}

// idea from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
void FileCacheManager::pairSplit(string pair) {
    string delim = "~";
    // key and value
    string k, v;
    size_t pos = 0;
    while ((pos = pair.find(delim)) != string::npos) {
        k = pair.substr(0, pos);
        pair.erase(0, pos + delim.length());
        v = pair;
        this->prob2str.insert({v, k});
    }
}