#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "mxcsr.c"

int main() {
	uint32_t mxcsr;

	mxcsr = get_mxcsr();
	mxcsr &= ~INVALID_OPERATION_MASK;
	set_mxcsr(mxcsr);

	__asm__ __volatile__(
		"xorps %xmm0, %xmm0\n"	
		"divps %xmm0, %xmm1\n" // 0/0 => invalid operation
	);
}
