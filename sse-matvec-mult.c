/*
	Multiply matrix 4x4 by vector 4x1 using SSE instructions,
	$Revision: 1.2 $

	[a0, a1, a2, a3]   [x]   [a0*x + a1*y + a*z + a3]
	[b0, b1, b2, b3]   [y]   [b0*x + b1*y + b*z + b3]
	[              ] * [ ] = [                      ]
	[c0, c1, c2, c3]   [z]   [c0*x + c1*y + c*z + c3]
	[d0, d1, d2, d3]   [w]   [d0*x + d1*y + d*z + d3]

	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://www.mula.w.pl

	License: public domain

	initial release 10.03.2007, last update $Date: 2007-09-15 12:59:33 $
*/

#include "sse-aux.inc"

// start-snippet
void sse_matvec_mult(float mat[4*4], float vec[4], float result[4]) {
asm(
   // load vector
   "movups (%1), %%xmm4                    \n" // xmm4 := [x, y, w, z] = V

   // load matrix
   "movups 0x00(%0), %%xmm0                \n" // xmm0 := [a0, a1, a2, a3] = A
   "movups 0x10(%0), %%xmm1                \n" // xmm1 := [b0, b1, b2, b3] = B
   "movups 0x20(%0), %%xmm2                \n" // xmm2 := [c0, c1, c2, c3] = C
   "movups 0x30(%0), %%xmm3                \n" // xmm3 := [d0, d1, d2, d3] = D

   // multiply all rows by vector
   "mulps %%xmm4, %%xmm0                   \n" // xmm0 := A*V
   "mulps %%xmm4, %%xmm1                   \n" // xmm1 := B*V
   "mulps %%xmm4, %%xmm2                   \n" // xmm2 := C*V
   "mulps %%xmm4, %%xmm3                   \n" // xmm3 := D*V

   // finally calc dot products
   "movaps   %%xmm0, %%xmm4                \n" // save A
   "unpcklps %%xmm1, %%xmm0                \n" // xmm0 := [a0, b0, a1, b1]
   "unpckhps %%xmm1, %%xmm4                \n" // xmm4 := [a2, b2, a3, b3] (xmm1 is free)
   "                                       \n"
   "movaps   %%xmm2, %%xmm1                \n" // save C
   "unpcklps %%xmm3, %%xmm2                \n" // xmm2 := [c0, d0, c1, d1]
   "unpckhps %%xmm3, %%xmm1                \n" // xmm1 := [c2, d2, c3, d3] (xmm3 is free)
   "                                       \n"
   "addps    %%xmm4, %%xmm0                \n" // xmm0 := [a0+a2, b0+b2, a1+a3, b1+b3] (xmm4 is free)
   "addps    %%xmm2, %%xmm1                \n" // xmm1 := [c0+c2, bd+d2, c1+c3, d1+d3] (xmm2 is free)
   "                                       \n"
   "movaps   %%xmm0, %%xmm4                \n"
   "shufps $0b01000100, %%xmm1, %%xmm0     \n" // xmm0 := [a02, b02, c02, d02 ]
   "shufps $0b11101110, %%xmm1, %%xmm4     \n" // xmm4 := [a13, b13, c13, d13 ]
   "                                       \n"
   "addps    %%xmm4, %%xmm0                \n" // xmm0 := [a0123, b0123, c0123, d0123]
   "movups   %%xmm0, (%2)                  \n"
   "0:                                     \n"
   :
   : "r" (mat), "r" (vec), "r" (result)
   : "memory"
);
}
// end-snippet


void matvec_mult(float mat[4*4], float vec[4], float result[4]) {
	int i, j;
	for (i=0; i<4; i++) result[i] = 0.0;
	for (j=0; j<4; j++)
		for (i=0; i<4; i++)
			result[j] += vec[i] * mat[4*j+i];
}


int main() {
	int i;
	float mat[4*4], vec[4], res1[4], res2[4], err[4];

	initfrand();
	for (i=0; i<16; i++)
		mat[i] = frand(-1000, 1000);
	for (i=0; i<4; i++)
		vec[i] = frand(-1000, 1000);

	sse_matvec_mult(mat, vec, res2);
	matvec_mult(mat, vec, res1);

	for (i=0; i<4; i++) err[i] = 100.0 * (1.0 - res1[i]/res2[i]);
	printf("    ref = ");  print_vect(res1);
	printf("    SSE = ");  print_vect(res2);
	printf("err [%%] = "); print_vect(err);
	return 0;
}

// vim: ts=8 nowrap
