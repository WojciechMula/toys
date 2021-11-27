// Code from https://github.com/simdutf/simdutf
// src/scalar/utf8.h

#include "scalar.h"
#include <cstdint>

size_t count_code_points(const char* buf, size_t len) {
    const int8_t * p = reinterpret_cast<const int8_t *>(buf);
    size_t counter{0};
    for(size_t i = 0; i < len; i++) {
        // -65 is 0b10111111, anything larger in two-complement's should start a new code point.
        if(p[i] > -65) { counter++; }
    }
    return counter;
}

