#include <cstdint>

#ifdef HAVE_PEXT_INSTRUCTION
uint64_t pext(uint64_t src, uint64_t mask) {
    uint64_t result;

    __asm__ __volatile__ ("pext %2, %1, %0"
        : "=r" (result)
        : "r" (src)
        , "r" (mask)
    );

    return result;
}
#endif
