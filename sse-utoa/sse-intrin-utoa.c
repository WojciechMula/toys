/*
	SSE: conversion integers to decimal representation

	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	License: BSD

	initial release 2011-10-21

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

#include <immintrin.h>

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

// utoa32_sse_2 specific
uint32_t mul_10000trick[4] SIMD_ALIGN = packed_dword(65536 - 10000);

uint16_t	div_consts[8] SIMD_ALIGN = {
				8389,	// div 10^3, shift = 23 + 2
				5243,	// div 10^2, shift = 19 + 2
			   13108,	// div 10^1, shift = 17 + 2
			  0x8000,	// 
				8389,
				5243,
			   13108,
			  0x8000
};

uint16_t	shift_consts[8] SIMD_ALIGN = {
				1 << (16 - (23 + 2 - 16)),
				1 << (16 - (19 + 2 - 16)),
				1 << (16 - 1 - 2),
				1 << (15),
				1 << (16 - (23 + 2 - 16)),
				1 << (16 - (19 + 2 - 16)),
				1 << (16 - 1 - 2),
				1 << (15)
};

//---- output buffer for SSE procedures --------------------------------
static char utoa_buffer[32] SIMD_ALIGN;



void dump_epi32(__m128i x) {
    uint32_t dump[4];

    _mm_storeu_si128((__m128i*)dump, x);
    putchar('[');
    for (int i=0; i < 4; i++) {
        if (i > 0) putchar('|');
        printf(" %8d ", dump[i]);
    }
    printf("]\n");
}

void dump_epi16(__m128i x) {
    uint16_t dump[8];

    _mm_storeu_si128((__m128i*)dump, x);
    putchar('[');
    for (int i=0; i < 8; i++) {
        if (i > 0) putchar('|');
        printf(" %4d ", dump[i]);
    }
    printf("]\n");
}

void dump_epi8(__m128i x) {
    uint8_t dump[16];

    _mm_storeu_si128((__m128i*)dump, x);
    putchar('[');
    for (int i=0; i < 16; i++) {
        if (i > 0) putchar('|');
        printf(" %2d ", dump[i]);
    }
    printf("]\n");
}


char* utoa32_sse(uint32_t v) {
    // v is a 8-digit number: abcdefh (a..h are decimal digits)
    __m128i x = _mm_cvtsi32_si128(v);

    const __m128i div_10000 = _mm_set1_epi32(DIV_10000);
    const __m128i mul_10000 = _mm_set1_epi32(10000);
    const int div_10000_shift = 45;

    const __m128i div_100   = _mm_set1_epi16(DIV_100);
    const __m128i mul_100   = _mm_set1_epi16(100);
    const int div_100_shift = 3;

    const __m128i div_10    = _mm_set1_epi16(DIV_10);
    const __m128i mul_10    = _mm_set1_epi16(10);

    const __m128i ascii0    = _mm_set1_epi8('0');
    
    //                [ 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 ]
    // x            = [       0       |       0       |       0       |      abcdefgh ]
	// x div 10^4   = [       0       |       0       |       0       |          abcd ]
    __m128i x_div_10000;
    x_div_10000 = _mm_mul_epu32(x, div_10000);
    x_div_10000 = _mm_srli_epi64(x_div_10000, div_10000_shift);

    // x mod 10^4   = [       0       |       0       |       0       |          efgh ]
    __m128i x_mod_10000;
    x_mod_10000 = _mm_mul_epu32(x_div_10000, mul_10000);
    x_mod_10000 = _mm_sub_epi32(x, x_mod_10000);

    // y            = [   0   |   0   |   0   |   0   |   0   |   0   |  abcd |  efgh ]
    __m128i y = _mm_unpacklo_epi16(x_div_10000, x_mod_10000);
    
    // y_div_100    = [   0   |   0   |   0   |   0   |   0   |   0   |    ab |    ef ]
    __m128i y_div_100;
    y_div_100 = _mm_mulhi_epu16(y, div_100);
    y_div_100 = _mm_srli_epi16(y_div_100, div_100_shift);

    // y_mod_100    = [   0   |   0   |   0   |   0   |   0   |   0   |    cd |    gh ]
    __m128i y_mod_100;
    y_mod_100 = _mm_mullo_epi16(y_div_100, mul_100);
    y_mod_100 = _mm_sub_epi16(y, y_mod_100);

    // z            = [   0   |   0   |   0   |   0   |    ab |    cd |    ef |    gh ]
    __m128i z = _mm_unpacklo_epi16(y_div_100, y_mod_100);

    // z_div_10     = [   0   |   0   |   0   |   0   |     a |     c |     e |     g ]
    __m128i z_div_10 = _mm_mulhi_epu16(z, div_10);

    // z_mod_10     = [   0   |   0   |   0   |   0   |     b |     d |     f |     h ]
    __m128i z_mod_10;
    z_mod_10 = _mm_mullo_epi16(z_div_10, mul_10);
    z_mod_10 = _mm_sub_epi16(z, z_mod_10);

    // interleave z_mod_10 and z_div_10 - it's still a word vector
    __m128i tmp;
    // tmp          = [   a   |   b   |   c   |   d   |   e   |   f   |   g   |   h   ]
    tmp = _mm_unpacklo_epi16(z_div_10, z_mod_10);

    // tmp          = [ 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | a | b | c | d | e | f | g | h ]
    tmp = _mm_packus_epi16(_mm_setzero_si128(), tmp);

    // determine number of leading zeros
    uint16_t mask = ~_mm_movemask_epi8(_mm_cmpeq_epi8(tmp, _mm_setzero_si128()));
    uint32_t offset = __builtin_ctz(mask | 0x8000);

    // convert to ascii
    tmp = _mm_add_epi8(tmp, ascii0);

    // and save result
    _mm_storeu_si128((__m128i*)utoa_buffer, tmp);

	return &utoa_buffer[offset];
}

char* utoa32_sse_2(uint32_t v) {

    // v is a 8-digit number: abcdefh (a..h are decimal digits)
    __m128i x = _mm_cvtsi32_si128(v);

    const __m128i div_10000 = _mm_set1_epi32(DIV_10000);
    const int div_10000_shift = 45;

    const __m128i mul_10000_merge = _mm_set1_epi32(65536 - 10000);

    const __m128i div_var = _mm_setr_epi16(
        8389,	// div 10^3, shift = 23 + 2
        5243,	// div 10^2, shift = 19 + 2
       13108,	// div 10^1, shift = 17 + 2
      0x8000,	// 
        8389,
        5243,
       13108,
      0x8000);

    const __m128i shift_var = _mm_setr_epi16(
        1 << (16 - (23 + 2 - 16)),
        1 << (16 - (19 + 2 - 16)),
        1 << (16 - 1 - 2),
        1 << (15),
        1 << (16 - (23 + 2 - 16)),
        1 << (16 - (19 + 2 - 16)),
        1 << (16 - 1 - 2),
        1 << (15)
    );

    const __m128i mul_10    = _mm_set1_epi16(10);
    const __m128i ascii0    = _mm_set1_epi8('0');

    //                [ 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 ]
    // x            = [       0       |       0       |       0       |      abcdefgh ]
	// x div 10^4   = [       0       |       0       |       0       |          abcd ]
    __m128i x_div_10000;
    x_div_10000 = _mm_mul_epu32(x, div_10000);
    x_div_10000 = _mm_srli_epi64(x_div_10000, div_10000_shift);

    // y            = [   0   |   0   |   0   |   0   |   0   |   0   |  abcd |  efgh ]
    __m128i y;
    y = _mm_mul_epu32(x_div_10000, mul_10000_merge);
    y = _mm_add_epi32(x, y);

    dump_epi16(y);

    // t0           = [     0 |     0 |     0 |     0 |  abcd |  abcd |  efgh |  efgh ]
    __m128i t0;
    t0 = _mm_unpacklo_epi16(y, y);
    // t0           = [  efgh |  efgh |  efgh |  efgh |  abcd |  abcd |  abcd |  abcd ]
    t0 = _mm_shuffle_epi32(t0, 0x05); // order: 0, 0, 1, 1 = b000001010

    dump_epi16(t0);

    // z * 4
    t0 = _mm_slli_epi16(t0, 2);

    // z divide by 10^3, 10^2, 10^1 and 10^0
    // t1 = [ a << 9 | ab << 5 | abc << 3 | abcd << 2 | e << 9 | ef << 5 | efg << 3 | efgh << 2 ]
    __m128i t1;
    t1 = _mm_mulhi_epu16(t0, div_var);

    // variable shift by 9, 5, 3, 2
    // t2 = [ 000a | 00ab | 0abc | abcd | 000e | 00ef | 0efg | efgh ]
    __m128i t2;
    t2 = _mm_mulhi_epu16(t1, shift_var);
    
    // t3 = [ 0000 | 000a | 00ab | 0abc | 0000 | 000e | 00ef | 0efg ]
    __m128i t3 = _mm_slli_epi64(t2, 16);

    // t4 = [ 0000 | 00a0 | 0ab0 | abc0 | 0000 | 00e0 | 0ef0 | efg0 ]
    __m128i t4 = _mm_mullo_epi16(t3, mul_10);

    // t5 = t2 - t4
    // t5 = [    a |    b |    c |    d |    e |    f |    g |    h ]
    __m128i t5 = _mm_sub_epi16(t2, t4);

    // t6 = [              0               | a | b | c| d | e | f | g | h ]
    __m128i t6 = _mm_packus_epi16(_mm_setzero_si128(), t5);

    dump_epi8(t6);

    // determine number of leading zeros
    uint16_t mask = ~_mm_movemask_epi8(_mm_cmpeq_epi8(t6, _mm_setzero_si128()));
    uint32_t offset = __builtin_ctz(mask | 0x8000);

    // convert to ascii
    t6 = _mm_add_epi8(t6, ascii0);

    // and save result
    _mm_storeu_si128((__m128i*)utoa_buffer, t6);

    return &utoa_buffer[offset];
}

char* utoa64_sse(uint64_t v) {

    // v is 16-digit number = abcdefghijklmnop

    const __m128i div_10000 = _mm_set1_epi32(DIV_10000);
    const __m128i mul_10000 = _mm_set1_epi32(10000);
    const int div_10000_shift = 45;

    const __m128i div_100   = _mm_set1_epi16(DIV_100);
    const __m128i mul_100   = _mm_set1_epi16(100);
    const int div_100_shift = 3;

    const __m128i div_10    = _mm_set1_epi16(DIV_10);
    const __m128i mul_10    = _mm_set1_epi16(10);

    const __m128i ascii0    = _mm_set1_epi8('0');

	// can't be easliy done in SSE
	const uint32_t a = v / 100000000; // 8-digit number: abcdefgh
	const uint32_t b = v % 100000000; // 8-digit number: ijklmnop

    //                [ 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 ]
    // x            = [       0       |      ijklmnop |       0       |      abcdefgh ]
    __m128i x = _mm_set_epi64x(b, a);

	// x div 10^4   = [       0       |          ijkl |       0       |          abcd ]
    __m128i x_div_10000;
    x_div_10000 = _mm_mul_epu32(x, div_10000);
    x_div_10000 = _mm_srli_epi64(x_div_10000, div_10000_shift);

    // x mod 10^4   = [       0       |          mnop |       0       |          efgh ]
    __m128i x_mod_10000;
    x_mod_10000 = _mm_mul_epu32(x_div_10000, mul_10000);
    x_mod_10000 = _mm_sub_epi32(x, x_mod_10000);

    // y            = [          mnop |          ijkl |          efgh |          abcd ]
    __m128i y = _mm_or_si128(x_div_10000, _mm_slli_epi64(x_mod_10000, 32));
    
    // y_div_100    = [   0   |    mn |   0   |    ij |   0   |    ef |   0   |    ab ]
    __m128i y_div_100;
    y_div_100 = _mm_mulhi_epu16(y, div_100);
    y_div_100 = _mm_srli_epi16(y_div_100, div_100_shift);

    // y_mod_100    = [   0   |    op |   0   |    kl |   0   |    gh |   0   |    cd ]
    __m128i y_mod_100;
    y_mod_100 = _mm_mullo_epi16(y_div_100, mul_100);
    y_mod_100 = _mm_sub_epi16(y, y_mod_100);

    // z            = [    mn |    op |    ij |    kl |    ef |    gh |    ab |    cd ]
    __m128i z = _mm_or_si128(y_div_100, _mm_slli_epi32(y_mod_100, 16));

    // z_div_10     = [ 0 | m | 0 | o | 0 | i | 0 | k | 0 | e | 0 | g | 0 | a | 0 | c ]
    __m128i z_div_10 = _mm_mulhi_epu16(z, div_10);

    // z_mod_10     = [ 0 | n | 0 | p | 0 | j | 0 | l | 0 | f | 0 | h | 0 | b | 0 | d ]
    __m128i z_mod_10;
    z_mod_10 = _mm_mullo_epi16(z_div_10, mul_10);
    z_mod_10 = _mm_sub_epi16(z, z_mod_10);

    // interleave z_mod_10 and z_div_10 -
    // tmp          = [ m | n | o | p | i | j | k | l | e | f | g | h | a | b | c | d ]
    __m128i tmp = _mm_or_si128(z_div_10, _mm_slli_epi16(z_mod_10, 8));

    // determine number of leading zeros
    uint16_t mask = ~_mm_movemask_epi8(_mm_cmpeq_epi8(tmp, _mm_setzero_si128()));
    uint32_t offset = __builtin_ctz(mask | 0x8000);

    // convert to ascii
    tmp = _mm_add_epi8(tmp, _mm_set1_epi8('0'));

    // and save result
    _mm_storeu_si128((__m128i*)utoa_buffer, tmp);

    return &utoa_buffer[offset];
}

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

