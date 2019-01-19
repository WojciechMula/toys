#include "scalar.h"

uint64_t scalar_count_bytes(const uint8_t* data, size_t size, uint8_t byte) {
    uint64_t result = 0;
    for (size_t i = 0; i < size; i++)
        result += (data[i] == byte);

    return result;
}
