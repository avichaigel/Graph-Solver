//
// Created by avichai on 19/01/2020.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H

#include "State.h"
#include "Point.h"
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<State<Point*>*>> outer;
public:
    vector<vector<State<Point*>*>> &getOuter() {
        return outer;
    }
};


#endif //EX4_MATRIX_H
