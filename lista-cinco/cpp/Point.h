//
// Created by jpedroh on 13/11/2019.
//

#ifndef CPP_POINT_H
#define CPP_POINT_H


#include <complex>

class Point {
public:
    int index;

    Point(int x, int y, int index) {
        this->x = x;
        this->y = y;
        this->index = index;
    }

    int getEnergyToPoint(Point p) {
        auto boost = p.hasCoin ? -1 : 1;
        int distance = (int) (std::pow((p.x - this->x), 2) + pow((p.y - this->y), 2));
        return distance * boost;
    }

private:
    int x;
    int y;
    bool hasCoin = false;
};


#endif //CPP_POINT_H
