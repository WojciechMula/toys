/*
	Mandelbrot fractal generator --- SSE2 & SSE4.1 implementation, $Revision: 1.3 $

	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	License: BSD

	initial release 28-06-2008, last update $Date: 2008-12-22 20:15:08 $

	----------------------------------------------------------------------

	SSE procedure calculates 4 pixels in parallel. SSE4.1 procedure uses
	PTEST instruction to break loop when lengths of all 4 complex numbers
	are greater than some threshold.  SSE2 version uses PMOVMSKB and x86
	TEST.

	Average speedup over FPU procedure is around 4.5 times.
	Measured on Core2 Duo E8200 @ 2.66GHz.


	Compilation SSE4.1 version:

		gcc -O3 -Wall -pedantic -std=c99 sse4-mandelbrot.c -o your_favorite_name

	Compilation SSE2 version:

		gcc -O3 -Wall -pedantic -std=c99 -DSSE2 sse-mandelbrot.c -o your_favorite_name

	Usage:

		run program without argument to read help

*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <sys/time.h>
#include <stdarg.h>

#if !defined(VERSION32BIT) && !defined(VERSION64BIT)
#   error "Define either VERSION32BIT or VERSION64BIT"
#endif

#if defined(VERSION32BIT) && defined(VERSION64BIT)
#   error "Define either VERSION32BIT or VERSION64BIT"
#endif

//=== helper functions ===================================================
uint32_t get_time(void) {
	static struct timeval T;
	gettimeofday(&T, NULL);
	return (T.tv_sec * 1000000) + T.tv_usec;
}


void die(const char* fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	vprintf(fmt, ap);
	putchar('\n');
	va_end(ap);

	exit(EXIT_FAILURE);
}


#include "fpu-proc.c"
#if defined(VERSION32BIT)
#   include "sse4-proc-32-bit.c"
#elif defined(VERSION64BIT)
#   if defined(AVX2)
#       include "avx2-proc-64-bit.c"
#   endif
#   if defined(AVX512)
#       include "avx512-proc-64-bit.c"
#   endif
#   include "sse4-proc-64-bit.c"
#endif


//=== main program =======================================================
#define WIDTH  (512*4)
#define HEIGHT (512*4)

uint8_t image[WIDTH][HEIGHT];


void help(char* progname) {

#if defined(VERSION32BIT)
    puts("SSE fractal generator (handcrafted 32-bit version)");
#else
    puts("SSE fractal generator (compiled 64-bit version)");
#endif
    puts("");

	printf("%s procedure [Remin Immin Remax Immax [threshold] [maxiters]] [--dry-run]\n", progname);
    puts("");
	puts("FPU - select FPU procedure");
#if defined(VERSION32BIT)
    #ifdef SSE2
        puts("SSE - select SSE2 procedure");
    #else
        puts("SSE - select SSE4.1 procedure");
    #endif
#else
    puts("SSE - select SSE procedure");
#endif
#if defined(AVX2)
    puts("AVX2 - select AVX2 procedure");
#endif
#if defined(AVX512)
    puts("AVX512 - select AVX512 procedure");
#endif
    puts("Parameters:");
    puts("");
	puts("Remin Immin Remax Immax - define area of calculations; default -2.0 -2.0 +2.0 +2.0");
	puts("threshold - define max radius, greater than 0; default 20.0");
	puts("maxiters  - define max number of iterations; default 255");
    puts("");
    puts("Options:");
    puts("");
    puts("--dry-run - do not save any file");
	exit(EXIT_FAILURE);
}



int main(int argc, char* argv[]) {
	FILE* f = NULL;

	uint32_t t1, t2;

	// parameters
	float Re_min = -2.0, Re_max = +2.0;
	float Im_min = -2.0, Im_max = +2.0;
	float threshold = 20.0;
	int   maxiters  = 255;

	enum {None, FPUprocedure, SSEprocedure, AVX2procedure, AVX512procedure} function;
	function = None;

	// parse command line
	char *err;
	if (argc == 1) {
		help(argv[0]);
    }


	// 1. function name
	if (strcasecmp(argv[1], "FPU") == 0)
		function = FPUprocedure;
	else
	if (strcasecmp(argv[1], "SSE") == 0)
		function = SSEprocedure;
#if defined(AVX2)
	else
	if (strcasecmp(argv[1], "AVX2") == 0)
		function = AVX2procedure;
#endif
#if defined(AVX512)
	else
	if (strcasecmp(argv[1], "AVX512") == 0)
		function = AVX512procedure;
#endif
	else
		help(argv[0]);


	// 2. optional area of calculations
	if (argc >= 6) {
		Re_min = strtod(argv[2], &err);
		if (*err != '\0') die("Invalid Remin value");

		Im_min = strtod(argv[3], &err);
		if (*err != '\0') die("Invalid Immin value");

		Re_max = strtod(argv[4], &err);
		if (*err != '\0') die("Invalid Remax value");

		Im_max = strtod(argv[5], &err);
		if (*err != '\0') die("Invalid Immax value");
	}

	// 3. optional threshold value
	if (argc >= 7) {
		threshold = strtod(argv[6], &err);
		if (*err != '\0') die("Invalid threshold value");
		if (threshold <= 0)
			die("threshold must be greater than 0");
	}

	// 4. optional maxiters values
	if (argc >= 8) {
		maxiters = strtol(argv[7], &err, 10);
		if (*err != '\0') die("Invalid maxiters value");
		if (maxiters <= 0)
			die("maxiters must be greater than 0");
	}


    // check for options
    char dry_run = 0;
    for (int i=1; i < argc; i++) {
        if (strcmp(argv[i], "--dry-run") == 0) {
            dry_run = 1;
            break;
        }
    }


	// print summary
	printf("Image %d x %d, Area [(%0.5f,%0.5f), (%0.5f, %0.5f)], thresold=%0.2f, maxiters=%d\n",
		WIDTH, HEIGHT,
		Re_min, Im_min, Re_max, Im_max,
		threshold,
		maxiters
	);


	// run selected function
	switch (function) {
		case None:
			break;

		case FPUprocedure:
			printf("FPU ");
			fflush(stdout);
			t1 = get_time();
			FPU_mandelbrot(
				Re_min, Re_max,
				Im_min, Im_max,
				threshold, maxiters,
				WIDTH, HEIGHT,
				&image[0][0]
			);
			t2 = get_time();
			printf("%d us\n", t2-t1);

            if (!dry_run) {
			    f = fopen("fpu.pgm", "wb");
            }
			break;

		case SSEprocedure:

#if defined(VERSION32BIT)
    #ifdef SSE2
                printf("SSE2 ");
    #else //SSE4.1
                printf("SSE4.1 ");
    #endif
#else
            printf("SSE ");
#endif
			fflush(stdout);
			t1 = get_time();
			SSE_mandelbrot(
				Re_min, Re_max,
				Im_min, Im_max,
				threshold, maxiters,
				WIDTH, HEIGHT,
				&image[0][0]
			);
			t2 = get_time();
			printf("%d us\n", t2-t1);

            if (!dry_run) {
			    f = fopen("sse.pgm", "wb");
            }
			break;

		case AVX2procedure:
#if defined(AVX2)
            printf("AVX2 ");
			fflush(stdout);
			t1 = get_time();
			AVX2_mandelbrot(
				Re_min, Re_max,
				Im_min, Im_max,
				threshold, maxiters,
				WIDTH, HEIGHT,
				&image[0][0]
			);
			t2 = get_time();
			printf("%d us\n", t2-t1);

            if (!dry_run) {
			    f = fopen("avx2.pgm", "wb");
            }
#endif
			break;

		case AVX512procedure:
#if defined(AVX512)
            printf("AVX512 ");
			fflush(stdout);
			t1 = get_time();
			AVX512_mandelbrot(
				Re_min, Re_max,
				Im_min, Im_max,
				threshold, maxiters,
				WIDTH, HEIGHT,
				&image[0][0]
			);
			t2 = get_time();
			printf("%d us\n", t2-t1);

            if (!dry_run) {
			    f = fopen("avx512.pgm", "wb");
            }
#endif
			break;
	}

	// save image
	if (f) {
		fprintf(f, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
		fwrite(image, WIDTH*HEIGHT, 1, f);
		fclose(f);
	}
	return 0;
}

