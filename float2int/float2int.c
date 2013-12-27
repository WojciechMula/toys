/*

	Compilation:

	$ gcc -Wall -pedantic -std=c99 float2int.c -o your_favorite_name

	Usage:

	$ ./your_favorite_name [list of numbers]


 */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>

/*
 * Returns integer part of floating point value. If value is too large,
 * sets errno to ERANGE and returns max possible value.
 *
 * Funcion works properly only when argument is a normalized floating
 * point value. Unnormalized, NaN, infinity values are not supported.
 */
int float2int(const float value) {
	const int BIAS = 127;
	const uint32_t INT32_MIN_POSITIVE = 2147483648; // -INT32_MIN

	union {
		struct {
			uint32_t fraction	: 23;
			uint32_t exp_bias	: 8;
			uint32_t sign		: 1;
		} fields;

		float fp;
	} number;

	errno = 0;
	number.fp = value;

	const int shift = number.fields.exp_bias - BIAS - 23;

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

	// finally check range
	if (number.fields.sign) {
		if (integer > INT32_MIN_POSITIVE) {
			errno = ERANGE;

			return INT32_MIN;
		} else {
			return -integer;
		}
	} else {
		if (integer > INT32_MAX) {
			errno = ERANGE;

			return INT32_MAX;
		} else {
			return integer;
		}
	}
}


int main(int argc, char* argv[]) {
	for (int i=1; i < argc; i++) {
		const float value     = atof(argv[i]);
		const int   casted    = (int)value;
		const int   converted = float2int(value);
		const int   overflow  = (errno == ERANGE);

		printf("input: '%s'\n", argv[i]);
		printf("\tvalue     : %0.5f\n", value);
		printf("\tcasted    : %d\n", casted);
		printf("\tfloat2int : %d (overflow=%s)\n", converted, overflow ? "yes" : "no");
	}
}
