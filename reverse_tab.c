#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>

#include <sys/time.h>

unsigned gettime() {
        struct timeval tv;
        gettimeofday(&tv, NULL);

        return (tv.tv_sec * 1000000 + tv.tv_usec)/1000;
}
//-------------------------------------------------------

void swap_tab(char* c, size_t n) {
	char *a, *b, t;
	size_t i;

	a = c;
	b = c + n - 1;
	n = n/2;
	while (n--) {
		t  = *a;
		*a = *b;
		*b = t;

		a++;
		b--;
	}
}
//---------------------------------------------------------------------------

void swap_tab_asm(char* c, size_t n) {
	asm volatile (
		"	leal -1(%%esi,%%ecx), %%edi	\n"	// edi = last
		"	shrl $1, %%ecx 			\n"
		"	jz   1f				\n"
		"					\n"	
		"2:					\n"
		"	movb (%%esi), %%al		\n"
		"	movb (%%edi), %%bl		\n"
		"	movb %%bl, (%%esi)		\n"
		"	movb %%al, (%%edi)		\n"
		"	addl $1, %%esi			\n"
		"	subl $1, %%edi			\n"
		"	decl %%ecx			\n"
		"	jnz 2b				\n"
		"1:					\n"
		: /* no output */
		: "*S" (c), "*c" (n)
		: "eax", "ebx", "edi"
	);
}
//---------------------------------------------------------------------------

void swap_tab_bswap(char* c, size_t n) {
	asm volatile (
		/*					*/
		"	movl %%ecx, %%eax		\n"
		"	shr     $3, %%eax		\n"
		"	jz	2f			\n"
		"					\n"	// esi = i
		"	leal -4(%%esi, %%ecx), %%edi	\n"	// edi = n - i
		"	leal (%%esi, %%eax, 4), %%edx	\n"	// edx = i + n/2
		"					\n"	// esi = i
		"1:					\n"
		"	movl (%%esi), %%eax		\n"
		"	movl (%%edi), %%ebx		\n"
		"	bswap %%eax			\n"
		"	bswap %%ebx			\n"
		"	movl %%ebx, (%%esi)		\n"
		"	movl %%eax, (%%edi)		\n"
		"	addl $4, %%esi			\n"
		"	subl $4, %%edi			\n"
		"					\n"
		"	cmpl %%edx, %%esi		\n"
		"	jne  1b				\n"
		"					\n"

		/*	swap one byte per iteration	*/
		"	andl $0x7, %%ecx		\n"
		"	jz   9f				\n"
		"2:					\n"
		"	leal -1(%%esi,%%ecx), %%edi	\n"	// edi = last
		"	shrl $1, %%ecx 			\n"
		"	jz   9f				\n"
		"					\n"
		"3:					\n"
		"	movb (%%esi), %%al		\n"
		"	movb (%%edi), %%bl		\n"
		"	movb %%bl, (%%esi)		\n"
		"	movb %%al, (%%edi)		\n"
		"	addl $1, %%esi			\n"
		"	subl $1, %%edi			\n"
		"	decl %%ecx			\n"
		"	jnz 3b				\n"
		"9:					\n"
		: /* no output */
		: "S" (c), "c" (n)
		: "eax", "ebx", "edi", "edx"
	);
}
//---------------------------------------------------------------------------

