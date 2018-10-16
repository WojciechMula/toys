#include "scalar.h"

uint32_t scalar_sumbytes(uint8_t* array, size_t size)
{
    uint32_t sum = 0;
    // this loop might get vectorized
    for (size_t i=0; i < size; i++)
        sum += array[i];

    return sum;
}
