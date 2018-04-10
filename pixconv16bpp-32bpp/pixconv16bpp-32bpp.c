/*
	16bpp to 32bpp pixel conversion
	
	This simple program includes following procedures:
	* naive      --- straightforward conversion that use and, or and shifts
	                 1 pixel/iteration
	* lookup16   --- single, large lookup table, 1 pixel/iteration
	* lookup8    --- two, small lookup tables, 1 pixel/iteration
	* lookup8(2) --- optimized lookup8, 2 pixels/iteration
	* MMX        --- naive using MMX instructions, 4 pixels/iteration
	* SSE2       --- naive using SSE2 instructions, 8 pixels/iteration
	* SSE2(2)    --- unrolled SSE2, 16 pixels/iteration

	Define NONTEMPORAL to use non-temporal stores in procedures
	MMX, SSE2 and SSE2(2).
	
	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl
	
	License: BSD
*/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/time.h>
#include <time.h>

static uint32_t lookup8_lo[256] __attribute__((aligned(64)));
static uint32_t lookup8_hi[256] __attribute__((aligned(64)));
static uint32_t lookup8_lo2[256] __attribute__((aligned(64)));
static uint32_t lookup8_hi2[256] __attribute__((aligned(64)));
static uint32_t lookup16[256*256] __attribute__((aligned(64)));

#ifndef WIDTH
#	define WIDTH	1024
#else
#	if WIDTH % 16 != 0
#		error "WIDTH must be multiple of 16"
#	endif
#endif

#ifndef HEIGHT
#	define HEIGHT	768
#endif

static uint16_t image_16bpp[HEIGHT+1][WIDTH] __attribute__((aligned(16)));
static uint32_t image_32bpp[HEIGHT+1][WIDTH] __attribute__((aligned(16)));


void prepare_lookups() {
	uint32_t x, r, g, b;

	for (x=0; x < 256; x++) {
		lookup8_lo[x] =
			  (x & 0x1f) << 3	// red
			| (x & 0xe0) << 3;	// green[0:2]

		lookup8_hi[x] =
			  (x & 0x07) << (8+3)	// green[3:5]
			| (x & 0xf8) << 16;	// blue
		
		lookup8_lo2[x] = lookup8_lo[x] << 16;
		lookup8_hi2[x] = lookup8_hi[x] << 16;
	}

	for (x=0; x < 65536; x++) {
		r =  x & 0x1f;
		g = (x >>  5) & 0x3f;
		b = (x >> 11) & 0x1f;

		lookup16[x] = r | (g << 8) || (b << 16);
	}
}

void convert_lookup8() {
	int x, y;
	for (y=0; y < HEIGHT; y++)
		for (x=0; x < WIDTH; x++) {
			image_32bpp[y][x] =
				lookup8_lo[image_16bpp[y][x] & 0xff] |
				lookup8_hi[image_16bpp[y][x] >> 8];
	}
}


void convert_lookup8_2() {
	uint32_t tmp;
	int x, y;
	for (y=0; y < HEIGHT; y++)
		for (x=0; x < WIDTH; x+=2) {
			tmp = (((uint32_t)image_16bpp[y][x]) << 16) | image_16bpp[y][x+1];
			image_32bpp[y][x] =
				lookup8_lo[tmp & 0xff] |
				lookup8_hi[(tmp >> 8) & 0xff];
			image_32bpp[y][x+1] =
				lookup8_lo2[(tmp >> 16) & 0xff] |
				lookup8_hi2[(tmp >> 24) & 0xff];
	}
}


void convert_lookup16() {
	int x, y;
	for (y=0; y < HEIGHT; y++)
		for (x=0; x < WIDTH; x++)
			image_32bpp[y][x] = lookup16[image_16bpp[y][x]];
}



void convert_naive() {
	int x, y;
	uint32_t tmp, R, G, B;
	for (y=0; y < HEIGHT; y++)
		for (x=0; x < WIDTH; x++) {
			tmp = image_16bpp[y][x];

			R = tmp & 0x1f;
			G = (tmp >> 5) & 0x3f;
			B = (tmp >> 11) & 0x1f;

			image_32bpp[y][x] = R | (G << 8) | (B << 16);
		}
}



#ifndef PLAINC
static uint8_t convert_MMX_maskR[8];
static uint8_t convert_MMX_maskG[8];
static uint8_t convert_MMX_maskB[8];