void swap_tab_bswap_unrolled(char* c, size_t n) {
	asm volatile (
		"	movl %%ecx, %%eax		\n"
		"	shr     $4, %%eax		\n"
		"	jz	2f			\n"
		"					\n"
		"	pushl %%ebp			\n"
		"	pushl %%ecx			\n"
		"	leal -8(%%esi, %%ecx), %%edi	\n"
		"	shl     $3, %%eax		\n"
		"	leal (%%esi, %%eax),   %%ebp	\n"
		"1:					\n"
		"	movl  (%%esi), %%eax		\n"
		"	movl 4(%%esi), %%ebx		\n"
		"	movl  (%%edi), %%ecx		\n"
		"	movl 4(%%edi), %%edx		\n"
		"	bswap %%eax			\n"
		"	bswap %%ebx			\n"
		"	bswap %%ecx			\n"
		"	bswap %%edx			\n"
		"	movl %%ebx,  (%%edi)		\n"
		"	movl %%eax, 4(%%edi)		\n"
		"	movl %%edx,  (%%esi)		\n"
		"	movl %%ecx, 4(%%esi)		\n"
		"	addl $8, %%esi			\n"
		"	subl $8, %%edi			\n"
		"					\n"
		"	cmpl %%ebp, %%esi		\n"
		"	jne  1b				\n"
		"	popl %%ecx			\n"
		"	popl %%ebp			\n"

		/*	swap one byte per iteration	*/
		"	andl $0xf, %%ecx		\n"
		"	jz   9f				\n"
		"2:					\n"
		"	leal -1(%%esi,%%ecx), %%edi	\n"	// edi = last
		"	shrl $1, %%ecx 			\n"
		"	jz   9f				\n"
		"					\n"
		"3:					\n"
		"	movb (%%esi), %%al		\n"
		"	movb (%%edi), %%bl		\n"
		"	movb %%bl, (%%esi)		\n"
		"	movb %%al, (%%edi)		\n"
		"	addl $1, %%esi			\n"
		"	subl $1, %%edi			\n"
		"	decl %%ecx			\n"
		"	jnz 3b				\n"
		"9:					\n"
		: /* no output */
		: "S" (c), "c" (n)
		: "eax", "ebx", "edi", "edx"
	);
}
//---------------------------------------------------------------------------

void swap_tab_sse(char* c, size_t n) {
	asm volatile (
		"	movl %%ecx, %%eax		\n"
		"	andl $0xffffffe0, %%eax		\n"
		"	jz   2f				\n"
		"					\n"	// esi = o
		"	leal -16(%%esi, %%ecx), %%edi	\n"	// edi = n - i
		"	shrl $1, %%eax			\n"	// edx = i + n/2
		"	leal (%%esi, %%eax), %%edx	\n"
		"1:					\n"
		"	movups (%%esi), %%xmm0		\n"
		"	movups (%%edi), %%xmm1		\n"
		"					\n"
		"	movaps %%xmm0, %%xmm2		\n"
		"	movaps %%xmm1, %%xmm3		\n"
		"					\n"
		"	psrlw  $8, %%xmm0		\n"
		"	psrlw  $8, %%xmm1		\n"
		"	psllw  $8, %%xmm2		\n"
		"	psllw  $8, %%xmm3		\n"
		"					\n"
		"	por  %%xmm2, %%xmm0		\n"
		"	por  %%xmm3, %%xmm1		\n"
		"					\n"
		"	pshufd $0x4e, %%xmm0, %%xmm0	\n"
		"	pshufd $0x4e, %%xmm1, %%xmm1	\n"
		"					\n"
		"	pshuflw $0x1b, %%xmm0, %%xmm0	\n"
		"	pshufhw $0x1b, %%xmm0, %%xmm0	\n"
		"	pshuflw $0x1b, %%xmm1, %%xmm1	\n"
		"	pshufhw $0x1b, %%xmm1, %%xmm1	\n"
		"					\n"
		"	movups %%xmm1, (%%esi)		\n"
		"	movups %%xmm0, (%%edi)		\n"
		"					\n"
		"	addl $16, %%esi			\n"
		"	subl $16, %%edi			\n"
		"					\n"
		"	cmpl %%edx, %%esi		\n"
		"	jne  1b				\n"

		/*	swap one byte per iteration	*/
		"	andl $0x1f, %%ecx		\n"	// ecx = n % 32
		"	jz   9f				\n"
		"2:					\n"
		"	leal -1(%%esi,%%ecx), %%edi	\n"	// edi = last
		"	shrl $1, %%ecx 			\n"
		"	jz   9f				\n"
		"					\n"
		"3:					\n"
		"	movb (%%esi), %%al		\n"
		"	movb (%%edi), %%bl		\n"
		"	movb %%bl, (%%esi)		\n"
		"	movb %%al, (%%edi)		\n"
		"	addl $1, %%esi			\n"
		"	subl $1, %%edi			\n"
		"	decl %%ecx			\n"
		"	jnz 3b				\n"
		"9:					\n"
		: /* no output */
		: "S" (c), "c" (n)
		: "eax", "ebx", "edi", "edx"
	);
}
//---------------------------------------------------------------------------

