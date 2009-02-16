/*
	Convering floating point numbers to int, $Revision: 1.3 $
	
	Comparison of FPU based method and simple method that
	require one addition and bitwise AND -- method is limited
	to positive numbers not greater then 2^52.

	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://wm.ite.pl/articles/fptricks.html
	
	License: BSD


	Compilation:

		gcc -Wall -pedantic -std=c99 -O3 float2int.c

	Run program without arguments, to read usage info.

	
	initial release 14-06-2008, last update $Date: 2009-02-16 21:57:29 $
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#ifndef SIZE
#	define SIZE 65536
#endif

double in[SIZE];
int64_t out_1[SIZE];
int64_t out_2[SIZE];


//=== FPU ==============================================================
void convert_FPU() {
	int i;
	for (i=0; i < SIZE; i++)
		out_1[i] = in[i];
}


//=== C implementation =================================================
void convert_simple() {
	double C = (1ll << 52);
	union {
		double  val;
		int64_t bin;
	} tmp;

	int i;
	for (i=0; i < SIZE; i++) {
		tmp.val  = in[i] + C;	// we add BIG number -- this cause lost of fraction bits.
		tmp.bin  = tmp.bin & 0x000fffffffffffffll;
		out_2[i] = tmp.bin;
	}
}


//=== asm implementation ===============================================
double C = (1ll << 52);
uint64_t tmp;

void convert_simple_asm() {
	int32_t dummy __attribute__((unused));
	__asm__ volatile (
	"	xorl %%eax, %%eax		\n"
	"	fldl C				\n"	// preload BIG number
	"0:					\n"
	"	fld %%st(0)			\n"
	"	faddl in(%%eax)			\n"
	"	fstpl out_2(%%eax)		\n"
	"	andl $0x000fffff, out_2+4(%%eax)\n"
	"					\n"
	"	addl $8, %%eax			\n"
	"	subl $1, %%ecx			\n"
	"	jnz 0b				\n"
	"					\n"
	"	fstpl tmp			\n"
	: "=c" (dummy)
	: "c" (SIZE)
	: "eax"
	);
}


//== main program ======================================================== 
void help() {
	puts("progname 0|1|2|3 iterations");
	puts("0 - run bare FPU code");
	puts("1 - run simple approach (C implementation)");
	puts("2 - run simple approach (x86 implementation)");
	puts("3 - compare results (for debugging)");
}


int main(int argc, char* argv[]) {
	int i;
	char ok;

	if (argc < 3) {
		help();
		return 1;
	}

	srand(time(NULL));

	for (i=0; i < SIZE; i++)
		switch (rand() % 5) {
			case 0:
				in[i] = (double)rand();
				break;
			case 1:
				in[i] = (double)rand() / 10.0;
				break;
			case 2:
				in[i] = (double)rand() / 100.0;
				break;
			case 3:
				in[i] = (double)rand() / 1000.0;
				break;
			case 4:
				in[i] = (double)rand() / 10000.0;
				break;
			default:
				return 1;
		}

	int function   = atoi(argv[1]);
	int iterations = atoi(argv[2]) <= 0 ? 1 : atoi(argv[2]);

	switch (function) {
		case 0:
			printf("function FPU, iterations = %d, size = %d\n", iterations, SIZE);
			while (iterations--)
				convert_FPU();
			break;
		
		case 1:
			printf("function simple (C), iterations = %d, size = %d\n", iterations, SIZE);
			while (iterations--)
				convert_simple();
			break;
		
		case 2:
			printf("function simple (x86), iterations = %d, size = %d\n", iterations, SIZE);
			while (iterations--)
				convert_simple_asm();
			break;

		case 3:
			printf("compare FPU and C implementation\n");
			convert_FPU();
			convert_simple();

			ok = 1;
			for (i=0; i < SIZE; i++)
				if (out_1[i] != out_2[i]) {
					if (out_2[i] - out_1[i] == 1)
						/* diffence 1 is not error */
						;
					else
						printf("%5d: %0.14f -> %lld, %lld\n",
							i, in[i], out_1[i], out_2[i]), ok=0;
				}

			if (ok)
				puts("\tok!");
			
			printf("compare FPU and x86 implementation\n");
			convert_simple_asm();

			ok = 1;
			for (i=0; i < SIZE; i++)
				if (out_1[i] != out_2[i]) {
					if (out_2[i] - out_1[i] == 1)
						/* diffence 1 is not error */
						;
					else
						printf("%5d: %0.14f -> %lld, %lld\n",
							i, in[i], out_1[i], out_2[i]), ok=0;
				}
			
			if (ok)
				puts("\tok!");

			break;

		default:
			help();
			return 1;
	}

	return 0;
}

// eof
