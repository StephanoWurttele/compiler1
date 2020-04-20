#ifndef SCANNER_H
#define SCANNER_H
#include <iostream>
#include "tokens.h"

class Scanner{
    public:
    Scanner(){};
    static Token scan(char input);
};


#endif