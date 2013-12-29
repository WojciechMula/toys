#ifndef ieee_double_h_included__
#define ieee_double_h_included__

#include <stdint.h>

typedef union {
	struct {
		uint64_t fraction: 52;
		uint64_t exp_bias: 11;
		uint64_t sign    : 1;
	} fields;

	uint64_t qword;
	double   value;
} IEEE754_double;

const int IEEE754_DOUBLE_BIAS = 1023;

#endif
