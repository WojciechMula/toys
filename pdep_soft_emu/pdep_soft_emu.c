#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>


// ------------------------------------------------------------------------


uint32_t naive(uint32_t src, uint32_t mask) {
    
    uint32_t result   = 0;
    uint32_t mask_bit = 1;
    uint32_t src_bit  = 1;
    int i;

    for (i=0; i < 32; i++, mask_bit <<= 1) {
        if (mask & mask_bit) {
            if (src & src_bit) {
                result |= mask_bit;
            }

            src_bit <<= 1;
        }
    }

    return result;
}


// ------------------------------------------------------------------------


uint32_t branchless(uint32_t src, uint32_t mask) {
    
    uint32_t result = 0;

    while (1) {

        // 1. isolate the lowest set bit of mask
        const uint32_t lowest = -mask & mask;

        if (lowest == 0) {
            break;
        }

        // 2. populate LSB from src
        const uint32_t LSB = (uint32_t)((int32_t)(src << 31) >> 31);

        // 3. copy bit from mask
        result |= LSB & lowest;

        // 4. clear lowest bit
        mask &= ~lowest;

        // 5. prepare for next iteration
        src >>= 1;
    }

    return result;
}

// ------------------------------------------------------------------------


uint32_t get_time(void) {
    static struct timeval T;
    gettimeofday(&T, NULL);
    return (T.tv_sec * 1000000) + T.tv_usec;
}



void compare() {

    const uint32_t mask = 0x01010101;

    for (int i=0; i < 16; i++) {
        assert(naive(i, mask) == branchless(i, mask));
    }
}


double test_naive(int iterations, const uint32_t mask) {
    volatile uint32_t result = 0;

    const uint32_t t1 = get_time();
    for (int i=0; i < iterations; i++) {
        result += naive(i, mask);
    }
    const uint32_t t2 = get_time();

    return (t2 - t1)/1000000.0;
}


double test_branchless(int iterations, const uint32_t mask) {
    volatile uint32_t result = 0;

    const uint32_t t1 = get_time();
    for (int i=0; i < iterations; i++) {
        result += branchless(i, mask);
    }
    const uint32_t t2 = get_time();

    return (t2 - t1)/1000000.0;
}


// ------------------------------------------------------------------------


int main() {
    compare();

    const int iterations = (1 << 20);
    uint32_t mask = 0;

    printf("| %8s | %15s | %15s | %10s |\n", "mask", "naive", "branchless", "speedup");

    for (int i=0; i < 33; i++) {

        const double tn = test_naive(iterations, mask);
        const double tb = test_branchless(iterations, mask);
        const double speedup = tn / tb;

        printf("| %08x | %15.4f | %15.4f | %10.2f |\n", mask, tn, tb, speedup);

        mask = 2*mask + 1;
    }
}
