#include <cstdint>
#include <cstdlib>
#include <immintrin.h>


void bitmask_naive(const uint32_t* array, size_t n, const uint32_t key, uint8_t* bitvector) {
    
    for (size_t i=0; i < n; i++) {
        const uint8_t val = (array[i] == key); // in C++ bool casted to int has value 0 or 1

        bitvector[i/8] |= val << (i % 8);
    }
}


void bitmask_better_1(const uint32_t* array, size_t n, const uint32_t key, uint8_t* bitvector) {

    const size_t blocks = n / 32;
    const size_t tail   = n % 32;

    const uint32_t *input = array;
    uint32_t* bitvector32 = reinterpret_cast<uint32_t*>(bitvector);

    for (size_t i=0; i < blocks; i++) {

        uint64_t result = 0xffffffffffffffffllu;
        uint64_t bit    = uint64_t(1) << 32;

        for (int j=0; j < 32; j++) {
            uint64_t low = bit - 1;

            // j-th bit (in the higher 32-bit word) is set if current input is not equal to the key
            uint64_t tmp = (key ^ *input) + low;
            input++;

            result ^= (tmp & bit); // clear j-th if the above condition is true
            bit <<= 1;
        }

        *bitvector32++ = result >> 32; // save 32 bits at once
    }

    // process tail
}


void bitmask_better_2(const uint32_t* array, size_t n, const uint32_t key, uint8_t* bitvector) {

    const size_t blocks = n / 32;
    const size_t tail   = n % 32;

    const uint32_t *input = array;
    uint32_t* bitvector32 = reinterpret_cast<uint32_t*>(bitvector);

    for (size_t i=0; i < blocks; i++) {

        uint32_t result = 0;

        for (int j=31; j >= 0; j--) {
            const uint32_t bit = (input[j] == key);   // (1)
            result = 2*result + bit;                  // (2)
        }

        *bitvector32++ = result;
        input += 32;
    }

    // process tail
}

