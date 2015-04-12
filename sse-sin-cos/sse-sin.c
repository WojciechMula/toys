#define ALIGNED __attribute__((aligned(16)))

#define packed_double(x) {(x), (x)}

double coef3[2] ALIGNED = packed_double(1.0/6);
double coef5[2] ALIGNED = packed_double(1.0/120);
double coef7[2] ALIGNED = packed_double(1.0/5040);
double coef9[2] ALIGNED = packed_double(1.0/362880);


void sin_sse(const double arg1, const double arg2, double* sin_x1, double* sin_x2) {

	__asm__ volatile (
		"movlpd %0, %%xmm7			    \n"
		"movhpd %1, %%xmm7			    \n" // xmm7 = [arg2, arg1]
		"movapd %%xmm7, %%xmm6			\n" 

		"movapd %%xmm7, %%xmm0			\n"
		"mulpd  %%xmm6, %%xmm6			\n" // xmm6 = x^2 [x2]
		"mulpd  %%xmm6, %%xmm0			\n" // xmm0 = x^3 [x3]

		"movapd %%xmm6, %%xmm1			\n"
		"movapd %%xmm6, %%xmm2			\n"
		"movapd %%xmm6, %%xmm3			\n"
		"mulpd  %%xmm0, %%xmm1			\n" // xmm1 = x^5 [x5]
		"mulpd  %%xmm1, %%xmm2			\n" // xmm2 = x^7 [x7]
		"mulpd  %%xmm2, %%xmm3			\n" // xmm3 = x^9 [x9]

		"mulpd   coef3, %%xmm0			\n" // xmm0 = x^3/6
		"mulpd   coef5, %%xmm1			\n" // xmm1 = x^5/120
		"mulpd   coef7, %%xmm2			\n" // xmm2 = x^7/5040
		"mulpd   coef9, %%xmm3			\n" // xmm3 = x^7/362800

		// final sum
		"subpd  %%xmm0, %%xmm7			\n"
		"addpd  %%xmm1, %%xmm7			\n"
		"subpd  %%xmm2, %%xmm7			\n"
		"addpd  %%xmm3, %%xmm7			\n"

		"movhpd %%xmm7, %2				\n"
		"movlpd %%xmm7, %3				\n"
		: /* no output */
		: "m" (arg1),
		  "m" (arg2),
		  "m" (*sin_x1),
		  "m" (*sin_x2)
		: /* nothing is modified */
	);
}


double sin_sse_wrapper(const double x) {
	double result = -1.0;

	sin_sse(x, x, &result, &result);

	return result;
}
