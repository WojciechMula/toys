/*
	Mandelbrot fractal generator --- SSE4.1 implementation, $Revision: 1.1 $

	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://www.republika.pl/wmula/

	License: BSD

	initial release 28-06-2008, last update $Date: 2008-06-29 14:04:29 $

	----------------------------------------------------------------------

	SSE procedure calculates 4 pixels in parallel; it uses PTEST instruction
	to break loop when lengths of all 4 complex numbers are greater then some
	threshold.

	Average speedup over FPU procedure is around 4.5 times.


	Compilation:

		gcc -O3 -Wall -pedantic -std=c99 sse4-mandelbrot.c -o your_favorite_name

	Usage:

		run program without argument to read help

*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <strings.h>
#include <sys/time.h>
#include <time.h>
#include <stdarg.h>

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


//=== C reference implementation =========================================
void FPU_mandelbrot(
	float Re_min, float Re_max,
	float Im_min, float Im_max,
	float threshold,
	int maxiters,
	int width, int height,
	uint8_t *data)

{
	float dRe, dIm;
	float Cre, Cim, Xre, Xim, Tre, Tim;
	int x, y, i;

	uint8_t* ptr = data;

	// step on Re and Im axis
	dRe = (Re_max - Re_min)/width;
	dIm = (Im_max - Im_min)/height;


	Cim = Im_min;

	for (y=0; y < height; y++) {
		Cre = Re_min;
		for (x=0; x < width; x++) {
			Xre = 0.0;
			Xim = 0.0;
			for (i=0; i < maxiters; i++) {
				Tre = Xre*Xre - Xim*Xim + Cre;
				Tim = 2*Xre*Xim + Cim;

				if (Tre*Tre + Tim*Tim > threshold)
					break;

				Xre = Tre;
				Xim = Tim;
			}

			*ptr++ = i;
			Cre += dRe;
		}

		Cim += dIm;
	}
}


//=== SSE4 implementation ================================================
#define SIMD_ALIGN __attribute__((aligned(16)))


float SSE_Cre[4]		SIMD_ALIGN;
float SSE_Cim[4]		SIMD_ALIGN;
float SSE_threshold[4]		SIMD_ALIGN;
float SSE_4dRe[4]		SIMD_ALIGN;
float SSE_dIm[4]		SIMD_ALIGN;


void SSE_mandelbrot(
	float Re_min, float Re_max,
	float Im_min, float Im_max,
	float threshold,
	int maxiters,
	int width, int height,
	uint8_t *data)

{
	float dRe, dIm;
	int x, y;

	uint8_t* ptr = data;

	// step on Re and Im axis
	dRe = (Re_max - Re_min)/width;
	dIm = (Im_max - Im_min)/height;

	
	// prepare vectors
	// 1. threshold (xmm7)
	SSE_threshold[0] = threshold;
	SSE_threshold[1] = threshold;
	SSE_threshold[2] = threshold;
	SSE_threshold[3] = threshold;
	__asm__ volatile ("movups SSE_threshold, %xmm7");
	
	
	// 2. Cim (xmm1)
	SSE_Cim[0] = Im_min;
	SSE_Cim[1] = Im_min;
	SSE_Cim[2] = Im_min;
	SSE_Cim[3] = Im_min;
	__asm__ volatile ("movups SSE_Cim, %xmm1");

	// 3. Re advance every x iteration (memory)
	SSE_4dRe[0] = SSE_4dRe[1] = SSE_4dRe[2] = SSE_4dRe[3] = 4*dRe;

	// 4. Im advance every y iteration (memory)
	SSE_dIm[0] = SSE_dIm[1] = SSE_dIm[2] = SSE_dIm[3] = dIm;


	// calculations
	for (y=0; y < height; y++) {

		// xmm0 = {Re_min, Re_min + dRe, Re_min + 2*dRe + Re_min + 3*dRe
		SSE_Cre[0] = Re_min;
		SSE_Cre[1] = Re_min + dRe;
		SSE_Cre[2] = Re_min + 2*dRe;
		SSE_Cre[3] = Re_min + 3*dRe;
		__asm__ volatile ("movups SSE_Cre, %xmm0");

		for (x=0; x < width; x+=4) {
			__asm__ volatile (
			"xorps    %%xmm2, %%xmm2	\n"	// Xre = 0.0
			"xorps    %%xmm3, %%xmm3	\n"	// Xim = 0.0
			"pxor     %%xmm6, %%xmm6	\n"	// xmm6 = 4 x itercount

			"0:				\n"
			// Tim = 2*Xre*Xim + Cre
			"movaps   %%xmm2, %%xmm4	\n"
			"mulps    %%xmm3, %%xmm4	\n"	// xmm4 = Xre*Xim
			"addps    %%xmm4, %%xmm4	\n"	// xmm4 = 2*Xre*Xim
			"addps    %%xmm1, %%xmm4	\n"	// xmm4 = 2*Xre*Xim + Cre
			
			// Tre = Xre^2 - Xim^2 + Cim
			"mulps    %%xmm2, %%xmm2	\n"	// xmm2 = Xre^2
			"mulps    %%xmm3, %%xmm3	\n"	// xmm3 = Xim^2
			"addps    %%xmm0, %%xmm2	\n"	// xmm2 = Xre^2 + Cim
			"subps    %%xmm3, %%xmm2	\n"	// xmm2 = Xre^2 - Xim^2 + Cim

			// calculate distance
			"movaps   %%xmm2, %%xmm5	\n"
			"movaps   %%xmm4, %%xmm3	\n"
			"mulps    %%xmm5, %%xmm5	\n"	// xmm5 = Tre^2
			"mulps    %%xmm4, %%xmm4	\n"	// xmm4 = Tim^2
			"addps    %%xmm5, %%xmm4	\n"	// xmm4 = Tre^2 + Tim^2

			"cmpleps  %%xmm7, %%xmm4	\n"	// xmm4 < threshold
			"ptest    %%xmm4, %%xmm4	\n"	// all greater?
			"jz	  3f			\n"	// break

			"psubd    %%xmm4, %%xmm6	\n"	// at least on less:
								// advance itercount
								// for xmm[4] < threshold


			"subl     $1, %%ecx		\n"
			"jnz      0b			\n"
			"3:				\n"

			"packuswb  %%xmm6, %%xmm6	\n"	// convert itercounts
			"packuswb  %%xmm6, %%xmm6	\n"	// from dwords to bytes
			"movd      %%xmm6, (%%eax)	\n"	// and save

			:
			: "c" (maxiters),
			  "a" (ptr)
			);

			// advance Cre vector
			__asm__ volatile ("addps SSE_4dRe, %xmm0");

			// advance data ptr
			ptr += 4;
		}

		// advance Cim vector
		__asm__ volatile ("addps SSE_dIm, %xmm1");
	}
}


//=== main program =======================================================
#define WIDTH  (512*4)
#define HEIGHT (512*4)

uint8_t image[WIDTH][HEIGHT];


void help(char* progname) {
	printf("%s FPU|SSE [Remin Immin Remax Immax [threshold] [maxiters]]", progname);
	puts("FPU - select FPU procedure");
	puts("SSE - select SSE procedure");
	puts("Remin Immin Remax Immax - define area of calculations; default -2.0 -2.0 +2.0 +2.0");
	puts("threshold - define max radius, greater then 0; default 20.0");
	puts("maxiters  - define max number of iterations; default 255");
	exit(EXIT_FAILURE);
}



int main(int argc, char* argv[]) {
	FILE* f;

	uint32_t t1, t2;

	// parameters
	float Re_min = -2.0, Re_max = +2.0;
	float Im_min = -2.0, Im_max = +2.0;
	float threshold = 20.0;
	int   maxiters  = 255;

	enum {None, FPUprocedure, SSEprocedure} function;
	function = None;

	// parse command line
	char *err;
	if (argc == 1)
		help(argv[0]);
	

	// 1. function name
	if (strcasecmp(argv[1], "FPU") == 0)
		function = FPUprocedure;
	else
	if (strcasecmp(argv[1], "SSE") == 0)
		function = SSEprocedure;
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
			die("threshold must be greater then 0");
	}

	// 4. optional maxiters values
	if (argc >= 8) {
		maxiters = strtol(argv[7], &err, 10);
		if (*err != '\0') die("Invalid maxiters value");
		if (maxiters <= 0)
			die("maxiters must be greater then 0");
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
			f = NULL;
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
		
			f = fopen("fpu.pgm", "wb");
			break;

		case SSEprocedure:
			printf("SSE ");
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
		
			f = fopen("sse.pgm", "wb");
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

// eof
