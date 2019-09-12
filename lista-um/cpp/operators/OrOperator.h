//
// Created by jpedroh on 12/09/2019.
//

#ifndef CPP_OROPERATOR_H
#define CPP_OROPERATOR_H


#include "BinaryOperator.h"

class OrOperator : public BinaryOperator {
public:
    int operate(int a, int b) override {
        return a || b;
    }
};


#endif //CPP_OROPERATOR_H
