#include <cstdint>

#ifdef HAVE_BMI2_INSTRUCTIONS
uint64_t pext(uint64_t src, uint64_t mask) {
    uint64_t result;

    __asm__ __volatile__ ("pext %2, %1, %0"
        : "=r" (result)
        : "r" (src)
        , "r" (mask)
    );

    return result;
}


uint64_t pdep(uint64_t src, uint64_t mask) {
    uint64_t result;

    __asm__ __volatile__ ("pdep %2, %1, %0"
        : "=r" (result)
        : "r" (src)
        , "r" (mask)
    );

    return result;
}

uint32_t pext32(uint32_t src, uint32_t mask) {
    uint32_t result;

    __asm__ __volatile__ ("pext %2, %1, %0"
        : "=r" (result)
        : "r" (src)
        , "r" (mask)
    );

    return result;
}


uint32_t pdep32(uint32_t src, uint32_t mask) {
    uint32_t result;

    __asm__ __volatile__ ("pdep %2, %1, %0"
        : "=r" (result)
        : "r" (src)
        , "r" (mask)
    );

    return result;
}
#endif
