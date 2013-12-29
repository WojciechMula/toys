/*

	Calculate floor value without FPU/SSE instruction.

	Compilation:

	$ make

	Usage:

	$ ./demo [numbers]

	For example

	$ ./demo 123.75 0.012 120000000000000 0.99999999 99.999
	floor(123.75000000) = 123.00000000
	floor(0.01200000) = 0.00000000
	floor(120000000000000.00000000) = 120000000000000.00000000
	floor(0.99999999) = 0.00000000
	floor(99.99900000) = 99.00000000
 */

#include <stdlib.h>
#include <stdio.h>
#include "floor.c"


int main(int argc, char* argv[]) {
	for (int i=1; i < argc; i++) {
		const double x = atof(argv[i]);

		const double floor_x = custom_floor(x);

		printf("floor(%0.8f) = %0.8f\n", x, floor_x);
	}

	return EXIT_SUCCESS;
}

