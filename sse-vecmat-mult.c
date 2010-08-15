/*
	Multiply vector 1x4 by matrix 4x4 using SSE instructions
	$Revision: 1.4 $
	
		       [a0, a1, a2, a3]   [x*a0 + y*b0 + z*c0 + w*d0]
		       [b0, b1, b2, b3]   [x*a1 + y*b1 + z*c1 + w*d1]
	[x, y, z, w] * [              ] = [                         ]
		       [c0, c1, c2, c3]   [x*a2 + y*b2 + z*c2 + w*d2]
		       [d0, d1, d2, d3]   [x*a3 + y*b3 + z*c3 + w*d3]
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/
	
	License: public domain
	
	initial release 12.03.2002, last update $Date: 2008-06-08 23:00:44 $
*/


#include "sse-aux.c"

// start-snippet
void sse_vecmat_mult(float mat[4*4], float vec[4], float result[4]) {
__asm__ volatile (
   // load vector
   "movups (%1), %%xmm4                    \n" // xmm4 := [x, y, z, w] = V
   "movaps %%xmm4, %%xmm5                  \n"
   "movaps %%xmm4, %%xmm6                  \n"
   "movaps %%xmm4, %%xmm7                  \n"

   // load matrix
   "movups 0x00(%0), %%xmm0                \n" // xmm0 := [a0, a1, a2, a3] = A
   "movups 0x10(%0), %%xmm1                \n" // xmm1 := [b0, b1, b2, b3] = B
   "movups 0x20(%0), %%xmm2                \n" // xmm2 := [c0, c1, c2, c3] = C
   "movups 0x30(%0), %%xmm3                \n" // xmm3 := [d0, d1, d2, d3] = D

   // populate coords in vectors
   "shufps $0b00000000, %%xmm4, %%xmm4     \n" // xmm4 := [x, x, x, x]
   "shufps $0b01010101, %%xmm5, %%xmm5     \n" // xmm5 := [y, y, y, y]
   "shufps $0b10101010, %%xmm6, %%xmm6     \n" // xmm6 := [z, z, z, z]
   "shufps $0b11111111, %%xmm7, %%xmm7     \n" // xmm7 := [w, w, w, w]

   // multiply all rows by vector
   "mulps %%xmm4, %%xmm0                   \n" // xmm0 := [x*a0, x*a1, x*a2, x*a3]
   "mulps %%xmm5, %%xmm1                   \n" // xmm1 := [y*b0, y*b1, y*b2, y*b3]
   "mulps %%xmm6, %%xmm2                   \n" // xmm2 := [z*c0, z*c1, z*c2, z*c3]
   "mulps %%xmm7, %%xmm3                   \n" // xmm3 := [w*d0, w*d1, w*d2, w*d3]

   // finally calc dot products
   "addps %%xmm1, %%xmm0                   \n"
   "addps %%xmm3, %%xmm2                   \n"
   "addps %%xmm2, %%xmm0                   \n"

   // save result
   "movups %%xmm0, (%2)                    \n"
   :
   : "r" (mat), "r" (vec), "r" (result)
   : "memory"
);
}
// end-snippet


void vecmat_mult(float mat[4*4], float vec[4], float result[4]) {
	int i, j;
	for (i=0; i<4; i++) result[i] = 0.0;
	for (j=0; j<4; j++)
		for (i=0; i<4; i++)
			result[j] += vec[i] * mat[j+4*i];
}


int main() {
	int i;
	float mat[4*4], vec[4], res1[4], res2[4], err[4];

	initfrand();
	for (i=0; i<16; i++)
		mat[i] = frand(-1000, 1000);
	for (i=0; i<4; i++)
		vec[i] = frand(-1000, 1000);

	sse_vecmat_mult(mat, vec, res2);
	vecmat_mult(mat, vec, res1);
	
	for (i=0; i<4; i++) err[i] = 100.0 * (1.0 - res1[i]/res2[i]);
	printf("    ref = ");  print_vec_float(res1);
	printf("    SSE = ");  print_vec_float(res2);
	printf("err [%%] = "); print_vec_float(err);
	return 0;
}

// vim: ts=8 nowrap
