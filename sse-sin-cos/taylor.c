#define _XOPEN_SOURCE 500 /* enable M_PI constant */
#include <math.h>

double sin_taylor5(const double x) {
	const double x2 = x*x;
	const double x3 = x*x2;
	const double x5 = x3*x2;
	const double x7 = x5*x2;
	const double x9 = x7*x2;

	return x - x3*(1.0/6) + x5*(1.0/120) - x7*(1.0/5040) + x9*(1.0/362880);
}

double sin_taylor4(const double x) {
	const double x2 = x*x;
	const double x3 = x*x2;
	const double x5 = x3*x2;
	const double x7 = x5*x2;

	return x - x3*(1.0/6) + x5*(1.0/120) - x7*(1.0/5040);
}

double sin_taylor3(const double x) {
	const double x2 = x*x;
	const double x3 = x*x2;
	const double x5 = x3*x2;

	return x - x3*(1.0/6) + x5*(1.0/120);
}


