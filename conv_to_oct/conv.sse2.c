#include <stdint.h>

#define packed_word(w7, w6, w5, w4, w3, w2, w1, w0) {w0, w1, w2, w3, w4, w5, w6, w7}

#define SIMD_ALIGN __attribute__((aligned(16)))

uint16_t sse2_mask[8] SIMD_ALIGN =
    packed_word(0x000e, 0x0070, 0x0380, 0x1c00,
                0x000e, 0x0070, 0x0380, 0x1c00);

uint16_t sse2_mul[8] SIMD_ALIGN =
    packed_word(1 << 15, 1 << 12, 1 << 9, 1 << 6,
                1 << 15, 1 << 12, 1 << 9, 1 << 6);

uint8_t sse2_ascii[16] SIMD_ALIGN =
    {0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
     0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30};


// convert 8*3 bits
uint64_t to_oct_sse2(uint32_t x) {
    
    uint64_t result;

    const uint32_t lower  = x & 0x000fff; // lower 12 bits
    const uint32_t higher = x & 0xfff000; // higher 12 bits

    const uint32_t combined = lower | (higher << 4);

    // combined = |0000hhhgggfffeee|0000dddcccbbbaaa|
    //             word E-H         word A-D
    __asm__ __volatile__(
        // 1. populate words
        "movd %1, %%xmm0                \n" // packed_word(| 0 | 0 | 0 | 0 | 0 | 0 |E-H|A-D|)
        "punpcklwd %%xmm0, %%xmm0       \n" // packed_word(| 0 | 0 | 0 | 0 |E-H|E-H|A-D|A-D|)
        "punpcklwd %%xmm0, %%xmm0       \n" // packed_word(|E-H|E-H|E-H|E-H|A-D|A-D|A-D|A-D|)
        
        // 2. shift left all words
        // |000dddcccbbbaaa0|000dddcccbbbaaa0|000dddcccbbbaaa0|000dddcccbbbaaa0| .. same for E-H
        "paddw %%xmm0, %%xmm0           \n"

        // 3. mask bits
        // |000000000000aaa0|000000000bbb0000|000000ccc0000000|000ddd0000000000| .. same for E-H
        //        a                  b               c                 d
        "pand sse2_mask, %%xmm0         \n"

        // 4. shift:
        //    a << 15, b << 12, c << 9, d << 6
        "pmulhuw sse2_mul, %%xmm0       \n"

        // 5. pack and convert to ASCII
        "packuswb %%xmm0, %%xmm0        \n"
        "paddb sse2_ascii, %%xmm0       \n"

        "movq %%xmm0, %0                \n"
        : "=m" (result)
        : "r" (combined)
    );

    return result;
}
