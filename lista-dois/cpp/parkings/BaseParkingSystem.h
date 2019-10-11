//
// Created by jpedroh on 12/09/2019.
//

#ifndef LISTA_DOIS_BASEPARKINGSYSTEM_H
#define LISTA_DOIS_BASEPARKINGSYSTEM_H


#include <utility>

#include "../ParkedCar.h"

class BaseParkingSystem {
public:
    BaseParkingSystem(int initialSize, int fMin, int fMax) {
        this->cars = new ParkedCar *[initialSize];
        this->actualArraySize = initialSize;
        this->minimumArraySize = initialSize;
        this->fMin = fMin;
        this->fMax = fMax;
    }

    virtual ParkedCar *insert(const std::string &plate) = 0;

    virtual ParkedCar *search(const std::string &plate) = 0;

    ParkedCar *remove(const std::string &plate) {
        ParkedCar *car = this->search(plate);
        if (car->position == -1) {
            return car;
        }

        this->cars[car->position]->plate = UNAVAILABLE_SLOT_FLAG;
        this->parkedSlots--;

        if (this->shouldRehashOnRemoval()) {
            int newArraySize = std::max(this->actualArraySize / 2, this->minimumArraySize);
            this->rehash(newArraySize);
        }
        return car;
    }

protected:
    ParkedCar **cars;
    int actualArraySize;
    int minimumArraySize;
    int fMin;
    int fMax;
    int filledSlots = 0;
    int parkedSlots = 0;

    bool shouldRehashOnInsertion() {
        return (100 * this->filledSlots) > (this->actualArraySize * this->fMax);
    }

    bool shouldRehashOnRemoval() {
        return (100 * this->parkedSlots) < (this->actualArraySize * this->fMin);
    }

    int getOriginalPosition(std::string plate) {
        return BaseParkingSystem::calculateKey(std::move(plate)) % this->actualArraySize;
    }

    void rehash(int newArraySize) {
	std::cout << "REHASHING \n";
        this->filledSlots = 0;
        this->parkedSlots = 0;
        int oldArraySize = this->actualArraySize;

        // COPIANDO O ARRAY ATUAL PARA UM AXILIAR
        auto aux = new ParkedCar *[oldArraySize];
        for (int i = 0; i < oldArraySize; i++) {
            aux[i] = this->cars[i];
        }

        // SOBRESCREVE O ARRAY ATUAL COM UM NOVO DE TAMANHO X
        this->cars = new ParkedCar *[newArraySize];
        this->actualArraySize = newArraySize;

        // ITERA SOBRE O ARRAY ANTIGO E REINSERE NA HASH
        for (int i = 0; i < oldArraySize; i++) {
            if (aux[i] != nullptr && aux[i]->plate != UNAVAILABLE_SLOT_FLAG) {
                this->insert(aux[i]->plate);
            }
        }
    }

private:
    static int calculateKey(std::string plate) {
        int key = 0;
        for (int i = 0; i < plate.length(); i++) {
            int power = std::pow(26, i);
            int letter = plate.at(i) - 'A';
            key += letter * power;
        }
        return key;
    }
};


#endif //LISTA_DOIS_BASEPARKINGSYSTEM_H

