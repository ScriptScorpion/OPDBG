#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <cctype>
#include <fstream>
#include "hash_function.h"

#define EMPTY ""

// Difference between x32 and x64 assembly
// In x32 assembly opcodes equals to command it corresponds and next values are just registers to work with
// In x64 same as with x32 but with 48 at the start

struct Commands {
     const uint16_t opcode;
     const char *called;
     uint8_t Size() {
         switch (opcode) {
             case 0x0F: return 96;
             case 0x88: return 8;
             case 0x89: return 48;
             case 0x8B: return 48;
             case 0x8D: return 48;
             case 0xE8: return 48;
         }
     }
};

struct Convert {
    std::vector <std::string> ChangeRegistersSize(const std::string &registers, const uint8_t &size) {
        if (size != 8 && size != 16 && size != 32 && size != 64) {
            return {};
        }
        std::string reg1 {};
        std::string reg2 {};
        if (registers.find(',') != std::string::npos) {
            size_t i = 0;
            for (; registers[i] != ','; ++i) {
                if (std::isalpha(registers[i])) {
                    reg1 += registers[i];
                }
            }
            for (; i < registers.length(); ++i) {
                if (std::isalpha(registers[i])) {
                    reg2 += registers[i];
                }
            }
            if (size == 8) {
                switch (HashFunc(reg1.c_str())) {
                    case HashFunc("rax"): {
                        reg1 = "al";
                        break;    
                    }
                    case HashFunc("rcx"): {
                        reg1 = "cl";
                        break;
                    }
                    case HashFunc("rdx"): {
                        reg1 = "dl";
                        break;
                    }
                    case HashFunc("rbx"): {
                        reg1 = "bl";
                        break;
                    }

                    case HashFunc("eax"): {
                        reg1 = "al";
                        break;    
                    }
                    case HashFunc("ecx"): {
                        reg1 = "cl";
                        break;
                    }
                    case HashFunc("edx"): {
                        reg1 = "dl";
                        break;
                    }
                    case HashFunc("ebx"): {
                        reg1 = "bl";
                        break;
                    }

                    case HashFunc("ax"): {
                        reg1 = "al";
                        break;    
                    }
                    case HashFunc("cx"): {
                        reg1 = "cl";
                        break;
                    }
                    case HashFunc("dx"): {
                        reg1 = "dl";
                        break;
                    }
                    case HashFunc("bx"): {
                        reg1 = "bl";
                        break;
                    }
                    default: {
                        return {};
                    }
                }
                switch (HashFunc(reg2.c_str())) {
                    case HashFunc("rax"): {
                        reg2 = "al";
                        break;    
                    }
                    case HashFunc("rcx"): {
                        reg2 = "cl";
                        break;
                    }
                    case HashFunc("rdx"): {
                        reg2 = "dl";
                        break;
                    }
                    case HashFunc("rbx"): {
                        reg2 = "bl";
                        break;
                    }

                    case HashFunc("eax"): {
                        reg2 = "al";
                        break;    
                    }
                    case HashFunc("ecx"): {
                        reg2 = "cl";
                        break;
                    }
                    case HashFunc("edx"): {
                        reg2 = "dl";
                        break;
                    }
                    case HashFunc("ebx"): {
                        reg2 = "bl";
                        break;
                    }

                    case HashFunc("ax"): {
                        reg2 = "al";
                        break;    
                    }
                    case HashFunc("cx"): {
                        reg2 = "cl";
                        break;
                    }
                    case HashFunc("dx"): {
                        reg2 = "dl";
                        break;
                    }
                    case HashFunc("bx"): {
                        reg2 = "bl";
                        break;
                    }
                    default: {
                        return {};
                    }
                }
            }
            else if (size == 16) {
                switch (HashFunc(reg1.c_str())) {
                    case HashFunc("rax"): {
                        reg1 = "ax";
                        break;    
                    }
                    case HashFunc("rcx"): {
                        reg1 = "cx";
                        break;
                    }
                    case HashFunc("rdx"): {
                        reg1 = "dx";
                        break;
                    }
                    case HashFunc("rbx"): {
                        reg1 = "bx";
                        break;
                    }
                    case HashFunc("rsp"): {
                        reg1 = "sp";
                        break;
                    }
                    case HashFunc("rbp"): {
                        reg1 = "bp";
                        break;
                    }
                    case HashFunc("rsi"): {
                        reg1 = "si";
                        break;
                    }
                    case HashFunc("rdi"): {
                        reg1 = "di";
                        break;
                    }

                    case HashFunc("eax"): {
                        reg1 = "ax";
                        break;    
                    }
                    case HashFunc("ecx"): {
                        reg1 = "cx";
                        break;
                    }
                    case HashFunc("edx"): {
                        reg1 = "dx";
                        break;
                    }
                    case HashFunc("ebx"): {
                        reg1 = "bx";
                        break;
                    }
                    case HashFunc("esp"): {
                        reg1 = "sp";
                        break;
                    }
                    case HashFunc("ebp"): {
                        reg1 = "bp";
                        break;
                    }
                    case HashFunc("esi"): {
                        reg1 = "si";
                        break;
                    }
                    case HashFunc("edi"): {
                        reg1 = "di";
                        break;
                    }

                    case HashFunc("al"): {
                        reg1 = "ax";
                        break;    
                    }
                    case HashFunc("cl"): {
                        reg1 = "cx";
                        break;
                    }
                    case HashFunc("dl"): {
                        reg1 = "dx";
                        break;
                    }
                    case HashFunc("bl"): {
                        reg1 = "bx";
                        break;
                    }
                    default: {
                        return {};
                    }
                }
                switch (HashFunc(reg2.c_str())) {
                    case HashFunc("rax"): {
                        reg2 = "ax";
                        break;    
                    }
                    case HashFunc("rcx"): {
                        reg2 = "cx";
                        break;
                    }
                    case HashFunc("rdx"): {
                        reg2 = "dx";
                        break;
                    }
                    case HashFunc("rbx"): {
                        reg2 = "bx";
                        break;
                    }
                    case HashFunc("rsp"): {
                        reg2 = "sp";
                        break;
                    }
                    case HashFunc("rbp"): {
                        reg2 = "bp";
                        break;
                    }
                    case HashFunc("rsi"): {
                        reg2 = "si";
                        break;
                    }
                    case HashFunc("rdi"): {
                        reg2 = "di";
                        break;
                    }

                    case HashFunc("eax"): {
                        reg2 = "ax";
                        break;    
                    }
                    case HashFunc("ecx"): {
                        reg2 = "cx";
                        break;
                    }
                    case HashFunc("edx"): {
                        reg2 = "dx";
                        break;
                    }
                    case HashFunc("ebx"): {
                        reg2 = "bx";
                        break;
                    }
                    case HashFunc("esp"): {
                        reg2 = "sp";
                        break;
                    }
                    case HashFunc("ebp"): {
                        reg2 = "bp";
                        break;
                    }
                    case HashFunc("esi"): {
                        reg2 = "si";
                        break;
                    }
                    case HashFunc("edi"): {
                        reg2 = "di";
                        break;
                    }

                    case HashFunc("al"): {
                        reg2 = "ax";
                        break;    
                    }
                    case HashFunc("cl"): {
                        reg2 = "cx";
                        break;
                    }
                    case HashFunc("dl"): {
                        reg2 = "dx";
                        break;
                    }
                    case HashFunc("bl"): {
                        reg2 = "bx";
                        break;
                    }
                    default: {
                        return {};
                    }
                }
            }
            else if (size == 32) {
                switch (HashFunc(reg1.c_str())) {
                    case HashFunc("rax"): {
                        reg1 = "eax";
                        break;    
                    }
                    case HashFunc("rcx"): {
                        reg1 = "ecx";
                        break;
                    }
                    case HashFunc("rdx"): {
                        reg1 = "edx";
                        break;
                    }
                    case HashFunc("rbx"): {
                        reg1 = "ebx";
                        break;
                    }
                    case HashFunc("rsp"): {
                        reg1 = "esp";
                        break;
                    }
                    case HashFunc("rbp"): {
                        reg1 = "ebp";
                        break;
                    }
                    case HashFunc("rsi"): {
                        reg1 = "esi";
                        break;
                    }
                    case HashFunc("rdi"): {
                        reg1 = "edi";
                        break;
                    }

                    case HashFunc("ax"): {
                        reg1 = "eax";
                        break;    
                    }
                    case HashFunc("cx"): {
                        reg1 = "ecx";
                        break;
                    }
                    case HashFunc("dx"): {
                        reg1 = "edx";
                        break;
                    }
                    case HashFunc("bx"): {
                        reg1 = "ebx";
                        break;
                    }
                    case HashFunc("sp"): {
                        reg1 = "esp";
                        break;
                    }
                    case HashFunc("bp"): {
                        reg1 = "ebp";
                        break;
                    }
                    case HashFunc("si"): {
                        reg1 = "esi";
                        break;
                    }
                    case HashFunc("di"): {
                        reg1 = "edi";
                        break;
                    }

                    case HashFunc("al"): {
                        reg1 = "eax";
                        break;    
                    }
                    case HashFunc("cl"): {
                        reg1 = "ecx";
                        break;
                    }
                    case HashFunc("dl"): {
                        reg1 = "edx";
                        break;
                    }
                    case HashFunc("bl"): {
                        reg1 = "ebx";
                        break;
                    }
                    default: {
                        return {};
                    }
                }
                switch (HashFunc(reg2.c_str())) {
                    case HashFunc("rax"): {
                        reg2 = "eax";
                        break;    
                    }
                    case HashFunc("rcx"): {
                        reg2 = "ecx";
                        break;
                    }
                    case HashFunc("rdx"): {
                        reg2 = "edx";
                        break;
                    }
                    case HashFunc("rbx"): {
                        reg2 = "ebx";
                        break;
                    }
                    case HashFunc("rsp"): {
                        reg2 = "esp";
                        break;
                    }
                    case HashFunc("rbp"): {
                        reg2 = "ebp";
                        break;
                    }
                    case HashFunc("rsi"): {
                        reg2 = "esi";
                        break;
                    }
                    case HashFunc("rdi"): {
                        reg2 = "edi";
                        break;
                    }

                    case HashFunc("ax"): {
                        reg2 = "eax";
                        break;    
                    }
                    case HashFunc("cx"): {
                        reg2 = "ecx";
                        break;
                    }
                    case HashFunc("dx"): {
                        reg2 = "edx";
                        break;
                    }
                    case HashFunc("bx"): {
                        reg2 = "ebx";
                        break;
                    }
                    case HashFunc("sp"): {
                        reg2 = "esp";
                        break;
                    }
                    case HashFunc("bp"): {
                        reg2 = "ebp";
                        break;
                    }
                    case HashFunc("si"): {
                        reg2 = "esi";
                        break;
                    }
                    case HashFunc("di"): {
                        reg2 = "edi";
                        break;
                    }

                    case HashFunc("al"): {
                        reg2 = "eax";
                        break;    
                    }
                    case HashFunc("cl"): {
                        reg2 = "ecx";
                        break;
                    }
                    case HashFunc("dl"): {
                        reg2 = "edx";
                        break;
                    }
                    case HashFunc("bl"): {
                        reg2 = "ebx";
                        break;
                    }
                    default: {
                        return {};
                    }
                }
            }
            else { // 64
                switch (HashFunc(reg1.c_str())) {
                    case HashFunc("eax"): {
                        reg1 = "rax";
                        break;    
                    }
                    case HashFunc("ecx"): {
                        reg1 = "rcx";
                        break;
                    }
                    case HashFunc("edx"): {
                        reg1 = "rdx";
                        break;
                    }
                    case HashFunc("ebx"): {
                        reg1 = "rbx";
                        break;
                    }
                    case HashFunc("esp"): {
                        reg1 = "rsp";
                        break;
                    }
                    case HashFunc("ebp"): {
                        reg1 = "rbp";
                        break;
                    }
                    case HashFunc("esi"): {
                        reg1 = "rsi";
                        break;
                    }
                    case HashFunc("edi"): {
                        reg1 = "rdi";
                        break;
                    }
                    
                    case HashFunc("ax"): {
                        reg1 = "rax";
                        break;    
                    }
                    case HashFunc("cx"): {
                        reg1 = "rcx";
                        break;
                    }
                    case HashFunc("dx"): {
                        reg1 = "rdx";
                        break;
                    }
                    case HashFunc("bx"): {
                        reg1 = "rbx";
                        break;
                    }
                    case HashFunc("sp"): {
                        reg1 = "rsp";
                        break;
                    }
                    case HashFunc("bp"): {
                        reg1 = "rbp";
                        break;
                    }
                    case HashFunc("si"): {
                        reg1 = "rsi";
                        break;
                    }
                    case HashFunc("di"): {
                        reg1 = "rdi";
                        break;
                    }

                    case HashFunc("al"): {
                        reg1 = "rax";
                        break;    
                    }
                    case HashFunc("cl"): {
                        reg1 = "rcx";
                        break;
                    }
                    case HashFunc("dl"): {
                        reg1 = "rdx";
                        break;
                    }
                    case HashFunc("bl"): {
                        reg1 = "rbx";
                        break;
                    }
                    default: {
                        return {};
                    }
                }
                switch (HashFunc(reg2.c_str())) {
                    case HashFunc("eax"): {
                        reg2 = "rax";
                        break;    
                    }
                    case HashFunc("ecx"): {
                        reg2 = "rcx";
                        break;
                    }
                    case HashFunc("edx"): {
                        reg2 = "rdx";
                        break;
                    }
                    case HashFunc("ebx"): {
                        reg2 = "rbx";
                        break;
                    }
                    case HashFunc("esp"): {
                        reg2 = "rsp";
                        break;
                    }
                    case HashFunc("ebp"): {
                        reg2 = "rbp";
                        break;
                    }
                    case HashFunc("esi"): {
                        reg2 = "rsi";
                        break;
                    }
                    case HashFunc("edi"): {
                        reg2 = "rdi";
                        break;
                    }

                    case HashFunc("ax"): {
                        reg2 = "rax";
                        break;    
                    }
                    case HashFunc("cx"): {
                        reg2 = "rcx";
                        break;
                    }
                    case HashFunc("dx"): {
                        reg2 = "rdx";
                        break;
                    }
                    case HashFunc("bx"): {
                        reg2 = "rbx";
                        break;
                    }
                    case HashFunc("sp"): {
                        reg2 = "rsp";
                        break;
                    }
                    case HashFunc("bp"): {
                        reg2 = "rbp";
                        break;
                    }
                    case HashFunc("si"): {
                        reg2 = "rsi";
                        break;
                    }
                    case HashFunc("di"): {
                        reg2 = "rdi";
                        break;
                    }

                    case HashFunc("al"): {
                        reg2 = "rax";
                        break;    
                    }
                    case HashFunc("cl"): {
                        reg2 = "rcx";
                        break;
                    }
                    case HashFunc("dl"): {
                        reg2 = "rdx";
                        break;
                    }
                    case HashFunc("bl"): {
                        reg2 = "rbx";
                        break;
                    }
                    default: {
                        return {};
                    }
                }
            }
            return {reg1, reg2};
        }
        else {
            std::string reg1 {};
            for (const char &c : registers) {
                if (std::isalpha(c)) {
                    reg1 += c;
                }
            }
            if (size == 8) {
                switch (HashFunc(reg1.c_str())) {
                    case HashFunc("rax"): {
                        reg1 = "al";
                        break;    
                    }
                    case HashFunc("rcx"): {
                        reg1 = "cl";
                        break;
                    }
                    case HashFunc("rdx"): {
                        reg1 = "dl";
                        break;
                    }
                    case HashFunc("rbx"): {
                        reg1 = "bl";
                        break;
                    }

                    case HashFunc("eax"): {
                        reg1 = "al";
                        break;    
                    }
                    case HashFunc("ecx"): {
                        reg1 = "cl";
                        break;
                    }
                    case HashFunc("edx"): {
                        reg1 = "dl";
                        break;
                    }
                    case HashFunc("ebx"): {
                        reg1 = "bl";
                        break;
                    }
                    default: {
                        return {};
                    }
                }
            }
            else if (size == 16) {
                switch (HashFunc(reg1.c_str())) {
                    case HashFunc("rax"): {
                        reg1 = "ax";
                        break;    
                    }
                    case HashFunc("rcx"): {
                        reg1 = "cx";
                        break;
                    }
                    case HashFunc("rdx"): {
                        reg1 = "dx";
                        break;
                    }
                    case HashFunc("rbx"): {
                        reg1 = "bx";
                        break;
                    }
                    case HashFunc("rsp"): {
                        reg1 = "sp";
                        break;
                    }
                    case HashFunc("rbp"): {
                        reg1 = "bp";
                        break;
                    }
                    case HashFunc("rsi"): {
                        reg1 = "si";
                        break;
                    }
                    case HashFunc("rdi"): {
                        reg1 = "di";
                        break;
                    }

                    case HashFunc("eax"): {
                        reg1 = "ax";
                        break;    
                    }
                    case HashFunc("ecx"): {
                        reg1 = "cx";
                        break;
                    }
                    case HashFunc("edx"): {
                        reg1 = "dx";
                        break;
                    }
                    case HashFunc("ebx"): {
                        reg1 = "bx";
                        break;
                    }
                    case HashFunc("esp"): {
                        reg1 = "sp";
                        break;
                    }
                    case HashFunc("ebp"): {
                        reg1 = "bp";
                        break;
                    }
                    case HashFunc("esi"): {
                        reg1 = "si";
                        break;
                    }
                    case HashFunc("edi"): {
                        reg1 = "di";
                        break;
                    }
                    default: {
                        return {};
                    }
                }
            }
            else if (size == 32) {
                switch (HashFunc(reg1.c_str())) {
                    case HashFunc("rax"): {
                        reg1 = "eax";
                        break;    
                    }
                    case HashFunc("rcx"): {
                        reg1 = "ecx";
                        break;
                    }
                    case HashFunc("rdx"): {
                        reg1 = "edx";
                        break;
                    }
                    case HashFunc("rbx"): {
                        reg1 = "ebx";
                        break;
                    }
                    case HashFunc("rsp"): {
                        reg1 = "esp";
                        break;
                    }
                    case HashFunc("rbp"): {
                        reg1 = "ebp";
                        break;
                    }
                    case HashFunc("rsi"): {
                        reg1 = "esi";
                        break;
                    }
                    case HashFunc("rdi"): {
                        reg1 = "edi";
                        break;
                    }
                    default: {
                        return {};
                    }
                }
            }
            else { // 64
                switch (HashFunc(reg1.c_str())) {
                    case HashFunc("eax"): {
                        reg1 = "rax";
                        break;    
                    }
                    case HashFunc("ecx"): {
                        reg1 = "rcx";
                        break;
                    }
                    case HashFunc("edx"): {
                        reg1 = "rdx";
                        break;
                    }
                    case HashFunc("ebx"): {
                        reg1 = "rbx";
                        break;
                    }
                    case HashFunc("esp"): {
                        reg1 = "rsp";
                        break;
                    }
                    case HashFunc("ebp"): {
                        reg1 = "rbp";
                        break;
                    }
                    case HashFunc("esi"): {
                        reg1 = "rsi";
                        break;
                    }
                    case HashFunc("edi"): {
                        reg1 = "rdi";
                        break;
                    }
                    default: {
                        return {};
                    }
                }
            }
            return {reg1}; 
        }
    }
}Converter;