void swap_tab_sse_unrolled(char* c, size_t n) {
	asm volatile (
		"	movl %%ecx, %%eax		\n"
		"	andl $0xffffffc0, %%eax		\n"
		"	jz   2f				\n"
		"					\n"
		"	leal -32(%%esi, %%ecx), %%edi	\n"
		"	shrl $1, %%eax			\n"
		"	leal (%%esi, %%eax), %%edx	\n"
		"1:					\n"
		"	movups   (%%esi), %%xmm0	\n"
		"	movups 16(%%esi), %%xmm1	\n"
		"	movups   (%%edi), %%xmm2	\n"
		"	movups 16(%%edi), %%xmm3	\n"
		"					\n"
		
		"	pshufd $0x4e, %%xmm0, %%xmm0	\n"	// reverse dwords
		"	pshufd $0x4e, %%xmm1, %%xmm1	\n"
		"	pshufd $0x4e, %%xmm2, %%xmm2	\n"
		"	pshufd $0x4e, %%xmm3, %%xmm3	\n"
		"					\n"
		"	pshuflw $0x1b, %%xmm0, %%xmm0	\n"	// reverse words
		"	pshufhw $0x1b, %%xmm0, %%xmm0	\n"
		"	pshuflw $0x1b, %%xmm1, %%xmm1	\n"
		"	pshufhw $0x1b, %%xmm1, %%xmm1	\n"
		"	pshuflw $0x1b, %%xmm2, %%xmm2	\n"
		"	pshufhw $0x1b, %%xmm2, %%xmm2	\n"
		"	pshuflw $0x1b, %%xmm3, %%xmm3	\n"
		"	pshufhw $0x1b, %%xmm3, %%xmm3	\n"
		"					\n"
		"	movaps %%xmm0, %%xmm4		\n"	// reverse bytes
		"	movaps %%xmm1, %%xmm5		\n"
		"	movaps %%xmm2, %%xmm6		\n"
		"	movaps %%xmm3, %%xmm7		\n"
		"					\n"
		"	psrlw  $8, %%xmm0		\n"
		"	psrlw  $8, %%xmm1		\n"
		"	psrlw  $8, %%xmm2		\n"
		"	psrlw  $8, %%xmm3		\n"
		"	psllw  $8, %%xmm4		\n"
		"	psllw  $8, %%xmm5		\n"
		"	psllw  $8, %%xmm6		\n"
		"	psllw  $8, %%xmm7		\n"
		"					\n"
		"	por  %%xmm4, %%xmm0		\n"	// combine results
		"	por  %%xmm5, %%xmm1		\n"
		"	por  %%xmm6, %%xmm2		\n"
		"	por  %%xmm7, %%xmm3		\n"
		"					\n"
		"	movups %%xmm3,   (%%esi)	\n"
		"	movups %%xmm2, 16(%%esi)	\n"
		"	movups %%xmm1,   (%%edi)	\n"
		"	movups %%xmm0, 16(%%edi)	\n"
		"					\n"
		"	addl $32, %%esi			\n"
		"	subl $32, %%edi			\n"
		"					\n"
		"	cmpl %%edx, %%esi		\n"
		"	jne  1b				\n"

		/*	swap one byte per iteration	*/
		"	andl $0x3f, %%ecx		\n"	// ecx = n % 32
		"	jz   9f				\n"
		"2:					\n"
		"	leal -1(%%esi,%%ecx), %%edi	\n"	// edi = last
		"	shrl $1, %%ecx 			\n"
		"	jz   9f				\n"
		"					\n"
		"3:					\n"
		"	movb (%%esi), %%al		\n"
		"	movb (%%edi), %%bl		\n"
		"	movb %%bl, (%%esi)		\n"
		"	movb %%al, (%%edi)		\n"
		"	addl $1, %%esi			\n"
		"	subl $1, %%edi			\n"
		"	decl %%ecx			\n"
		"	jnz 3b				\n"
		"9:					\n"
		: /* no output */
		: "S" (c), "c" (n)
		: "eax", "ebx", "edi", "edx"
	);
}
//---------------------------------------------------------------------------

