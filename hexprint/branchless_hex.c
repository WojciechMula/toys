/*
	Brancheless conversion hex to ASCII

	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	License: public domain

	initial release 8-05-2010

	----------------------------------------------------------------------

	Usage:

		prog [list of numbers]

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* branchless convert nibble to ASCII */
int to_hex(int x) {
	int result;
	__asm__ volatile (
		"andl $0x0f, %%eax			\n"
		"leal -10(%%eax), %%ebx			\n"
		"shrl $29, %%ebx			\n"
		"neg  %%ebx				\n"	// ebx = (eax < 10) ? -7 : 0
		"leal 55(%%eax, %%ebx), %%eax		\n"
		: "=a" (result)
		: "a" (x)
		: "ebx"
	);

	return result;
}
//------------------------------------------------------------------------

/* branchless convert nibble to ASCII */
int to_hex2(int x) {
	int result;
	__asm__ volatile (
		"andl $0x0f, %%eax			\n"
		"leal (0x7fffffff-9)(%%eax), %%ebx	\n"	// MSB(ebx)=1 when eax >= 10
		"sarl $31, %%ebx			\n"	// ebx - mask
//		"and  $7, %%ebx				\n"	// ebx = 7 when eax >= 10 (for A-F letters)
		"andl $39, %%ebx			\n"	// ebx = 39 when eax >= 10 (for a-f letters)
		"leal '0'(%%eax, %%ebx), %%eax		\n"	// eax = '0' + eax + ebx => ASCII letter
		: "=a" (result)
		: "a" (x)
		: "ebx"
	);

	return result;
}
//------------------------------------------------------------------------

/* branchless convert 4 nibbles to ASCII */
uint32_t word_to_hex(int x) {
	uint32_t result;
	uint32_t tmp;

	// [0000abcd] => [0a0b0c0d]
	tmp = (x & 0x000f) | ((x & 0x00f0) << 4) | ((x & 0x0f00) << 8) | ((x & 0xf000) << 12);

	__asm__ volatile (

		"leal 0x76767676(%%eax), %%ebx		\n"	// MSB of each byte is set when corresponding
								// eax byte is >= 10
								// 0x7f - 9 = 0x76
		"andl $0x80808080, %%ebx		\n"
		"movl %%ebx, %%ecx			\n"
		"shrl    $7, %%ebx			\n"
		"subl %%ebx, %%ecx			\n"
		"andl $0x07070707, %%ecx		\n"
		"leal 0x30303030(%%eax, %%ecx), %%eax	\n"
		: "=a" (result)
		: "a" (tmp)
		: "ebx", "ecx"
	);

	return result;
}

int main(int argc, char* argv[]) {
	int i;
	int x;
    union {
	    char string[5];
        uint32_t word;
    }buffer ;

    memset(buffer.string, 0, sizeof(buffer.string));
	
	for (i=0; i <= 15; i++)
		printf("%d => %d ('%c')\n", i, to_hex(i), to_hex(i));
	
	puts("");
	for (i=0; i <= 15; i++)
		printf("%d => %d ('%c')\n", i, to_hex2(i), to_hex2(i));

	for (i=1; i < argc; i++) {
		x = atoi(argv[i]);
        buffer.word = word_to_hex(x);
		printf("%08x => %08x ('%s')", x, word_to_hex(x), buffer.string);
	}
	
	return 0;
}
//------------------------------------------------------------------------

