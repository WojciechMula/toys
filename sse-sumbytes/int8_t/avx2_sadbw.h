#pragma once

#include <cstdint>
#include <cstdlib>

int32_t avx2_sadbw_sumsignedbytes(int8_t* array, size_t size);
int32_t avx2_sadbw_unrolled4_sumsignedbytes(int8_t* array, size_t size);

int32_t avx2_sadbw_variant_sumsignedbytes(int8_t* array, size_t size);
