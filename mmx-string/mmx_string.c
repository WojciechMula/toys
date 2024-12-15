/*
	$Date: 2008-06-08 23:00:44 $, $Revision: 1.6 $

	MMX routines performing few string.h function

	Functions mmx_strcmp2, mmx_strlen2 and mmx_strchr2 are same as
	"regular" functions (i.e. mmx_strcmp, mmx_strlen, mmx_strchr), but
	do not use pmovmskb instruction and thus are able to run on older
	processor: Pentium MMX and Pentium II.


	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	License: public domain
*/

#include <stdlib.h>
#include <stdint.h>

////////////////////////////////////////////////////////////////////////

int mmx_strcmp(const char* a, const char* b) {
	int pos;
	
	__asm__ volatile(
	"pxor    %%mm5, %%mm5         \n\t" // mm5 := pb(0x00)
	"pcmpeqb %%mm6, %%mm6         \n\t" // mm6 := pb(0xff)

	"1:\n\t"

	"	movq    (%%edi), %%mm0    \n\t" // A := load 8 bytes
	"	movq    (%%esi), %%mm1    \n\t" // B := load 8 bytes
	"	addl    $8,    %%edi      \n\t"
	"	addl    $8,    %%esi      \n\t"

	"	movq     %%mm0, %%mm2     \n\t" // save A
	"	pcmpeqb  %%mm1, %%mm0     \n\t" // mm0 := (A[i] == B[i]) ? 0xff : 0x00
	"	pcmpeqb  %%mm5, %%mm1     \n\t" // mm1 := (A[i] == 0x00) ? 0xff : 0x00
	"	pcmpeqb  %%mm5, %%mm2     \n\t" // mm2 := (B[i] == 0x00) ? 0xff : 0x00
	"	pxor     %%mm6, %%mm0     \n\t" // negate mm0 (0xff on different bytes)
	"	por      %%mm1, %%mm0     \n\t"
	"	por      %%mm2, %%mm0     \n\t" // mm0 := mm0 | mm1 | mm2 -> 0xff on different bytes or null in A or B

	"	pmovmskb %%mm0, %%eax     \n\t" 
	"	or       %%eax, %%eax     \n\t"
	"	jz       1b               \n\t"
	
	"bsf      %%eax, %%ebx            \n\t"
	"movzx    -8(%%edi, %%ebx), %%eax \n\t" // eax := string_a[edi+ebx-8]
	"movzx    -8(%%esi, %%ebx), %%ebx \n\t" // ebx := string_b[esi+ebx-8]
	"subl     %%ebx, %%eax            \n\t"
	
	: "=a" (pos)
	: "D" (a), "S" (b)
	: "%ebx"
	);

	return pos;
}


size_t mmx_strlen(const char* s) {
	size_t len;

	__asm__ volatile(
	"	pxor     %%mm6, %%mm6       \n\t" // mm6 := pb(0x00)

	"	leal     8(%%esi),  %%ebx   \n\t" // save esi + 8
	"1:   \n\t"
	"	movq    (%%esi), %%mm0   \n\t" // load 8 bytes
	"	addl     $8,     %%esi   \n\t"
	"	pcmpeqb  %%mm6,  %%mm0   \n\t" // mm0 = (byte == 0x00) ? 0xff : 0x00

	"	pmovmskb %%mm0,  %%eax   \n\t"
	"	or       %%eax,  %%eax   \n\t" // loop over, if no \000 found, i.e. mask zero
	"	jz       1b   \n\t"

	"bsf  %%eax, %%eax   \n\t" // eax := bsf(eax)/4
	"subl %%ebx, %%esi   \n\t" // esi := esi - ebx
	"addl %%esi, %%eax   \n\t" // eax := esi + eax

	: "=a" (len)
	: "S"  (s)
	: "%ebx"
	);

	return len;
}


