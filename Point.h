//
// Created by avichai on 20/01/2020.
//

#ifndef EX4_POINT_H
#define EX4_POINT_H

using namespace std;

#include "State.h"

class Point{
private:
    int i, j;
public:
    int getI() const;
    int getJ() const;
    Point(int i1, int j1);

    bool operator == (Point p2) {
        return this->getI() == p2.getI() && this->getJ() == p2.getJ();
    }
};


#endif //EX4_POINT_H
