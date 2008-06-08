/*
	Calculating 4 dot products using SSE instructions, $Revision: 1.5 $
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://www.republika.pl/wmula/
	
	License: public domain
	
	initial release 11.02.2002, last update $Date: 2008-06-08 23:00:44 $
*/

#include "sse-aux.c"

// start-snippet
void sse_dot4(float* v1x4, float* v2x4, float* results) {
__asm__ volatile (
   // load 4 vectors from v1
   "movups    (%0), %%xmm0                 \n"
   "movups  16(%0), %%xmm1                 \n"
   "movups  32(%0), %%xmm2                 \n"
   "movups  48(%0), %%xmm3                 \n"
   
   // load 4 vectors from v2
   "movups    (%1), %%xmm4                 \n"
   "movups  16(%1), %%xmm5                 \n"
   "movups  32(%1), %%xmm6                 \n"
   "movups  48(%1), %%xmm7                 \n"
   
   // perfom parallel multiplications
   "mulps   %%xmm4, %%xmm0                 \n" // xmm0 := |A3|A2|A1|A0|
   "mulps   %%xmm5, %%xmm1                 \n" // xmm1 := |B3|B2|B1|B0|
   "mulps   %%xmm6, %%xmm2                 \n" // xmm2 := |C3|C2|C1|C0|
   "mulps   %%xmm7, %%xmm3                 \n" // xmm3 := |D3|D2|D1|D0|
   // (xmm4-xmm7 are free)
   
   // perfom additions
   "movaps   %%xmm0, %%xmm4                \n"
   "unpcklps %%xmm1, %%xmm0                \n" // xmm0 := |B1|A1|B0|A0|
   "unpckhps %%xmm1, %%xmm4                \n" // xmm4 := |B3|A3|B2|A2| (xmm1 is free)
   "movaps   %%xmm2, %%xmm1                \n"
   "unpcklps %%xmm3, %%xmm2                \n" // xmm2 := |D1|C1|D0|C0|
   "unpckhps %%xmm3, %%xmm1                \n" // xmm1 := |D3|C3|D2|C2| (xmm3 is free)
   "addps    %%xmm4, %%xmm0                \n" // xmm0 := | B13 | A13 | B02 | A02 | (xmm1 is free)
   "addps    %%xmm1, %%xmm2                \n" // xmm2 := | D13 | C13 | D02 | C02 | (xmm3 is free)
   
   "movaps   %%xmm0, %%xmm1                \n"
   "shufps   $0b01000100, %%xmm2, %%xmm0   \n" // xmm0 := | D02 | C02 | B02 | A02 |
   "shufps   $0b11101110, %%xmm2, %%xmm1   \n" // xmm1 := | D13 | C13 | B13 | A13 |
   "addps    %%xmm1, %%xmm0                \n" // xmm0 := |D0123|C0123|B0123|A0123|
   "movups   %%xmm0, (%2)                  \n"
   :
   : "r" (v1x4), "r" (v2x4), "r" (results)
   );
}
// end-snippet


void dot4(float* v1x4, float* v2x4, float* results) {
	int i;
	for (i=0; i < 4; i++)
		results[i] = 0.0;
	
	for (i=0; i < 4; i++) {
		results[0] += v1x4[i]    * v2x4[i];
		results[1] += v1x4[i+4]  * v2x4[i+4];
		results[2] += v1x4[i+8]  * v2x4[i+8];
		results[3] += v1x4[i+12] * v2x4[i+12];
	}
}


int main() {
	srand(time(NULL));
	float v1[4*4];
	float v2[4*4];
	float results1[4];
	float results2[4];
	float err[4];
	
	int i=0;
	for (i=0; i < 4*4; i++) {
		v1[i] = frand(-500.0, +500.0);
		v2[i] = frand(-500.0, +500.0);
	}

	sse_dot4(v1, v2, results2);
	dot4(v1, v2, results1);

	printf("    ref = "); print_vec_float(results1);
	printf("    SSE = "); print_vec_float(results2);
	for (i=0; i<4; i++)
		err[i] = 100.0 * (1.0 - results1[i]/results2[i]);
	printf("err [%%] = "); print_vec_float(err);
	return 0;
}

// vim: ts=8 nowrap
