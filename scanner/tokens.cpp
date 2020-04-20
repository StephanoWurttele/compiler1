#include "tokens.h"

Token::Token(int _name, char character){
    content = ' ';
    switch (_name){
        case 0:
            name = L;
            break;
        case 1:
            name = D;
            break;
        case 2: 
            name = OS;
            break;
        case 3: 
            name = OR;
            break;
        case 4: 
            name = OM;
            break;
        case 5: 
            name = OD;
            break;
        case 6: 
            name = OA;
            break;
        case 7: 
            name = S;
            break;
        default:  
            name = F;
    }
};