/*
	Transpose 4x4 matrix (in-place) using SSE instructions, $Revision: 1.1 $
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://www.mula.w.pl
	
	License: public domain
	
	initial release 10.03.2002, last update $Date: 2007-09-13 17:16:46 $
*/

#include "sse-aux.inc"

void sse_transpose(float mat[4*4]) {
asm(
                                 //         0  1  2  3 <- index
	"movups 0x00(%0), %%xmm0 \n" // xmm0 := a0 a1 a2 a3
	"movups 0x10(%0), %%xmm1 \n" // xmm1 := b0 b1 b2 b3
	"movups 0x20(%0), %%xmm2 \n" // xmm2 := c0 c1 c2 c3
	"movups 0x30(%0), %%xmm3 \n" // xmm3 := d0 d1 d2 d3

	"movaps   %%xmm0, %%xmm4 \n"
	"unpcklps %%xmm2, %%xmm0 \n" // xmm0 := a0 c0 a1 c1
	"unpckhps %%xmm2, %%xmm4 \n" // xmm4 := a2 c2 a3 c3

	"movaps   %%xmm1, %%xmm2 \n"
	"unpcklps %%xmm3, %%xmm1 \n" // xmm1 := b0 d0 b1 d1
	"unpckhps %%xmm3, %%xmm2 \n" // xmm2 := b2 d2 b3 d3

	"movaps   %%xmm0, %%xmm3 \n"
	"unpcklps %%xmm1, %%xmm0 \n" // xmm0 := a0 b0 c0 d0
	"unpckhps %%xmm1, %%xmm3 \n" // xmm3 := a1 b1 c1 d1

	"movaps   %%xmm4, %%xmm1 \n"
	"unpcklps %%xmm2, %%xmm1 \n" // xmm1 := a2 b2 c2 d2
	"unpckhps %%xmm2, %%xmm4 \n" // xmm4 := a3 b3 c3 d3

	"movups %%xmm0, 0x00(%0) \n"
	"movups %%xmm3, 0x10(%0) \n"
	"movups %%xmm1, 0x20(%0) \n"
	"movups %%xmm4, 0x30(%0) \n"
	: "=r" (mat)
	: "0" (mat)
	: "memory"
);
}

int main() {
	srand(time(NULL));
	float mat[4*4];
	int i=0;
	for (i=0; i < 4*4; i++)
		mat[i] = i;

	printf("M = \n");
	for (i=0; i < 4; i++) print_vect(&mat[i*4]);

	sse_transpose(mat);

	printf("M^T = \n");
	for (i=0; i < 4; i++) print_vect(&mat[i*4]);

	return 0;
}

// vim: ts=4 sw=4 nowrap