void swap_tab_pshufb(char* c, size_t n) {
	static uint8_t rev[16] __attribute__((aligned(16))) =
		{15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};

	asm volatile ("movaps (%0), %%xmm7" : : "r" (rev));
	asm volatile (
		"	movl %%ecx, %%eax		\n"
		"	andl $0xffffffe0, %%eax		\n"
		"	jz   2f				\n"
		"					\n"	// esi = o
		"	leal -16(%%esi, %%ecx), %%edi	\n"	// edi = n - i
		"	shrl $1, %%eax			\n"	// edx = i + n/2
		"	leal (%%esi, %%eax), %%edx	\n"
		"1:					\n"
		"	movups (%%esi), %%xmm0		\n"
		"	movups (%%edi), %%xmm1		\n"
		"					\n"
		"	pshufb %%xmm7, %%xmm0		\n"
		"	pshufb %%xmm7, %%xmm1		\n"
		"					\n"
		"	movups %%xmm1, (%%esi)		\n"
		"	movups %%xmm0, (%%edi)		\n"
		"					\n"
		"	addl $16, %%esi			\n"
		"	subl $16, %%edi			\n"
		"					\n"
		"	cmpl %%edx, %%esi		\n"
		"	jne  1b				\n"

		/*	swap one byte per iteration	*/
		"	andl $0x1f, %%ecx		\n"	// ecx = n % 32
		"	jz   9f				\n"
		"2:					\n"
		"	leal -1(%%esi,%%ecx), %%edi	\n"	// edi = last
		"	shrl $1, %%ecx 			\n"
		"	jz   9f				\n"
		"					\n"
		"3:					\n"
		"	movb (%%esi), %%al		\n"
		"	movb (%%edi), %%bl		\n"
		"	movb %%bl, (%%esi)		\n"
		"	movb %%al, (%%edi)		\n"
		"	addl $1, %%esi			\n"
		"	subl $1, %%edi			\n"
		"	decl %%ecx			\n"
		"	jnz 3b				\n"
		"9:					\n"
		: /* no output */
		: "S" (c), "c" (n)
		: "eax", "ebx", "edi", "edx"
	);
}
//---------------------------------------------------------------------------

