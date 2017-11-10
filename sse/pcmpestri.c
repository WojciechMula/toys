#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <sys/time.h>

unsigned gettime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return (tv.tv_sec * 1000000 + tv.tv_usec)/1000;
}
//---------------------------------------------------------------------------

/* imm8 defs: */
#define SSESTR_PACKED_UBYTE     0               /* element size */
#define SSESTR_PACKED_UWORD     0b01
#define SSESTR_PACKED_SBYTE     0b10
#define SSESTR_PACKED_SWORD     0b11

#define SSESTR_EQUAL_ANY        0               /* compare method */
#define SSESTR_EQUAL_EACH       0b1000
#define SSESTR_EQUAL_ORDERED    0b1100
#define SSESTR_RANGES           0b0100

#define SSESTR_UNCHANGED        0               /* IntRes1 polariy */
#define SSESTR_UNCHANGED2       0b100000
#define SSESTR_NEGATED          0b010000
#define SSESTR_NEGATED_VALID    0b110000

#define SSESTR_BITMASK          0               /* output selection */
#define SSESTR_BYTEMASK         0b1000000       /* for PCMPxSTRM */

#define SSESTR_FIRSTBIT         0               /* output selection */
#define SSESTR_LASTBIT          0b1000000       /* for PCMPxSTRI */

#define imm8 SSESTR_EQUAL_ANY | SSESTR_BYTEMASK
/*           SSESTR_PACKED_UBYTE  | \
             SSESTR_EQUAL_EACH    | \
             SSESTR_NEGATED       | \
             SSESTR_BYTEMASK
*/
char buffer[16];

void pcmpestrm_debug(const char* s1, const char* s2, int len1, int len2)
{
    int ecx;
    int eax;
#define LAHF_CF (0b00000001 << 8)
#define LAHF_PF (0b00000100 << 8)
#define LAHF_AF (0b00010000 << 8)
#define LAHF_ZF (0b01000000 << 8)
#define LAHF_SF (0b10000000 << 8)
#define LAHF_OF 1


    __asm__ __volatile__ (
        "movups  (%%rsi), %%xmm1                \n"
        "movups  (%%rdi), %%xmm2                \n"
        "xor      %%rcx, %%rcx                  \n"
        "pcmpestrm %[setup], %%xmm2, %%xmm1     \n"
        "lahf                                   \n"
        "seto %%al                              \n"
        "movdqu  %%xmm0, buffer                 \n"
        : "=c" (ecx),
          "=a" (eax)
        : "S" (s1),
          "D" (s2),
          "a" (len1),
          "d" (len2),
          [setup] "i" (imm8)
        : "memory"
    );

    printf("s1  = '%s'\n", s1); 
    printf("len1= %d\n", len1);
    printf("s2  = '%s'\n", s2); 
    printf("len2= %d\n", len2);
    printf("mask=  ");
    for (int i = 0; i < 16; i++) {
        putchar(buffer[i] ? '1' : '_');
    }
    putchar('\n');

    printf("ecx = %d\n", ecx);
    printf("eax = %x\n", eax);
    printf(" CF = %d\n", (eax & LAHF_CF) != 0);
    printf(" ZF = %d\n", (eax & LAHF_ZF) != 0);
    printf(" SF = %d\n", (eax & LAHF_SF) != 0);
    printf(" OF = %d\n", (eax & LAHF_OF) != 0);
    printf(" AF = %d\n", (eax & LAHF_AF) != 0);
}

int main(int argc, char* argv[])
{
    if (argc < 5) {
        return EXIT_FAILURE;
    }

#define s1 argv[1]
#define s2 argv[2]
    
    int len1 = atoi(argv[3]);
    int len2 = atoi(argv[4]);

    int tmp;

    tmp = strlen(s1); if (len1 > tmp) len1 = tmp;
    tmp = strlen(s2); if (len2 > tmp) len2 = tmp;

    pcmpestrm_debug(s1, s2, len1, len2);

    return EXIT_SUCCESS;
}

