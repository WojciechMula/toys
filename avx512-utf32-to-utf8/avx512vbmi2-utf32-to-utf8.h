#pragma once

#include <cstddef>

#include <immintrin.h>

/*
    Input:

    expanded_utf8  - 16 x UTF-8 character; each from 1 to 4 bytes, unused bytes
                     in each lane are unspecified
    length - 16 x length of UTF-8 character (numbers from 1 to 4)
    output - at least 64 bytes long buffer

    Result:

    the number of bytes stored to `output`.
*/
size_t avx512vbmi2_compress_utf8(__m512i expanded_utf8, __m512i length, char* output);