void swap_tab_pshufb_unrolled(char* c, size_t n) {
	static uint8_t rev[16] __attribute__((aligned(16))) =
		{15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};

	asm volatile ("movaps (%0), %%xmm7" : : "r" (rev));
	asm volatile (
		"	movl %%ecx, %%eax		\n"
		"	andl $0xffffffc0, %%eax		\n"
		"	jz   2f				\n"
		"					\n"
		"	leal -32(%%esi, %%ecx), %%edi	\n"
		"	shrl $1, %%eax			\n"
		"	leal (%%esi, %%eax), %%edx	\n"
		"1:					\n"
		"	movups   (%%esi), %%xmm0	\n"
		"	movups 16(%%esi), %%xmm1	\n"
		"	movups   (%%edi), %%xmm2	\n"
		"	movups 16(%%edi), %%xmm3	\n"
		"					\n"
		"	pshufb %%xmm7, %%xmm0		\n"
		"	pshufb %%xmm7, %%xmm1		\n"
		"	pshufb %%xmm7, %%xmm2		\n"
		"	pshufb %%xmm7, %%xmm3		\n"
		"					\n"
		"	movups %%xmm3,   (%%esi)	\n"
		"	movups %%xmm2, 16(%%esi)	\n"
		"	movups %%xmm1,   (%%edi)	\n"
		"	movups %%xmm0, 16(%%edi)	\n"
		"					\n"
		"	addl $32, %%esi			\n"
		"	subl $32, %%edi			\n"
		"					\n"
		"	cmpl %%edx, %%esi		\n"
		"	jne  1b				\n"

		/*	swap one byte per iteration	*/
		"	andl $0x3f, %%ecx		\n"
		"	jz   9f				\n"
		"2:					\n"
		"	leal -1(%%esi,%%ecx), %%edi	\n"	// edi = last
		"	shrl $1, %%ecx 			\n"
		"	jz   9f				\n"
		"					\n"
		"3:					\n"
		"	movb (%%esi), %%al		\n"
		"	movb (%%edi), %%bl		\n"
		"	movb %%bl, (%%esi)		\n"
		"	movb %%al, (%%edi)		\n"
		"	addl $1, %%esi			\n"
		"	subl $1, %%edi			\n"
		"	decl %%ecx			\n"
		"	jnz 3b				\n"
		"9:					\n"
		: /* no output */
		: "S" (c), "c" (n)
		: "eax", "ebx", "edi", "edx"
	);
}
//---------------------------------------------------------------------------

#define SIZE (1024*1024)

char tab1[SIZE];
char tab2[SIZE];
char tab3[SIZE];

void init_tabs(size_t n) {
	int i;
	char c;
	if (n < 256-'a')
		for (i=0; i < n; i++) {
			tab1[i] = tab2[i] = i + 'a';
		}
	else
		for (i=0; i < n; i++) {
			c = rand();
			tab1[i] = tab2[i] = c;
		}
}
//---------------------------------------------------------------------------

int cmp_tabs(size_t n) {
	return  (memcmp(tab1, tab2, n) == 0);
}
//---------------------------------------------------------------------------

void dump(char* tab, size_t n) {
	size_t i;
	int c;
	for (i=0; i < n; i++) {
		c = (tab[i]) & 0xff;
		if (c >= 'a' && c <= 'z')
			putchar(c);
		else
		if (c >= 'A' && c <= 'Z')
			putchar(c);
		else
		if (c >= '0' && c <= '9')
			putchar(c);
		else
			printf("%02x", c);
	}

	putchar('\n');
}
//---------------------------------------------------------------------------

typedef void (*swap_fun_t)(char*, size_t);
typedef struct {
	swap_fun_t	fun;
	char*		shortname;
	char*		name;
	unsigned	time;
} function_t;

function_t functions[] = {
	{swap_tab_asm,			"x86",		"x86 assembler implementation", 0},
	{swap_tab_bswap,		"bswap",	"asm: BSWAP", 0},
	{swap_tab_bswap_unrolled,	"bswap2",	"asm: 2 x BSWAP", 0},
	{swap_tab_sse,			"sse",		"asm: SEE2 implementation", 0},
	{swap_tab_sse_unrolled,		"sse2",		"asm: SEE2 implementation - unrolled loop", 0},
	{swap_tab_pshufb,		"pshufb",	"asm: SSSE3 - PSHUFB", 0},
	{swap_tab_pshufb_unrolled,	"pshufb2",	"asm: SSSE3 - 2 x PSHUFB", 0},
	{NULL, NULL, NULL, 0}
};

int function_idx(char* shortname) {
	int i;
	i = 0;
	while (functions[i].fun) {
		if (strcmp(shortname, functions[i].shortname) == 0)
			return i;
		else
			i += 1;
	}

	return -1;
}
//---------------------------------------------------------------------------

void usage(FILE* file) {
	int i;
	fprintf(file, "usage:\n");
	fprintf(file, "1. program v|verify offset table_size functions_list\n");
	fprintf(file, "2. program m|meausre offset table_size iterations functions_list\n");
	fprintf(file, "\n");
	fprintf(file, "offset in range 0..15\n");
	fprintf(file, "table_size in range 0..(%d - offset)\n", SIZE);
	fprintf(file, "functions:\n");
	
	i = 0;
	fprintf(file, "* all <special name>\n");
	while (functions[i].fun) {
		fprintf(file, "* %s: %s\n", functions[i].shortname, functions[i].name);
		i += 1;
	}

	exit(EXIT_FAILURE);
}
//---------------------------------------------------------------------------

