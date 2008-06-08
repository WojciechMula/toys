/*
	Alpha blending of 32bpp images, $Revision: 1.7 $
	
	Program contains four procedures:

	* x86    --- C implementation (blend_image_inplace)
	             (1 pixel/iteration)
	* SSSE3  --- SIMD reference implementation (ssse3_blend_image_inplace)
	             (4 pixels/iteration)
	* SSE4   --- instruction pmovzx used instead of punpckxbw (sse4_blend_image_inplace)
	             (4 pixels/iteration)
	* SSE4-2 --- unrolled SSE4 variant (sse4_blend_image_inplace_unrolled)
	             (8 pixels/iteration)

	compilation:
	$ gcc -O3 -Wall -pedantic -std=c99 blend_32bpp.c


	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://www.republika.pl/wmula/
	
	License: BSD
	
	initial release 3-06-2008, last update $Date: 2008-06-08 23:00:44 $
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <strings.h>

#define SIMD_ALIGN __attribute__((aligned(16)))
#define NO_INLINE __attribute__((noinline))

uint8_t populate_alpha[16] SIMD_ALIGN = {
	// 0 1 2 3 4 5 6 7 8 9 a b c d e f
	// r g b A r g b A ...............
	0xff, 0x3, 0xff, 0x3, 0xff, 0x3, 0xff, 0xff,
	0xff, 0x7, 0xff, 0x7, 0xff, 0x7, 0xff, 0xff,
	// 0 A 0 A 0 A 0 0 0 A 0 A 0 A 0 0
};
	
	
void blend_image_inplace(uint32_t* background, uint32_t* foreground, int count) {
	uint32_t Rf, Gf, Bf, Af;
	uint32_t Rb, Gb, Bb;
	uint32_t R, G, B;

	while (count) {
		Rf =  (*foreground) & 0xff;
		Gf = ((*foreground) >>  8) & 0xff;
		Bf = ((*foreground) >> 16) & 0xff;
		Af = ((*foreground) >> 24) & 0xff;
		
		Rb =  (*background) & 0xff;
		Gb = ((*background) >>  8) & 0xff;
		Bb = ((*background) >> 16) & 0xff;

		R = (Rf * Af)/256 + Rb;
		G = (Gf * Af)/256 + Gb;
		B = (Bf * Af)/256 + Bb;

		if (R > 255) R = 255;
		if (G > 255) G = 255;
		if (B > 255) B = 255;

		(*background) = R | (G << 8) | (B << 16);

		foreground += 1;
		background += 1;
		count -= 1;
	}
}


void ssse3_blend_image_inplace(uint32_t* background, uint32_t* foreground, int count) {
	uint32_t dummy __attribute__((unused));

	__asm__ volatile (
		"movdqa populate_alpha, %%xmm7	\n"
		"pxor   %%xmm6, %%xmm6		\n"	// xmm6 = packed_byte(0x00)

		"0:				\n"

		// load 4 foreground pixels
		// xmm0 = [r0 g0 b0 a0|r1 g1 b1 a1|r2 g2 b2 a2|r3 g3 b3 a3]
		"movdqa  (%%esi), %%xmm0	\n"
		"movhlps  %%xmm0, %%xmm1	\n" // xmm1 = [r2 g2 b2 a2|r3 g3 b3 a3| ? | ? ]

		"movdqa   %%xmm0, %%xmm2	\n"
		"movdqa   %%xmm0, %%xmm3	\n"

		// extend components from bytes to words (_ = zero)
		// xmm2 = [r0 __ g0 __|b0 __ a0 __|r1 __ g1 __ |b1 __ a1 __]
		// xmm3 = [r2 __ g2 __|b2 __ a2 __|r3 __ g3 __ |b3 __ a3 __]
		"punpcklbw %%xmm6, %%xmm2	\n"
		"punpckhbw %%xmm6, %%xmm3	\n"

		// populate alpha, and multiply by 256
 		// xmm0 = [__ a0 __ a0|__ a0 __ __|__ a1 __ a1 |__ a1 __ __]
 		// xmm1 = [__ a2 __ a2|__ a2 __ __|__ a3 __ a3 |__ a3 __ __]
		"pshufb	  %%xmm7, %%xmm0	\n"
		"pshufb	  %%xmm7, %%xmm1	\n"

		// multiply (alpha * 256) by components, get higher word, i.e.
		// ((alpha << 256) * x) >> 16 -- values not greater then 255
		//
		// xmm0 = [r0*a0 g0*a0|b0*a0 __ __|r1*a1 g1*a1|b1*a1 __ __]
		// xmm2 = [r2*a2 g2*a2|b2*a2 __ __|r3*a3 g3*a3|b3*a3 __ __]
		"pmulhuw  %%xmm2, %%xmm0	\n"
		"pmulhuw  %%xmm3, %%xmm1	\n"

		// load 4 background pixels
		"movdqa  (%%edi), %%xmm2	\n"

		// multiplied foreground: convert back words to bytes  
		"packuswb %%xmm1, %%xmm0	\n"

		// add finally add to background, and save
		"paddusb %%xmm2, %%xmm0		\n"
		"movdqa  %%xmm0, (%%edi)	\n"

		"addl $16, %%esi		\n"
		"addl $16, %%edi		\n"
		"subl  $1, %%ecx		\n"
		"jnz   0b			\n"


		: "=D" (dummy),
		  "=S" (dummy),
		  "=c" (dummy)
		: "D" (background),
		  "S" (foreground),
		  "c" (count/4)
		: "memory"
		
	);
}


void sse4_blend_image_inplace(uint32_t* background, uint32_t* foreground, int count) {
	uint32_t dummy __attribute__((unused));

	__asm__ volatile (
		"movdqa populate_alpha, %%xmm7	\n"

		"0:				\n"

		"movdqa  (%%esi), %%xmm0	\n"	// 4 foreground pixels
		"movhlps  %%xmm0, %%xmm1	\n"

		"pmovzxbw %%xmm0, %%xmm2	\n"	// components
		"pmovzxbw %%xmm1, %%xmm3	\n"

		"pshufb	  %%xmm7, %%xmm0	\n"	// alpha
		"pshufb	  %%xmm7, %%xmm1	\n"

		"pmulhuw  %%xmm2, %%xmm0	\n"
		"pmulhuw  %%xmm3, %%xmm1	\n"

		"movdqa  (%%edi), %%xmm2	\n"

		"packuswb %%xmm1, %%xmm0	\n"

		"paddusb %%xmm2, %%xmm0		\n"
		"movdqa  %%xmm0, (%%edi)	\n"

		"addl $16, %%esi		\n"
		"addl $16, %%edi		\n"
		"subl  $1, %%ecx		\n"
		"jnz   0b			\n"


		: "=D" (dummy),
		  "=S" (dummy),
		  "=c" (dummy)
		: "D" (background),
		  "S" (foreground),
		  "c" (count/4)
		: "memory"
		
	);
}


void sse4_blend_image_inplace_unrolled(uint32_t* background, uint32_t* foreground, int count) {
	uint32_t dummy __attribute__((unused));

	__asm__ volatile (
		"0:				\n"

		"movdqa (%%esi), %%xmm0		\n"	// 4 foreground pixels
		"movdqa 16(%%esi), %%xmm4	\n"	// 4 foreground pixels
		"movhlps %%xmm0, %%xmm1		\n"
		"movhlps %%xmm4, %%xmm5		\n"

		"pmovzxbw %%xmm0, %%xmm2	\n"	// components
		"pmovzxbw %%xmm1, %%xmm3	\n"
		"pmovzxbw %%xmm4, %%xmm6	\n"	// components
		"pmovzxbw %%xmm5, %%xmm7	\n"

		"pshufb populate_alpha, %%xmm0	\n"	// alpha
		"pshufb populate_alpha, %%xmm1	\n"
		"pshufb populate_alpha, %%xmm4	\n"	// alpha
		"pshufb populate_alpha, %%xmm5	\n"

		"pmulhuw %%xmm2, %%xmm0		\n"
		"pmulhuw %%xmm3, %%xmm1		\n"
		"pmulhuw %%xmm6, %%xmm4		\n"
		"pmulhuw %%xmm7, %%xmm5		\n"

		"movdqa   (%%edi), %%xmm2	\n"
		"movdqa 16(%%edi), %%xmm6	\n"

		"packuswb %%xmm1, %%xmm0	\n"
		"packuswb %%xmm5, %%xmm4	\n"

		"paddusb %%xmm2, %%xmm0		\n"
		"paddusb %%xmm6, %%xmm4		\n"
		"movdqa  %%xmm0, (%%edi)	\n"
		"movdqa  %%xmm4, 16(%%edi)	\n"

		"addl $32, %%esi		\n"
		"addl $32, %%edi		\n"
		"subl  $1, %%ecx		\n"
		"jnz   0b			\n"


		: "=D" (dummy),
		  "=S" (dummy),
		  "=c" (dummy)
		: "D" (background),
		  "S" (foreground),
		  "c" (count/8)
		: "memory"
		
	);
}

#ifndef WIDTH
#	define WIDTH  640
#endif

#ifndef HEIGHT
#	define HEIGHT 480
#endif

#define SIZE (WIDTH)*(HEIGHT)

uint32_t fore[WIDTH][HEIGHT] SIMD_ALIGN;
uint32_t back[WIDTH][HEIGHT] SIMD_ALIGN;


void die(const char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	vprintf(fmt, ap);
	va_end(ap);

	exit(1);
}


int load_ppm(const char* filename, uint32_t *pixels, uint8_t alpha) {
	FILE* f;
	int y, x;
	uint32_t buf; // 4 bytes

	f = fopen(filename, "rb");
	if (f == NULL)
		die("Can't open '%s'", filename);

	buf = (uint32_t)alpha << 24;	// alpha is constant

	for (y=0; y < HEIGHT; y++) {
		for (x=0; x < WIDTH; x++) {
			if (fread(&buf, 3, 1, f) == 0) {
				die("Can't read '%s'.  Has PPM got size %d x %d?", filename, WIDTH, HEIGHT);
				fclose(f);
				return 0;
			}
			else
				*pixels++ = buf;
		}
	}

	fclose(f);
	return 1;
}


int save_ppm(const char* filename, uint32_t *pixels) {
	FILE* f;
	int y, x;

	f = fopen(filename, "wb");
	if (f == NULL)
		die("Can't open '%s'", filename);

	fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

	for (y=0; y < HEIGHT; y++) {
		for (x=0; x < WIDTH; x++)
			if (fwrite(pixels++, 3, 1, f) == 0) {
				die("Can't read '%s'.  Has PPM got size %d x %d?", filename, WIDTH, HEIGHT);
				fclose(f);
				return 0;
			}
	}

	fclose(f);
	return 1;
}


void help() {
	puts(
		"1. progname blend   x86|ssse3|sse4|sse4-2 filename-back.ppm filename-fore.ppm alpha\n"
		"2. progname measure x86|ssse3|sse4|sse4-2 iterations\n"

		"\n"
		"1. Program loads two PPM files and constant alpha, then perform blending and save back result (use to verify)\n"
		"2. Program runs selected procedure in a loop with given number iterations"
		
	);
}



int main(int argc, char* argv[]) {

	// parameters
	int action     = -1;
	int function   = -1;
	int iterations = 0;
	int alpha      = 0;
	char path[2048];

	if (argc < 4) {
		help();
		return 1;
	}

	// parse arguments
	// - action
	if (strcasecmp(argv[1], "blend") == 0) {
		if (argc < 6) {
			help();
			return 1;
		}
		action = 0;
	}
	else
	if (strcasecmp(argv[1], "measure") == 0)
		action = 1;
	else {
		help();
		return 1;
	}

	// - function
	if (strcasecmp(argv[2], "x86") == 0)
		function = 10;
	else
	if (strcasecmp(argv[2], "ssse3") == 0)
		function = 30;
	else
	if (strcasecmp(argv[2], "sse4") == 0)
		function = 40;
	else
	if (strcasecmp(argv[2], "sse4-2") == 0)
		function = 42;
	else {
		help();
		return 1;
	}

	if (action == 0) { // blend
		alpha = atoi(argv[5]);
		if (alpha < 0 || alpha > 255)
			die("Alpha must lie in range 0..255\n");

		if (!load_ppm(argv[3], &back[0][0], 0x00))
			die("Can't open or read '%s'\n", argv[1]);
		
		if (!load_ppm(argv[4], &fore[0][0], alpha))
			die("Can't open or read '%s'\n", argv[1]);
	}
	else { // measure
		iterations = atoi(argv[3]);
		if (iterations <= 0) {
			help();
			return 1;
		}
	}


	// run
	if (action == 0) { // blend
		switch (function) {
			case 10:
				puts("x86");
				strcpy(path, "x86.ppm");
				blend_image_inplace(&back[0][0], &fore[0][0], SIZE);
				break;

			case 30:
				puts("SSSE3");
				strcpy(path, "ssse3.ppm");
				ssse3_blend_image_inplace(&back[0][0], &fore[0][0], SIZE);
				break;

			case 40:
				puts("SSE4");
				strcpy(path, "sse4.ppm");
				sse4_blend_image_inplace(&back[0][0], &fore[0][0], SIZE);
				break;

			case 42:
				puts("SSE4 unrolled");
				strcpy(path, "sse42.ppm");
				sse4_blend_image_inplace_unrolled(&back[0][0], &fore[0][0], SIZE);
				break;

			default:
				return 0;
		}

		if (!save_ppm(path, &back[0][0]))
			die("Can't write '%s'\n", path);
		
	}
	else { // measure
		switch (function) {
			case 10:
				printf("x86, iterations=%d, image %d x %d\n", iterations, WIDTH, HEIGHT);
				while (iterations--)
					blend_image_inplace(&back[0][0], &fore[0][0], SIZE);
				break;

			case 30:
				printf("SSSE3, iterations=%d, image %d x %d\n", iterations, WIDTH, HEIGHT);
				while (iterations--)
					ssse3_blend_image_inplace(&back[0][0], &fore[0][0], SIZE);
				break;

			case 40:
				printf("SSE4, iterations=%d, image %d x %d\n", iterations, WIDTH, HEIGHT);
				while (iterations--)
					sse4_blend_image_inplace(&back[0][0], &fore[0][0], SIZE);
				break;

			case 42:
				printf("SSE4 unrolled, iterations=%d, image %d x %d\n", iterations, WIDTH, HEIGHT);
				while (iterations--)
					sse4_blend_image_inplace_unrolled(&back[0][0], &fore[0][0], SIZE);
				break;
		}
	}

	return 0;
}

// eof
