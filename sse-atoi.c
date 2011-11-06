/*
	SSE: atoi implementation

*/

#include <stdio.h>
#include <stdint.h>

#define SIMD_ALIGN __attribute__((aligned(16)))

#define T(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) \
	{a1, a0, a3, a2, a5, a4, a7, a6, a9, a8, a11, a10, a13, a12, a15, a14} 
	// swapped adjacent elements!

static uint8_t transform[18][16] SIMD_ALIGN = {

	T(0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80),
	T(   0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80),
	T(   1,    0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80),
	T(   2,    1,    0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80),
	T(   3,    2,    1,    0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80),
	T(   4,    3,    2,    1,    0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80),
	T(   5,    4,    3,    2,    1,    0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80),
	T(   6,    5,    4,    3,    2,    1,    0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80),
	T(   7,    6,    5,    4,    3,    2,    1,    0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80),
	T(   8,    7,    6,    5,    4,    3,    2,    1,    0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80),
	T(   9,    8,    7,    6,    5,    4,    3,    2,    1,    0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80),
	T(  10,    9,    8,    7,    6,    5,    4,    3,    2,    1,    0, 0x80, 0x80, 0x80, 0x80, 0x80),
	T(  11,   10,    9,    8,    7,    6,    5,    4,    3,    2,    1,    0, 0x80, 0x80, 0x80, 0x80),
	T(  12,   11,   10,    9,    8,    7,    6,    5,    4,    3,    2,    1,    0, 0x80, 0x80, 0x80),
	T(  13,   12,   11,   10,    9,    8,    7,    6,    5,    4,    3,    2,    1,    0, 0x80, 0x80),
	T(  14,   13,   12,   11,   10,    9,    8,    7,    6,    5,    4,    3,    2,    1,    0, 0x80),
	T(  15,   14,   13,   12,   11,   10,    9,    8,    7,    6,    5,    4,    3,    2,    1,    0),
	T(  15,   14,   13,   12,   11,   10,    9,    8,    7,    6,    5,    4,    3,    2,    1,    0)  // duplicate!
};

#undef T

#include "programming/snippets/asm/sse-aux.c"

static uint8_t ASCII_lower[16] = packed_byte('0');
static uint8_t ASCII_upper[16] = packed_byte('9' + 1);

static uint16_t mul_add_10[8] SIMD_ALIGN = packed_word(256*10 + 1);
static uint16_t mul_add_100[8] SIMD_ALIGN = {1, 100, 1, 100, 1, 100, 1, 100};
static uint16_t mul_add_10000[8] SIMD_ALIGN = {1, 10000, 1, 10000, 1, 10000, 1, 10000};
static uint32_t mul_1000000000[4] SIMD_ALIGN = {100000000, 0, 100000000, 0}; 

static uint32_t mask_bits[17] = {
#define mask(n) ((1 << (n)) - 1)
	mask(0),
	mask(1),
	mask(2),
	mask(3),
	mask(4),
	mask(5),
	mask(6),
	mask(7),
	mask(8),
	mask(9),
	mask(10),
	mask(11),
	mask(12),
	mask(13),
	mask(14),
	mask(15),
	mask(16)
};


int sse_atoi(char* s) {
	int result;

	__asm__ __volatile__ (
		// ecx = first char is '-' ? 0xffffffff : 0x00000000
		// ebx = first char is '+' or '-' ? 1 : 0
		"xorl %%ebx, %%ebx					\n"
		"xorl %%ecx, %%ecx					\n"
		"movb (%%eax), %%dl					\n"
		"cmpb $'+', %%dl					\n"
		"sete %%bl							\n"
		"cmpb $'-', %%dl					\n"
		"sete %%cl							\n"
		"orl  %%ecx, %%ebx					\n"
		"leal 0x7fffffff(%%ecx), %%ecx		\n"
		"sarl $31, %%ecx					\n"

		// load digits
		"movdqu	(%%eax, %%ebx), %%xmm0		\n"
		
		// locate '0'
		"pxor %%xmm1, %%xmm1				\n"
		"pcmpeqb %%xmm0, %%xmm1				\n"
		"pmovmskb %%xmm1, %%edx				\n"
		"movl $16, %%eax					\n"
		"bsf %%edx, %%edx					\n"
		"cmovz %%eax, %%edx					\n"

		// validate input
		"movdqa	ASCII_lower, %%xmm4			\n"
		"movdqa	ASCII_upper, %%xmm5			\n"
		"pcmpgtb %%xmm0, %%xmm4				\n"
		"pcmpgtb %%xmm0, %%xmm5				\n"
		"pandn %%xmm5, %%xmm4				\n"
		"pmovmskb %%xmm4, %%ebx				\n"
		"movl mask_bits(, %%edx, 4), %%eax	\n"
		"andl %%eax, %%ebx					\n"
		"cmpl %%eax, %%ebx					\n"
		"movl $0xdeedbeef, %%eax			\n"
		"jne L1								\n"

		// convert ASCII to numbers
		"movdqa ASCII_lower, %%xmm3			\n"
		"psubb %%xmm3, %%xmm0				\n"

		// choose proper shuffle pattern && shuffle bytes
		"shl $4, %%edx						\n"
		"movdqa transform(%%edx), %%xmm2	\n"
		"pshufb %%xmm2, %%xmm0				\n"

		// join adjacent bytes = form 2-digit numbers
		"pmullw mul_add_10, %%xmm0			\n"
		"psrlw  $8, %%xmm0					\n"

		// join adjacent words = form 4-digit numbers
		"pmaddwd mul_add_100, %%xmm0		\n"

		// join adjacent words again = form 8-digits numbers
		"pxor %%xmm1, %%xmm1				\n"
		"packusdw %%xmm1, %%xmm0			\n"
		"pmaddwd mul_add_10000, %%xmm0		\n"

		// join adjacent dwords = form full 16-digits number
		"pshufd $0b11111100, %%xmm0, %%xmm1	\n"
		"pshufd $0b11111101, %%xmm0, %%xmm2	\n"
		"pmuludq mul_1000000000, %%xmm2		\n"
		"paddq  %%xmm1, %%xmm2				\n"

		// save 32-bit result 
		"movd %%xmm2, %%eax					\n"

		// negate, if minus char was found
		"xorl %%ecx, %%eax					\n"
		"subl %%ecx, %%eax					\n"

		"L1:"
		: "=a" (result)
		: "a" (s)
		: "edx", "ebx", "ecx"
	);

	return result;
}


int main(int argc, char* argv[]) {
	char* s = argv[1];

	if (argc > 1) {
		int x = sse_atoi(s);
		printf("'%s' => %d (%x)\n", s, x, x);
	}
	return 0;
}
