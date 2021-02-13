#pragma once

#include <cstdint>
#include <cstddef>

uint64_t avx512bw_count_bytes(const uint8_t* data, size_t size, uint8_t byte);
uint64_t avx512bw_count_bytes_unrolled(const uint8_t* data, size_t size, uint8_t byte);
uint64_t avx512bw_count_bytes__version2(const uint8_t* data, size_t size, uint8_t byte);
uint64_t avx512bw_count_bytes__version3(const uint8_t* data, size_t size, uint8_t byte);
uint64_t avx512bw_count_bytes__version4(const uint8_t* data, size_t size, uint8_t byte);
uint64_t avx512bw_count_bytes__version5(const uint8_t* data, size_t size, uint8_t byte);
