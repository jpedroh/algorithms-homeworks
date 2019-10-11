//
// Created by jpedroh on 11/10/2019.
//

#ifndef CPP_AGENT_H
#define CPP_AGENT_H


class Agent {
private:
    int id;
    int casta;
    int base;
    int depth;

public:
    Agent(int id, int casta, int base) {
        this->id = id;
        this->casta = casta;
        this->base = base;
        this->depth = -1;
    }

    static Agent* buildInvalidAgent() {
        return new Agent(-1, -1, -1);
    }

    int getId() {
        return id;
    }

    int getCasta() {
        return casta;
    }

    int getBase() {
        return base;
    }

    void setBase(int _base) {
        this->base = _base;
    }

    int getDepth() {
        return depth;
    }

    void setDepth(int _depth) {
        this->depth = _depth;
    }
};


#endif //CPP_AGENT_H
