#include "ieee_double.h"

/*
 * Caluclate floor of x with using FPU/SSE, just
 * plain bit operations.
 */
double custom_floor(const double x) {
	IEEE754_double number = {.value=x};

	// bit position of decimal dot
	const int dot_position = 52 - (number.fields.exp_bias - IEEE754_DOUBLE_BIAS);

	if (dot_position > 52) {
		// value is less then 1.0
		return 0.0;
	}

	if (dot_position > 0 && dot_position <= 52) {
		// value is grater then 1.0 and have a fraction - dot is located
		// somewhere in fraction field
		const uint64_t mask = ((uint64_t)1 << dot_position) - 1;

		// reset bits after dot
		number.fields.fraction &= ~mask;
	}

	return number.value;
}

