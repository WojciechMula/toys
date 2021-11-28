#pragma once

#include <cstdint>

int utf8_bytes(uint32_t value, uint8_t* byte);
uint32_t utf8_bytes(uint32_t value);
