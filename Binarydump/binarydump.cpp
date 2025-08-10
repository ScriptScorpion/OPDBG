
// this example was written using std::string instead of std::stringstream

#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <algorithm>

int main(int argc, char *argv[]) {
     
     if (argc > 1) {
          std::ifstream file(argv[1], std::ios::binary);
          std::string code {};
          std::string binary {};
          
          while (std::getline(file, code)) {
               for (const char x : code) {
                    binary += std::bitset<8>(x).to_string();
                    binary += " ";
               }
          }
          
          std::cout << binary;

          printf("\n\n-----------------------------------------------------------------------------------------------\n\n");

          binary.erase(std::remove(binary.begin(), binary.end(), ' '), binary.end());
          for (size_t i = 0; i < binary.length(); i += 8) {
               char binary_char =  static_cast <char> (std::bitset<8>(binary.substr(i, 8)).to_ullong());
               std::cout << (isprint(binary_char) ? binary_char : '.');
          }
          
          printf("\n");
     }
     return 0;
}