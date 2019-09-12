//
// Created by jpedroh on 12/09/2019.
//

#ifndef LISTA_DOIS_PARKINGB_H
#define LISTA_DOIS_PARKINGB_H


#include "BaseParkingSystem.h"

class ParkingB : public BaseParkingSystem {
public:
    ParkingB(int initialSize, int fMin, int fMax) : BaseParkingSystem(initialSize, fMin, fMax) { }

public:
    ParkedCar *insert(const std::string &plate) override{
        if(this->shouldRehashOnInsertion()) {
            this->rehash(2*this->actualArraySize);
        }

        auto car = new ParkedCar(plate, this->getOriginalPosition(plate));

        while(this->cars[car->position] != nullptr) {
            car->position = (car->position + 1) % this->actualArraySize;
            car->distance++;

            ParkedCar* currentCar = this->cars[car->position];

            if(currentCar != nullptr && currentCar->plate != UNAVAILABLE_SLOT_FLAG && car->distance > currentCar->distance) {
                std::string oldPlate = currentCar->plate;
                this->cars[car->position] = car;

                this->insert(oldPlate);
                return car;
            }

        }

        this->cars[car->position] = car;
        this->filledSlots++;
        this->parkedSlots++;
        return car;
    }

    ParkedCar *search(const std::string &plate) override {
        auto car = new ParkedCar(plate, this->getOriginalPosition(plate));

        if(this->cars[car->position] == nullptr) {
            return ParkedCar::buildInvalidCar();
        }

        while(this->cars[car->position] != nullptr && this->cars[car->position]->plate != car->plate) {
            car->position = (car->position + 1) % this->actualArraySize;
            car->distance++;

            auto currentCar = this->cars[car->position];
            if(currentCar != nullptr && currentCar->plate != UNAVAILABLE_SLOT_FLAG && currentCar->distance < car->distance) {
                return ParkedCar::buildInvalidCar();
            }
        }

        if(this->cars[car->position] == nullptr) {
            return ParkedCar::buildInvalidCar();
        }

        return car;
    }
};


#endif //LISTA_DOIS_PARKINGB_H
