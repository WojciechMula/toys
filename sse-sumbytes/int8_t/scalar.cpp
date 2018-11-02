#include "scalar.h"
#include <numeric>

int32_t scalar_sumsignedbytes(int8_t* array, size_t size)
{
    int32_t sum = 0;
    // this loop might get vectorized
    for (size_t i=0; i < size; i++)
        sum += array[i];

    return sum;
}

int32_t scalar_cpp_sumsignedbytes(int8_t* array, size_t size)
{
    return std::accumulate(array, array + size, int32_t(0));
}