char* mmx_strchr(const char* s, int c) {
	char* ptr;

	__asm__ volatile(
	"	pxor      %%mm6, %%mm6   \n\t"

	"	movb      %%al,  %%ah    \n\t"
	"	movd      %%eax, %%mm5   \n\t"
	"	punpcklbw %%mm5, %%mm5   \n\t"
	"	punpcklbw %%mm5, %%mm5   \n\t" // mm5 := pb(al)

	"1:   \n\t"
	"	movq    (%%esi), %%mm0   \n\t"	// load 8 bytes
	"	addl     $8,     %%esi   \n\t"
	"	movq     %%mm0,  %%mm1   \n\t"	// mm1 := mm0
	"	pcmpeqb  %%mm6,  %%mm0   \n\t"	// mm0 := (char == 0x00) ? 0xff : 0x00
	"	pcmpeqb  %%mm5,  %%mm1   \n\t"  // mm1 := (char == c) ? 0xff : 0x00
	"	por      %%mm1,  %%mm0   \n\t"	// combine mm0 | mm0

	"	pmovmskb %%mm0,  %%eax   \n\t"
	"	or       %%eax,  %%eax   \n\t"	// loop over, if no \000 found, i.e. mask is zero
	"	jz       1b              \n\t"

	"bsf  %%eax, %%eax            \n\t"
	"leal -8(%%esi, %%eax), %%eax \n\t" // eax := esi + eax - 8

	: "=a" (ptr)
	: "S"  (s), "a" (c)
	);

	if (*ptr) return ptr;
	else      return NULL;
}


////////////////////////////////////////////////////////////////////////

uint16_t __mask[4] = {0x0011, 0x0011, 0x0011, 0x0011};

int mmx_strcmp2(const char* a, const char* b) {
	int pos;

	__asm__ volatile(
	"pxor    %%mm5, %%mm5         \n\t" // mm5 := pb(0x00)
	"pcmpeqb %%mm6, %%mm6         \n\t" // mm6 := pb(0xff)
	"movq    (%0),  %%mm7         \n\t" // mm7 := pw(0x0011)
	:
	: "r" (__mask)
	);
	
	__asm__ volatile(
	"1:\n\t"

	"	movq    (%%edi), %%mm0    \n\t" // A := load 8 bytes
	"	movq    (%%esi), %%mm1    \n\t" // B := load 8 bytes
	"	addl    $8,    %%edi      \n\t"
	"	addl    $8,    %%esi      \n\t"

	"	movq     %%mm0, %%mm2     \n\t" // save A
	"	pcmpeqb  %%mm1, %%mm0     \n\t" // mm0 := (A[i] == B[i]) ? 0xff : 0x00
	"	pcmpeqb  %%mm5, %%mm1     \n\t" // mm1 := (A[i] == 0x00) ? 0xff : 0x00
	"	pcmpeqb  %%mm5, %%mm2     \n\t" // mm2 := (B[i] == 0x00) ? 0xff : 0x00
	"	pxor     %%mm6, %%mm0     \n\t" // negate mm0 (0xff on different bytes)
	"	por      %%mm1, %%mm0     \n\t"
	"	por      %%mm2, %%mm0     \n\t" // mm0 := mm0 | mm1 | mm2 -> 0xff on different bytes or null in A or B

	                                        // sample
					        // mm0 := |ff|00|ff|ff|00|00|00|00|
	"	psrlq    $4,    %%mm0     \n\t" // mm0 := |0f|f0|0f|ff|f0|00|00|00|
	"	pand     %%mm7, %%mm0     \n\t" // mm0 := |00|10|00|11|00|00|00|00|
	"	packsswb %%mm0, %%mm0     \n\t" // mm0 := |..|..|..|..|10|11|00|00|
	"	movd     %%mm0, %%eax     \n\t" // eax := |10|11|00|00|
	"	or       %%eax, %%eax     \n\t"
	"	jz       1b               \n\t"
	
	"bsf      %%eax, %%ebx            \n\t" // ebx := 16
	"shr      $2,    %%ebx            \n\t" // ebx := 16/4 = 4
	"movzx    -8(%%edi, %%ebx), %%eax \n\t" // eax := string_a[edi+ebx-8]
	"movzx    -8(%%esi, %%ebx), %%ebx \n\t" // ebx := string_b[esi+ebx-8]
	"subl     %%ebx, %%eax            \n\t"
	
	: "=a" (pos)
	: "D" (a), "S" (b)
	: "%ebx"
	);

	return pos;
}


