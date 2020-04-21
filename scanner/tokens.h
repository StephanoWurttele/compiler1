#ifndef TOKENS_H
#define TOKENS_H

enum tokens{L, D, OS, OR, OM, OD, OA, ODot, S, F, Other, Count};
class Token{
    private:
    tokens name;
    char content;
    public:
    Token(){};
    Token(tokens _name, char character) : name(_name), content(character){};
    Token(int _name, char character);
    tokens type(){return name;};
    char cont(){return content;};
};

#endif