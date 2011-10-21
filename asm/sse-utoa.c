/*
	SSE: conversion integers to decimal representation

	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	License: BSD

	initial release 2011-10-21
	$Id$

	----------------------------------------------------------------------

	Max speedup: 3 times. See http://0x80.pl/articles/sse-itoa.html

	Compilation:

		$ gcc -Wall -std=c99 -O2 sse-utoa.c -o prog

	Verify:

		$ ./prog sse32 0 99999999 | awk '$1 != $3 {printf("ERROR >%s< >%s<\n", $1, $3)}'
	
	Usage:

		run program without argument to read help

*/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

//--- functions --------------------------------------------------------
char* utoa32_sse(const uint32_t x);	// 0 .. 9999_9999 => ASCII
char* utoa64_sse(const uint64_t x);	// 0 .. 9999_9999_9999_9999 => ASCII

char* utoa32(const uint32_t x); // reference implementation
char* utoa64(const uint64_t x); // reference implementation

//----------------------------------------------------------------------
//--- C reference implementations --------------------------------------
//----------------------------------------------------------------------

char* utoa32(uint32_t x) {
	static char buf[17];
	uint32_t i = 15;
	do {
		buf[i--] = (x % 10) + '0';
		x /= 10;
	} while (x > 0);

	return buf + i + 1;
}


char* utoa64(const uint64_t x) {
	static char buf[32+1];
	uint32_t a, b, i;
	if (x > 99999999) {
		a = x / 100000000;
		b = x % 100000000;
		
		i = 31;
		do {
			buf[i--] = (a % 10) + '0';
			a /= 10;
		} while (a > 0);

		if (b > 0) {
			i = 31 - 16;
			do {
				buf[i--] = (b % 10) + '0';
				b /= 10;
			} while (b > 0);
		}
	
		return buf + i + 1;
	}
	else
		return utoa32(x);
}


//----------------------------------------------------------------------
//--- SSE implementations ----------------------------------------------
//----------------------------------------------------------------------

//--- defines ----------------------------------------------------------
#define packed_byte(x)   {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x}
#define packed_word(x)   {x, x, x, x, x, x, x, x}
#define packed_dword(x)   {x, x, x, x}

#define SIMD_ALIGN __attribute__((aligned(16)))

// magick numbers for 16-bit division
#define DIV_10		0x199a	// shift = 0 + 16
#define DIV_100		0x147b	// shift = 3 + 16

// magic number for 32-bit division
#define DIV_10000	0xd1b71759		// shift = 13 + 32

//--- SSE helper vectors -----------------------------------------------
uint16_t div_10[8] SIMD_ALIGN = packed_word(DIV_10);
uint16_t mul_10[8] SIMD_ALIGN = packed_word(10);

uint16_t div_100[8] SIMD_ALIGN = packed_word(DIV_100);
uint16_t mul_100[8] SIMD_ALIGN = packed_word(100);

uint32_t div_10000[4] SIMD_ALIGN = packed_dword(DIV_10000);
uint32_t mul_10000[4] SIMD_ALIGN = packed_dword(10000);

uint8_t  to_ascii[16] SIMD_ALIGN = packed_byte('0');

//---- output buffer for SSE procedures --------------------------------
static char utoa_buffer[32] SIMD_ALIGN;


