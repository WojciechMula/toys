#pragma once

#include <cstdint>
#include <cstdlib>

uint32_t avx2_16bit_sumbytes_variant2(uint8_t* array, size_t size);
uint32_t avx2_16bit_sumbytes_variant2_unrolled4(uint8_t* array, size_t size);

