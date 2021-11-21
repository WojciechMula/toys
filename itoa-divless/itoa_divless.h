#pragma once

#include <cstdint>

// itoa_divless convert number into a 16-digit decimal representation.
// 
// Buffer has to point at 16-byte buffer (or large).
// The trailing zero is not written.
void itoa_divless(uint32_t x, char* buffer);
