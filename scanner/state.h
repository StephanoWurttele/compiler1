#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>

class State{
    private:
        std::string name = "";
        bool acceptance;
    public:
        State(std::string _name, bool _end):name(_name), acceptance(_end){};
        bool final(){return acceptance;};
        std::string getName(){return name;};
        int number(){return std::stoi(name.substr(1));};
};
#endif