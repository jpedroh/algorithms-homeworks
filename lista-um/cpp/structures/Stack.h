//
// Created by jpedroh on 12/09/2019.
//

#ifndef CPP_STACK_H
#define CPP_STACK_H

template<typename T>
class Stack {
public:
    T node;
    Stack *next;

    static Stack *buildStackHead(T headValue) {
        return new Stack(headValue);
    }

    void push(T value) {
        Stack *newNode = new Stack(value);
        newNode->next = this->next;
        this->next = newNode;
    }

    T pop() {
        Stack *aux = this->next;
        this->next = aux->next;
        T value = aux->node;
        delete aux;
        return value;
    }

private:
    Stack(T value) {
        this->node = value;
        this->next = nullptr;
    }

};


#endif //CPP_STACK_H