size_t mmx_strlen2(const char* s) {
	size_t len;

	__asm__ volatile(
	"pxor    %%mm6, %%mm6            \n\t" // mm6 := pb(0x00)
	"movq    (%0),  %%mm7            \n\t" // mm7 := pw(0x0011)
	:
	: "r" (__mask)
	);
	__asm__ volatile(
	"	leal     8(%%esi),  %%ebx   \n\t"	// save esi + 8
	"1:   \n\t"
	"	movq    (%%esi), %%mm0   \n\t"	// load 8 bytes
	"	addl     $8,     %%esi   \n\t"
	"	pcmpeqb  %%mm6,  %%mm0   \n\t"	// mm0 = (byte == 0x00) ? 0xff : 0x00

	"	psrlq    $4,     %%mm0   \n\t"	// convert 8-byte mask 
	"	pand     %%mm7,  %%mm0   \n\t"	// to 32-bit mask
	"	packsswb %%mm0,  %%mm0   \n\t"
	
	"	movd     %%mm0,  %%eax   \n\t"
	"	or       %%eax,  %%eax   \n\t"	// loop over, if no \000 found, i.e. mask zero
	"	jz       1b   \n\t"

	"bsf  %%eax, %%eax   \n\t" // eax := bsf(eax)/4
	"shr  $2,    %%eax   \n\t"
	"subl %%ebx, %%esi   \n\t" // esi := esi - ebx
	"addl %%esi, %%eax   \n\t" // eax := esi + eax

	: "=a" (len)
	: "S"  (s)
	: "%ebx"
	);

	return len;
}


char* mmx_strchr2(const char* s, int c) {
	char* ptr;

	__asm__ volatile(
	"pxor    %%mm6, %%mm6        \n\t" // mm6 := pb(0x00)
	"movq    (%0),  %%mm7        \n\t" // mm7 := pw(0x0011)
	:
	: "r" (__mask)
	);
	__asm__ volatile(
	

	"	movb      %%al, %%ah     \n\t"
	"	movd      %%eax, %%mm5   \n\t"
	"	punpcklbw %%mm5, %%mm5   \n\t"
	"	punpcklbw %%mm5, %%mm5   \n\t" // mm5 := pb(al)

	"1:   \n\t"
	"	movq    (%%esi), %%mm0   \n\t"	// load 8 bytes
	"	addl     $8,     %%esi   \n\t"
	"	movq     %%mm0,  %%mm1   \n\t"	// mm1 := mm0
	"	pcmpeqb  %%mm6,  %%mm0   \n\t"	// mm0 := (char == 0x00) ? 0xff : 0x00
	"	pcmpeqb  %%mm5,  %%mm1   \n\t"  // mm1 := (char == c) ? 0xff : 0x00
	"	por      %%mm1,  %%mm0   \n\t"	// combine mm0 | mm0

	"	psrlq    $4,     %%mm0   \n\t"	// convert 8-byte mask 
	"	pand     %%mm7,  %%mm0   \n\t"	// to 32-bit mask
	"	packsswb %%mm0,  %%mm0   \n\t"
	
	"	movd     %%mm0,  %%eax   \n\t"
	"	or       %%eax,  %%eax   \n\t"	// loop over, if no \000 found, i.e. mask is zero
	"	jz       1b              \n\t"

	"bsf  %%eax, %%eax            \n\t" // eax := bsf(eax)/4
	"shr  $2,    %%eax            \n\t"
	"leal -8(%%esi, %%eax), %%eax \n\t" // eax := esi + eax - 8

	: "=a" (ptr)
	: "S"  (s), "a" (c)
	);

	if (*ptr) return ptr;
	else      return NULL;
}



// vim: ts=4 sw=4 nowrap
