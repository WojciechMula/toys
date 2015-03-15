#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "mxcsr.c"

void divps_by_zero();

int main() {
	divps_by_zero();

	dump_mxcsr();
}

#define packed_float(x) {(x), (x), (x), (x)}
#define packed_value(name, x) float name[4] = packed_float(x)

float zero[4] = packed_float(0);
float one[4]  = packed_float(1);

void divps_by_zero() {

	__asm__ __volatile__(
		"movups %0,     %%xmm0\n" // zero
		"movups	%1,     %%xmm1\n" // one
		"divps  %%xmm0, %%xmm1\n"
		:
		: "m" (zero)
		, "m" (one)
		:
	);
}

