#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

static uint32_t LUT_R[256] __attribute__((aligned(16)));
static uint32_t LUT_G[256] __attribute__((aligned(16)));
static uint32_t LUT_B[256] __attribute__((aligned(16)));
static uint32_t LUT_A[256] __attribute__((aligned(16)));


void convert(uint32_t* input, uint32_t* output, int n) {
	uint32_t R, G, B, A;
	int i;
	for (i=0; i < n; i++) {
		R = input[i] & 0xff;
		G = (input[i] >> 8)  & 0xff;
		B = (input[i] >> 16) & 0xff;
		A = (input[i] >> 24) & 0xff;

		R = LUT_R[R];
		G = LUT_G[G];
		B = LUT_B[B];
		A = LUT_A[A];

		output[i] = R | G | B | A;
	}
}


void x86_convert(uint32_t* input, uint32_t* output, int n) {
	asm volatile(
		"	pushl %%ebp			\n"
		"	movl  %%ecx, %%ebp		\n"
		"0:					\n"
		"	movl   (%%esi), %%eax 		\n"
		"	addl        $4, %%esi		\n"
	
		"	movzbl    %%al, %%ebx		\n"
		"	movzbl    %%ah, %%ecx		\n"
		"	shrl       $16, %%eax		\n"
		"	movzbl    %%ah, %%edx		\n"
		"	movzbl    %%al, %%eax		\n"

		"	movl   LUT_R(,%%ebx,4), %%ebx	\n"
		"	orl    LUT_G(,%%ecx,4), %%ebx	\n"
		"	orl    LUT_B(,%%edx,4), %%ebx	\n"
		"	orl    LUT_A(,%%eax,4), %%ebx	\n"
		"	movl   %%ebx, (%%edi)		\n"
		"	addl      $4, %%edi		\n"

		"	subl   $1, %%ebp		\n"
		"	jnz    0b			\n"

		"	popl	%%ebp			\n"
		:
		: "S" (input),
		  "D" (output),
		  "c" (n)
		: "eax", "ebx", "edx", "memory"
	);
}



void sse2_convert(uint32_t* input, uint32_t* output, int n) {
	asm volatile(
		"	pushl %%ebp			\n"
		"	movl  %%ecx, %%ebp		\n"
		"0:					\n"
		"	movdqa (%%esi), %%xmm0		\n"
		"	addl       $16, %%esi		\n"
	
		"	movd	%%xmm0, %%eax		\n"
		"	movzbl    %%al, %%ebx		\n"
		"	movzbl    %%ah, %%ecx		\n"
		"	shrl       $16, %%eax		\n"
		"	movzbl    %%ah, %%edx		\n"
		"	movzbl    %%al, %%eax		\n"

		"	pshufd $0b00111001, %%xmm0, %%xmm0	\n"
			
		"	movl   LUT_R(,%%ebx,4), %%ebx	\n"
		"	orl    LUT_G(,%%ecx,4), %%ebx	\n"
		"	orl    LUT_B(,%%edx,4), %%ebx	\n"
		"	orl    LUT_A(,%%eax,4), %%ebx	\n"
		"	movl   %%ebx, (%%edi)		\n"

		"	movd	%%xmm0, %%eax		\n"
		"	movzbl    %%al, %%ebx		\n"
		"	movzbl    %%ah, %%ecx		\n"
		"	shrl       $16, %%eax		\n"
		"	movzbl    %%ah, %%edx		\n"
		"	movzbl    %%al, %%eax		\n"

		"	pshufd $0b00111001, %%xmm0, %%xmm0	\n"
			
		"	movl   LUT_R(,%%ebx,4), %%ebx	\n"
		"	orl    LUT_G(,%%ecx,4), %%ebx	\n"
		"	orl    LUT_B(,%%edx,4), %%ebx	\n"
		"	orl    LUT_A(,%%eax,4), %%ebx	\n"
		"	movl   %%ebx, (%%edi)		\n"

		"	movd	%%xmm0, %%eax		\n"
		"	movzbl    %%al, %%ebx		\n"
		"	movzbl    %%ah, %%ecx		\n"
		"	shrl       $16, %%eax		\n"
		"	movzbl    %%ah, %%edx		\n"
		"	movzbl    %%al, %%eax		\n"

		"	pshufd $0b00111001, %%xmm0, %%xmm0	\n"
			
		"	movl   LUT_R(,%%ebx,4), %%ebx	\n"
		"	orl    LUT_G(,%%ecx,4), %%ebx	\n"
		"	orl    LUT_B(,%%edx,4), %%ebx	\n"
		"	orl    LUT_A(,%%eax,4), %%ebx	\n"
		"	movl   %%ebx, (%%edi)		\n"

		"	movd	%%xmm0, %%eax		\n"
		"	movzbl    %%al, %%ebx		\n"
		"	movzbl    %%ah, %%ecx		\n"
		"	shrl       $16, %%eax		\n"
		"	movzbl    %%ah, %%edx		\n"
		"	movzbl    %%al, %%eax		\n"

		"	movl   LUT_R(,%%ebx,4), %%ebx	\n"
		"	orl    LUT_G(,%%ecx,4), %%ebx	\n"
		"	orl    LUT_B(,%%edx,4), %%ebx	\n"
		"	orl    LUT_A(,%%eax,4), %%ebx	\n"
		"	movl   %%ebx, (%%edi)		\n"
		
		"	addl   $16, %%edi		\n"
		"	subl    $1, %%ebp		\n"
		"	jnz    0b			\n"

		"	popl	%%ebp			\n"
		:
		: "S" (input),
		  "D" (output),
		  "c" (n/4)
		: "eax", "ebx", "edx", "memory"
	);
}


