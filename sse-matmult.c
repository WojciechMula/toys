/*
	Matrix 4x4 multiplication using SSE instructions, $Revision: 1.1 $
	
	[Aa0 Aa1 Aa2 Aa3]  [Ba0 Ba1 Ba2 Ba3]   [Aa0*Ba0 + Aa1*Bb0 + Aa2*Bc0 + Aa3*Bd0, ..., ..., ...]
	[Ab0 Ab1 Ab2 Ab3]  [Bb0 Bb1 Bb2 Bb3] = [Ab0*Ba0 + Ab1*Bb0 + Ab2*Bc0 + Ab3*Bd0, ..., ..., ...]
	[Ac0 Ac1 Ac2 Ac3]  [Bc0 Bc1 Bc2 Bc3]   [..., ..., ..., ...]
	[Ad0 Ad1 Ad2 Ad3]  [Bd0 Bd1 Bd2 Bd3]   [..., ..., ..., ...]
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://www.mula.w.pl
	
	License: public domain
	
	initial release 15.09.2007, last update $Date: 2007-09-15 21:45:37 $
*/

#include <math.h>
#include "sse-aux.inc"

void sse_matmat_mult(float mat1[4*4], float mat2[4*4], float mat3[4*4]) {
asm(
    // load all rows from M2, i.e. Ba, Bb, Bc an Bd
    "movups 0x00(%1), %%xmm4	            \n" // xmm4 := Ba
    "movups 0x10(%1), %%xmm5                \n" // xmm5 := Bb
    "movups 0x20(%1), %%xmm6                \n" // xmm6 := Bc
    "movups 0x30(%1), %%xmm7                \n" // xmm7 := Bd

#define BLOCK(offset) \
    /* load n-th row from matrix M1, for example Aa, and clone it */ \
    "movups "#offset"(%0), %%xmm0           \n" /* xmm0 := Aa */ \
    "movaps %%xmm0, %%xmm1                  \n" \
    "movaps %%xmm0, %%xmm2                  \n" \
    "movaps %%xmm0, %%xmm3                  \n" \
    /* populate each element */ \
    "shufps $0b00000000, %%xmm0, %%xmm0     \n" /* xmm0 := [Aa0, Aa0, Aa0, Aa0] */ \
    "shufps $0b01010101, %%xmm1, %%xmm1     \n" /* xmm1 := [Aa1, Aa1, Aa1, Aa1] */ \
    "shufps $0b10101010, %%xmm2, %%xmm2     \n" /* xmm2 := [Aa2, Aa2, Aa2, Aa2] */ \
    "shufps $0b11111111, %%xmm3, %%xmm3     \n" /* xmm3 := [Aa3, Aa3, Aa3, Aa3] */ \
    /* and mul by all M2 rows */ \
    "mulps %%xmm4, %%xmm0                   \n" /* xmm0 := [Aa0*Ba0, Aa0*Ba1, Aa0*Ba2, Aa0*Ba3] */ \
    "mulps %%xmm5, %%xmm1                   \n" \
    "mulps %%xmm6, %%xmm2                   \n" \
    "mulps %%xmm7, %%xmm3                   \n" \
    /* finally calculate n-th row of resultant matrix */ \
    "addps %%xmm1, %%xmm0                   \n" \
    "addps %%xmm3, %%xmm2                   \n" \
    "addps %%xmm2, %%xmm0                   \n" \
    "movups %%xmm0, "#offset"(%2)           \n"

    BLOCK(0x00)
    BLOCK(0x10)
    BLOCK(0x20)
    BLOCK(0x30)
    :
    : "r" (mat1), "r" (mat2), "r" (mat3)
);
}


void matmat_mult(float mat1[4*4], float mat2[4*4], float mat3[4*4]) {
	int i, j, k;
	for (j=0; j<4; j++) {
		for (i=0; i<4; i++) {
			mat3[i+4*j] = 0.0;
			for (k=0; k<4; k++) {
				mat3[i+4*j] += mat1[k+4*j] * mat2[i+4*k];
			}
		}
	}
}

int main(int argc, char* argv[]) {
	float mat1[4*4], mat2[4*4], res1[4*4], res2[4*4], err[4*4];
	float range = 0.0;
	int i;

	initfrand();
	if (argc > 1)
		range = fabs(atof(argv[1]));
	if (range == 0.0)
		range = 1000.0;

	for (i=0; i<16; i++) {
		mat1[i] = frand(-range, range);
		mat2[i] = frand(-range, range);
	}

	sse_matmat_mult(mat1, mat2, res2);
	matmat_mult(mat1, mat2, res1);
	
	printf("ref = \n");
	for (i=0; i<4; i++) print_vect(&res1[4*i]);
	
	printf("SSE = \n");
	for (i=0; i<4; i++) print_vect(&res2[4*i]);

	printf("err [%%] = \n");
	for (i=0; i<16; i++) err[i] = 100.0 * (1.0 - res1[i]/res2[i]);
	for (i=0; i<4; i++) print_vect(&err[4*i]);

	return 0;
}

// vim: ts=8 nowrap
