#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[]) {
	char* err;

	if (argc < 2)
		return EXIT_FAILURE;

	uint32_t number = strtol(argv[1], &err, 0);
	uint32_t bit    = strtol(argv[2], &err, 0);

	printf("bit %d of %08x is ", bit, number);

#ifdef NO_ASM_GOTO
	uint32_t bit_set;
	asm (
		"bt %2, %%eax		\n"
		"setc %%al			\n"
		"movzx %%al, %%eax	\n"
		: "=a" (bit_set)
		: "a" (number), "r" (bit)
		: "cc"
	);

	if (bit_set)
		goto has_bit;
#else
	asm goto (
		"bt %1, %0		\n"
		"jc %l[has_bit]	\n"

		: /* no output */
		: "r" (number), "r" (bit)
		: "cc"
		: has_bit // <<< name of label
	);
#endif

	puts("not set");
	return EXIT_SUCCESS;	

has_bit:
	puts("set");

	return EXIT_SUCCESS;	
}
