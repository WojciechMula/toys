#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


#include "decimal_digits_sse.c"
#include "decimal_digits_naive.c"


int main(int argc, char* argv[]) {
	for (int i=1; i < argc; i++) {
		const int x = atoi(argv[i]);
		if (x >= 0) {
			const int sse = decimal_digits_sse(x);
			const int ref = decimal_digits_naive(x);
		
			printf("%15d: digits %2d (SSE proc), %2d (correct)", x, sse, ref);
            if (sse != ref)
                printf(" FAILED");

            putchar('\n');
		} else {
			printf("%15d: negative numbers not supported\n", x);
		}
	}

	return EXIT_SUCCESS;
}