void sse4_convert(uint32_t* input, uint32_t* output, int n) {
	asm volatile(
		"	pushl %%ebp			\n"
		"	movl  %%ecx, %%ebp		\n"
		"0:					\n"
		"	movdqa (%%esi), %%xmm0		\n"
		"	addl       $16, %%esi		\n"
		
		"	pextrb $0, %%xmm0, %%eax	\n"
		"	pextrb $1, %%xmm0, %%ebx	\n"
		"	pextrb $2, %%xmm0, %%ecx	\n"
		"	pextrb $3, %%xmm0, %%edx	\n"
		"	movl   LUT_R(,%%eax,4), %%eax	\n"
		"	orl    LUT_G(,%%ebx,4), %%eax	\n"
		"	orl    LUT_B(,%%edx,4), %%eax	\n"
		"	orl    LUT_A(,%%edx,4), %%eax	\n"
		"	pinsrd $0, %%eax, %%xmm1	\n"

		"	pextrb $4, %%xmm0, %%eax	\n"
		"	pextrb $5, %%xmm0, %%ebx	\n"
		"	pextrb $6, %%xmm0, %%ecx	\n"
		"	pextrb $7, %%xmm0, %%edx	\n"
		"	movl   LUT_R(,%%eax,4), %%eax	\n"
		"	orl    LUT_G(,%%ebx,4), %%eax	\n"
		"	orl    LUT_B(,%%edx,4), %%eax	\n"
		"	orl    LUT_A(,%%edx,4), %%eax	\n"
		"	pinsrd $1, %%eax, %%xmm1	\n"

		"	pextrb $8, %%xmm0, %%eax	\n"
		"	pextrb $9, %%xmm0, %%ebx	\n"
		"	pextrb $10, %%xmm0, %%ecx	\n"
		"	pextrb $11, %%xmm0, %%edx	\n"
		"	movl   LUT_R(,%%eax,4), %%eax	\n"
		"	orl    LUT_G(,%%ebx,4), %%eax	\n"
		"	orl    LUT_B(,%%edx,4), %%eax	\n"
		"	orl    LUT_A(,%%edx,4), %%eax	\n"
		"	pinsrd $2, %%eax, %%xmm1	\n"

		"	pextrb $12, %%xmm0, %%eax	\n"
		"	pextrb $13, %%xmm0, %%ebx	\n"
		"	pextrb $14, %%xmm0, %%ecx	\n"
		"	pextrb $15, %%xmm0, %%edx	\n"
		"	movl   LUT_R(,%%eax,4), %%eax	\n"
		"	orl    LUT_G(,%%ebx,4), %%eax	\n"
		"	orl    LUT_B(,%%edx,4), %%eax	\n"
		"	orl    LUT_A(,%%edx,4), %%eax	\n"
		"	pinsrd $3, %%eax, %%xmm1	\n"

		"	movdqa %%xmm1, (%%edi)		\n"
		"	addl   $16, %%edi		\n"

		"	subl   $1, %%ebp		\n"
		"	jnz    0b			\n"

		"	popl	%%ebp			\n"
		:
		: "S" (input),
		  "D" (output),
		  "c" (n/4)
		: "eax", "ebx", "edx", "memory"
	);
}


void help() {
	puts("progname naive|x86|sse2|sse4 repeat-count [default=100]");
}


int main(int argc, char* argv[]) {
	int n;
	uint32_t* input;
	uint32_t* output;
	
	if (argc == 1) {
		help();
		return 1;
	}

	n = 1024*768;

	input = output = NULL;
	if (posix_memalign((void*)&input,  16, 4*n)) {
		puts("can't allocate mem(1)");
		return 1;
	}
	if (posix_memalign((void*)&output, 16, 4*n)) {
		puts("can't allocate mem(2)");
		return 1;
	}

	int i;
	int repeat_count = 0;

	if (argc > 2)
		repeat_count = atoi(argv[2]);
	
	if (repeat_count <= 0)
		repeat_count = 100;
		
	
	if (strcasecmp(argv[1], "naive") == 0) {
		printf("function %s, repeat count %d\n", argv[1], repeat_count);
		for (i=0; i < repeat_count; i++)
			convert(input, output, n);
	}
	else
	if (strcasecmp(argv[1], "x86") == 0) {
		printf("function %s, repeat count %d\n", argv[1], repeat_count);
		for (i=0; i < repeat_count; i++)
			x86_convert(input, output, n);
	}
	else
	if (strcasecmp(argv[1], "SSE2") == 0) {
		printf("function %s, repeat count %d\n", argv[1], repeat_count);
		for (i=0; i < repeat_count; i++)
			sse2_convert(input, output, n);
	}
	else
	if (strcasecmp(argv[1], "SSE4") == 0) {
		printf("function %s, repeat count %d\n", argv[1], repeat_count);
		for (i=0; i < repeat_count; i++)
			sse4_convert(input, output, n);
	}
	else
		help();

	free(input);
	free(output);
	return 0;
}
