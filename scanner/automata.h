#ifndef AUTOMATA_H
#define AUTOMATA_H
#include "transitions.h"
#include <vector>
class Automata{
    private:
    std::vector<State*> states;
    std::vector<std::vector<Transition>> transitions;
    State* current_state;
    public:
    Automata(std::string file);
    void run(std::vector<Token> string);
    bool accepted();
    State* FindState(std::string state);
    void show(){
        for (int i=0; i<states.size(); ++i){
            std::cout << "State " << states[i]->getName()<< " which acceptance state is " << states[i]->final() << std::endl;
            std::cout << "Has transitions:"<<std::endl;
            for(int j=0; j<(int)tokens::Count; ++j){
                std::cout << "Goes to " << transitions[i][j].getTarget()->getName() << " through " << transitions[i][j].path() << std::endl;
            }
        }
    }
};

#endif