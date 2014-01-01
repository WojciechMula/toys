#define _XOPEN_SOURCE 500 /* enable M_PI constant */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "sse-sin.c"


void compare() {
	for (double x = -M_PI/2.0; x < M_PI/2.0; x += M_PI/100000) {
		const double reference = sin(x);
		const double sse = sin_sse_wrapper(x);

		printf("%12.8f %12.8f %12.8f %12.8f\n", x, reference, sse, reference - sse);
	}
}

int main() {
	compare();

	return EXIT_SUCCESS;
}

