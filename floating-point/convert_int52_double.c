/*
	Branch-less signed 52-bit word to double conversion, $Revision: 1.2 $
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl

	License: public domain
	
	initial release 8-06-2008, last update $Date: 2008-06-15 18:51:04 $
	
	----------------------------------------------------------------------

	http://softwarecommunity.intel.com/isn/Community/en-US/forums/thread/30256500.aspx

	Compilation:

		gcc -O3 -Wall -pedantic -std=c99 convert_int52_double.c

	Usage:

		run program without argument to read help

	
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


#define ALIGNED __attribute__((aligned(16)))

#ifndef SIZE
#	define SIZE 65536
#endif
int64_t  in [SIZE][2] ALIGNED;
double   out_FPU[SIZE][2] ALIGNED;
double   out_SSE[SIZE][2] ALIGNED;


//=== FPU conversion =====================================================
void FPU_convert(int64_t in[2], double out[2]) {
	out[0] = in[0];
	out[1] = in[1];
}


//=== C implementation ===================================================
#if 0
	Let start with U2 feature: negative number treated
	as unsigned has value (1 << number_of_bits) - abs(number)

	Thus:
	negative x_double has value (1 << 52) + ((1 << 52) - abs(x)) = (1 << 53) - abs(x)
	positive x_double has value (1 << 52) + x

	To get x or -abs(x), value (1 << 52) or (1 << 53) have to be subtracted:

	if (x >= 0)
		as_double(x_double) -= as_double(1 << 52);
		// (double)(1 << 52) = 0x4330000000000000;
	else
		as_double(x_double) -= as_double(1 << 53);
		// (double)(1 << 53) = 0x4340000000000000;
		
#endif

double convert(int64_t x) {
	union {
		double   flt;
		uint64_t bin;
	} x_double, pow;

	// 1. construct double
	x_double.bin = ((uint64_t)(0x3ff+52) << 52) | (x & 0x000fffffffffffffll);
	//                                             ^ just zero higher bits ^

	// 2. select proper const
	pow.bin = (x < 0) ? 0x4340000000000000ll : 0x4330000000000000ll;
	//                    double(1 << 53)         double(1 << 52)

	// 3. adjust value
	x_double.flt -= pow.flt;

	return x_double.flt;
}


void C_convert(int64_t in[2], double out[2]) {
	out[0] = convert(in[0]);
	out[1] = convert(in[1]);
}


//=== SSE implementation (first version) =================================
uint64_t CONST[2] ALIGNED = {0x4330000000000000ll, 0x4330000000000000ll};
uint64_t EXP[2]   ALIGNED = {0x4330000000000000ll, 0x4330000000000000ll}; // EXP=CONST

uint64_t MASK[2]  ALIGNED = {0x000fffffffffffffll, 0x000fffffffffffffll};
uint64_t NEG[2]   ALIGNED = {0x0010000000000000ll, 0x0010000000000000ll};

void SSE_convert(int64_t in[2], double out[2]) {
	__asm__ volatile (
	"	movdqa (%%eax), %%xmm0		\n"
	"	movdqa  %%xmm0, %%xmm1		\n"
	"	movdqa   CONST, %%xmm2		\n"

	// step 1.
	"	pand      MASK, %%xmm0		\n"
	"	por        EXP, %%xmm0		\n"

	// step 2.
	"	psrad      $32, %%xmm1		\n"
	"	pand       NEG, %%xmm1		\n"
	"					\n"
	"	paddd     %%xmm1, %%xmm2	\n"

	// step 3.
	"	subpd     %%xmm2, %%xmm0	\n"
	"	movapd    %%xmm0, (%%ebx)	\n"

	: /* no output */
	: "a" (in),
	  "b" (out)
	: "memory"
	);
}


//=== SSE implementation (second version, constants are preloaded) =======
uint64_t NEG2[2]   ALIGNED = {0x0070000000000000ll, 0x0070000000000000ll};

void SSE_preload2() {
	__asm__ volatile (
		"movdqa CONST, %xmm5\n"
		"movdqa  MASK, %xmm6\n"
		"movdqa  NEG2, %xmm7\n"
	);
}


