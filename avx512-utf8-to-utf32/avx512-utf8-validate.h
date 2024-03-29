#pragma once

#include <cstdint>
#include <immintrin.h>

/*
    Checks whether 16-20 bytes consist valid UTF-8 characters.

    - leading_bytes -- bitmask tells which bytes [0..15] contain a UTF-8 leading byte
    - valid_chars   -- bitmask tells which leading bytes are followed by the proper
                       number of continuation bytes

    Returns true if the bitmasks match and the first byte is the leading UTF-8 character.
*/
bool avx512_utf8_structure_validate_16_bytes(__m128i bytes_ap_128, __m128i bytes_qt_128);
bool avx512_utf8_structure_validate_16_bytes(__m128i bytes_ap_128, __m128i bytes_qt_128, uint16_t& leading_bytes, uint16_t& valid_chars);
bool avx512_utf8_structure_validate_16_bytes(const char* ptr, uint16_t& leading_bytes, uint16_t& valid_chars);

__mmask16 avx512_utf8_validate_ranges(__m512i char_class, __m512i utf32);
