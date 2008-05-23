/*
	Hex dump comparison, $Revision: 1.4 $
	
	Four different approaches to dump hex:
	* lookup[16]  (nibble-addressing)
	* lookup[256] (byte-addressing)
	* 2 x lookup[256]
	* using SSSE3 instruction PSHUFB
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://www.mula.w.pl
	
	License: public domain
	
	initial release 23-05-2008, last update $Date: 2008-05-23 17:52:35 $
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t buffer[16*100];

static char HEXDIGITS[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

// ---- lookup[16] --------------------------------------------------------
void c_print(uint8_t* buffer, int chunks16) {
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


// ---- lookup[256] -------------------------------------------------------
uint16_t c2_hexdigits[256] __attribute__((aligned(16)));

void c2_prepare_lookups() {
	int i;
	for (i=0; i < 256; i++) {
		c2_hexdigits[i] = (HEXDIGITS[i >> 4]) |
				  (HEXDIGITS[i & 0xf] << 8);
	}
}

void c2_print(uint8_t* buffer, int chunks16) {
	static uint16_t print_buffer[17] __attribute__((aligned(16)));
	int i, n;
	print_buffer[16] = 0;
	for (n=0; n < chunks16; n++) {
		for (i=0; i < 16; i++)
			print_buffer[i] = c2_hexdigits[buffer[n*16 + i]];

		printf("%s\n", print_buffer);
	}
}


// ---- 2 x lookup[256] ---------------------------------------------------
uint32_t c3_hexdigits0[256] __attribute__((aligned(16)));
uint32_t c3_hexdigits1[256] __attribute__((aligned(16)));

void c3_prepare_lookups() {
	uint32_t x;
	uint32_t z[2];
	int i;
	z[1] = 0;
	for (i=0; i < 256; i++) {
		x = (HEXDIGITS[i >> 4]) | (HEXDIGITS[i & 0xf] << 8);
		c3_hexdigits0[i] = x;
		c3_hexdigits1[i] = x << 16;
	}
}

void c3_print(uint8_t* buffer, int chunks16) {
	static uint32_t print_buffer[9] __attribute__((aligned(16)));
	int i, n;
	print_buffer[8] = 0;
	for (n=0; n < chunks16; n++) {
		for (i=0; i < 8; i++)
			print_buffer[i] = c3_hexdigits0[buffer[n*16 + 2*i + 0]] |
					  c3_hexdigits1[buffer[n*16 + 2*i + 1]];

		printf("%s\n", print_buffer);
	}
}


// ---- SSSE3 -------------------------------------------------------------
void ssse3_print(uint8_t* buffer, int chunks16) {
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
			"pand      %%xmm6, %%xmm0	\n"	// xmm0 := lower nibbles
			"pand      %%xmm6, %%xmm1	\n"	// xmm1 := higher nibbles
			"movdqa    %%xmm1, %%xmm2	\n"
			"punpcklbw %%xmm0, %%xmm1	\n"	// interleave nibbles
			"punpckhbw %%xmm0, %%xmm2	\n"

			"movdqa    %%xmm7, %%xmm0	\n"
			"movdqa    %%xmm7, %%xmm3	\n"
			"pshufb    %%xmm1, %%xmm0	\n"	// perform lookup[16]
			"pshufb    %%xmm2, %%xmm3	\n"	// using PSHUFB

			"movdqa    %%xmm0,   (%%ebx)	\n"	// save results
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
		c2_prepare_lookups();
		c3_prepare_lookups();

		puts("std1:");
		c_print(buffer, 5);
		puts("====");
		puts("std2:");
		c2_print(buffer, 5);
		puts("====");
		puts("std3:");
		c3_print(buffer, 5);
		puts("====");
		puts("SSSE3:");
		ssse3_print(buffer, 5);
	}
	else {
		int n = 100000;
		if (strcasecmp(argv[1], "std") == 0 || strcasecmp(argv[1], "std1") == 0)
			for (i=0; i < n; i++)
				c_print(buffer, 100);
		else
		if (strcasecmp(argv[1], "std2") == 0) {
			c2_prepare_lookups();
			for (i=0; i < n; i++)
				c2_print(buffer, 100);
		}
		else
		if (strcasecmp(argv[1], "std3") == 0) {
			c3_prepare_lookups();
			for (i=0; i < n; i++)
				c3_print(buffer, 100);
		}
		else
		if (strcasecmp(argv[1], "SSSE3") == 0)
			for (i=0; i < n; i++)
				ssse3_print(buffer, 100);
		else 
			printf("%s [std1|std2|std3|ssse3]\n", argv[0]);
	}

	return 0;
}

// eof
