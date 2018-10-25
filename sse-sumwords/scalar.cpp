#include "scalar.h"
#include <numeric>

uint32_t scalar_sumwords(uint16_t* array, size_t size)
{
    uint32_t sum = 0;
    // this loop might get vectorized
    for (size_t i=0; i < size; i++)
        sum += array[i];

    return sum;
}

uint32_t scalar_cpp_sumwords(uint16_t* array, size_t size)
{
    return std::accumulate(array, array + size, uint32_t(0));
}