void convert_MMX() {
	int x, y;

	// preload masks
	__asm__ volatile ("movq (%%eax), %%mm5" : : "a" (convert_MMX_maskB));
	__asm__ volatile ("movq (%%eax), %%mm6" : : "a" (convert_MMX_maskG));
	__asm__ volatile ("movq (%%eax), %%mm7" : : "a" (convert_MMX_maskR));

	// process image
	for (y=0; y < HEIGHT; y++)
		for (x=0; x < WIDTH; x+=4) {
			__asm__ volatile (
				"movq (%%eax), %%mm1		\n"	// |rrrrrggg|gggbbbbb|
				"movq %%mm1,   %%mm2		\n"	// copy
				"movq %%mm1,   %%mm3		\n"	// copy

				// isolate components
				"pand %%mm5,   %%mm1		\n"	// |________|___bbbbb|
				"pand %%mm6,   %%mm2		\n"	// |_____ggg|ggg_____|
				"pand %%mm7,   %%mm3		\n"	// |rrrrr___|________|
			
				"psllw $3,     %%mm1		\n"	// |________|bbbbb___|
				"psllw $5,     %%mm2		\n"	// |gggggg__|________|
				"por  %%mm2,   %%mm1		\n"	// |gggggg__|bbbbb___|

				"psrlw $8,     %%mm3		\n"	// |________|rrrrr___|

				"movq %%mm3,   %%mm4		\n"
				
				// construct 32bpp
				"punpcklbw %%mm1, %%mm3		\n"	// |________|rrrrr___|gggggg__|bbbbb___|
				"punpckhbw %%mm1, %%mm4		\n"

				// save 32bpp pixels
#ifdef NONTEMPORAL
				"movntq %%mm3,  (%%ebx)		\n"
				"movntq %%mm4, 8(%%ebx)		\n"
#else
				"movq %%mm3,  (%%ebx)		\n"
				"movq %%mm4, 8(%%ebx)		\n"
#endif
				: 
				: "a" (&image_16bpp[y][x]),
				  "b" (&image_32bpp[y][x])
				: "memory"
			);
		}
}
#endif // PLAINC

void fill_image_16bpp(unsigned int SEED) {
	int x, y;

	srand(SEED);
	for (y=0; y < HEIGHT; y++)
		for (x=0; x < WIDTH; x++)
			image_16bpp[y][x] = rand() % 65536;
}


#ifndef PLAINC
static uint8_t convert_SSE2_maskR[16] __attribute__((aligned(16)));
static uint8_t convert_SSE2_maskG[16] __attribute__((aligned(16)));
static uint8_t convert_SSE2_maskB[16] __attribute__((aligned(16)));

void convert_SSE2() {
	int x, y;

	// preload masks
	__asm__ volatile ("movdqa (%%eax), %%xmm5" : : "a" (convert_SSE2_maskB));
	__asm__ volatile ("movdqa (%%eax), %%xmm6" : : "a" (convert_SSE2_maskG));
	__asm__ volatile ("movdqa (%%eax), %%xmm7" : : "a" (convert_SSE2_maskR));

	// process image
	int n = 0;
	for (y=0; y < HEIGHT; y++) {
		for (x=0; x < WIDTH; x+=8) {
			n++;
			__asm__ volatile (
				"movdqa (%%eax), %%xmm1		\n"	// |rrrrrggg|gggbbbbb|
				"movdqa %%xmm1,  %%xmm2		\n"	// copy
				"movdqa %%xmm1,  %%xmm3		\n"	// copy

				// isolate components
				"pand %%xmm5,  %%xmm1		\n"	// |________|___bbbbb|
				"pand %%xmm6,  %%xmm2		\n"	// |_____ggg|ggg_____|
				"pand %%xmm7,  %%xmm3		\n"	// |rrrrr___|________|
			
				"psllw $3,     %%xmm1		\n"	// |________|bbbbb___|
				"psllw $5,     %%xmm2		\n"	// |gggggg__|________|
				"psrlw $8,     %%xmm3		\n"	// |________|rrrrr___|
				"por  %%xmm2,  %%xmm1		\n"	// |gggggg__|bbbbb___|

				"movdqa %%xmm3,  %%xmm2		\n"
				
				// construct 32bpp
				"punpcklbw %%xmm1, %%xmm2	\n"	// |________|rrrrr___|gggggg__|bbbbb___|
				"punpckhbw %%xmm1, %%xmm3	\n"
			

				// save 32bpp pixels
#ifdef NONTEMPORAL
				"movntdq %%xmm2,   (%%ebx)		\n"
				"movntdq %%xmm3, 16(%%ebx)		\n"
#else
				"movdqa %%xmm2,   (%%ebx)		\n"
				"movdqa %%xmm3, 16(%%ebx)		\n"
#endif
				: 
				: "a" (&image_16bpp[y][x]),
				  "b" (&image_32bpp[y][x])
				: "memory"
			);
		}
	}

#ifdef NONTEMPORAL
	__asm__ volatile ("sfence");
#endif
}

