//
// Created by jpedroh on 12/09/2019.
//

#ifndef CPP_BINARYOPERATORFACTORY_H
#define CPP_BINARYOPERATORFACTORY_H


#include "BinaryOperator.h"
#include "OrOperator.h"
#include "AndOperator.h"
#include "ImpliesOperator.h"

class BinaryOperatorFactory {
public:
    static BinaryOperator *buildBinaryOperator(char input) {
        switch (input) {
            case 'v':
                return new OrOperator();
            case '^':
                return new AndOperator();
            case '>':
                return new ImpliesOperator();
            default:
                return nullptr;
        }

    }
};


#endif //CPP_BINARYOPERATORFACTORY_H
