/*
	SSE4.1 insertion sort, $Revision: 1.2 $
	
	Using instruction PHMINPOSUW as key part
	of insertion sort.  Weird.
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://www.republika.pl/wmula/
	
	License: BSD
	
	initial release 31-08-2008, last update $Date: 2008-08-31 16:33:28 $
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/*** SSE4.1 *************************************************************/
// snippet-start
typedef uint16_t table[8];

table max[8] = {
	{0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff}
};

void sse4_sort(table T) {
	uint32_t dummy;

	__asm__ volatile (
	"	movdqu (%%eax), %%xmm0		\n"
	"	xor %%ecx, %%ecx		\n"	// i = 0
	"1:					\n"
	"	phminposuw %%xmm0, %%xmm1	\n"	// find min, and its index j
	"	movd %%xmm1, %%edx		\n"
	"	movw   %%dx, (%%eax, %%ecx, 2)	\n"	// save min at i-th position
	"					\n"
	"	shrl   $16, %%edx		\n"
	"	shll    $4, %%edx		\n"
	"					\n"
	"	por  max(%%edx), %%xmm0		\n"	// set max at pisition j
	"					\n"
	"	addl    $1, %%ecx		\n"	// i += 1
	"	cmp     $8, %%ecx		\n"
	"	jl      1b			\n"
	
	:
	: "a" (T)
	: "ecx", "edx"
	);
}
// snippet-end

/*** standard sort ******************************************************/
int cmp_uint16_t(uint16_t* x, uint16_t* y) {
	if ((*x) < (*y))
		return -1;
	else
	if ((*x) > (*y))
		return +1;
	else
		return  0;
}


void sort(table T) {
	qsort(T, 8, sizeof(T[0]), cmp_uint16_t);
}


int cmp(table T1, table T2) {
	int i;
	for (i=0; i < 8; i++)
		if (T1[i] != T2[i])
			return 0;
	
	return 1;
}


/*** main ***************************************************************/
void print(table T) {
	int i;

	printf("[0x%04x", T[0]);
	for (i=1; i < 8; i++)
		printf(", 0x%04x", T[i]);
	printf("]\n");
}


int main(int argc, char* argv[]) {
	if (argc > 1) {
		srand(atoi(argv[1]));
	}
	else
		srand(time(NULL));

	table T1, T2;

	int i;
	for (i=0; i < 8; i++) {
		T1[i] = T2[i] = rand();
	}

	printf("table = ");
	print(T1);

	sse4_sort(T1);
	sort(T2);

	printf("SSE4  = ");
	print(T1);
	
	printf("qsort = ");
	print(T2);

	printf("result: %s\n", cmp(T1, T2) ? "ok" : "!!!FAILED");

	return 0;
}

