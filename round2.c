/*
	Double precision floating point rounding, $Revision: 1.2 $
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://www.republika.pl/wmula/news2008.html#log15-06-2008

	License: BSD
	
	initial release 15-06-2008, last update $Date: 2008-06-15 18:09:30 $

	----------------------------------------------------------------------
	
	This program includes 3 different procedures:
	1. round_FPU1 --- round using instruction FRNDINT
	2. round_FPU2 --- round by convert to int and then back to double
	3. round_C    --- simple method

	Compilation:

		gcc -O3 -lm -Wall -pedantic -std=c99 round2.c

	Usage:
		run program without arguments to read help message
	
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>

#ifndef SIZE
#	define SIZE 65536
#endif

double in[SIZE];
double out_1[SIZE];
double out_2[SIZE];


//=== stdlib round =======================================================
void round_stdlib() {
	int i;
	for (i=0; i < SIZE; i++)
		out_1[i] = round(in[i]);
}


//=== FPU - FRNDINT ======================================================
void round_FPU1() {
	int32_t dummy __attribute__((unused));
	__asm__ volatile (
	"	xorl %%eax, %%eax		\n"
	"0:					\n"
	"	fldl in(%%eax)			\n"
	"	frndint				\n"
	"	fstpl out_2(%%eax)		\n"
	"					\n"
	"	addl $8, %%eax			\n"
	"	subl $1, %%ecx			\n"
	"	jnz 0b				\n"
	"					\n"
	: "=c" (dummy)
	: "c" (SIZE)
	: "eax", "memory"
	);
	int i;
	for (i=0; i < SIZE; i++)
		out_1[i] = round(in[i]);
}


//=== FPU - fistp/fild ===================================================
double tmp;

void round_FPU2() {
	int32_t dummy __attribute__((unused));
	__asm__ volatile (
	"	xorl %%eax, %%eax		\n"
	"0:					\n"
	"	fldl in(%%eax)			\n"
#if HAVE_SSSE3
	"	fisttpl tmp			\n"
#else
	"	fistpl tmp			\n"
#endif
	"	fildl tmp			\n"
	"	fstpl out_2(%%eax)		\n"
	"					\n"
	"	addl $8, %%eax			\n"
	"	subl $1, %%ecx			\n"
	"	jnz 0b				\n"
	"					\n"
	"					\n"
	: "=c" (dummy)
	: "c" (SIZE)
	: "eax"
	);
}


//=== C implementation ===================================================
void round_C() {
	double C = (1ll << 52);
	int i;
	for (i=0; i < SIZE; i++) {
		double tmp = in[i];
		tmp += C;
		tmp -= C;
		out_2[i] = tmp;
	}
}


//========================================================================
void help() {
	puts("rounding of double prescision numbers");
	puts("");
	puts("progname 0|1|2|3 iterations");
	puts("0 -- use stdlib function 'round'");
	puts("1 -- use FPU instruction FRNDINT");
	puts("2 -- use FPU instructions FISTP/FILD");
	puts("3 -- use simple method (C implementation)");
	puts("4 -- verify results -- stdlib results are considered valid  (for debugging)");
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
			printf("stdlib, iterations = %d, size = %d\n", iterations, SIZE);
			while (iterations--)
				round_stdlib();
			break;
		
		case 1:
			printf("FPU FRNDINT, iterations = %d, size = %d\n", iterations, SIZE);
			while (iterations--)
				round_FPU1();
			break;
		
		case 2:
			printf("FPU FISTP/FILD, iterations = %d, size = %d\n", iterations, SIZE);
			while (iterations--)
				round_FPU2();
			break;
		
		case 3:
			printf("simple method (C impl.), iterations = %d, size = %d\n", iterations, SIZE);
			while (iterations--)
				round_C();
			break;
		
		case 4:
			round_stdlib();

			puts("verify FPU FRNDINT");
			round_FPU1();
			ok = 1;
			for (i=0; i < SIZE; i++)
				if (out_1[i] != out_2[i] && out_1[i] - out_2[i] != 1)
					printf("%5d: %0.14f -> %0.14f, %0.14f\n",
						i, in[i], out_1[i], out_2[i]), ok=0;
			if (ok)
				puts("\tok!");

			puts("verify FPU FISTP/FILD");
			round_FPU2();
			ok = 1;
			for (i=0; i < SIZE; i++)
				if (out_1[i] != out_2[i] && out_1[i] - out_2[i] != 1)
					printf("%5d: %0.14f -> %0.14f, %0.14f\n",
						i, in[i], out_1[i], out_2[i]), ok=0;
			if (ok)
				puts("\tok!");

			puts("verify simple method");
			round_C();
			ok = 1;
			for (i=0; i < SIZE; i++)
				if (out_1[i] != out_2[i] && out_1[i] - out_2[i] != 1)
					printf("%5d: %0.14f -> %0.14f, %0.14f\n",
						i, in[i], out_1[i], out_2[i]), ok=0;
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
