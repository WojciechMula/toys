#ifndef CONV_H
#define CONV_H

#include <stdint.h>

uint32_t to_oct_pdep(uint32_t x);
uint64_t to_oct_sse2(uint32_t x);
uint32_t to_oct_naive(uint32_t x);
uint32_t to_oct_mul(uint32_t x);

void prepare_single_lookup();
uint32_t to_oct_single_lookup(uint32_t x);

void prepare_two_lookups();
uint32_t to_oct_two_lookups(uint16_t x);


#endif
