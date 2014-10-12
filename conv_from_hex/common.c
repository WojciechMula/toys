#include <stdint.h>

uint32_t bswap(uint32_t x) {
    uint32_t result;

    __asm__ __volatile__("bswap %0" : "=&r" (result) : "0" (x));

    return result;
}

#define SIMD_ALIGN __attribute__((aligned(16)))

#define packed_byte(b) {uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b)}
#define packed_word(w) {uint16_t(w), uint16_t(w), uint16_t(w), uint16_t(w), uint16_t(w), uint16_t(w), uint16_t(w), uint16_t(w)}