void Parse(std::vector <std::string> &output, const std::string &Format, std::ifstream &File) {
     // all lines that commented with predifined, and other opcodes that have in docs `+rb` or `+rw` or `+rd` needs to redone because it is means that:
     // '+' 'rb' or 'rw' or 'rd' - means '+8' in 99% cases, and that value corresponds to what register operation will affect
     // example: 0x56 - `push esi`; 0x5e - `pop esi`. (0x56 + 0x8 = 0x5e)
     const std::vector <Commands> commands = {
          {0x50, "push rax"},
          {0x51, "push rcx"},
          {0x52, "push rdx"},
          {0x53, "push rbx"},
          {0x54, "push rsp"},
          {0x55, "push rbp"},
          {0x58, "pop rax"},
          {0x59, "pop rcx"},
          {0x5A, "pop rdx"},
          {0x5B, "pop rbx"},
          {0x5C, "pop rsp"},
          {0x5D, "pop rbp"},
          
          {0x0F, EMPTY}, // mov
          {0x88, EMPTY}, // mov 
          {0x89, EMPTY}, // mov
          {0x8B, EMPTY}, // mov 
          {0x8D, EMPTY}, // lea
          {0xE8, EMPTY}, // call

          {0x90, "nop"},
          {0xC3, "ret"}, // no input
          {0xCB, "ret"}, // no input
          {0xC9, "leave"}, // no input
          {0xF4, "hlt"}, // no input
     };
     bool ARCH_X64 {};
     std::vector <uint8_t> insiders;
     std::string builder {};
     std::stringstream hexer {};
     uint64_t entry {};
     uint8_t byte {}; 
     uint16_t Arch {};
     uint32_t text_size {};
     
     // NOTES:
     // .read reads each character
     // hex values are readed backwars, like 0x4550 will be: 50 -> P, 45 -> E, output is PE
     // to find info about sections goto 'shoff' address and skip 40 bytes of zeros and then you find 1 section, next section is located in adress: `current section start position + shent_size` 
     
     if (Format == "ELF") {
          uint32_t phoff {};
          uint32_t shoff {};
          uint16_t phnum {};
          uint16_t shnum {};
          uint16_t phent_size {};
          uint16_t shent_size {};
          uint8_t numbers_size {};

          File.seekg(0x12);
          File.read(reinterpret_cast<char*>(&Arch), sizeof(Arch));
          if (Arch == 0x3E) {
               ARCH_X64 = true;
               output.push_back("x86-64");
               output.push_back("");
               numbers_size = 8;
          }
          else if (Arch == 0x03 || Arch == 0x13) {
               ARCH_X64 = false;
               output.push_back("x86");
               output.push_back("");
               numbers_size = 4;
          }
          else {
               output.clear();
               std::cerr << "Unknown Linux architecture: " + std::to_string(Arch) << std::endl;
               return;
          }
          File.seekg(0x18);
          File.read(reinterpret_cast<char*>(&entry), numbers_size); 
          
          File.seekg(0x18 + numbers_size); 
          File.read(reinterpret_cast<char*>(&phoff), numbers_size);
        
          File.seekg(0x18 + numbers_size + numbers_size);
          File.read(reinterpret_cast<char*>(&shoff), numbers_size);
          
          File.seekg(0x18 + numbers_size + numbers_size + numbers_size + 6);
          File.read(reinterpret_cast<char*>(&phent_size), 2);

          File.seekg(0x18 + numbers_size + numbers_size + numbers_size + 8);
          File.read(reinterpret_cast<char*>(&phnum), 2);

          File.seekg(0x18 + numbers_size + numbers_size + numbers_size + 10);
          File.read(reinterpret_cast<char*>(&shent_size), 2);

          File.seekg(0x18 + numbers_size + numbers_size + numbers_size + 12); 
          File.read(reinterpret_cast<char*>(&shnum), 2);
            //    14 - .text section
            //    shent_size - size of section
            //    0x20 - skipping 40 bytes of zeros
          if (numbers_size == 8) {
              text_size = shoff + (14 * shent_size) + 0x20; 
          }
          else {
              text_size = shoff + (13 * shent_size) + 0x14;
          }
          File.seekg(text_size);
          File.read(reinterpret_cast<char*>(&text_size), 4);
          for (size_t i = 0; i < text_size; ++i) {
               File.seekg(entry + i);
               File.read(reinterpret_cast<char*>(&byte), 1);
               insiders.push_back(byte);
          }
     }
     else if (Format == "WIN") { 
          uint16_t sections_amount {};
          uint32_t signature {};
          uint16_t arch_spec_text_section {};
          std::string str {}; 
          str.resize(4); // needed so .read() writes to existing place
          File.seekg(0x3C);
          File.read(reinterpret_cast<char*>(&signature), 4);
          File.seekg(signature);
          File.read(&str[0], 4);
          const std::string tmp("PE\0\0", 4);
          if (str != tmp) {
               return;
          }
          File.seekg(signature + 4);
          File.read(reinterpret_cast<char*>(&Arch), sizeof(Arch));
          if (Arch == 0x8664) {
               ARCH_X64 = true;
               output.push_back("x86-64");
               output.push_back("");
               arch_spec_text_section = 0x188;

          }
          else if (Arch == 0x014C) {
               ARCH_X64 = false;
               output.push_back("x86");
               output.push_back("");
               arch_spec_text_section = 0x178;

          }
          else {
               output.clear();
               std::cerr << "Unknown Windows architecture: " + std::to_string(Arch) << std::endl;
               return;
          }
          File.seekg(signature + 6);
          File.read(reinterpret_cast<char*>(&sections_amount), 2);
          File.seekg(arch_spec_text_section + 8); 
          File.read(reinterpret_cast<char*>(&text_size), 4); 
          File.seekg(arch_spec_text_section + 20);
          File.read(reinterpret_cast<char*>(&entry), 4);
          for (size_t i = 0; i < text_size; ++i) {
               File.seekg(entry + i);
               File.read(reinterpret_cast<char*>(&byte), 1);
               insiders.push_back(byte);
          }
     }
     else {
          output.clear();
          std::cerr << "Format error \n";
          std::cerr.flush();
          return;
     }
     for (size_t y = 0; y < insiders.size(); ++y) {
          for (size_t x = 0; x < commands.size(); ++x) {
               if (commands[x].opcode == insiders[y]) {
                    if (strcmp(commands[x].called, EMPTY) != 0) {
                         builder = (commands[x].called);
                         if (builder.find("push") != std::string::npos) {
                              if (!ARCH_X64) {
                                   std::vector <std::string> temp = Converter.ChangeRegistersSize(builder.substr(5), 32);
                                   builder = "push " + temp.front();
                              }
                         }
                         else if (builder.find("pop") != std::string::npos) {
                              if (!ARCH_X64) {
                                   std::vector <std::string> temp = Converter.ChangeRegistersSize(builder.substr(4), 32);
                                   builder = "pop " + temp.front();
                              } 
                         }
                         y++;
                         output.push_back(builder);
                         builder.assign(builder.length(), '\0');
                         builder.clear();
                         break;
                    }
                    size_t z = 0;
                    switch(commands[x].opcode) {
                         case 0x0F: {
                              if (insiders[y+1] == 0x22) {
                                   builder = "mov ";    
                                   unsigned short temp = insiders[y + 2];
                                   unsigned short mod = (temp >> 6) & 0b11; // get 2 bit value 
                                   unsigned short rg1 = (temp >> 0) & 0b111; // get 3 bit value
                                   unsigned short rg2 = (temp >> 3) & 0b111; // get 3 bit value
                                   if (mod != 0b11) {
                                   std::cerr << "Unknown mod of command" << std::endl;
                                   output.clear();
                                   return;
                                   }
                                   switch (rg1) {
                                        case 0: builder += "cr0, "; break;
                                        case 1: builder += "cr1, "; break;
                                        case 2: builder += "cr2, "; break;
                                        case 3: builder += "cr3, "; break;
                                        case 4: builder += "cr4, "; break;
                                        default: {
                                             std::cerr << "Unknown register of command" << std::endl;
                                             output.clear();
                                             return;
                                        }
                                   }
                                   if (ARCH_X64) { 
                                        switch (rg2) {
                                             case 0: {
                                                  builder += "rax";
                                                  break;
                                             }
                                             case 1: {
                                                  builder += "rcx";
                                                  break;
                                             }
                                             case 2: {
                                                  builder += "rdx";
                                                  break;
                                             }
                                             case 3: {
                                                  builder += "rbx";
                                                  break;
                                             }
                                             case 4: {
                                                  builder += "rsp";
                                                  break;
                                             }
                                             case 5: {
                                                  builder += "rbp";
                                                  break;
                                             }
                                             case 6: {
                                                  builder += "rsi";
                                                  break;
                                             }
                                             case 7: {
                                                  builder += "rdi";
                                                  break;
                                             }
                                             default: {
                                                  std::cerr << "Unknown register of command" << std::endl;
                                                  output.clear();
                                                  return;
                                             }
                                        }
                                   }
                                   else {
                                        switch (rg2) {
                                             case 0: {
                                                  builder += "eax";
                                                  break;
                                             }
                                             case 1: {
                                                  builder += "ecx";
                                                  break;
                                             }
                                             case 2: {
                                                  builder += "edx";
                                                  break;
                                             }
                                             case 3: {
                                                  builder += "ebx";
                                                  break;
                                             }
                                             case 4: {
                                                  builder += "esp";
                                                  break;
                                             }
                                             case 5: {
                                                  builder += "ebp";
                                                  break;
                                             }
                                             case 6: {
                                                  builder += "esi";
                                                  break;
                                             }
                                             case 7: {
                                                  builder += "edi";
                                                  break;
                                             }
                                             default: {
                                                  std::cerr << "Unknown register of command" << std::endl;
                                                  output.clear();
                                                  return;
                                             }
                                        }
                                   }
                                   
                              }
                              z += 2;
                              break;
                        }
                        case 0x88: {
                              unsigned short temp = insiders[y+1];
                              unsigned short mod = (temp >> 6) & 0b11;
                              unsigned short rg1 = (temp >> 0) & 0b111;
                              unsigned short rg2 = (temp >> 3) & 0b111;
                              builder = "mov ";
                              if (mod != 0b11) {
                                   std::cerr << "Unknown mod of command" << std::endl;
                                   output.clear();
                                   return;
                              }
                              if (ARCH_X64) { 
                                   switch (rg1) {
                                        case 0: {
                                             builder += "rax, ";
                                             break;
                                        }
                                        case 1: {
                                             builder += "rcx, ";
                                             break;
                                        }
                                        case 2: {
                                             builder += "rdx, ";
                                             break;
                                        }
                                        case 3: {
                                             builder += "rbx, ";
                                             break;
                                        }
                                        case 4: {
                                             builder += "rsp, ";
                                             break;
                                        }
                                        case 5: {
                                             builder += "rbp, ";
                                             break;
                                        }
                                        case 6: {
                                             builder += "rsi, ";
                                             break;
                                        }
                                        case 7: {
                                             builder += "rdi, ";
                                             break;
                                        }
                                        default: {
                                             std::cerr << "Unknown register of command" << std::endl;
                                             output.clear();
                                             return;
                                        }
                                   }
                                   switch (rg2) {
                                        case 0: {
                                             builder += "rax";
                                             break;
                                        }
                                        case 1: {
                                             builder += "rcx";
                                             break;
                                        }
                                        case 2: {
                                             builder += "rdx";
                                             break;
                                        }
                                        case 3: {
                                             builder += "rbx";
                                             break;
                                        }
                                        case 4: {
                                             builder += "rsp";
                                             break;
                                        }
                                        case 5: {
                                             builder += "rbp";
                                             break;
                                        }
                                        case 6: {
                                             builder += "rsi";
                                             break;
                                        }
                                        case 7: {
                                             builder += "rdi";
                                             break;
                                        }
                                        default: {
                                             hexer << std::hex << reinterpret_cast<unsigned short*>(rg2);
                                             builder += hexer.str();
                                             hexer.str("");
                                             hexer.clear();
                                             break;
                                        }
                                   }
                              }
                              else {
                                   switch (rg1) {
                                        case 0: {
                                             builder += "eax, ";
                                             break;
                                        }
                                        case 1: {
                                             builder += "ecx, ";
                                             break;
                                        }
                                        case 2: {
                                             builder += "edx, ";
                                             break;
                                        }
                                        case 3: {
                                             builder += "ebx, ";
                                             break;
                                        }
                                        case 4: {
                                             builder += "esp, ";
                                             break;
                                        }
                                        case 5: {
                                             builder += "ebp, ";
                                             break;
                                        }
                                        case 6: {
                                             builder += "esi, ";
                                             break;
                                        }
                                        case 7: {
                                             builder += "edi, ";
                                             break;
                                        }
                                        default: {
                                             std::cerr << "Unknown register of command" << std::endl;
                                             output.clear();
                                             return;
                                        }
                                   }
                                   switch (rg2) {
                                        case 0: {
                                             builder += "eax";
                                             break;
                                        }
                                        case 1: {
                                             builder += "ecx";
                                             break;
                                        }
                                        case 2: {
                                             builder += "edx";
                                             break;
                                        }
                                        case 3: {
                                             builder += "ebx";
                                             break;
                                        }
                                        case 4: {
                                             builder += "esp";
                                             break;
                                        }
                                        case 5: {
                                             builder += "ebp";
                                             break;
                                        }
                                        case 6: {
                                             builder += "esi";
                                             break;
                                        }
                                        case 7: {
                                             builder += "edi";
                                             break;
                                        }
                                        default: {
                                             hexer << std::hex << reinterpret_cast<unsigned short*>(rg2);
                                             builder += hexer.str();
                                             hexer.str("");
                                             hexer.clear();
                                             break;
                                        }
                                   }
                              }
                              z += 1;
                              break;
                         }
                         case 0x89: {
                              unsigned short temp = insiders[y+1];
                              unsigned short mod = (temp >> 6) & 0b11;
                              unsigned short rg1 = (temp >> 0) & 0b111;
                              unsigned short rg2 = (temp >> 3) & 0b111;
                              builder = "mov ";
                              if (mod != 0b11) {
                                   std::cerr << "Unknown mod of command" << std::endl;
                                   output.clear();
                                   return;
                              }
                              if (ARCH_X64) {
                                   switch (rg1) {
                                        case 0: {
                                             builder += "rax, ";
                                             break;
                                        }
                                        case 1: {
                                             builder += "rcx, ";
                                             break;
                                        }
                                        case 2: {
                                             builder += "rdx, ";
                                             break;
                                        }
                                        case 3: {
                                             builder += "rbx, ";
                                             break;
                                        }
                                        case 4: {
                                             builder += "rsp, ";
                                             break;
                                        }
                                        case 5: {
                                             builder += "rbp, ";
                                             break;
                                        }
                                        case 6: {
                                             builder += "rsi, ";
                                             break;
                                        }
                                        case 7: {
                                             builder += "rdi, ";
                                             break;
                                        }
                                        default: {
                                             std::cerr << "Unknown register of command" << std::endl;
                                             output.clear();
                                             return;
                                        }
                                   }
                                   switch (rg2) {
                                        case 0: {
                                             builder += "rax";
                                             break;
                                        }
                                        case 1: {
                                             builder += "rcx";
                                             break;
                                        }
                                        case 2: {
                                             builder += "rdx";
                                             break;
                                        }
                                        case 3: {
                                             builder += "rbx";
                                             break;
                                        }
                                        case 4: {
                                             builder += "rsp";
                                             break;
                                        }
                                        case 5: {
                                             builder += "rbp";
                                             break;
                                        }
                                        case 6: {
                                             builder += "rsi";
                                             break;
                                        }
                                        case 7: {
                                             builder += "rdi";
                                             break;
                                        }
                                        default: {
                                             hexer << std::hex << reinterpret_cast<unsigned short*>(rg2);
                                             builder += hexer.str();
                                             hexer.str("");
                                             hexer.clear();
                                             break; 
                                        }
                                   }
                              }
                              else {
                                   switch (rg1) {
                                        case 0: {
                                             builder += "eax, ";
                                             break;
                                        }
                                        case 1: {
                                             builder += "ecx, ";
                                             break;
                                        }
                                        case 2: {
                                             builder += "edx, ";
                                             break;
                                        }
                                        case 3: {
                                             builder += "ebx, ";
                                             break;
                                        }
                                        case 4: {
                                             builder += "esp, ";
                                             break;
                                        }
                                        case 5: {
                                             builder += "ebp, ";
                                             break;
                                        }
                                        case 6: {
                                             builder += "esi, ";
                                             break;
                                        }
                                        case 7: {
                                             builder += "edi, ";
                                             break;
                                        }
                                        default: {
                                             std::cerr << "Unknown register of command" << std::endl;
                                             output.clear();
                                             return;
                                        }
                                   }
                                   switch (rg2) {
                                        case 0: {
                                             builder += "eax";
                                             break;
                                        }
                                        case 1: {
                                             builder += "ecx";
                                             break;
                                        }
                                        case 2: {
                                             builder += "edx";
                                             break;
                                        }
                                        case 3: {
                                             builder += "ebx";
                                             break;
                                        }
                                        case 4: {
                                             builder += "esp";
                                             break;
                                        }
                                        case 5: {
                                             builder += "ebp";
                                             break;
                                        }
                                        case 6: {
                                             builder += "esi";
                                             break;
                                        }
                                        case 7: {
                                             builder += "edi";
                                             break;
                                        }
                                        default: {
                                             hexer << std::hex << reinterpret_cast<unsigned short*>(rg2);
                                             builder += hexer.str();
                                             hexer.str("");
                                             hexer.clear();
                                             break; 
                                        }
                                   }
                              }

                              z += 1;
                              break;
                         }
                         case 0x8B: {
                              unsigned short temp = insiders[y+1];
                              unsigned short mod = (temp >> 6) & 0b11;
                              unsigned short rg1 = (temp >> 3) & 0b111;
                              unsigned short rg2 = (temp >> 0) & 0b111;
                              [[maybe_unused]]uint32_t disp;
                              if (mod == 0b10) {
                                   if (rg1 == 0b100) {
                                        disp = *(reinterpret_cast<uint32_t*>(&insiders[y+3]));
                                        z += 2;
                                   }
                                   else {
                                        disp = *(reinterpret_cast<uint32_t*>(&insiders[y+2]));
                                         z += 1;
                                   }
                              }
                              else if (mod == 0b01) {
                                   if (rg1 == 0b100) {
                                        disp = *(reinterpret_cast<uint32_t*>(&insiders[y+3]));
                                        z += 2;
                                   }
                                   else {
                                        disp = *(reinterpret_cast<uint32_t*>(&insiders[y+2]));
                                        z += 1;
                                   }
                              }
                              else if (mod == 0b00) {
                                   if (rg1 == 0b100) {
                                        if (((*(reinterpret_cast<uint8_t*>(&insiders[y+2]))) & 0b111) == 0b101) {
                                            disp = *(reinterpret_cast<uint32_t*>(&insiders[y+3]));
                                            z += 2;
                                        }
                                        else {
                                            disp = *(reinterpret_cast<uint32_t*>(&insiders[y+2]));
                                            z += 1;
                                        }
                                   }
                                   else if (rg1 == 0b101) {
                                        disp = *(reinterpret_cast<uint32_t*>(&insiders[y+2]));
                                        z += 1;
                                   }
                                   else {
                                        disp = 0;
                                   }
                              }
                              else {
                                   std::cerr << "unknown mod of command" << std::endl;
                                   output.clear();
                                   return;
                              }
                              
                              builder = "mov ";
                              if (ARCH_X64) { 
                                   switch (rg1) {
                                        case 0: {
                                             builder += "rax, ";
                                             break;
                                        }
                                        case 1: {
                                             builder += "rcx, ";
                                             break;
                                        }
                                        case 2: {
                                             builder += "rdx, ";
                                             break;
                                        }
                                        case 3: {
                                             builder += "rbx, ";
                                             break;
                                        }
                                        case 4: {
                                             builder += "rsp, ";
                                             break;
                                        }
                                        case 5: {
                                             builder += "rbp, ";
                                             break;
                                        }
                                        case 6: {
                                             builder += "rsi, ";
                                             break;
                                        }
                                        case 7: {
                                             builder += "rdi, ";
                                             break;
                                        }
                                        default: {
                                             std::cerr << "Unknown register of command" << std::endl;
                                             output.clear();
                                             return;
                                        }
                                   }
                                   switch (rg2) {
                                        case 0: {
                                             builder += "QWORD [rax]";
                                             break;
                                        }
                                        case 1: {
                                             builder += "QWORD [rcx]";
                                             break;
                                        }
                                        case 2: {
                                             builder += "QWORD [rdx]";
                                             break;
                                        }
                                        case 3: {
                                             builder += "QWORD [rbx]";
                                             break;
                                        }
                                        case 4: {
                                             builder += "QWORD [rsp]";
                                             break;
                                        }
                                        case 5: {
                                             builder += "QWORD [rbp]";
                                             break;
                                        }
                                        case 6: {
                                             builder += "QWORD [rsi]";
                                             break;
                                        }
                                        case 7: {
                                             builder += "QWORD [rdi]";
                                             break;
                                        }
                                        default: {
                                             hexer << std::hex << reinterpret_cast<unsigned short*>(rg2);
                                             builder += hexer.str();
                                             hexer.str("");
                                             hexer.clear();
                                             break;
                                        }
                                   }
                              }
                              else {
                                   switch (rg1) {
                                        case 0: {
                                             builder += "eax, ";
                                             break;
                                        }
                                        case 1: {
                                             builder += "ecx, ";
                                             break;
                                        }
                                        case 2: {
                                             builder += "edx, ";
                                             break;
                                        }
                                        case 3: {
                                             builder += "ebx, ";
                                             break;
                                        }
                                        case 4: {
                                             builder += "esp, ";
                                             break;
                                        }
                                        case 5: {
                                             builder += "ebp, ";
                                             break;
                                        }
                                        case 6: {
                                             builder += "esi, ";
                                             break;
                                        }
                                        case 7: {
                                             builder += "edi, ";
                                             break;
                                        }
                                        default: {
                                             std::cerr << "Unknown register of command" << std::endl;
                                             output.clear();
                                             return;
                                        }
                                   }
                                   switch (rg2) {
                                        case 0: {
                                             builder += "DWORD [eax]";
                                             break;
                                        }
                                        case 1: {
                                             builder += "DWORD [ecx]";
                                             break;
                                        }
                                        case 2: {
                                             builder += "DWORD [edx]";
                                             break;
                                        }
                                        case 3: {
                                             builder += "DWORD [ebx]";
                                             break;
                                        }
                                        case 4: {
                                             builder += "DWORD [esp]";
                                             break;
                                        }
                                        case 5: {
                                             builder += "DWORD [ebp]";
                                             break;
                                        }
                                        case 6: {
                                             builder += "DWORD [esi]";
                                             break;
                                        }
                                        case 7: {
                                             builder += "DWORD [edi]";
                                             break;
                                        }
                                        default: {
                                             hexer << std::hex << reinterpret_cast<unsigned short*>(rg2);
                                             builder += hexer.str();
                                             hexer.str("");
                                             hexer.clear();
                                             break;
                                        }
                                   }
                              }

                              z += 1;
                              break;
                         }
                         case 0x8D: {
                              unsigned short temp = insiders[y+1];
                              unsigned short mod = (temp >> 6) & 0b11;
                              unsigned short rg1 = (temp >> 3) & 0b111;
                              unsigned short rg2 = (temp >> 0) & 0b111;
                              [[maybe_unused]]uint32_t disp;
                              if (mod == 0b10) {
                                   if (rg1 == 0b100) {
                                        disp = *(reinterpret_cast<uint32_t*>(&insiders[y+3]));
                                        z += 2;
                                   }
                                   else {
                                        disp = *(reinterpret_cast<uint32_t*>(&insiders[y+2]));
                                         z += 1;
                                   }
                              }
                              else if (mod == 0b01) {
                                   if (rg1 == 0b100) {
                                        disp = *(reinterpret_cast<uint32_t*>(&insiders[y+3]));
                                        z += 2;
                                   }
                                   else {
                                        disp = *(reinterpret_cast<uint32_t*>(&insiders[y+2]));
                                        z += 1;
                                   }
                              }
                              else if (mod == 0b00) {
                                   if (rg1 == 0b100) {
                                        if (((*(reinterpret_cast<uint8_t*>(&insiders[y+2]))) & 0b111) == 0b101) {
                                            disp = *(reinterpret_cast<uint32_t*>(&insiders[y+3]));
                                            z += 2;
                                        }
                                        else {
                                            disp = *(reinterpret_cast<uint32_t*>(&insiders[y+2]));
                                            z += 1;
                                        }
                                   }
                                   else if (rg1 == 0b101) {
                                        disp = *(reinterpret_cast<uint32_t*>(&insiders[y+2]));
                                        z += 1;
                                   }
                                   else {
                                        disp = 0;
                                   }
                              }
                              else {
                                   std::cerr << "unknown mod of command" << std::endl;
                                   output.clear();
                                   return;
                              }
                              builder = "lea ";
                              if (ARCH_X64) { 
                                   switch (rg1) {
                                        case 0: {
                                             builder += "rax, ";
                                             break;
                                        }
                                        case 1: {
                                             builder += "rcx, ";
                                             break;
                                        }
                                        case 2: {
                                             builder += "rdx, ";
                                             break;
                                        }
                                        case 3: {
                                             builder += "rbx, ";
                                             break;
                                        }
                                        case 4: {
                                             builder += "rsp, ";
                                             break;
                                        }
                                        case 5: {
                                             builder += "rbp, ";
                                             break;
                                        }
                                        case 6: {
                                             builder += "rsi, ";
                                             break;
                                        }
                                        case 7: {
                                             builder += "rdi, ";
                                             break;
                                        }
                                        default: {
                                             std::cerr << "Unknown register of command" << std::endl;
                                             output.clear();
                                             return;
                                        }
                                   }
                                   switch (rg2) {
                                        case 0: {
                                             builder += "rax";
                                             break;
                                        }
                                        case 1: {
                                             builder += "rcx";
                                             break;
                                        }
                                        case 2: {
                                             builder += "rdx";
                                             break;
                                        }
                                        case 3: {
                                             builder += "rbx";
                                             break;
                                        }
                                        case 4: {
                                             builder += "rsp";
                                             break;
                                        }
                                        case 5: {
                                             builder += "rbp";
                                             break;
                                        }
                                        case 6: {
                                             builder += "rsi";
                                             break;
                                        }
                                        case 7: {
                                             builder += "rdi";
                                             break;
                                        }
                                        default: {
                                             hexer << std::hex << reinterpret_cast<unsigned short*>(rg2);
                                             builder += hexer.str();
                                             hexer.str("");
                                             hexer.clear();
                                             break;
                                        }
                                   }
                              }
                              else {
                                   switch (rg1) {
                                        case 0: {
                                             builder += "eax, ";
                                             break;
                                        }
                                        case 1: {
                                             builder += "ecx, ";
                                             break;
                                        }
                                        case 2: {
                                             builder += "edx, ";
                                             break;
                                        }
                                        case 3: {
                                             builder += "ebx, ";
                                             break;
                                        }
                                        case 4: {
                                             builder += "esp, ";
                                             break;
                                        }
                                        case 5: {
                                             builder += "ebp, ";
                                             break;
                                        }
                                        case 6: {
                                             builder += "esi, ";
                                             break;
                                        }
                                        case 7: {
                                             builder += "edi, ";
                                             break;
                                        }
                                        default: {
                                             std::cerr << "Unknown register of command" << std::endl;
                                             output.clear();
                                             return;
                                        }
                                   }
                                   switch (rg2) {
                                        case 0: {
                                             builder += "eax";
                                             break;
                                        }
                                        case 1: {
                                             builder += "ecx";
                                             break;
                                        }
                                        case 2: {
                                             builder += "edx";
                                             break;
                                        }
                                        case 3: {
                                             builder += "ebx";
                                             break;
                                        }
                                        case 4: {
                                             builder += "esp";
                                             break;
                                        }
                                        case 5: {
                                             builder += "ebp";
                                             break;
                                        }
                                        case 6: {
                                             builder += "esi";
                                             break;
                                        }
                                        case 7: {
                                             builder += "edi";
                                             break;
                                        }
                                        default: {
                                             hexer << std::hex << reinterpret_cast<unsigned short*>(rg2);
                                             builder += hexer.str();
                                             hexer.str("");
                                             hexer.clear();
                                             break;
                                        }
                                   }
                              }

                              z += 1;
                              break;
                         }
                         case 0xE8: {
                              unsigned short temp = insiders[y+1];
                              hexer << std::hex << reinterpret_cast<unsigned short*>(temp);
                              builder = "call " + hexer.str();
                              hexer.str("");
                              hexer.clear();
                              z += 1;
                              break;
                         }

                         default: {
                              z++;
                              break;
                         }
                    }
                    size_t extra_zeros = z;
                    while (insiders[y + 1 + extra_zeros] == 0x0 && insiders[y + 2 + extra_zeros] == 0x0 && (y + 1 + extra_zeros < insiders.size())) {
                        extra_zeros += 2;
                    }
                    y += z;
                    if (extra_zeros != z) {
                        y += extra_zeros - z;
                    }
                    output.push_back(builder);
                    builder.assign(builder.length(), '\0');
                    builder.clear();
                    break;
               }
               else {
                    continue;
               }
          }
     }
     return;
}
