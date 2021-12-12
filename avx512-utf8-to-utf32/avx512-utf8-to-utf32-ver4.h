#pragma once

#include <cstdint>

size_t avx512_utf8_to_utf32__version4(const char* str, size_t len, uint32_t* dwords);
