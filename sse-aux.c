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


//=== print 8-bit vectors ================================================
static void print_vec_int8(int8_t v[16]) {
	int i = 0;
	printf("{%3d", v[i]);
	for (i=1; i < 16; i++)
		printf(", %3d", v[i]);
	printf("}\n");
}


static void print_vec_uint8(uint8_t v[16]) {
	int i = 0;
	printf("{%3u", v[i]);
	for (i=1; i < 16; i++)
		printf(", %3u", v[i]);
	printf("}\n");
}


static void print_vec_uint8_hex(uint8_t v[16]) {
	int i = 0;
	printf("{%02x", v[i]);
	for (i=1; i < 16; i++)
		printf(",%02x", v[i]);
	printf("}\n");
}


//=== print 16-bit vectors ================================================
static void print_vec_int16(int16_t v[8]) {
	int i = 0;
	printf("{%6d", v[i]);
	for (i=1; i < 8; i++)
		printf(", %6d", v[i]);
	printf("}\n");
}


static void print_vec_uint16(uint16_t v[8]) {
	int i = 0;
	printf("{%5u", v[i]);
	for (i=1; i < 8; i++)
		printf(", %5u", v[i]);
	printf("}\n");
}


static void print_vec_uint16_hex(uint16_t v[8]) {
	int i = 0;
	printf("{%04x", v[i]);
	for (i=1; i < 8; i++)
		printf(", %04x", v[i]);
	printf("}\n");
}


//=== print 32-bit vectors ================================================
static void print_vec_int32(int32_t v[4]) {
	int i = 0;
	printf("{%12d", v[i]);
	for (i=1; i < 4; i++)
		printf(", %12d", v[i]);
	printf("}\n");
}


static void print_vec_uint32(uint32_t v[4]) {
	int i = 0;
	printf("{%12u", v[i]);
	for (i=1; i < 4; i++)
		printf(", %12u", v[i]);
	printf("}\n");
}


static void print_vec_uint32_hex(uint32_t v[4]) {
	int i = 0;
	printf("{%08x", v[i]);
	for (i=1; i < 4; i++)
		printf(", %08x", v[i]);
	printf("}\n");
}


//=== print float vectors =================================================
void print_vec_float(float v[4]) {
	printf("{%12.6f, %12.6f, %12.6f, %12.6f}\n", v[0], v[1], v[2], v[3]);
}


//=== load XMM register ==================================================
void load_xmm(int i, void* v) {
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
}


//=== print XMM registers ================================================
void print_xmm_float(int i) {
	static float v[4];
	load_xmm(i, (void*)v);
	printf("xmm%d = {%12.4f, %12.4f, %12.4f, %12.4f}\n", i, v[0], v[1], v[2], v[3]);
}


void print_xmm_uint8(int i) {
	static uint8_t v[16];
	load_xmm(i, (void*)v);
	printf("xmm%d = ", i);
	print_vec_uint8(v);
}


void print_xmm_int8(int i) {
	static int8_t v[16];
	load_xmm(i, (void*)v);
	printf("xmm%d = ", i);
	print_vec_int8(v);
}


void print_xmm_uint8_hex(int i) {
	static uint8_t v[16];
	load_xmm(i, (void*)v);
	printf("xmm%d = ", i);
	print_vec_uint8_hex(v);
}


void print_xmm_uint16(int i) {
	static uint16_t v[8];
	load_xmm(i, (void*)v);
	printf("xmm%d = ", i);
	print_vec_uint16(v);
}


void print_xmm_int16(int i) {
	static int16_t v[8];
	load_xmm(i, (void*)v);
	printf("xmm%d = ", i);
	print_vec_int16(v);
}


void print_xmm_uint16_hex(int i) {
	static uint16_t v[8];
	load_xmm(i, (void*)v);
	printf("xmm%d = ", i);
	print_vec_uint16_hex(v);
}


void print_xmm_uint32(int i) {
	static uint32_t v[4];
	load_xmm(i, (void*)v);
	printf("xmm%d = ", i);
	print_vec_uint32(v);
}


void print_xmm_int32(int i) {
	static int32_t v[4];
	load_xmm(i, (void*)v);
	printf("xmm%d = ", i);
	print_vec_int32(v);
}


void print_xmm_uint32_hex(int i) {
	static uint32_t v[4];
	load_xmm(i, (void*)v);
	printf("xmm%d = ", i);
	print_vec_uint32_hex(v);
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
