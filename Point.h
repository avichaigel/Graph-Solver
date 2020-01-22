//
// Created by avichai on 20/01/2020.
//

#ifndef EX4_POINT_H
#define EX4_POINT_H

using namespace std;

#include "State.h"

class Point{
private:
    int x, y;
public:
    int getX() const;
    int getY() const;
    Point(int x, int y);

    bool operator == (Point p2) {
        return this->getX() == p2.getX() && this->getY() == p2.getY();
    }
};


#endif //EX4_POINT_H
