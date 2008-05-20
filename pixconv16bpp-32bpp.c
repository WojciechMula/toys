#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static uint32_t lookup8_lo[256] __attribute__((aligned(64)));
static uint32_t lookup8_hi[256] __attribute__((aligned(64)));
static uint32_t lookup16[256*256] __attribute__((aligned(64)));

#define WIDTH	(1024)
#define HEIGHT	768

static uint16_t image_16bpp[HEIGHT+1][WIDTH] __attribute__((aligned(16)));
static uint32_t image_32bpp[HEIGHT+1][WIDTH] __attribute__((aligned(16)));


void prepare_lookups() {
	uint32_t x, r, g, b;

	for (x=0; x < 256; x++) {
		lookup8_lo[x] =
			  (x & 0x1f) << 3	// red
			| (x & 0xe0) << 3;	// green[0:2]

		lookup8_lo[x] =
			  (x & 0x07) << (8+3)	// green[3:5]
			| (x & 0xf8) << 16;	// blue
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


static uint8_t convert_MMX_maskR[8];
static uint8_t convert_MMX_maskG[8];
static uint8_t convert_MMX_maskB[8];

void convert_MMX() {
	int x, y;

	// preload masks
	asm volatile ("movq (%%eax), %%mm5" : : "a" (convert_MMX_maskB));
	asm volatile ("movq (%%eax), %%mm6" : : "a" (convert_MMX_maskG));
	asm volatile ("movq (%%eax), %%mm7" : : "a" (convert_MMX_maskR));

	// process image
	for (y=0; y < HEIGHT; y++)
		for (x=0; x < WIDTH; x+=4) {
			asm volatile (
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
				"movntq %%mm3,  (%%ebx)		\n"
				"movntq %%mm4, 8(%%ebx)		\n"
				: 
				: "a" (&image_16bpp[y][x]),
				  "b" (&image_32bpp[y][x])
				: "memory"
			);
		}
}


void fill_image_16bpp(unsigned int SEED) {
	int x, y;

	srand(SEED);
	for (y=0; y < HEIGHT; y++)
		for (x=0; x < WIDTH; x++)
			image_16bpp[y][x] = rand() % 65536;
}


static uint8_t convert_SSE2_maskR[16];
static uint8_t convert_SSE2_maskG[16];
static uint8_t convert_SSE2_maskB[16];

void convert_SSE2() {
	int x, y;
	uint32_t addr;

	// preload masks
	asm volatile ("movdqu (%%eax), %%xmm5" : : "a" (convert_SSE2_maskB));
	asm volatile ("movdqu (%%eax), %%xmm6" : : "a" (convert_SSE2_maskG));
	asm volatile ("movdqu (%%eax), %%xmm7" : : "a" (convert_SSE2_maskR));

	// process image
	for (y=0; y < HEIGHT; y++) {
		asm volatile ("movdqa (%%eax), %%xmm4" : : "a" (&image_16bpp[y][0]));
//		asm volatile ("prefetcht1 (%%eax)" : : "a" (&image_16bpp[y+1][0]));
		for (x=0; x < WIDTH; x+=8) {
			asm volatile (
				"movdqa %%xmm4,  %%xmm1		\n"	// copy
				"movdqa %%xmm4,  %%xmm2		\n"	// copy
				"movdqa %%xmm4,  %%xmm3		\n"	// copy
				"movdqa 16(%%eax), %%xmm4		\n"	// |rrrrrggg|gggbbbbb|

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
				"movntdq %%xmm2,   (%%ebx)		\n"
				"movntdq %%xmm3, 16(%%ebx)		\n"
				: 
				: "a" (&image_16bpp[y][x]),
				  "b" (&image_32bpp[y][x])
				: "memory"
			);
		}
	}
	
	asm volatile ("sfence");
}


const int default_repeatcount = 100;

void help() {
	printf(
		"pixconv lookup8|lookup16|naive|mmx|sse2 [repeat count=%d]\n", default_repeatcount
	);
	exit(1);
}


int main(int argc, char* argv[]) {
	static char* opts[5] = {
		/* 0 */ "lookup8",
		/* 1 */ "lookup16",
		/* 2 */ "naive",
		/* 3 */ "MMX",
		/* 4 */ "SSE2",
	};

	int procedure;
	int repeatcount;
	clock_t t1, t2;

	switch (argc) {
		case 2:
			for (procedure=0; procedure < 5; procedure++)
				if (strcasecmp(argv[1], opts[procedure]) == 0)
					break;

			repeatcount = default_repeatcount;
			break;
		case 3:
			for (procedure=0; procedure < 5; procedure++)
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
			printf("running lookup8 %d times\n", repeatcount);
			t1 = clock();
			while (repeatcount--)
				convert_lookup8();
			t2 = clock();

			printf("time = %0.7fs\n", (double)(t2-t1)/CLOCKS_PER_SEC);
			break;
		case 1:
			printf("running lookup16 %d times\n", repeatcount);
			t1 = clock();
			while (repeatcount--)
				convert_lookup16();
			t2 = clock();

			printf("time = %0.7fs\n", (double)(t2-t1)/CLOCKS_PER_SEC);
			break;
		case 2:
			printf("running naive %d times\n", repeatcount);
			t1 = clock();
			while (repeatcount--)
				convert_naive();
			t2 = clock();

			printf("time = %0.7fs\n", (double)(t2-t1)/CLOCKS_PER_SEC);
			break;
		case 3:
			printf("running MMX %d times\n", repeatcount);
			t1 = clock();
			while (repeatcount--)
				convert_MMX();
			t2 = clock();

			asm volatile ("emms");

			printf("time = %0.7fs\n", (double)(t2-t1)/CLOCKS_PER_SEC);
			break;
		case 4:
			printf("running SSE2 %d times\n", repeatcount);
			t1 = clock();
			while (repeatcount--)
				convert_SSE2();
			t2 = clock();

			printf("time = %0.7fs\n", (double)(t2-t1)/CLOCKS_PER_SEC);
			break;
		default:
			help();
	}

	return 0;
}
