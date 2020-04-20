#include <fstream>
#include "automata.h"

Automata::Automata(std::string filename){
    std::ifstream format(filename);
    unsigned NodeNum;
    std::string temp, ANode, targetNode;
    getline(format, temp);
    NodeNum = std::stoi(temp);
    for(int i = 0; i < NodeNum; i++ ){
        getline(format,temp);
        getline(format, ANode);
        State* tempS = new State(temp, ANode == "1");
        states.push_back(tempS);
    }
    for(int i = 0; i < NodeNum; ++i ){
        std::vector<Transition> vec;
        for(int j = 0; j < (int)tokens::Count; ++j){
            getline(format, targetNode);
            vec.emplace_back(j, FindState(targetNode));
        }
        transitions.push_back(vec);
    }
    current_state = states[0];
}

void Automata::run(std::vector<Token> TokenVec){
    for(Token t : TokenVec){
        for(Transition t2 : transitions[current_state->number()]){
            if (t2.path() == t.type()){
                current_state = t2.getTarget();
            }
        }
    }
};

bool Automata::accepted(){
    return current_state->final();
}

State* Automata::FindState(std::string state){
    for (State* x:states){
        if  (x->getName() == state){
            return x;
        }
    }
}
