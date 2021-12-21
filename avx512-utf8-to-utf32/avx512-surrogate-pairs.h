#pragma once

#include <cstddef>
#include <immintrin.h>

/*
Input:

- utf32 -- 16 x 32-bit Unicode characters
- valid -- selects which 32-bit lanes are active
- outut -- pointer to output buffer

Result:

- how many char16_t were stored

*/
size_t avx512_utf32_to_utf16(__m512i utf32, char16_t* output);
