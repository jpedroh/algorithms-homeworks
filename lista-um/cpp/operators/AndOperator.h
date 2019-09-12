//
// Created by jpedroh on 12/09/2019.
//

#ifndef CPP_ANDOPERATOR_H
#define CPP_ANDOPERATOR_H


#include "BinaryOperator.h"

class AndOperator : public BinaryOperator {
public:
    int operate(int a, int b) override {
        return a && b;
    }
};


#endif //CPP_ANDOPERATOR_H
