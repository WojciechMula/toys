#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "mxcsr.c"
#include "time.c"
#include "fpclassify.c"

#if !defined(DUMP_MXCSR)
//#   define DUMP_MXCSR
#endif

void mulps_in_loop();
void test(const char* name);

int main() {
	test("default settings");

	uint32_t mxcsr;
	mxcsr = get_mxcsr();
	mxcsr |= FLUSH_TO_ZERO;
	mxcsr &= RESET_ERROR_FLAGS;
	set_mxcsr(mxcsr);

	test("flush to zero");
}

#define packed_float(x) {(x), (x), (x), (x)}

float min_floats[4] = packed_float(FLT_MIN);
float final_value[4];

void test(const char* name) {
	uint32_t t1, t2;

	printf("%-20s", name); fflush(stdout);

	t1 = get_time();
	mulps_in_loop();
	t2 = get_time();

	printf("%6.3fs ", (t2-t1)/1000000.0);

	printf(
		"final value: %e, type: %s\n",
		final_value[0],
		fpclassifyf_str(final_value[0])
	);

#if defined(DUMP_MXCSR)
	print_mxcsr_exception_flags(stdout, get_mxcsr());
#endif
}

void mulps_in_loop() {
	const int32_t iterations = 10000000;
	uint32_t dummy;

	__asm__ __volatile__(
		"movups 	%2, %%xmm0\n" // min_floats
		"1:\n"
		"movaps 	%%xmm0, %%xmm1\n"
		"mulps 		%%xmm1, %%xmm1\n"
		"loop 		1b\n"
		"movups		%%xmm1, %3\n"
		: "=c" (dummy)
		: "c"  (iterations)
		, "m"  (min_floats)
		, "m"  (final_value)
		: "xmm0", "xmm1"
	);
}
