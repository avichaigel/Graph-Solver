//
// Created by avichai on 20/01/2020.
//

#include "Point.h"

int Point::getI() const {
    return i;
}

int Point::getJ() const {
    return j;
}

Point::Point(int i1, int j1) {
    this->i = i1;
    this->j = j1;
}
