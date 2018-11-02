#pragma once

#include <cstdint>
#include <cstdlib>

int32_t sse_sadbw_sumsignedbytes(int8_t* array, size_t size);
int32_t sse_sadbw_unrolled4_sumsignedbytes(int8_t* array, size_t size);
