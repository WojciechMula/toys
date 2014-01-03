#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "mxcsr.c"

void mulps_tiny_by_large_value();

int main() {
	mulps_tiny_by_large_value();

	dump_mxcsr();
}

#define packed_float(x) {(x), (x), (x), (x)}
#define packed_value(name, x) float name[4] = packed_float(x)

float tiny_value[4]    = packed_float(FLT_MIN);
float large_divisor[4] = packed_float(0.5);

void mulps_tiny_by_large_value() {
	__asm__ __volatile__(
		"movups tiny_value,    %%xmm0\n"
		"movups	large_divisor, %%xmm1\n"
		"mulps  %%xmm1, %%xmm0\n" // FLT_MIN * 0.5 => denormalized number
		"addps	%%xmm1, %%xmm0\n" // denormalized * value => denormal exception
		:
		:
		:
	);
}
