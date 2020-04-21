#include "automata.h"
#include "scanner.h"
int main(int argc, char *argv[]){
    if (argc != 2){
        std::cout<<"Please enter code line only";
        return 0;
    };
    //Automata scanner("input.txt");
    std::ifstream code_file(argv[1]);
    std::string code;
    std::vector<Token> TokenVec;
    std::vector<std::string> FinalTokenVec;
    //scanner.show();
    Scanner miniscanner;
    while(getline(code_file,code)){
        for (char c : code)  
            TokenVec.push_back(miniscanner.scan(c));
    }
    tokens temp = TokenVec[0].type();
    std::string temp2 = "";
    if (temp != S)
        temp2.push_back(TokenVec[0].cont());
    if (temp == D)
        throw std::invalid_argument("Can't start identifier with digit");
    for (int i = 1; i < TokenVec.size(); ++i){
        if (TokenVec[i].type() == L){
            if (temp == D){
                std::string error_message = "Can't start identifier with digit (Column " + std::to_string(i) + ")";
                throw std::invalid_argument(error_message);
            }
            temp = L;
            temp2.push_back(TokenVec[i].cont());
        }
        else if(TokenVec[i].type() == D){
            if (temp == L){
                temp2.push_back(TokenVec[i].cont());
                continue;
            }
            temp = D;
            temp2.push_back(TokenVec[i].cont());
        }
        else if(TokenVec[i].type() == ODot){
            if (temp == D){
                temp2.push_back(TokenVec[i].cont());
                continue;
            }
            std::string error_message = "Unexpected \".\" (Column " + std::to_string(i) + ")";
            throw std::invalid_argument(error_message);
            
        }
        else{
            if(temp == D || temp == L){
                FinalTokenVec.push_back(std::to_string(temp)+"_" + temp2 + ",");
            }
            temp2="";
            temp = TokenVec[i].type();
            if(temp == S){
                continue;
            }
            else{
                FinalTokenVec.push_back(std::to_string(TokenVec[i].type())+"_"+TokenVec[i].cont()+",");
            }
            
        }
    }
    if (temp!=S && temp !=F){
        FinalTokenVec.push_back(std::to_string(temp)+"_" + temp2 + ",");
    }
    for (int i = 0; i < FinalTokenVec.size(); ++i){
        std::cout << FinalTokenVec[i];
    }
    //scanner.run(TokenVec);
    //scanner.accepted() ? std::cout << "Email is valid" : std::cout << "Email is not valid";
    
    return 0;
};
