#pragma once

#include <cstdint>
#include <cstddef>

size_t avx512_utf8_to_utf32__version1(const char* str, size_t len, uint32_t* dwords);
size_t avx512_utf8_to_utf32__version2(const char* str, size_t len, uint32_t* dwords);
size_t avx512_utf8_to_utf32__version3(const char* str, size_t len, uint32_t* dwords);
size_t avx512_validating_utf8_to_utf32(const char* str, size_t len, uint32_t* dwords);
size_t avx512_validating_utf8_to_utf16(const char* str, size_t len, char16_t* chars);
