/*
	SSE: conversion integers to decimal representation

	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	License: BSD

	----------------------------------------------------------------------

	See http://0x80.pl/articles/sse-itoa.html
*/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

//--- functions --------------------------------------------------------
char* utoa32_sse(const uint32_t x);   // 0 .. 9999_9999 => ASCII
char* utoa32_sse_2(const uint32_t x); // 0 .. 9999_9999 => ASCII
char* utoa64_sse(const uint64_t x);   // 0 .. 9999_9999_9999_9999 => ASCII

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

// magick numbers for 16-bit division
#define DIV_10		0x199a	// shift = 0 + 16
#define DIV_100		0x147b	// shift = 3 + 16

// magic number for 32-bit division
#define DIV_10000	0xd1b71759		// shift = 13 + 32

#define SIMD_ALIGN __attribute__((aligned(16)))

//---- output buffer for SSE procedures --------------------------------
static char utoa_buffer[32] SIMD_ALIGN;

#ifdef USE_ASM

#include "asm-helpers.c"
#include "sse32-asm.c"
#include "sse32_2-asm.c"
#include "sse64-asm.c"

#else

#include <immintrin.h>
#include "sse32-intrin.c"
#include "sse32_2-intrin.c"
#include "sse64-intrin.c"

#endif


//----------------------------------------------------------------------

void usage() {
	puts("usage: progname function min [max [count]]");
	puts("");
	puts("where function is:");
	puts("* c32     - C function (32-bit conversion)");
	puts("* c64     - C function (64-bit conversion)");
	puts("* sse32   - SSE function (32-bit conversion)");
	puts("* sse32_2 - SSE function (32-bit conversion, other approach)");
	puts("* sse64   - SSE function (64-bit conversion)");
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
		sse_32_2,
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
	else if (keyword("sse32_2"))
		function = sse_32_2;
	else if (keyword("sse64"))
		function = sse_64;
	else
		usage();
#undef keyword

	if (function == naive_32 || function == sse_32 || function == sse_32_2) {
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

		case sse_32_2:
			if (count > 0) {
				while (count--)
					for (i32 = min32; i32 <= max32; i32 += 4) {
						tmp = utoa32_sse_2(i32 + 0);
						tmp = utoa32_sse_2(i32 + 1);
						tmp = utoa32_sse_2(i32 + 2);
						tmp = utoa32_sse_2(i32 + 3);
					}
			}
			else
				for (i32 = min32; i32 <= max32; i32++)
					printf("%u = %s\n", i32, utoa32_sse_2(i32));
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

