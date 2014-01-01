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



void mesure(const char* msg, double (*function)(double x)) {
	uint32_t t1, t2;

	printf("%s: ", msg);
	fflush(stdout);

	t1 = get_time();
	for (double x = -M_PI/2.0; x < M_PI/2.0; x += M_PI/10000000) {
		function(x);
	}
	t2 = get_time();

	printf("%0.3f s\n", (t2 - t1)/1000000.0);
}


#include "taylor.c"
#include "sse-sin.c"

int main() {
	mesure("libc sin", sin);
	mesure("taylor series (3 terms)", sin_taylor3);
	mesure("taylor series (4 terms)", sin_taylor4);
	mesure("taylor series (5 terms)", sin_taylor5);
	mesure("2 x taylor series (5 terms, SSE)", sin_sse_wrapper);

	return EXIT_SUCCESS;
}

