#include <cstdint>


uint32_t naive(char* s) {

    uint32_t result = 0;

    for (int i=0; i < 4; i++) {
        uint8_t byte = s[i];

        result = result * 10 + (byte - '0');
    }

    return result;
}

