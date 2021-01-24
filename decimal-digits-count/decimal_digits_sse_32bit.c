#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#define SIMD_ALIGN __attribute__((aligned(16)))
#define MAX_INT 2147483647

uint32_t powers_a[4] SIMD_ALIGN = {
	9,
	99,
	999,
	9999
};

uint32_t powers_b[4] SIMD_ALIGN = {
	99999,
	999999,
	9999999,
	99999999
};

uint32_t powers_c[4] SIMD_ALIGN = {
	999999999,
	MAX_INT,
	MAX_INT,
	MAX_INT,
};


int decimal_digits_sse(const int x) {
	assert(x >= 0);

	uint32_t result;

	__asm__ volatile(
		"movd 	%%eax, %%xmm0		\n"	// xmm0 = [x, 0, 0, 0]
		"pshufd $0, %%xmm0, %%xmm0	\n" // xmm0 = [x, x, x, x]
		"movapd %%xmm0, %%xmm1		\n"
		"movapd %%xmm0, %%xmm2		\n"
		"pcmpgtd  powers_a, %%xmm0	\n" // xmm0 = [x > 10^1 - 1, x > 10^2 - 1, x > 10^3 - 1, x > 10^4 - 1]
		"pcmpgtd  powers_b, %%xmm1	\n" // xmm1 = [x > 10^5 - 1, x > 10^6 - 1, x > 10^7 - 1, x > 10^8 - 1]
		"pcmpgtd  powers_c, %%xmm2	\n" // xmm2 = [x > 10^9 - 1, 0           , 0           , 0           ]
		                                // result of comparisons are: 0 (false) or -1 (true)
		// for example:
		// xmm0 = packed_dword(-1, -1, -1, -1)
		// xmm1 = packed_dword( 0,  0, -1, -1)
		// xmm2 = packed_dword( 0,  0,  0,  0)

		"psrld $31,    %%xmm0		\n" // xmm0 = packed_dword( 1, 1, 1, 1)
		"psubd %%xmm1, %%xmm0		\n" // xmm0 = packed_dword( 1, 1, 2, 2)
		"psubd %%xmm2, %%xmm0		\n" // xmm0 = packed_dword( 1, 1, 2, 2) -- no change

		"pxor     %%xmm1, %%xmm1	\n" // convert packed_dword to packed_word
		"packssdw %%xmm1, %%xmm0	\n" // xmm0 = packed_word(0, 0, 0, 0, 1, 1, 2, 2)
		                                // max value of word in xmm0 is 3, so higher
										// bytes are always zero
		"psadbw   %%xmm1, %%xmm0	\n" // xmm0 = packded_qword(0, 6)

		"movd %%xmm0, %%eax			\n" // eax = 6
		: "=a" (result)
		: "a" (x)
	);

	return result + 1;
}
