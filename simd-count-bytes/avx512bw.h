#pragma once

#include <cstdint>
#include <cstddef>

uint64_t avx512bw_count_bytes(const uint8_t* data, size_t size, uint8_t byte);
