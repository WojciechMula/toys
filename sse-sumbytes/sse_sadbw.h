#pragma once

#include <cstdint>
#include <cstdlib>

uint32_t sse_sadbw_sumbytes(uint8_t* array, size_t size);
uint32_t sse_sadbw_unrolled4_sumbytes(uint8_t* array, size_t size);
