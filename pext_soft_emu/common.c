#include <stdint.h>

uint32_t bswap(uint32_t x) {
    uint32_t result;

    __asm__ __volatile__("bswap %0" : "=&r" (result) : "0" (x));

    return result;
}
