#include "scanner.h"

bool l(char character)
{
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character == '_');
}

bool d(char character)
{
    return (character >= '0' && character <= '9');
}

Token Scanner::scan(char input){
    tokens token;
    if (l(input))
        token = L;
    else if(d(input)){
        token = D;
    }
    else{
        switch (input){
        case '+': 
            token = OS;
            break;
        case '-': 
            token = OR;
            break;
        case '*': 
            token = OM;
            break;
        case '/': 
            token = OD;
            break;
        case '=': 
            token = OA;
            break;
        case ' ': 
            token = S;
            break;
        case '.': 
            token = ODot;
            break;
        case ';': 
            token = F;
            break;
        default:  
            token = Other;
    }
    }
    return Token(token, input);
}