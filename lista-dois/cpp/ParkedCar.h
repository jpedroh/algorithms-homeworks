//
// Created by jpedroh on 12/09/2019.
//
#include <bits/stdc++.h>

#ifndef LISTA_DOIS_PARKEDCAR_H
#define LISTA_DOIS_PARKEDCAR_H

#define UNAVAILABLE_SLOT_FLAG "/////"

class ParkedCar {
public:
    std::string plate;
    int position;
    int distance;

    ParkedCar(std::string plate, int originalPosition, int distance = 0) {
        this->plate = plate;
        this->position = originalPosition;
        this->distance = distance;
    }

    static ParkedCar* buildInvalidCar() {
        return new ParkedCar(UNAVAILABLE_SLOT_FLAG, -1, -1);
    }
};


#endif //LISTA_DOIS_PARKEDCAR_H
