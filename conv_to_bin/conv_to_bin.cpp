/*
	Convert to binary representation - conversion procedures

	Author  : Wojciech Muła
	Date    : 2014-09-11
	License : BSD
*/


#include <cstdio>
#include <cstdint>
#include <cstring>
#include <assert.h>

#define SIMD_ALIGN __attribute__((aligned(16)))
#define packed_byte(x)   {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x}

// constants for SIMD version
uint8_t bit_mask[16] SIMD_ALIGN = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
uint8_t ascii[16]    SIMD_ALIGN = packed_byte('0');


namespace convert_to_bin {

// --- naive --------------------------------------------------------------

uint64_t naive(uint8_t v) {

	union {
		uint64_t qword;
		uint8_t  bytes[8];
	} result;

	for (int i=7; i >= 0; i--) {

		const uint8_t bit = (1 << i);

		result.bytes[i] = (v & bit) ? '1' : '0';
	}

	return result.qword;
}


// --- lookup -------------------------------------------------------------


static uint64_t lookup_table[256];

uint64_t lookup(uint8_t v) {
	return lookup_table[v];
}


void prepare_lookup() {
    for (int i=0; i < 256; i++) {
        lookup_table[i] = naive(i);
    }
}


// --- SWAR version -------------------------------------------------------


uint64_t swar(uint8_t v) {

	const uint64_t r1 =  v * 0x0101010101010101;
	const uint64_t r2 = r1 & 0x8040201008040201;
	const uint64_t r3 = r2 + 0x00406070787c7e7f;
	const uint64_t r4 = (r3 >> 7) & 0x0101010101010101;

	return 0x3030303030303030 + r4;  // ord('0') == 0x30
}


// --- SIMD version -------------------------------------------------------


#ifdef ARCH_64BIT
uint64_t simd(uint8_t v) {

    uint64_t result;

	__asm__ __volatile__ (
		// 1. populate byte
		"movd       %1,  %%xmm0    \n"
		"punpcklbw  %%xmm0, %%xmm0    \n"

		// 2. mask bits
		"pand       %2, %%xmm0  \n"
		"pcmpeqb    %2, %%xmm0  \n"

		// 3. convert to ASCII
		"movdqa     %3, %%xmm1     \n"
		"psubb      %%xmm0, %%xmm1    \n"

		// save result
		"movq       %%xmm1, %0   \n"

		: "=r" (result)

		: "r" (0x01010101 * v)
        , "m" (bit_mask)
        , "m" (ascii)

        : "memory"
	);

	return result;
}
#else
uint64_t simd(uint8_t v) {

    uint64_t result;

	__asm__ __volatile__ (
		// 1. populate byte
		"movd       %0,  %%xmm0    \n"
		"punpcklbw  %%xmm0, %%xmm0    \n"

		// 2. mask bits
		"pand       %1, %%xmm0  \n"
		"pcmpeqb    %1, %%xmm0  \n"

		// 3. convert to ASCII
		"movdqa     %2, %%xmm1     \n"
		"psubb      %%xmm0, %%xmm1    \n"

		// save result
		"movq       %%xmm1, (%3)   \n"

		: /* no output */

		: "r" (0x01010101 * v)
        , "m" (bit_mask)
        , "m" (ascii)
        , "r" (&result)

        : "memory"
	);

	return result;
}
#endif


// --- PDEP version -------------------------------------------------------


namespace CPU {

#ifdef HAVE_PDEP_INSTRUCTION
uint64_t pdep(uint64_t src1, uint64_t src2) {
    uint64_t result;

    __asm__ __volatile__(
        "pdep %1, %2, %0"
        : "=r" (result)
        : "r" (src1)
        , "r" (src2)
    );

    return result;
}
#else
uint64_t pdep(uint64_t src1, uint64_t src2) {
    uint64_t result = 0;

    int k = 0;
    for (int i=0; i < 64; i++) {
        const uint64_t mask = (1llu << i);


        if (src1 & mask) {
            if (src2 & (1llu << k)) {
                result |= mask;
            }
            k += 1;
        }
    }

    return result;
}
#endif


uint64_t bswap(uint64_t qword) {
    union {
        uint64_t qword;
        uint8_t  bytes[8];
    } result;

    result.qword = qword;

    for (int i=0; i < 4; i++) {
        const uint8_t t = result.bytes[i];

        result.bytes[i] = result.bytes[7 - i];
        result.bytes[7 - i] = t;
    }

    return result.qword;
}


} // namespace CPU


uint64_t pdep(uint8_t v) {

    const uint64_t expanded = CPU::pdep(0x0101010101010101, v);

	return 0x3030303030303030 + expanded;
}


} // namespace conv_to_bin

