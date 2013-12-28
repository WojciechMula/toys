/*

	Calculate floor value without FPU/SSE instruction.

	Compilation:

	$ gcc -Wall -std=c99 -O2 floor.c -o your_favorite_name

	Usage:

	$ ./your_favorite_name [numbers]

	For example

	$ ./your_favorite_name 123.75 0.012 120000000000000 0.99999999 99.999
	floor(123.75000000) = 123.00000000
	floor(0.01200000) = 0.00000000
	floor(120000000000000.00000000) = 120000000000000.00000000
	floor(0.99999999) = 0.00000000
	floor(99.99900000) = 99.00000000
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

double custom_floor(const double x) {

	const int BIAS = 1023;

	union {
		struct {
			uint64_t fraction: 52;
			uint64_t exp_bias: 11;
			uint64_t sign    : 1;
		} fields;

		double value;
	} number = {.value=x};

	// bit position of decimal dot
	const int dot_position = 52 - (number.fields.exp_bias - BIAS);

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


int main(int argc, char* argv[]) {
	for (int i=1; i < argc; i++) {
		const double x = atof(argv[i]);

		const double floor_x = custom_floor(x);

		printf("floor(%0.8f) = %0.8f\n", x, floor_x);
	}

	return EXIT_SUCCESS;
}