char* utoa32_sse(uint32_t x) {
	uint32_t offset = 0;

	__asm__ __volatile__ (
		// 1) x divmod 10^4
		"movd		%%eax, %%xmm1					\n"

		// xmm0 = eax div 10000
		"movdqa		div_10000, %%xmm0				\n"
		"pmuludq	%%xmm1, %%xmm0					\n"
		"psrlq		$45, %%xmm0						\n"

		// xmm3 = (eax div 10000) * 10000
		"movdqa		mul_10000, %%xmm3				\n"
		"pmuludq	%%xmm0, %%xmm3					\n"

		// xmm1 = eax mod 10000
		"psubd		%%xmm3, %%xmm1					\n"

		// xmm0 = [ eax div 10000 | eax mod 10000 | ... ]
		"punpcklwd	%%xmm1, %%xmm0					\n"
		
		// 2) x[i] divmod 10^2

		// xmm0 = [ abcd | efgh | ijkl | mnop | ... ], [a..p] - decimal digits
		"movdqa		div_100, %%xmm1					\n"
		"movdqa		mul_100, %%xmm2					\n"

		// xmm1 = [ 00ab | 00ef | 00ij | 00mn | ... ]
		"pmulhuw	%%xmm0, %%xmm1					\n"
		"psrlw		$3, %%xmm1						\n"

		// xmm2 = [ ab00 | ef00 | ij00 | mn00 | ...]
		"pmullw		%%xmm1, %%xmm2					\n"

		// xmm0 = [ 00cd | 00gh | 00kl | 00op | ... ]
		"psubw		%%xmm2, %%xmm0					\n"

		// xmm1 = [ 00ab | 00cd | 00ef | 00gh | ... ]
		"punpcklwd	%%xmm0, %%xmm1					\n"

		// 3) x[i] divmod 10
		"movdqa		div_10, %%xmm0					\n"
		"movdqa		mul_10, %%xmm2					\n"

		// xmm0 = x[i] div 10
		"pmulhuw	%%xmm1, %%xmm0					\n"
		
		// xmm1 = x[i] mod 10
		"pmullw		%%xmm0, %%xmm2					\n"
		"psubw		%%xmm2, %%xmm1					\n"
		
		// result
		"punpcklwd	%%xmm1, %%xmm0					\n"
		"pxor		%%xmm2, %%xmm2					\n"
		"packuswb	%%xmm0, %%xmm2					\n"

		// 4) conversion to ASCII and skip leading zeros
		"movdqa		to_ascii, %%xmm0				\n"
		"paddb		%%xmm0, %%xmm2					\n"
		// xmm2 - result
		"pcmpeqb	%%xmm2, %%xmm0					\n"
		"pmovmskb	%%xmm0, %%eax					\n"
		"not		%%eax							\n"
		"orl		$0x8000, %%eax					\n"
		"bsf		%%eax, %%eax					\n"
		// eax = position of first non-zero digit

		// 5) save
		"movdqa		%%xmm2, utoa_buffer				\n"
		: "=a" (offset)
		: "a" (x)
	);

	return &utoa_buffer[offset];
}


char* utoa64_sse(uint64_t x) {
	uint32_t offset = 0;
	uint32_t a, b;

	// can't be easliy done in SSE
	a = x / 100000000;
	b = x % 100000000;

	__asm__ __volatile__ (
		"movd %%eax, %%xmm0							\n"
		"movd %%ebx, %%xmm1							\n"
		"punpckldq %%xmm1, %%xmm0					\n"
		"pshufd $0b11001101, %%xmm0, %%xmm0			\n"	// prepare data for pmuludq

		// 1) divmod 10^4

		"movdqa	div_10000, %%xmm1					\n"
		"movdqa mul_10000, %%xmm2					\n"

		// xmm1 = x[i] div 1000
		"pmuludq	%%xmm0, %%xmm1					\n"	// div
		"psrlq		$45, %%xmm1						\n"

		// xmm0 = x[i] mod 1000
		"pmuludq	%%xmm1, %%xmm2					\n" // mod
		"psubd		%%xmm2, %%xmm0					\n"

		"pshufd		$0b10110011, %%xmm0, %%xmm0		\n" // join div & mod results
		"por		%%xmm1, %%xmm0					\n"

		// 2) divmod 10^2

		"movdqa	div_100, %%xmm1						\n"
		"movdqa	mul_100, %%xmm2						\n"
		"											\n"
		"pmulhuw %%xmm0, %%xmm1						\n"	// div
		"psrlw       $3, %%xmm1						\n"
		"pmullw  %%xmm1, %%xmm2						\n" // mod
		"psubw	 %%xmm2, %%xmm0						\n"
		
		"pslld		$16, %%xmm0						\n"	// join div & mod results
		"por 		%%xmm1, %%xmm0					\n"

		// 3) divmod 10

		"movdqa div_10, %%xmm1						\n"
		"movdqa mul_10, %%xmm2						\n"
		
		"pmulhuw %%xmm0, %%xmm1						\n"	// div
		"pmullw  %%xmm1, %%xmm2						\n"
		"psubw	 %%xmm2, %%xmm0						\n"	// mod

		"psllw		$8,		%%xmm0					\n"	// join div & mod result
		"por		%%xmm1, %%xmm0					\n"
		
		// 4) convert to ASCII, count leading zeros and save result
			
		"movdqa		to_ascii, %%xmm2				\n"
		"paddb		%%xmm2, %%xmm0					\n"
		"pcmpeqb	%%xmm0, %%xmm2					\n"
		"pmovmskb	%%xmm2, %%eax					\n"
		"not		%%eax							\n"
		"orl		$0x8000, %%eax					\n"
		"bsf		%%eax, %%eax					\n"

		"movdqa		%%xmm0, utoa_buffer				\n"
		: "=a" (offset)
		: "a" (b),
		  "b" (a)
	);

	return &utoa_buffer[offset];
}

