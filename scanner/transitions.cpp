#include "transitions.h"

Transition::Transition(int val, State* targetNode){
    target = targetNode;
    token = Token(val, ' ');
}