//
// Created by jpedroh on 12/09/2019.
//

#ifndef CPP_IMPLIESOPERATOR_H
#define CPP_IMPLIESOPERATOR_H


#include "BinaryOperator.h"

class ImpliesOperator : public BinaryOperator {
public:
    int operate(int a, int b) override {
        return !a || b;
    }
};


#endif //CPP_IMPLIESOPERATOR_H
