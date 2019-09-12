//
// Created by jpedroh on 12/09/2019.
//

#ifndef CPP_BINARYOPERATOR_H
#define CPP_BINARYOPERATOR_H


#include <string>

class BinaryOperator {
public:
    virtual int operate(int a, int b) = 0;
};


#endif //CPP_BINARYOPERATOR_H
