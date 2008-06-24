#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "sse-aux.c"

//========================================================================
float in_matrix[4][4]	SIMD_ALIGN;
float in_vector[4]	SIMD_ALIGN;
float out_vector1[4]	SIMD_ALIGN;
float out_vector2[4]	SIMD_ALIGN;
float out_vector3[4]	SIMD_ALIGN;


//========================================================================
void matvecmul(float in_matrix[4][4], float in_vector[4], float out_vector[4]) {
	int i, j;
	for (i=0; i < 4; i++) {
		out_vector[i] = 0.0;
		for (j=0; j < 4; j++)
			out_vector[i] += (in_matrix[i][j] * in_vector[j]);
	}
}


//========================================================================
#ifdef DATA_ALIGNED
void sse3_matvecmul(float in_matrix[4][4], float in_vector[4], float out_vector[4]) {
	asm volatile (
		"movaps   (%0), %%xmm0			\n"
		"movaps %%xmm0, %%xmm1			\n"
		"movaps %%xmm0, %%xmm2			\n"
		"movaps %%xmm0, %%xmm3			\n"
		: /* no output */
		: "r" (in_vector)
	);
	asm volatile (
		"mulps  0x00(%0), %%xmm0		\n"
		"mulps  0x10(%0), %%xmm1		\n"
		"mulps  0x20(%0), %%xmm2		\n"
		"mulps  0x30(%0), %%xmm3		\n"
		"					\n"
		"haddps %%xmm1, %%xmm0			\n"
		"haddps %%xmm3, %%xmm2			\n"
		
		"haddps %%xmm2, %%xmm0			\n"
		"					\n"
		: /* no output */
		: "r" (in_matrix)
	);
	asm volatile (
		"movaps %%xmm0, (%0)"
		: /* no output */
		: "r" (out_vector)
	);
}
#else
void sse3_matvecmul(float in_matrix[4][4], float in_vector[4], float out_vector[4]) {
	asm volatile (
		"movups (%0), %%xmm7"
		: /* no output */
		: "r" (in_vector)
	);
	asm volatile (
		"movups 0x00(%0), %%xmm0		\n"
		"movups 0x10(%0), %%xmm1		\n"
		"movups 0x20(%0), %%xmm2		\n"
		"movups 0x30(%0), %%xmm3		\n"
		"					\n"
		"mulps  %%xmm7, %%xmm0			\n"
		"mulps  %%xmm7, %%xmm1			\n"
		"mulps  %%xmm7, %%xmm2			\n"
		"mulps  %%xmm7, %%xmm3			\n"
		"					\n"
		"haddps %%xmm1, %%xmm0			\n"
		"haddps %%xmm3, %%xmm2			\n"
		
		"haddps %%xmm2, %%xmm0			\n"
		"					\n"
		: /* no output */
		: "r" (in_matrix)
	);
	asm volatile (
		"movups %%xmm0, (%0)"
		: /* no output */
		: "r" (out_vector)
	);
}
#endif


//========================================================================
#ifdef DATA_ALIGNED
void sse4_matvecmul(float in_matrix[4][4], float in_vector[4], float out_vector[4]) {
	asm volatile (
		"movaps   (%0), %%xmm0			\n"
		"movaps %%xmm0, %%xmm1			\n"
		"movaps %%xmm0, %%xmm2			\n"
		"movaps %%xmm0, %%xmm3			\n"
		: /* no output */
		: "r" (in_vector)
	);
	asm volatile (
		"dpps   $0xf1, 0x00(%0), %%xmm0		\n"
		"dpps   $0xf2, 0x10(%0), %%xmm1		\n"
		"dpps   $0xf4, 0x20(%0), %%xmm2		\n"
		"dpps   $0xf8, 0x30(%0), %%xmm3		\n"
		
		"orps   %%xmm1, %%xmm0			\n"
		"orps   %%xmm3, %%xmm2			\n"
		"orps   %%xmm2, %%xmm0			\n"
		: /* no output */
		: "r" (in_matrix)
	);
	asm volatile (
		"movaps %%xmm0, (%0)"
		:
		: "r" (out_vector)
	);
}
#else
void sse4_matvecmul(float in_matrix[4][4], float in_vector[4], float out_vector[4]) {
	asm volatile (
		"movups (%0), %%xmm7"
		:
		: "r" (in_vector)
	);
	asm volatile (
		"movups 0x00(%0), %%xmm0		\n"
		"movups 0x10(%0), %%xmm1		\n"
		"movups 0x20(%0), %%xmm2		\n"
		"movups 0x30(%0), %%xmm3		\n"
		"					\n"
		"dpps   $0xf1, %%xmm7, %%xmm0		\n"
		"dpps   $0xf2, %%xmm7, %%xmm1		\n"
		"dpps   $0xf4, %%xmm7, %%xmm2		\n"
		"dpps   $0xf8, %%xmm7, %%xmm3		\n"
		"					\n"
		"orps   %%xmm1, %%xmm0			\n"
		"orps   %%xmm3, %%xmm2			\n"
		"orps   %%xmm2, %%xmm0			\n"
		"					\n"
		: /* no output */
		: "r" (in_matrix)
	);
	asm volatile (
		"movups %%xmm0, (%0)"
		:
		: "r" (out_vector)
	);
}
#endif


//========================================================================
int main(int argc, char* argv[]) {
	int i, j;

	enum {None, Compare, TestFPU, TestSSE3, TestSSE4} function;
	int iterations = 0;

	float range = 10000.0;

	function = None;
	if (argc > 1) {
		if (strcasecmp(argv[1], "compare") == 0 || strcasecmp(argv[1], "cmp") == 0)
			function = Compare;
		else
		if (strcasecmp(argv[1], "fpu") == 0)
			function = TestFPU;
		else
		if (strcasecmp(argv[1], "sse3") == 0)
			function = TestSSE3;
		else
		if (strcasecmp(argv[1], "sse4") == 0)
			function = TestSSE4;
	}

	if (argc > 2)
		iterations = atoi(argv[2]);

	if (iterations <= 0)
		iterations = 1;

	initfrand();
	for (i=0; i < 4; i++)
		for (j=0; j < 4; j++)
			in_matrix[i][j] = frand(-range, +range);
	
	for (i=0; i < 4; i++)
		in_vector[i] = frand(-range, range);

	if (function != Compare && function != None)
		printf("iterations = %d\n", iterations);

	switch (function) {
		case Compare:
			puts("Input matrix");
			for (i=0; i < 4; i++)
				print_vec_float(in_matrix[i]);

			puts("");
			puts("Input vector");
			print_vec_float(in_vector);

			
			puts("");
			puts("mat*vec result:");
			matvecmul(in_matrix, in_vector, out_vector1);
			print_vec_float(out_vector1);
			
			puts("");
			puts("SSE3 mat*vec result:");
			sse3_matvecmul(in_matrix, in_vector, out_vector2);
			print_vec_float(out_vector2);
			
			
			puts("");
			puts("SSE4 mat*vec result:");
			sse4_matvecmul(in_matrix, in_vector, out_vector3);
			print_vec_float(out_vector3);

			break;


		case TestFPU:
			while (iterations--)
				matvecmul(in_matrix, in_vector, out_vector1);
			break;


		case TestSSE3:
			while (iterations--)
				sse3_matvecmul(in_matrix, in_vector, out_vector2);
			break;


		case TestSSE4:
			while (iterations--)
				sse4_matvecmul(in_matrix, in_vector, out_vector3);
			break;
	}
	
	return 0;
}

