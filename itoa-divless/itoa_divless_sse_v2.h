#pragma once

#include <cstdint>

// itoa_divless_sse_v2 convert number into a 16-digit decimal representation.
// 
// Buffer has to point at 16-byte buffer (or large).
// The trailing zero is not written.
void itoa_divless_sse_v2(uint32_t x, char* buffer);
