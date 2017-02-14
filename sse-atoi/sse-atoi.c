/*
	SSE: atoi implementation

	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	License: BSD

	initial release: 2011-11-07

	----------------------------------------------------------------------

	Usage:

		run program without argument to read help

*/

#include <stdint.h>
#include <stdlib.h>

#define SIMD_ALIGN __attribute__((aligned(16)))

#define T(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) \
	{a1, a0, a3, a2, a5, a4, a7, a6, a9, a8, a11, a10, a13, a12, a15, a14} 
	// swapped adjacent elements!

uint8_t transform[18][16] SIMD_ALIGN = {

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

#define packed_byte(x) {(x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x)} 
#define packed_word(x) {(x), (x), (x), (x), (x), (x), (x), (x)}

uint8_t ASCII_lower[16] = packed_byte('0');
uint8_t ASCII_upper[16] = packed_byte('9' + 1);

uint16_t mul_add_10[8] SIMD_ALIGN = packed_word(256*10 + 1);
uint16_t mul_add_100[8] SIMD_ALIGN = {1, 100, 1, 100, 1, 100, 1, 100};
uint16_t mul_add_10000[8] SIMD_ALIGN = {1, 10000, 1, 10000, 1, 10000, 1, 10000};
uint32_t mul_1000000000[4] SIMD_ALIGN = {100000000, 0, 100000000, 0}; 

uint32_t mask_bits[17] = {
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

		// load digits (and garbage)
		"movdqu	(%%eax, %%ebx), %%xmm0		\n"
		
		// locate '\0'
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
		"pandn %%xmm5, %%xmm4				\n"	// xmm4[i] := (xmm0[i] >= '0' and xmm[i] <= '9')
		"pmovmskb %%xmm4, %%ebx				\n"
		"movl mask_bits(, %%edx, 4), %%eax	\n"
		"andl %%eax, %%ebx					\n"	// mask bytes after '\0'
		"cmpl %%eax, %%ebx					\n"
		"xor %%eax, %%eax					\n"	// mark error
		"jne L1								\n"

		// convert ASCII to numbers
		"movdqa ASCII_lower, %%xmm3			\n"
		"psubb %%xmm3, %%xmm0				\n"

		// choose proper shuffle pattern && shuffle bytes
		"shl $4, %%edx						\n"
		"movdqa transform(%%edx), %%xmm2	\n"
		"pshufb %%xmm2, %%xmm0				\n"

		// join adjacent digits [bytes] => 2-digit numbers
		"pmullw mul_add_10, %%xmm0			\n"
		"psrlw  $8, %%xmm0					\n"

		// join adjacent words => form 4-digit numbers
		"pmaddwd mul_add_100, %%xmm0		\n"

		// join adjacent words again => form 8-digits numbers
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

		// negate, if minus char was found earlier
		"xorl %%ecx, %%eax					\n"
		"subl %%ecx, %%eax					\n"

		"L1:\n"
		: "=a" (result)
		: "a" (s)
		: "edx", "ebx", "ecx"
	);

	return result;
}


int simple_atoi(char* c) {
	const char sign = *c;
	int result = 0;
	if (sign == '+' || sign == '-')
		c++;

	while (*c) {
		//const uint8_t d = (uint8_t)*c++;
		const int d = *c++;
		if (d >= '0' && d <= '9')
			result = result * 10 + (d - '0');
		else
			return 0;
	}

	if (sign == '-')
		return -result;
	else
		return result;
}


#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>

uint32_t get_time(void) {
	static struct timeval T;
	gettimeofday(&T, NULL);
	return (T.tv_sec * 1000000) + T.tv_usec;
}

void usage() {
	puts("program verify|atoi|sse numbers [iterations]");
	exit(0);
}


int main(int argc, char* argv[]) {
	char** array;
	char tmp[32];
	int n;
	int k;
	int i, j;

	enum {
		verify,
		measure_atoi,
		measure_sse
	};

	int function;

	if (argc < 3)
		usage();
	

#define keyword(name) (strcasecmp(name, argv[1]) == 0)
	if (keyword("verify"))
		function = verify;
	else if (keyword("atoi"))
		function = measure_atoi;
	else if (keyword("sse"))
		function = measure_sse;
	else
		usage();
#undef keyword

	n = atoi(argv[2]);
	if (n == 0) {
		puts("number must be greater then 0");
		return EXIT_FAILURE;
	}

	if (argc > 3)
		k = atoi(argv[3]);
	else
		k = 1;

	if (n == 0) {
		puts("count must be greater then 0");
		return EXIT_FAILURE;
	}

	array = malloc(n * sizeof(char*));
	if (array == NULL) {
		perror("malloc");
		return EXIT_FAILURE;
	}

	// prepare data
	for (i=0; i < n; i++) {
		int x = rand();
		if (rand() % 2)
			x = -x;

		sprintf(tmp, "%d", x);
		array[i] = strdup(tmp);
	}

	// do the job
	if (function == verify) {
		puts("verify...");
		for (i=0; i < n; i++) {
			int a = atoi(array[i]);
			int s = sse_atoi(array[i]);
			if (a != s) {
				printf("SSE failed at '%s' => %d, should be %d\n",
						array[i], a, s);
				return EXIT_FAILURE;
			}
		}
		puts("ok");
	}
	else if (function == measure_atoi) {
		printf("atoi, %d numbers, %d iterations\n", n, k);
		uint32_t t1, t2;
		t1  = get_time();
		for (j=0; j < k; j++) {
			for (i=0; i < n; i++) {
				simple_atoi(array[i]);
				simple_atoi(array[i]);
				simple_atoi(array[i]);
				simple_atoi(array[i]);
			}
		}
		t2  = get_time();

		printf("t = %0.3fs\n", (t2 - t1)/1000000.0);
	}
	else if (function == measure_sse) {
		printf("SSE, %d numbers, %d iterations\n", n, k);
		uint32_t t1, t2;
		t1  = get_time();
		for (j=0; j < k; j++) {
			for (i=0; i < n; i++) {
				sse_atoi(array[i]);
				sse_atoi(array[i]);
				sse_atoi(array[i]);
				sse_atoi(array[i]);
			}
		}
		t2  = get_time();

		printf("t = %0.3fs\n", (t2 - t1)/1000000.0);
	}
	
	free(array);
	return EXIT_SUCCESS;
}

/*
vim: nowrap ts=4 sw=4
*/
