#pragma once

#include <cstdint>
#include <cstdlib>

uint32_t sse_sadbw_sumwords(uint16_t* array, size_t size);
uint32_t sse_sadbw_unrolled4_sumwords(uint16_t* array, size_t size);
