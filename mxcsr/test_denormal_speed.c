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


#define packed_float(x) {(x), (x), (x), (x)}
#define packed_value(name, x) float name[4] = packed_float(x)

float tiny_value[4]    = packed_float(FLT_MIN);
float large_divisor[4] = packed_float(0.5);
float final_value[4];

void test(const char* msg, const uint32_t flags) {
	uint32_t mxcsr;
	uint32_t t1, t2;

	printf("%s ...", msg);
	fflush(stdout);

	mxcsr = get_mxcsr();
	mxcsr |= flags;
	set_mxcsr(mxcsr);

	t1 = get_time();
	test_loop();
	t2 = get_time();

	printf("%0.3fs\n", (t2-t1)/1000000.0);

	printf(
		"final value: %e, type: %s\n",
		final_value[0],
		fpclassifyf_str(final_value[0])
	);

	dump_mxcsr();
}


void test_loop() {
	const int32_t iterations = 10000000;
	uint32_t dummy;
	__asm__ __volatile__(
		"1:\n"
		"movups tiny_value,    %%xmm0\n"
		"movups	large_divisor, %%xmm1\n"
		"pxor   %%xmm2, %%xmm2\n"
		"mulps  %%xmm1, %%xmm0\n" // FLT_MIN * 0.5 => denormalized number
		"addps	%%xmm2, %%xmm0\n" // denormalized + 0.0 => denormal exception
		"loop 1b\n"
		"movups %%xmm0, final_value\n"
		: "=c" (dummy)
		: "c" (iterations)
		:
	);
}
