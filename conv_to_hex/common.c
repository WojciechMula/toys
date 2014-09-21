#include <stdint.h>
#include <assert.h>

#ifdef HAVE_BSWAP_INSTRUCTION
uint32_t bswap(uint32_t x) {
    uint32_t result;
    __asm__ __volatile__(
          "bswap %0"
        : "=r" (result)
        : "0" (x)
    );

    return result;
}
#else
uint32_t bswap(uint32_t x) {
    const uint32_t b0 = x & 0xff;
    const uint32_t b1 = (x >>  8) & 0xff;
    const uint32_t b2 = (x >> 16) & 0xff;
    const uint32_t b3 = (x >> 24) & 0xff;

    return (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;
}
#endif


#ifdef HAVE_PDEP_INSTRUCTION
uint32_t pdep(uint32_t src1, uint32_t src2) {
    uint32_t result;

    __asm__ __volatile__(
        "pdep %1, %2, %0"
        : "r" (result)
        : "r" (src1)
        , "r" (src2)
    );

    return result;
}
#else
uint32_t pdep(uint32_t src1, uint32_t src2) {
    uint32_t result = 0;

    int k = 0;
    for (int i=0; i < 32; i++) {
        const uint32_t mask = (1u << i);

        if (src1 & mask) {
            if (src2 & (1u << k)) {
                result |= mask;
            }
            k += 1;
        }
    }

    return result;
}
#endif