void measure_single(int index, size_t table_size, size_t offset, size_t iterations) {
	swap_fun_t fun;
	unsigned t1, t2;
	size_t i;
	static char* ok = "ok";
	static char* error = "error";
	char* status;;
	
	fun = functions[index].fun;

	t1 = gettime();
	for (i=0; i < iterations; i++) {
		fun(tab2 + offset, table_size);
		fun(tab2 + offset, table_size);
	}
	t2 = gettime();
	functions[index].time = (t2 - t1);

	if (memcmp(tab2 + offset, tab1 + offset, table_size) == 0)
		status = ok;
	else
		status = error;
	
	if (functions[0].time > 0)
		printf("%20s %10dms (seedup: %8.2f): %s\n",
			functions[index].shortname,
			functions[index].time,
			(float)(functions[0].time)/functions[index].time,
			status
		);
	else
		printf("%20s %10dms: %s\n",
			functions[index].shortname,
			functions[index].time,
			status
		);
}
//---------------------------------------------------------------------------

void verify_single(int index, size_t table_size, size_t offset, size_t iterations) {
	memcpy(tab3 + offset, tab1, table_size);
	functions[index].fun(tab3 + offset, table_size);
	if (memcmp(tab2, tab3 + offset, table_size) == 0)
		printf("%s: ok\n", functions[index].shortname);
	else
		printf("%s: ERROR!!!\n", functions[index].shortname);
}
//---------------------------------------------------------------------------

int main(int argc, char* argv[]) {
	size_t i, j, n, k, offset;
	int  index;
	char mode = '?';

	if (argc > 2) {
		if (strcmp(argv[1], "v") == 0 || strcmp(argv[1], "verify") == 0)
			mode = 'v';
		else
		if (strcmp(argv[1], "m") == 0 || strcmp(argv[1], "measure") == 0)
			mode = 'm';
		else
		if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
			mode = 'h';

	}

	switch (mode) {
		case '?':
			usage(stderr);
			break;
		
		case 'h':
			usage(stdout);
			break;

		case 'v':
			if (argc > 4) {
				n = atoi(argv[2]);
				offset = atoi(argv[3]) % 16;
				printf("table size = %d, offset = %d\n", n, offset);
				
				init_tabs(n);
				memcpy(tab2, tab1, n);

				swap_tab(tab2, n);
				for (i=4; i < argc; i++) {
					index = function_idx(argv[i]);
					if (index >= 0)
						verify_single(index, n, offset, k);
					else
					if (strcmp(argv[i], "all") == 0) {
						index = 0;
						while (functions[index].fun) {
							verify_single(index, n, offset, k);
							index += 1;
						}
					}
					else {
						printf("unknown function name '%s'\n", argv[i]);
					}

				}
			}
			else
				usage(stderr);

			break;

		case 'm':
			if (argc > 5) {
				offset = atoi(argv[2]) % 16;
				n = atoi(argv[3]);
				k = atoi(argv[4]);
				
				printf("table size = %d, offset = %d, iterations count = %d\n", n, offset, k);
				
				init_tabs(n);
				memcpy(tab2, tab1, n);

				for (i=5; i < argc; i++) {
					index = function_idx(argv[i]);
					if (index >= 0)
						measure_single(index, n, offset, k);
					else
					if (strcmp(argv[i], "all") == 0) {
						index = 0;
						while (functions[index].fun) {
							measure_single(index, n, offset, k);
							index += 1;
						}
					}
					else {
						printf("unknown function name '%s'\n", argv[i]);
					}

				}
			}
			else
				usage(stderr);

			break;
	} // switch

	return 0;
}
//---------------------------------------------------------------------------