//----------------------------------------------------------------------

void usage() {
	puts("usage: progname function min [max [count]]");
	puts("");
	puts("where function is:");
	puts("* c32 - C function (32-bit conversion)");
	puts("* c64 - C function (64-bit conversion)");
	puts("* sse32 - SSE function (32-bit conversion)");
	puts("* sse64 - SSE function (64-bit conversion)");
	puts("");
	puts("If min & max is given, then selected function");
	puts("does coversion of numbers from this range and");
	puts("results are printed. Param max could be ommited,");
	puts("then just one number is converted.");
	puts("");
	puts("If count is present, then selected function ");
	puts("performs conversion of number from range min-max");
	puts("in a loop.");

	exit(1);
}

int main(int argc, char* argv[]) {
	uint32_t min32, max32, i32;
	uint64_t min64, max64, i64;
	enum {
		unknown,
		naive_32,
		naive_64,
		sse_32,
		sse_64
	};
	int function = unknown;
	int count = 0;
	char* tmp;

	if (argc < 3)
		usage();

#define keyword(str) (strcasecmp(argv[1], str) == 0)
	if (keyword("c32"))
		function = naive_32;
	else if (keyword("c64"))
		function = naive_64;
	else if (keyword("sse32"))
		function = sse_32;
	else if (keyword("sse64"))
		function = sse_64;
	else
		usage();
#undef keyword

	if (function == naive_32 || function == sse_32) {
		if (argc == 3)
			min32 = max32 = atoi(argv[2]);
		else {
			min32 = atoi(argv[2]);
			max32 = atoi(argv[3]);
			if (min32 > max32)
				usage();
		}
	}
	else {
		if (argc == 3)
			min64 = max64 = atoll(argv[2]);
		else {
			min64 = atoll(argv[2]);
			max64 = atoll(argv[3]);
			if (min64 > max64)
				usage();
		}
	}

	if (argc > 4)
		count = atoi(argv[4]);

	switch (function) {
		case naive_32:
			if (count > 0)
				while (count--)
					for (i32 = min32; i32 <= max32; i32 += 4) {
						tmp = utoa32(i32 + 0);
						tmp = utoa32(i32 + 1);
						tmp = utoa32(i32 + 2);
						tmp = utoa32(i32 + 3);
					}
			else
				for (i32 = min32; i32 <= max32; i32++)
					printf("%u = %s\n", i32, utoa32(i32));
			break;

		case naive_64:
			if (count > 0)
				while (count--)
					for (i64 = min64; i64 <= max64; i64 += 4) {
						tmp = utoa64(i64 + 0);
						tmp = utoa64(i64 + 1);
						tmp = utoa64(i64 + 2);
						tmp = utoa64(i64 + 3);
					}
			else
				for (i64 = min64; i64 <= max64; i64++)
					printf("%llu = %s\n", i64, utoa64(i64));
			break;

		case sse_32:
			if (count > 0) {
				while (count--)
					for (i32 = min32; i32 <= max32; i32 += 4) {
						tmp = utoa32_sse(i32 + 0);
						tmp = utoa32_sse(i32 + 1);
						tmp = utoa32_sse(i32 + 2);
						tmp = utoa32_sse(i32 + 3);
					}
			}
			else
				for (i32 = min32; i32 <= max32; i32++)
					printf("%u = %s\n", i32, utoa32_sse(i32));
			break;

		case sse_64:
			if (count > 0) {
				while (count--)
					for (i64 = min64; i64 <= max64; i64 += 4) {
						tmp = utoa64_sse(i64 + 0);
						tmp = utoa64_sse(i64 + 1);
						tmp = utoa64_sse(i64 + 2);
						tmp = utoa64_sse(i64 + 3);
					}
			}
			else 
				for (i64 = min64; i64 <= max64; i64++)
					printf("%llu = %s\n", i64, utoa64_sse(i64));

			break;
		
		default:
			return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

