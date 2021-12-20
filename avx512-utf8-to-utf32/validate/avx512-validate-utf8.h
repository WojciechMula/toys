#pragma once

#include <cstddef>
#include <immintrin.h>

bool avx512_validate_utf8__version1(const char* utf8, size_t size);
bool avx512vbmi_validate_utf8__version1(const char* utf8, size_t size);
