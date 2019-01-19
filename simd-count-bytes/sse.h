#pragma once

#include <cstdint>
#include <cstddef>

uint64_t sse_count_byte(const uint8_t* data, size_t size, uint8_t byte);
uint64_t sse_count_byte_popcount(const uint8_t* data, size_t size, uint8_t byte);
