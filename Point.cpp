//
// Created by avichai on 20/01/2020.
//

#include "Point.h"

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

Point::Point(int x1, int y1) {
    this->x = x1;
    this->y = y1;
}
