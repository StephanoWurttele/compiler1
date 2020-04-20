#include <iostream>
#include <string>

int main(int argc, char *argv[]){
  std::string input;
  std::cin >> input;
  std::string delimiter = ",";

  size_t pos = 0;
  std::string token;
  while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        std::cout << token << std::endl;
        input.erase(0, pos + delimiter.length());
  }
  return 0;
}
