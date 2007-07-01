/*
	$Date: 2007-07-01 23:21:09 $, $Revision: 1.4 $

	+    1    +    2    +    3    +    4    +    5    +    6    +     7   +
	01234567890123456789012345678901234567890123456789012345678901234567890
	Demo program use to test/profile asm routines that perform saturated
	add of two 16bpp images.	Algorithms were described on my webpage (polish
	text) http://www.mula.w.pl/artices/saturared_add.html.

	Additional files aer required: load_ppm.c, load_ppm.h, Xscr.c, Xscr.h;
	avaiable on my site: http://www.mula.w.pl/snippets/index.html.

	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://www.mula.w.pl

	License: public domain
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <X11/Xlib.h>

#include "load_ppm.c"
#include "Xscr.c"

void usage(FILE* file) {
	const char* usage =

"Saturated add of 16bpp images\n"
"Author: Wojciech Mula, wojciech_mula@poczta.onet.pl\n"
"\n"
"a. progname test mmx|x86 times\n"
"b. progname view mmx|x86 filename.ppm\n"
"c. progname help\n"
"\n"
"a. Run procedure x86 or MMX optimized that perform saturated\n"
"   addition as many times as user want. Useful for profiling.\n"
"\n"
"b. Perform saturated addition on given PPM (RGB, 640x480, 24bpp).\n"
"   Image is displayed in X-Window, user controls program through\n"
"   commands entered in console.\n";

	fputs(usage, file);
}


void x86_saturated_add(uint16_t *A, uint16_t *B, int width, int height) {
	int x, y;
	uint32_t *a;
	uint32_t *b;

	a = (uint32_t*)A;
	b = (uint32_t*)B;
	for (y=0; y < height; y++)
		for (x=0; x < width/2; x++) {
		asm(
		"   mov %%eax, %%ecx                      \n\t"
		"   mov %%ebx, %%edx                      \n\t"
		"                                         \n\t"
		"   andl $0x07e0f81f, %%eax               \n\t"
		"   andl $0x07e0f81f, %%ebx               \n\t"
		"                                         \n\t"
		"   andl $0xf81f07e0, %%ecx               \n\t"
		"   andl $0xf81f07e0, %%edx               \n\t"
		"                                         \n\t"
		"   addl %%ebx, %%eax                     \n\t"
		"   addl %%ecx, %%edx                     \n\t"
		"                                         \n\t"
		"   movl %%eax, %%ebx                     \n\t"
		"   movl %%edx, %%ecx                     \n\t"
		"                                         \n\t"
		"   rcrl $1, %%edx                        \n\t"
		"   shrl $1, %%ebx                        \n\t"
		"                                         \n\t"
		"   andl $0x80100400, %%edx               \n\t"
		"   andl $0x04008010, %%ebx               \n\t"
		"   orl  %%edx, %%ebx                     \n\t"
		"                                         \n\t"
		"   andl $0x07e0f81f, %%eax               \n\t"
		"   andl $0xf81f07e0, %%ecx               \n\t"
		"   orl  %%ecx, %%eax                     \n\t"
		"                                         \n\t"
		"   orl  %%ebx, %%eax                     \n\t"
		"   movl %%ebx, %%edx                     \n\t"
		"   shrl $4, %%edx                        \n\t"
		"   subl %%edx, %%ebx                     \n\t"
		"                                         \n\t"
		"   orl  %%ebx, %%eax                     \n\t"
		"   shrl $1, %%ebx                        \n\t"
		"   andl $0x00200020, %%ebx               \n\t"
		"   orl  %%ebx, %%eax                     \n\t"
		: "=a" (*a)
		: "a" (*a), "b" (*b)
		: "%ecx", "%edx"
		);

		a++;
		b++;
		}
}


void MMX_saturated_add(uint16_t *A, uint16_t *B, int width, int height) {
	static uint16_t mask_rb[4] = {0xf81f, 0xf81f, 0xf81f, 0xf81f};
	static uint16_t mask_g[4]  = {0x07e0, 0x07e0, 0x07e0, 0x07e0};
	static uint16_t fill_b[4]  = {0x00e0, 0x00e0, 0x00e0, 0x00e0};
	static uint16_t fill_g[4]  = {0xf800, 0xf800, 0xf800, 0xf800};
	int x, y;
	uint64_t *a;
	uint64_t *b;

	asm(
	"   movq (%0), %%mm7                      \n\t"
	"   movq (%1), %%mm6                      \n\t"
	"   movq (%2), %%mm5                      \n\t"
	"   movq (%3), %%mm4                      \n\t"
	:
	: "r" (mask_rb), "r" (mask_g), "r" (fill_b), "r" (fill_g)
	);

	a = (uint64_t*)A;
	b = (uint64_t*)B;
	for (y=0; y < height; y++)
		for (x=0; x < width/4; x++) {
		asm(
		"   movq (%%eax), %%mm0                   \n\t"
		"   movq (%%ebx), %%mm2                   \n\t"
		"   movq %%mm0, %%mm1                     \n\t"
		"   movq %%mm2, %%mm3                     \n\t"
		"                                         \n\t"
		"   pand %%mm7, %%mm0                     \n\t"
		"   pand %%mm6, %%mm1                     \n\t"
		"   por  %%mm5, %%mm2                     \n\t"
		"   por  %%mm4, %%mm3                     \n\t"
		"                                         \n\t"
		"   paddusb %%mm2, %%mm0                  \n\t"
		"   paddusw %%mm3, %%mm1                  \n\t"
		"                                         \n\t"
		"   pand %%mm7, %%mm0                     \n\t"
		"   pand %%mm6, %%mm1                     \n\t"
		"   por  %%mm1, %%mm0                     \n\t"
		"                                         \n\t"
		"   movq %%mm0, (%%eax)                   \n\t"
		: /* no ouput */
		: "a" (a), "b" (b)
		: "memory"
		);

		a++;
		b++;
		}
}

