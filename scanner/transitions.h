#ifndef TRANSITIONS_H
#define TRANSITIONS_H

#include "tokens.h"
#include "state.h"

class Transition{
    private:
    Token token;
    State* target;
    public:
    Transition(int val, State* targetNode);
    tokens path(){return token.type();}
    State* getTarget(){return target;};
};

#endif