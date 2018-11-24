#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "mxcsr.c"
#include "time.c"
#include "fpclassify.c"

void test_loop();
void test(const char* msg, const uint32_t flags);

int main() {
	test("default settings", 0);
	test("denormals are zero", DENORMALS_ARE_ZEROS);
	test("flush to zero", FLUSH_TO_ZERO);
}


#if !defined(DUMP_MXCSR)
//#define DUMP_MXCSR
#endif

#define packed_float(x) {(x), (x), (x), (x)}
#define packed_value(name, x) float name[4] = packed_float(x)

float tiny_value[4]    = packed_float(FLT_MIN);
float large_divisor[4] = packed_float(0.5);
float final_value[4];

void test(const char* msg, const uint32_t flags) {
	uint32_t mxcsr;
	uint32_t t1, t2;

	printf("%-20s", msg);
	fflush(stdout);

	mxcsr = get_mxcsr();
	mxcsr |= flags;
	set_mxcsr(mxcsr);

	t1 = get_time();
	test_loop();
	t2 = get_time();

	printf("%8.3fs ", (t2-t1)/1000000.0);

	printf(
		"final value: %e, type: %s\n",
		final_value[0],
		fpclassifyf_str(final_value[0])
	);

#if defined(DUMP_MXCSR)
	dump_mxcsr();
#endif
}


void test_loop() {
	const int32_t iterations = 10000000;
	uint32_t dummy;
	__asm__ __volatile__(
		"movups %2, %%xmm3\n" // tiny_value
		"movups	%3, %%xmm4\n" // large_divisor
		"1:\n"
		"movaps %%xmm3, %%xmm0\n"
		"movaps %%xmm4, %%xmm1\n"
		"pxor   %%xmm2, %%xmm2\n"
		"mulps  %%xmm1, %%xmm0\n" // FLT_MIN * 0.5 => denormalized number
		"addps	%%xmm2, %%xmm0\n" // denormalized + 0.0 => denormal exception
		"loop 1b\n"
		"movups %%xmm0, %4\n" // final_value
		: "=c" (dummy)
		: "c" (iterations)
		, "m" (tiny_value)
		, "m" (large_divisor)
		, "m" (final_value)
		: "xmm0", "xmm1", "xmm2", "xmm3", "xmm4"
		
	);
}
