#pragma once
#include <cstdint>
constexpr uint16_t HashFunc(const char *input) {
    uint16_t hash = 0; 
    while (*input) {
        hash = ((*input >> 1) | (*input << 7)) + (hash << 3) - hash; // (*input / 2 | *input * 8) + input * 4
        input++;
    }    
    return hash;
}
