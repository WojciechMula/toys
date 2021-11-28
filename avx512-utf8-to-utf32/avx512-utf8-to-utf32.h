#pragma once

#include <immintrin.h>
#include <cstdint>

size_t avx512_utf8_to_utf32(const char* str, size_t len, uint32_t* dwords);
__m512i avx512_utf8_to_utf32__aux(__m512i utf8);
