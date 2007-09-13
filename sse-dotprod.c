/*
	Calculating dot product using SSE instructions, $Revision: 1.1 $

    Author: Wojciech Mu³a
    e-mail: wojciech_mula@poczta.onet.pl
    www:    http://www.mula.w.pl
    
    License: public domain

	initial release 13.03.2002, last update $Date: 2007-09-13 16:13:25 $
*/

#include "sse-aux.inc"

void sse_dot(float vec1[4], float vec2[4], float* result) {
asm(
   "movups (%0), %%xmm0                    \n" // load vec1: |w1|z1|y1|x1|
   "movups (%1), %%xmm1                    \n" // load vec2: |w2|z2|y2|x2|
   "                                       \n"
   "mulps   %%xmm1, %%xmm0                 \n" // xmm0 := |w1*w2|z1*z2|y1*y2|x1*x2|
   "movhlps %%xmm0, %%xmm1                 \n" // xmm1 := |  .  |  .  |w1*w2|z1*z2|
   "addps   %%xmm0, %%xmm1                 \n" // xmm1 := |  .  |  .  | w+y | z+x |
   "movaps  %%xmm1, %%xmm0                 \n" // save xmm1
   "shufps  $0x01,  %%xmm1, %%xmm1         \n" // xmm1 := |  .  |  .  |  .  | w+y |
   "addss   %%xmm1, %%xmm0                 \n" // xmm0[0] := dot product
   "movss   %%xmm0, (%2)                   \n"
   :
   : "r" (vec1), "r" (vec2), "r" (result));
}


float dot(float v1[4], float v2[4], float* result) {
	int i;
	*result = 0.0;
	for (i=0; i < 4; i++)
		*result += v1[i]*v2[i];
}


int main() {
	float v1[4];
	float v2[4];
	float res1, res2;
	int i=0;
       
	initfrand();
	for (i=0; i < 4; i++) {
		v1[i] = frand(-1000.0, 1000.0);
		v2[i] = frand(-1000.0, 1000.0);
	}
	
	sse_dot(v1, v2, &res2);
	dot(v1, v2, &res1);

	printf("dot=%.3f, sse_dot=%.3f, err=%.3f%%\n",
	       res1, res2, 100.0*(1.0 - res1/res2));
	return 0;
}

// vim: ts=4 sw=4 nowrap
