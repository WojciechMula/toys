#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


#include "decimal_digits_sse.c"
#include "decimal_digits_naive.c"
#ifdef AVX512
#   include "decimal_digits_avx512.c"
#endif


int main(int argc, char* argv[]) {
	for (int i=1; i < argc; i++) {
		const int x = atoi(argv[i]);
		if (x < 0) {
			printf("%15d: negative numbers not supported\n", x);
            continue;
        }
            
        const int ref = decimal_digits_naive(x);
        printf("%15d: digits %2d (correct)", x, ref);

        const int sse = decimal_digits_sse(x);
        printf(", %2d (SSE proc)", sse);
        if (sse != ref)
            printf(" FAILED");

#ifdef AVX512
        const int avx512 = decimal_digits_avx512(x);
    
        printf(", %2d (AVX512 proc)", avx512);
        if (avx512 != ref)
            printf(" FAILED");

#endif
        putchar('\n');
	}

	return EXIT_SUCCESS;
}
