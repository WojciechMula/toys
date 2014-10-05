#include <stdint.h>

#ifdef HAVE_PEXT_INSTRUCTION
uint32_t pext(uint32_t src, uint32_t mask) {
    uint32_t result;

    __asm__ __volatile__ ("pext %2, %1, %20"
        : "=r" (result)
        : "r" (src)
        , "r" (mask)
    );

    return result;
}
#else
uint32_t pext(uint32_t src, uint32_t mask) {

    uint32_t result = 0;
    uint32_t bit    = 1;

    while (1) {
 
        // isolate LSB set bit
        const uint32_t LSB = (-mask & mask);
        if (LSB == 0) {
            return result;
        }

        // clear it in a mask
        mask &= ~LSB;

        const uint32_t value = src & LSB;

        // convert isolated bit to mask
        const uint32_t mv    = ((int32_t)(-value)) >> 31;

        // update result
        result |= mv & bit;
        bit <<= 1;
    }

    return result;
}
#endif
