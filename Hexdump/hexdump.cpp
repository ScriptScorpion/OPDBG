
// this example written using std::stringstream instead of std::string

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
int main(int argc, char *argv[]) {

    
    if (argc > 1) {
        std::vector <char> lines {};
        std::stringstream output;   // cool thing
        std::ifstream file(argv[1], std::ios::binary);
        char byte;
        while (file.get(byte)) {
            lines.push_back(byte);

        }
        for (char x : lines) {
            output << std::hex << static_cast <unsigned int> (x) << " ";
        }

        std::cout << output.rdbuf();

        printf("\n\n-----------------------------------------------------------------------------------------------\n\n");
        for (char y : lines) {
            int u = static_cast <unsigned int> (y);
            std::cout << (isprint(u) ? static_cast <char> (u) : '.');
        }
        printf("\n");
    }
    
    return 0;
}
