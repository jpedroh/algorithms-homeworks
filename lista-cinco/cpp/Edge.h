//
// Created by jpedroh on 13/11/2019.
//

#ifndef CPP_EDGE_H
#define CPP_EDGE_H


#include "Point.h"

class Edge {
public:
    Point origem;
    Point destino;

    Edge(Point origem, Point destino) : origem(origem), destino(destino) {
        this->origem = origem;
        this->destino = destino;
    }
};

#endif //CPP_EDGE_H
