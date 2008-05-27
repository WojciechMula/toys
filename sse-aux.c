#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define packed_byte(x)   {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x}
#define packed_word(x)   {x, x, x, x, x, x, x, x}
#define packed_dword(x)  {x, x, x, x}
#define packed_float(f)  packed_dword(f)
#define packed_double(f) {f, f}

#define SIMD_ALIGN __attribute__((aligned(16)))


#define DUMP_XMM(x)		\
	"pushal\n"		\
	"pushl $" ##x "\n"	\
	"call dump_xmm\n"	\
	"popl %%eax\n"		\
	"popal\n"		\


void print_xmm_float(int i) {
	static float v[4];
	switch (i) {
		case 0: asm("movups %%xmm0, (%0)":: "r" (v)); break;
		case 1: asm("movups %%xmm1, (%0)":: "r" (v)); break;
		case 2: asm("movups %%xmm2, (%0)":: "r" (v)); break;
		case 3: asm("movups %%xmm3, (%0)":: "r" (v)); break;
		case 4: asm("movups %%xmm4, (%0)":: "r" (v)); break;
		case 5: asm("movups %%xmm5, (%0)":: "r" (v)); break;
		case 6: asm("movups %%xmm6, (%0)":: "r" (v)); break;
		case 7: asm("movups %%xmm7, (%0)":: "r" (v)); break;
	}
	printf("xmm%d = {%12.4f, %12.4f, %12.4f, %12.4f}\n", i, v[0], v[1], v[2], v[3]);
}


#define PRINT_XMM_FLOAT(n)
	"pushal\n"
	"pushl $" ##n "\n"
	"call print_xmm_float\n"
	"popl %%eax\n"
	"popal\n"


void print_xmm_hex(int i) {
	int k;
	static uint8_t v[16];
	switch (i) {
		case 0: asm("movups %%xmm0, (%0)":: "r" (v)); break;
		case 1: asm("movups %%xmm1, (%0)":: "r" (v)); break;
		case 2: asm("movups %%xmm2, (%0)":: "r" (v)); break;
		case 3: asm("movups %%xmm3, (%0)":: "r" (v)); break;
		case 4: asm("movups %%xmm4, (%0)":: "r" (v)); break;
		case 5: asm("movups %%xmm5, (%0)":: "r" (v)); break;
		case 6: asm("movups %%xmm6, (%0)":: "r" (v)); break;
		case 7: asm("movups %%xmm7, (%0)":: "r" (v)); break;
	}
	printf("xmm%d = {", i);
	for (k=0; k < 16; k++)
		printf("%02x", v[i]);
	printf("}\n");
}


#define PRINT_XMM_HEX(n)
	"pushal\n"
	"pushl $" ##n "\n"
	"call print_xmm_hex\n"
	"popl %%eax\n"
	"popal\n"


void print_xmm_str(int i) {
	int k;
	static uint8_t v[16];
	switch (i) {
		case 0: asm("movups %%xmm0, (%0)":: "r" (v)); break;
		case 1: asm("movups %%xmm1, (%0)":: "r" (v)); break;
		case 2: asm("movups %%xmm2, (%0)":: "r" (v)); break;
		case 3: asm("movups %%xmm3, (%0)":: "r" (v)); break;
		case 4: asm("movups %%xmm4, (%0)":: "r" (v)); break;
		case 5: asm("movups %%xmm5, (%0)":: "r" (v)); break;
		case 6: asm("movups %%xmm6, (%0)":: "r" (v)); break;
		case 7: asm("movups %%xmm7, (%0)":: "r" (v)); break;
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


#define PRINT_XMM_STR(n)
	"pushal\n"
	"pushl $" ##n "\n"
	"call print_xmm_str\n"
	"popl %%eax\n"
	"popal\n"
