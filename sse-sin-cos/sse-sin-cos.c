#define _XOPEN_SOURCE 500 /* enable M_PI constant */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <sys/time.h>


uint32_t get_time(void) {
	static struct timeval T;
	gettimeofday(&T, NULL);
	return (T.tv_sec * 1000000) + T.tv_usec;
}

double sin9(const double x) {
	const double x2 = x*x;
	const double x3 = x*x2;
	const double x5 = x3*x2;
	const double x7 = x5*x2;
	const double x9 = x7*x2;

	return x - x3*(1.0/6) + x5*(1.0/120) - x7*(1.0/5040) + x9*(1.0/362880);
}

double sin7(const double x) {
	const double x2 = x*x;
	const double x3 = x*x2;
	const double x5 = x3*x2;
	const double x7 = x5*x2;

	return x - x3*(1.0/6) + x5*(1.0/120) - x7*(1.0/5040);
}

double sin5(const double x) {
	const double x2 = x*x;
	const double x3 = x*x2;
	const double x5 = x3*x2;

	return x - x3*(1.0/6) + x5*(1.0/120);
}


void compare() {
	for (double x = -M_PI/2.0; x < M_PI/2.0; x += M_PI/100000) {
		const double s = sin(x);
		const double s9 = sin9(x);
		const double s7 = sin7(x);
		const double s5 = sin5(x);

		printf("%12.8f %12.8f %12.8f %12.8f %12.8f\n", x, s, s5, s7, s9);
	}
}


void mesure(const char* msg, double (*function)(double x)) {
	uint32_t t1, t2;

	t1 = get_time();
	for (double x = -M_PI/2.0; x < M_PI/2.0; x += M_PI/10000000) {
		function(x);
	}
	t2 = get_time();

	printf("%s: %0.3f s\n", msg, (t2 - t1)/1000000.0);
}


int main() {
	mesure("libc sin", sin);
	mesure("taylor series (5)", sin5);
	mesure("taylor series (7)", sin7);
	mesure("taylor series (9)", sin9);

	return EXIT_SUCCESS;
}

