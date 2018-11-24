#include <stdint.h> 
#include <stdio.h> 

#define FLUSH_TO_ZERO			0x8000
#define DENORMALS_ARE_ZEROS		0x0040

#define PRECISION_MASK			0x1000
#define UNDERFLOW_MASK			0x0800
#define OVERFLOW_MASK			0x0400
#define DIVIDE_BY_ZERO_MASK		0x0200
#define DENORMAL_MASK			0x0100
#define INVALID_OPERATION_MASK	0x0080

#define PRECISION_FLAG			0x0020
#define UNDERFLOW_FLAG			0x0010
#define OVERFLOW_FLAG			0x0008
#define DIVIDE_BY_ZERO_FLAG		0x0004
#define DENORMAL_FLAG			0x0002
#define INVALID_OPERATION_FLAG	0x0001

#define RESET_ERROR_FLAGS (~(PRECISION_FLAG | UNDERFLOW_FLAG | OVERFLOW_FLAG | DIVIDE_BY_ZERO_FLAG | DENORMAL_FLAG | INVALID_OPERATION_FLAG))


uint32_t get_mxcsr() {
	uint32_t result = 0;
	__asm__ __volatile__("stmxcsr %0": :"m" (result));

	return result;
}

void set_mxcsr(uint32_t mxcsr) {
	__asm__ __volatile__("ldmxcsr (%0)"
		:
		:"g" (&mxcsr)
		: "memory"
	);
}

#define condstr(cond, true_str, false_str) ((cond) ? true_str : false_str)
#define flagset(flag) condstr(mxcsr & (flag), "yes", "no")

void print_mxcsr_exception_flags(FILE* f, const uint32_t mxcsr) {
	fprintf(f, "Exception flags\n");
	fprintf(f, "* precision         : %s\n", flagset(PRECISION_FLAG));
	fprintf(f, "* underflow         : %s\n", flagset(UNDERFLOW_FLAG));
	fprintf(f, "* overflow          : %s\n", flagset(OVERFLOW_FLAG));
	fprintf(f, "* divide by zero    : %s\n", flagset(DIVIDE_BY_ZERO_FLAG));
	fprintf(f, "* denormal          : %s\n", flagset(DENORMAL_FLAG));
	fprintf(f, "* invalid operation : %s\n", flagset(INVALID_OPERATION_FLAG));
}

void print_mxcsr(FILE* f, const uint32_t mxcsr) {
	fprintf(f, "value: %04x\n", mxcsr);

	fprintf(f, "Calculations\n");
	fprintf(f, "* flush to zero     : %s\n", flagset(FLUSH_TO_ZERO));
	fprintf(f, "* denormals are zero: %s\n", flagset(DENORMALS_ARE_ZEROS));

	print_mxcsr_exception_flags(f, mxcsr);

	fprintf(f, "Exception masks\n");
	fprintf(f, "* precision         : %s\n", flagset(PRECISION_MASK));
	fprintf(f, "* underflow         : %s\n", flagset(UNDERFLOW_MASK));
	fprintf(f, "* overflow          : %s\n", flagset(OVERFLOW_MASK));
	fprintf(f, "* divide by zero    : %s\n", flagset(DIVIDE_BY_ZERO_MASK));
	fprintf(f, "* denormal          : %s\n", flagset(DENORMAL_MASK));
	fprintf(f, "* invalid operation : %s\n", flagset(INVALID_OPERATION_MASK));

}

void dump_mxcsr() {
	print_mxcsr(stdout, get_mxcsr());
}

#undef flagset
#undef condstr
