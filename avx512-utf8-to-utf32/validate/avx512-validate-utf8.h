#pragma once

#include <cstddef>
#include <immintrin.h>

bool avx512_validate_utf8__version1(const char* utf8, size_t size);

// avx512_validate_utf8_structure tests if leading bytes are followed by
// 1) the appropritate number of continuation bytes AND 2) another leading byte.
// Procedure does not check values of bytes, it does not detect all wrong
// UTF-8 sequencess.
bool avx512_validate_utf8_structure(__m512i input);
