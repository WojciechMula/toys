#pragma once

#include <immintrin.h>
#include <cstdint>

size_t avx512_utf8_to_utf32__version1(const char* str, size_t len, uint32_t* dwords);
size_t avx512_utf8_to_utf32__version2(const char* str, size_t len, uint32_t* dwords);
size_t avx512_utf8_to_utf32__version3(const char* str, size_t len, uint32_t* dwords);
size_t avx512_utf8_to_utf32__version4(const char* str, size_t len, uint32_t* dwords);
size_t avx512_validating_utf8_to_utf32(const char* str, size_t len, uint32_t* dwords);
__m512i avx512_utf8_to_utf32__aux__version1(__m512i utf8);
__m512i avx512_utf8_to_utf32__aux__version2(__m512i utf8);
__m512i avx512_utf8_to_utf32__aux__version3(__m512i utf8);
__m512i avx512_utf8_to_utf32__aux__version4(__m512i utf8);
__m512i avx512_expand__version1(const char* ptr);
__m512i avx512_expand__version2(const char* ptr);
