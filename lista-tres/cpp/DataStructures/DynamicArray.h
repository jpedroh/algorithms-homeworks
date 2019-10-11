//
// Created by jpedroh on 11/10/2019.
//

#ifndef CPP_DYNAMICARRAY_H
#define CPP_DYNAMICARRAY_H

#include <stddef.h>

template <typename T>
class DynamicArray {
private:
    const int INITIAL_ARRAY_SIZE = 10;
    T** items;
    int actualArraySize = INITIAL_ARRAY_SIZE;
    int cursorPosition = 0;

public:
    DynamicArray() {
        this->items = new T*[INITIAL_ARRAY_SIZE];
    }

    void insert(T value) {
        if(this->cursorPosition == this->actualArraySize) {
            this->doubleArrayCapacity();
        }
        this->items[this->cursorPosition] = value;
        this->cursorPosition++;
    }

    T* findById(int id) {
        int key = this->getKey(id);
        if(key < 0) {
            return nullptr;
        }
        return this->items[key];
    }

    bool removeById(int id) {
        int key = this->getKey(id);
        if(key < 0) {
            return false;
        }

        this->cursorPosition--;

        T temp = this->items[this->cursorPosition];
        this->items[key] = temp;
        return true;
    }

    int getLength() {
        return this->cursorPosition;
    }

private:
    int getKey(int id) {
        for (int i = 0; i < this->cursorPosition; i++) {
            if (this->items[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }

    void doubleArrayCapacity() {
        T temp[] = this->items;
        this->actualArraySize *= 2;

        this->items = new T*[this->actualArraySize];

        for (int i = 0; i < this->cursorPosition; i++) {
            this->items[i] = temp[i];
        }
    }
};


#endif //CPP_DYNAMICARRAY_H