void convert_SSE2_2() {
	int x, y;

	// preload masks
	__asm__ volatile ("movdqa (%%eax), %%xmm5" : : "a" (convert_SSE2_maskB));
	__asm__ volatile ("movdqa (%%eax), %%xmm6" : : "a" (convert_SSE2_maskG));
	__asm__ volatile ("movdqa (%%eax), %%xmm7" : : "a" (convert_SSE2_maskR));

	// process image
	int n = 0;
	for (y=0; y < HEIGHT; y++) {
		for (x=0; x < WIDTH; x+=16) {
			n++;
			__asm__ volatile (
				"movdqa   (%%eax), %%xmm1		\n"	// |rrrrrggg|gggbbbbb|
				"movdqa 16(%%eax), %%xmm4		\n"	// |rrrrrggg|gggbbbbb|
				"movdqa %%xmm1,  %%xmm2		\n"	// copy
				"movdqa %%xmm1,  %%xmm3		\n"	// copy
				"movdqa %%xmm4,  %%xmm5		\n"	// copy
				"movdqa %%xmm4,  %%xmm6		\n"	// copy

#if 1
				// isolate components
				"pand (convert_SSE2_maskB),  %%xmm1		\n"	// |________|___bbbbb|
				"pand (convert_SSE2_maskG),  %%xmm2		\n"	// |_____ggg|ggg_____|
				"pand (convert_SSE2_maskR),  %%xmm3		\n"	// |rrrrr___|________|

				"pand (convert_SSE2_maskB),  %%xmm1		\n"	// |________|___bbbbb|
				"pand (convert_SSE2_maskG),  %%xmm2		\n"	// |_____ggg|ggg_____|
				"pand (convert_SSE2_maskR),  %%xmm3		\n"	// |rrrrr___|________|
			
				"psllw $3,     %%xmm1		\n"	// |________|bbbbb___|
				"psllw $5,     %%xmm2		\n"	// |gggggg__|________|
				"psrlw $8,     %%xmm3		\n"	// |________|rrrrr___|
				"por  %%xmm2,  %%xmm1		\n"	// |gggggg__|bbbbb___|

				"movdqa %%xmm3,  %%xmm2		\n"
			
				"psllw $3,     %%xmm4		\n"	// |________|bbbbb___|
				"psllw $5,     %%xmm5		\n"	// |gggggg__|________|
				"psrlw $8,     %%xmm6		\n"	// |________|rrrrr___|
				"por  %%xmm4,  %%xmm5		\n"	// |gggggg__|bbbbb___|

				"movdqa %%xmm5,  %%xmm4		\n"
				
				// construct 32bpp
				"punpcklbw %%xmm1, %%xmm2	\n"	// |________|rrrrr___|gggggg__|bbbbb___|
				"punpckhbw %%xmm1, %%xmm3	\n"
				"punpcklbw %%xmm4, %%xmm5	\n"	// |________|rrrrr___|gggggg__|bbbbb___|
				"punpckhbw %%xmm4, %%xmm6	\n"
#endif
				// save 32bpp pixels
#ifdef NONTEMPORAL
				"movntdq %%xmm2,   (%%ebx)		\n"
				"movntdq %%xmm3, 16(%%ebx)		\n"
				"movntdq %%xmm5, 32(%%ebx)		\n"
				"movntdq %%xmm6, 48(%%ebx)		\n"
#else
				"movdqa %%xmm2,   (%%ebx)		\n"
				"movdqa %%xmm3, 16(%%ebx)		\n"
				"movdqa %%xmm5, 32(%%ebx)		\n"
				"movdqa %%xmm6, 48(%%ebx)		\n"
#endif
				: 
				: "a" (&image_16bpp[y][x]),
				  "b" (&image_32bpp[y][x])
				: "memory"
			);
		}
	}
	
	__asm__ volatile ("sfence");
}
#endif // PLAINC


