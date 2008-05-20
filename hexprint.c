#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t buffer[16*100];

void c_print(uint8_t* buffer, int chunks16) {
	static char HEXDIGITS[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	static char print_buffer[33] __attribute__((aligned(16)));
	int i, n;
	print_buffer[32] = '\0';
	for (n=0; n < chunks16; n++) {
		for (i=0; i < 16; i++) {
			print_buffer[2*i + 0] = HEXDIGITS[buffer[n*16 + i] >> 4];
			print_buffer[2*i + 1] = HEXDIGITS[buffer[n*16 + i] & 0xf];
		}

		printf("%s\n", print_buffer);
	}
}


void sse3_print(uint8_t* buffer, int chunks16) {
	static char HEXDIGITS[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	static char MASK_4bit[16] = {0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf};
	static char print_buffer[33] __attribute__((aligned(16)));
	int i, n;

	print_buffer[32] = '\0';
	asm volatile ("movdqu (%%eax), %%xmm7" : : "a" (HEXDIGITS));
	asm volatile ("movdqu (%%eax), %%xmm6" : : "a" (MASK_4bit));
	for (n=0; n < chunks16; n++) {
		asm volatile(
			"movdqu	  (%%eax), %%xmm0	\n"
			"movdqa    %%xmm0, %%xmm1	\n"
			"psrlw         $4, %%xmm1	\n"
			"pand      %%xmm6, %%xmm0	\n"
			"pand      %%xmm6, %%xmm1	\n"
			"movdqa    %%xmm1, %%xmm2	\n"
			"punpcklbw %%xmm0, %%xmm1	\n"
			"punpckhbw %%xmm0, %%xmm2	\n"
			"movdqa    %%xmm7, %%xmm0	\n"
			"movdqa    %%xmm7, %%xmm3	\n"
			"pshufb    %%xmm1, %%xmm0	\n"
			"pshufb    %%xmm2, %%xmm3	\n"
			"movdqa    %%xmm0,   (%%ebx)	\n"
			"movdqa    %%xmm3, 16(%%ebx)	\n"
			:
			: "a" (&buffer[n*16]),
			  "b" (print_buffer)
		);
		printf("%s\n", print_buffer);
	}
}


int main(int argc, char* argv[]) {
	int i;
	srand(time(NULL));
	for (i=0; i < sizeof(buffer); i++)
		buffer[i] = rand() % 256;

	if (argc == 1) {
		puts("std:");
		c_print(buffer, 5);
		puts("====");
		puts("SSE3:");
		sse3_print(buffer, 5);
	}
	else {
		if (strcasecmp(argv[1], "std") == 0)
			for (i=0; i < 100000; i++)
				c_print(buffer, 100);
		else
		if (strcasecmp(argv[1], "SSE3") == 0)
			for (i=0; i < 100000; i++)
				sse3_print(buffer, 100);
		else 
			printf("%s [std|sse3]\n", argv[0]);
	}

	return 0;
}
