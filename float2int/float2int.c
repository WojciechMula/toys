#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

typedef union {
		struct {
			uint32_t fraction	: 23;
			uint32_t exp_bias	: 8;
			uint32_t sign		: 1;
		} fields;

		uint32_t dword;
		float value;
	} IEEE745_float;

const int IEEE745_FLOAT_BIAS = 127;

/*
 * Returns integer part of floating point value. If value is too large,
 * sets errno to ERANGE and returns max possible value.
 *
 * Funcion works properly only when argument is a normalized floating
 * point value. Unnormalized, NaN, infinity values are not supported.
 */
int float2int(const float value) {
	const uint32_t INT32_MIN_POSITIVE = 2147483648; // -INT32_MIN

	IEEE745_float number = {.value = value};

	errno = 0;

	const int shift = number.fields.exp_bias - IEEE745_FLOAT_BIAS - 23;

	// shift amount is greater then number of significant bits,
	// so integer part is always 0
	if (shift < -23) {
		return 0;
	}

	// shift amount is greater than 7 (31 - 24), so integer exceed 31 bits
	if (shift > 7) {
		errno = ERANGE;

		return number.fields.sign ? INT32_MIN : INT32_MAX;
	}

	// shift amount in range [-23 .. 7]
	uint32_t integer = number.fields.fraction | (1 << 23); // set implicit integer 1

	if (shift < 0)
		integer >>= -shift;
	else if (shift > 0)
		integer <<= shift;

	if (shift == 7) {
		// range checking is required only when number of significant bits
		// is exacly 31.
		if (number.fields.sign) {
			if (integer > INT32_MIN_POSITIVE) {
				errno = ERANGE;

				return INT32_MIN;
			}
		} else {
			if (integer > INT32_MAX) {
				errno = ERANGE;

				return INT32_MAX;
			}
		}
	}

	return (number.fields.sign) ? -integer : integer;
}


