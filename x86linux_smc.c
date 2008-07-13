// Self modyfing code under x86 Linux
//
// by Wojciech Mu³a, http://www.republika.pl/wmula
// $Date: 2008-07-13 20:52:42 $, $Revision: 1.1 $

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <sys/mman.h>


// snippet-start
uint32_t function() {
	uint32_t result;

	__asm__ volatile (
	"smc_address:			\n"	// global label
	"	mov $0xbadcaffe, %%eax	\n"	// instruction we will patch
	: "=a" (result)
	);

	return result;
}


int main(int argc, char* argv[]) {
	uint32_t patch_val;

	if (argc > 1)
		patch_val = strtol(argv[1], NULL, 0);
	else
		patch_val = 0x11223344;

	printf("Before patch function() returned 0x%08x\n", function());

	// obtain global label address
	uint32_t address;
	__asm__ volatile ("mov $smc_address, %%eax" : "=a" (address));


	// change page rights
	// address must be aligned at page boundary
	if (mprotect((void*)(address & 0xfffff000), 4096, PROT_EXEC | PROT_WRITE | PROT_READ)) {
		printf("mprotect: %s\n", strerror(errno));
		return 1;
	}


	printf("Argument of mov instruction: 0x%08x\n", patch_val);

	// change argument of mov instruction (opcode: b8 xx yy zz ww)
	*(uint32_t*)(address+1) = patch_val;


	printf("After patch function() returned 0x%08x\n", function());
	return 0;
}
// snippet-end

// eof