const int default_repeatcount = 100;

#ifndef PLAINC
    #define OPT_COUNT 7
#else
    #define OPT_COUNT 4
#endif

static char* opts[OPT_COUNT] = {
	/* 0 */ "lookup8",
	/* 1 */ "lookup82",
	/* 2 */ "lookup16",
	/* 3 */ "naive",
#ifndef PLAINC
	/* 4 */ "MMX",
	/* 5 */ "SSE2",
	/* 6 */ "SSE22"
#endif
};

void help() {
	int i;
	printf("pixconf ");

	printf("%s", opts[0]);
	for (i=1; i < OPT_COUNT; i++)
		printf("|%s", opts[i]);
	
	printf(" [repeat count=%d]\n", default_repeatcount);
	exit(1);
}


int main(int argc, char* argv[]) {

	int procedure;
	int repeatcount;
	struct timeval t1, t2;

#define timeval_sec(val) ((val).tv_sec * 1000000l + (val).tv_usec)

	switch (argc) {
		case 2:
			for (procedure=0; procedure < OPT_COUNT; procedure++)
				if (strcasecmp(argv[1], opts[procedure]) == 0)
					break;

			repeatcount = default_repeatcount;
			break;
		case 3:
			for (procedure=0; procedure < OPT_COUNT; procedure++)
				if (strcasecmp(argv[1], opts[procedure]) == 0)
					break;

			repeatcount = (atoi(argv[2]) >= 0) ? atoi(argv[2]) : default_repeatcount;
			break;
		default:
			help();
			break;
	}


	prepare_lookups();
	fill_image_16bpp(time(NULL));

	switch (procedure) {
		case 0:
			printf("running lookup8 %d times on image %d x %d\n", repeatcount, WIDTH, HEIGHT);
			gettimeofday(&t1, NULL);
			while (repeatcount--)
				convert_lookup8();
			gettimeofday(&t2, NULL);

			printf("time = %ld microseconds\n", timeval_sec(t2) - timeval_sec(t1));
			break;
		
		case 1:
			printf("running lookup8(2) %d times on image %d x %d\n", repeatcount, WIDTH, HEIGHT);
			gettimeofday(&t1, NULL);
			while (repeatcount--)
				convert_lookup8_2();
			gettimeofday(&t2, NULL);

			printf("time = %ld microseconds\n", timeval_sec(t2) - timeval_sec(t1));
			break;

		case 2:
			printf("running lookup16 %d times on image %d x %d\n", repeatcount, WIDTH, HEIGHT);
			gettimeofday(&t1, NULL);
			while (repeatcount--)
				convert_lookup16();
			gettimeofday(&t2, NULL);

			printf("time = %ld microseconds\n", timeval_sec(t2) - timeval_sec(t1));
			break;

		case 3:
			printf("running naive %d times on image %d x %d\n", repeatcount, WIDTH, HEIGHT);
			gettimeofday(&t1, NULL);
			while (repeatcount--)
				convert_naive();
			gettimeofday(&t2, NULL);

			printf("time = %ld microseconds\n", timeval_sec(t2) - timeval_sec(t1));
			break;

#ifndef PLAINC
		case 4:
			printf("running MMX %d times on image %d x %d\n", repeatcount, WIDTH, HEIGHT);
			gettimeofday(&t1, NULL);
			while (repeatcount--)
				convert_MMX();
			__asm__ volatile ("emms");
			gettimeofday(&t2, NULL);

			printf("time = %ld microseconds\n", timeval_sec(t2) - timeval_sec(t1));
			break;

		case 5:
			printf("running SSE2 %d times on image %d x %d\n", repeatcount, WIDTH, HEIGHT);
			gettimeofday(&t1, NULL);
			while (repeatcount--)
				convert_SSE2();
			gettimeofday(&t2, NULL);

			printf("time = %ld microseconds\n", timeval_sec(t2) - timeval_sec(t1));
			break;

		case 6:
			printf("running unrolled SSE2 %d times on image %d x %d\n", repeatcount, WIDTH, HEIGHT);
			gettimeofday(&t1, NULL);
			while (repeatcount--)
				convert_SSE2_2();
			gettimeofday(&t2, NULL);

			printf("time = %ld microseconds\n", timeval_sec(t2) - timeval_sec(t1));
			break;
#endif // PLAINC

		default:
			help();
	}

	return 0;
}

// eof
