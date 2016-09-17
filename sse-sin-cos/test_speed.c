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



double mesure(const char* msg, double tref, double (*function)(double x)) {
	uint32_t t1, t2;

	printf("%-40s: ", msg);
	fflush(stdout);

	t1 = get_time();
	for (double x = -M_PI/2.0; x < M_PI/2.0; x += M_PI/10000000) {
		function(x);
	}
	t2 = get_time();

    const double t = (t2 - t1)/1000000.0;

    if (tref > 0.0) {
	    printf("%0.3f s (%0.2f)\n", t, tref/t);
    } else {
	    printf("%0.3f s\n", t);
    }

    return t;
}


#include "taylor.c"
#include "sse-sin.c"

int main() {

    double t = 0.0;

    t = mesure("libc sin", t, sin);
    mesure("Taylor series (3 terms)", t, sin_taylor3);
    mesure("Taylor series (4 terms)", t, sin_taylor4);
    mesure("Taylor series (5 terms)", t, sin_taylor5);
    mesure("2 x Taylor series (5 terms, SSE)", 2*t, sin_sse_wrapper);

	return EXIT_SUCCESS;
}

