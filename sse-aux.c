#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define packed_byte(x)   {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x}
#define packed_word(x)   {x, x, x, x, x, x, x, x}
#define packed_dword(x)  {x, x, x, x}
#define packed_float(f)  packed_dword(f)
#define packed_double(f) {f, f}

#define SIMD_ALIGN __attribute__((aligned(16)))


void initfrand() {
	srand(time(NULL));
}


float frand(float min, float max) {
	return min + ((float)rand()/RAND_MAX) * (max - min);
}


void print_vec_float(float v[4]) {
	printf("{%12.4f, %12.4f, %12.4f, %12.4f}\n", v[0], v[1], v[2], v[3]);
}


void print_xmm_float(int i) {
	static float v[4];
	switch (i) {
		case 0: __asm__ volatile("movups %%xmm0, (%0)":: "r" (v)); break;
		case 1: __asm__ volatile("movups %%xmm1, (%0)":: "r" (v)); break;
		case 2: __asm__ volatile("movups %%xmm2, (%0)":: "r" (v)); break;
		case 3: __asm__ volatile("movups %%xmm3, (%0)":: "r" (v)); break;
		case 4: __asm__ volatile("movups %%xmm4, (%0)":: "r" (v)); break;
		case 5: __asm__ volatile("movups %%xmm5, (%0)":: "r" (v)); break;
		case 6: __asm__ volatile("movups %%xmm6, (%0)":: "r" (v)); break;
		case 7: __asm__ volatile("movups %%xmm7, (%0)":: "r" (v)); break;
	}
	printf("xmm%d = {%12.4f, %12.4f, %12.4f, %12.4f}\n", i, v[0], v[1], v[2], v[3]);
}


#define PRINT_XMM_FLOAT(n)		\
	"pushal\n"			\
	"pushl $" ##n "\n"		\
	"call print_xmm_float\n"	\
	"popl %%eax\n"			\
	"popal\n"


void print_xmm_hex(int i) {
	int k;
	static uint8_t v[16];
	switch (i) {
		case 0: __asm__ volatile("movups %%xmm0, (%0)":: "r" (v)); break;
		case 1: __asm__ volatile("movups %%xmm1, (%0)":: "r" (v)); break;
		case 2: __asm__ volatile("movups %%xmm2, (%0)":: "r" (v)); break;
		case 3: __asm__ volatile("movups %%xmm3, (%0)":: "r" (v)); break;
		case 4: __asm__ volatile("movups %%xmm4, (%0)":: "r" (v)); break;
		case 5: __asm__ volatile("movups %%xmm5, (%0)":: "r" (v)); break;
		case 6: __asm__ volatile("movups %%xmm6, (%0)":: "r" (v)); break;
		case 7: __asm__ volatile("movups %%xmm7, (%0)":: "r" (v)); break;
	}
	printf("xmm%d = {", i);
	for (k=0; k < 16; k++)
		printf("%02x", v[i]);
	printf("}\n");
}


#define PRINT_XMM_HEX(n)	\
	"pushal\n"		\
	"pushl $" ##n "\n"	\
	"call print_xmm_hex\n"	\
	"popl %%eax\n"		\
	"popal\n"


void print_xmm_str(int i) {
	int k;
	static uint8_t v[16];
	switch (i) {
		case 0: __asm__ volatile("movups %%xmm0, (%0)":: "r" (v)); break;
		case 1: __asm__ volatile("movups %%xmm1, (%0)":: "r" (v)); break;
		case 2: __asm__ volatile("movups %%xmm2, (%0)":: "r" (v)); break;
		case 3: __asm__ volatile("movups %%xmm3, (%0)":: "r" (v)); break;
		case 4: __asm__ volatile("movups %%xmm4, (%0)":: "r" (v)); break;
		case 5: __asm__ volatile("movups %%xmm5, (%0)":: "r" (v)); break;
		case 6: __asm__ volatile("movups %%xmm6, (%0)":: "r" (v)); break;
		case 7: __asm__ volatile("movups %%xmm7, (%0)":: "r" (v)); break;
	}
	printf("xmm%d = {", i);
	for (k=0; k < 16; k++)
		if (v[i] < 0x20)
			printf("\\x%02x", v[i]);
		else
		if (v[i] == '\'')
			printf("\\'");
		else
			putchar(v[i]);

	printf("}\n");
}


#define PRINT_XMM_STR(n)	\
	"pushal\n"		\
	"pushl $" ##n "\n"	\
	"call print_xmm_str\n"	\
	"popl %%eax\n"		\
	"popal\n"