extern int errno;

void ordie(char* info, ...);
void die(char* info, ...);

uint16_t image1[480][640];
uint16_t image2[480][640];
uint16_t image3[480][640];


char* short_help =
	"a, <Enter>, <Space> - add image2 to image1\n"
	"r    - reset image1 (use original image)\n"
	"\n"
	"i    - set image2 to original image \n"
	"c    - set image2 to const value (R=1, G=2, B=1)\n"
	"\n"
	"?, h - this help\n"
	"q    - quit\n";

char MMX;

void keyboard(int x, int y, Time t, KeySym c, State s, unsigned int state) {
	if (s == Released)
		return;


	switch (c) {
		case XK_question:
		case XK_h:
		case XK_H:
			puts(short_help);
			break;

		case XK_r:
		case XK_R:
			memcpy( (void*)&image1[0][0], (void*)&image3[0][0], 640*480*2);
			Xscr_redraw_now();
			break;

		case XK_i:
		case XK_I:
			memcpy( (void*)&image2[0][0], (void*)&image3[0][0], 640*480*2);
			break;

		case XK_c:
		case XK_C:
			for (y=0; y < 480; y++)
				for (x=0; x < 640; x++)
					image2[y][x] = 0x0841;
			break;

		case XK_a:
		case XK_A:
		case XK_Return:
		case XK_space:
			if (MMX)
				MMX_saturated_add(&image1[0][0], &image2[0][0], 640, 480);
			else
				x86_saturated_add(&image1[0][0], &image2[0][0], 640, 480);
			Xscr_redraw();
			break;

		case XK_q:
		case XK_Q:
			Xscr_quit();
			break;
	}
}


int main(int argc, char* argv[]) {
	int times, result, c, x, y;
	uint16_t R, G, B;
	int img_width, img_height, img_bits;
	char update, quit;
	char ans[256];
	uint8_t *img, *pix;

	FILE* file;

	if (argc == 1) {
		usage(stdout);
		exit(EXIT_FAILURE);
	}
	// progname help
	if (strcasecmp(argv[1], "help") == 0) {
		usage(stdout);
		exit(EXIT_SUCCESS);
	}
	// progname test mmx|x86 times
	if (strcasecmp(argv[1], "test") == 0 && argc == 4) {
		int times;
		times = atoi(argv[3]) > 0 ? atoi(argv[3]) : 1000;
		if (strcasecmp(argv[2], "MMX") == 0) {
			while (times--)
				MMX_saturated_add(&image1[0][0], &image2[0][0], 640, 480);
			return 0;
		}
		if (strcasecmp(argv[2], "x86") == 0) {
			while (times--)
				x86_saturated_add(&image1[0][0], &image2[0][0], 640, 480);
			return 0;
		}
	}
	// progname view mmx|x86 filename
	if (strcasecmp(argv[1], "view") == 0 && argc == 4) {
		if (strcasecmp(argv[2], "mmx") == 0) MMX = 1; else
		if (strcasecmp(argv[2], "x86") == 0) MMX = 0;
		else {
			usage(stdout);
			exit(EXIT_FAILURE);
		}

		file = fopen(argv[3], "rb");
		if (!file)
			die("Can't read %s", argv[3]);
		result = ppm_load_16bpp(file, &img_width, &img_height, &img_bits, &img, 0);
		fclose(file);

		if (result < 0)
			die("PPM file error: %s", PPM_errormsg[-result]);
		if (img_width != 640 || img_height != 480)
			die("Wrong dimensions of image: %dx%d, required 640x480",
			    img_width, img_height);
		if (img_bits != 255)
			die("PPM max value is %d, required 255", img_bits);

		memcpy( (void*)&image1[0][0], (void*)img, 640*480*2);
		memcpy( (void*)&image2[0][0], (void*)img, 640*480*2);
		memcpy( (void*)&image3[0][0], (void*)img, 640*480*2);
		free(img);

	
		puts(short_help);
		result = Xscr_mainloop(
			640, 480, DEPTH_16bpp, (uint8_t*)&image1[0][0], false,
			keyboard, NULL, NULL,
			"Saturated add of 16bpp pixels"
		);

		if (result < 0) {
			printf("Xscr error: %s\n", Xscr_errormsg[-result]);
			return 1;
		}
		else
			return 0;
	}

	usage(stdout);
	return 0;
}


void ordie(char* info, ...) {
	va_list ap;
	if (errno != 0) {
		va_start(ap, info);
		vfprintf(stderr, info, ap);
		va_end(ap);
		fprintf(stderr, " [errno=%d]: %s\n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void die(char* info, ...) {
	va_list ap;

	va_start(ap, info);
	vfprintf(stderr, info, ap);
	fprintf(stderr, "\n");
	va_end(ap);

	exit(EXIT_FAILURE);
}

// vim: ts=2 sw=2 nowrap noexpandtab