void SSE_convert2(int64_t in[2], double out[2]) {
	__asm__ volatile (
	"	movdqa (%%eax), %%xmm0		\n"
	"	movdqa  %%xmm0, %%xmm1		\n"

	// step 1.
	"	pand    %%xmm6, %%xmm0		\n"	// and MASK
	"	por     %%xmm5, %%xmm0		\n"	// or  EXP=CONST

	// step 2.
	"	pand    %%xmm7, %%xmm1		\n"	// and CONST
	"	pxor    %%xmm5, %%xmm1		\n"	// xor NEG2

	// step 3.
	"	subpd     %%xmm1, %%xmm0	\n"
	"	movapd    %%xmm0, (%%ebx)	\n"

	: /* no output */
	: "a" (in),
	  "b" (out)
	: "memory"
	);
}


//========================================================================
void help() {
	puts("usage: progname 0|1|2 iterations");
	puts("0 -- test FPU");
	puts("1 -- test C implementation");
	puts("2 -- test SSE (first version)");
	puts("3 -- test SSE (second version)");
	puts("4 -- verify");
}


int main(int argc, char* argv[]) {
	if (argc < 3) {
		help();
		return 1;
	}

	int iterations = (atoi(argv[2]) <= 0) ? 1 : atoi(argv[2]);
	int i, j;
	char ok = 1;

	srand(time(NULL));
	for (i=0; i < SIZE; i++)
		for (j=0; j < 2; j++) 
			in[i][j] = (int64_t)rand() - (RAND_MAX/2);


	switch (atoi(argv[1])) {
		case 0:
			printf("FPU, iterations = %d, size = %d\n", iterations, SIZE);
			while (iterations--)
				for (i=0; i < SIZE; i++)
					FPU_convert(in[i], out_FPU[i]);
			break;

		case 1:
			printf("C implementation, iterations = %d, size = %d\n", iterations, SIZE);
			while (iterations--)
				for (i=0; i < SIZE; i++)
					C_convert(in[i], out_SSE[i]);
			break;

		case 2:
			printf("SSE (first version), iterations = %d, size = %d\n", iterations, SIZE);
			while (iterations--)
				for (i=0; i < SIZE; i++)
					SSE_convert(in[i], out_SSE[i]);
			break;

		case 3:
			printf("SSE (second version), iterations = %d, size = %d\n", iterations, SIZE);
			SSE_preload2();
			while (iterations--)
				for (i=0; i < SIZE; i++)
					SSE_convert2(in[i], out_SSE[i]);
			break;


		case 4:
			for (i=0; i < SIZE; i++)
				FPU_convert(in[i], out_FPU[i]);

			//==================================================
			printf("verify C implementation\n");
			for (i=0; i < SIZE; i++)
				C_convert(in[i], out_SSE[i]);

			ok = 1;
			for (i=0; i < SIZE; i++) {
				if (out_SSE[i][0] != out_FPU[i][0])
					printf("%1d: %lld -> %f <> %f\n",
						i, in[i][0], out_SSE[i][0], out_FPU[i][0]
					), ok=0;

				if (out_SSE[i][1] != out_FPU[i][1])
					printf("%1d: %lld -> %f <> %f\n",
						i, in[i][1], out_SSE[i][1], out_FPU[i][1]
					), ok=0;

			}

			if (ok)
				puts("\tok!");

			//==================================================
			printf("verify SSE (first version)\n");
			for (i=0; i < SIZE; i++)
				SSE_convert(in[i], out_SSE[i]);

			ok = 1;
			for (i=0; i < SIZE; i++) {
				if (out_SSE[i][0] != out_FPU[i][0])
					printf("%1d: %lld -> %f <> %f\n",
						i, in[i][0], out_SSE[i][0], out_FPU[i][0]
					), ok=0;

				if (out_SSE[i][1] != out_FPU[i][1])
					printf("%1d: %lld -> %f <> %f\n",
						i, in[i][1], out_SSE[i][1], out_FPU[i][1]
					), ok=0;

			}

			if (ok)
				puts("\tok!");

			//==================================================
			printf("verify SSE (second version)\n");
			SSE_preload2();
			for (i=0; i < SIZE; i++)
				SSE_convert2(in[i], out_SSE[i]);

			ok = 1;
			for (i=0; i < SIZE; i++) {
				if (out_SSE[i][0] != out_FPU[i][0])
					printf("%1d: %lld -> %f <> %f\n",
						i, in[i][0], out_SSE[i][0], out_FPU[i][0]
					), ok=0;

				if (out_SSE[i][1] != out_FPU[i][1])
					printf("%1d: %lld -> %f <> %f\n",
						i, in[i][1], out_SSE[i][1], out_FPU[i][1]
					), ok=0;

			}

			if (ok)
				puts("\tok!");

			break;

		default:
			return 1;
	}
	return 0;
}

// eof
