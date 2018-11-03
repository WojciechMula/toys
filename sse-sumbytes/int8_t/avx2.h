#pragma once

#include <cstdint>
#include <cstdlib>

int32_t avx2_sumsignedbytes(int8_t* array, size_t size);
int32_t avx2_sumsignedbytes_variant2(int8_t* array, size_t size);
