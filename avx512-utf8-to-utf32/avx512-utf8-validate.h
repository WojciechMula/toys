#pragma once

#include <cstdint>

/*
    Checks whether 16-20 bytes consist valid UTF-8 characters.

    - leading_bytes -- bitmask tells which bytes [0..15] contain a UTF-8 leading byte
    - valid_chars   -- bitmask tells which leading bytes are followed by the proper
                       number of continuation bytes

    Returns true if the bitmasks match and the first byte is the leading UTF-8 character.
*/
bool avx512_utf8_structure_validate_16_bytes(const char* ptr, uint16_t& leading_bytes, uint16_t& valid_chars);
