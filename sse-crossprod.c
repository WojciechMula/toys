/*
	Calculate cross product using SSE instructions, $Revision: 1.1 $
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://www.mula.w.pl
	
	License: public domain
	
	initial release 11.03.2002, last update $Date: 2007-09-13 17:02:59 $
*/

#include "sse-aux.inc"

void cross_prod(float v1[4], float v2[4], float result[4]) {
#define a v1[0]
#define b v1[1]
#define c v1[2]
#define x v2[0]
#define y v2[1]
#define z v2[2]
	result[0] = b*z - c*y;
	result[1] = c*x - a*z;
	result[2] = a*y - b*x;
#undef a
#undef b
#undef c
#undef x
#undef y
#undef z
}

void sse_cross_prod(float v1[4], float v2[4], float result[4]) {
asm(
    // load vectors                                 index -> 0   1   2   3
    "movups (%0), %%xmm0                    \n" // xmm0 := | a | b | c | . |
    "movups (%1), %%xmm1                    \n" // xmm1 := | x | y | z | . |
    
	// clone
    "movaps %%xmm0, %%xmm2                  \n"
    "movaps %%xmm1, %%xmm3                  \n"

    // shuffle
    "shufps $0b00001001, %%xmm0, %%xmm0     \n" // xmm0 := | b | c | a | . |
    "shufps $0b00010010, %%xmm1, %%xmm1     \n" // xmm1 := | z | x | y | . |
    
    "shufps $0b00010010, %%xmm2, %%xmm2     \n" // xmm2 := | c | a | b | . |
    "shufps $0b00001001, %%xmm3, %%xmm3     \n" // xmm3 := | y | z | x | . |

    // multiply
    "mulps %%xmm1, %%xmm0                   \n" // xmm0 := |b*z|c*x|a*y| . |
    "mulps %%xmm3, %%xmm2                   \n" // xmm2 := |c*y|a*z|b*x| . |

    // and finally subtract
    "subps %%xmm2, %%xmm0                   \n" // xmm0 := |b*z - c*y|c*x - a*z|a*y - b*x| ... |
    "movups %%xmm0, (%2)                    \n"
    :
    : "r" (v1), "r" (v2), "r" (result)
);
}


int main() {
	srand(time(NULL));
	float v1[4], v2[4], res1[4], res2[4], err[4];
	int i=0;
	for (i=0; i < 4; i++) {
		v1[i] = frand(-100.0, 100.0);
		v2[i] = frand(-100.0, 100.0);
	}
	sse_cross_prod(v1, v2, res2);
	cross_prod(v1, v2, res1);
	
	for (i=0; i<3; i++)
		err[i] = 100.0 * (1.0 - res1[i]/res2[i]);
	err[3] = 0.0;
	
	printf("    ref = ");  print_vect(res1);
	printf("    SSE = ");  print_vect(res2);
	printf("err [%%] = "); print_vect(err);
	return 0;
}

// vim: ts=4 sw=4 nowrap
