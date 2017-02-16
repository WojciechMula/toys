/*
	What is it?
	------------------------------------------------------------------------

	Demo program use to test/profile asm routines that perform saturated
	add of two 16bpp images.	Algorithms were described on my webpage (polish
	text) http://0x80.pl/artices/saturated_add.html.


	Usage
	------------------------------------------------------------------------

	Run program without arguments to read help.


	------------------------------------------------------------------------

	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	created: 2008-06-08
	License: public domain
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <strings.h>
#include <errno.h>

#include "load_ppm.h"
#include "Xscr.h"

#include "x86.c"
#include "mmx.c"

void usage(FILE* file) {
	const char* usage =

"Saturated add of 16bpp images\n"
"\n"
"Usage:\n"
"\n"
"progname mmx|x86 filename.ppm\n"
"\n"
"   Perform saturated addition on given PPM (RGB, 640x480, 24bpp).\n"
"   Image is displayed in X-Window, user controls program through\n"
"   commands entered in console.\n"
;

	fputs(usage, file);
}


extern int errno;

void ordie(char* info, ...);
void die(char* info, ...);

#define SIZEX 640
#define SIZEY 480

uint16_t image1[SIZEY][SIZEX];
uint16_t image2[SIZEY][SIZEX];
uint16_t image3[SIZEY][SIZEX];

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

void keyboard(int x, int y, Time t, KeySym c, KeyOrButtonState s, unsigned int state) {
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
			memcpy( (void*)&image1[0][0], (void*)&image3[0][0], SIZEX*SIZEY*2);
			Xscr_redraw_now();
			break;

		case XK_i:
		case XK_I:
			memcpy( (void*)&image2[0][0], (void*)&image3[0][0], SIZEX*SIZEY*2);
			break;

		case XK_c:
		case XK_C:
			for (y=0; y < SIZEY; y++)
				for (x=0; x < SIZEX; x++)
					image2[y][x] = 0x0841;
			break;

		case XK_a:
		case XK_A:
		case XK_Return:
		case XK_space:
			if (MMX)
				MMX_saturated_add(&image1[0][0], &image2[0][0], SIZEX, SIZEY);
			else
				x86_saturated_add(&image1[0][0], &image2[0][0], SIZEX, SIZEY);
			Xscr_redraw();
			break;

		case XK_q:
		case XK_Q:
			Xscr_quit();
			break;
	}
}

int main(int argc, char* argv[]) {
	int times;

	if (argc != 3) {
		usage(stdout);
		exit(EXIT_FAILURE);
	}

	int result;
	int img_width, img_height, img_bits;
	uint8_t *img;

	FILE* file;
	if (strcasecmp(argv[1], "mmx") == 0) MMX = 1; else
	if (strcasecmp(argv[1], "x86") == 0) MMX = 0;
	else {
		usage(stdout);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[2], "rb");
	if (!file)
		die("Can't read %s", argv[2]);
	result = ppm_load_16bpp(file, &img_width, &img_height, &img_bits, &img, 0);
	fclose(file);

	if (result < 0)
		die("PPM file error: %s", PPM_errormsg[-result]);
	if (img_width != SIZEX || img_height != SIZEY)
		die("Wrong dimensions of image: %dx%d, required 640x480",
		    img_width, img_height);
	if (img_bits != 255)
		die("PPM max value is %d, required 255", img_bits);

	memcpy( (void*)&image1[0][0], (void*)img, SIZEX*SIZEY*2);
	memcpy( (void*)&image2[0][0], (void*)img, SIZEX*SIZEY*2);
	memcpy( (void*)&image3[0][0], (void*)img, SIZEX*SIZEY*2);
	free(img);


	puts(short_help);
	result = Xscr_mainloop(
		SIZEX, SIZEY, DEPTH_16bpp, False, (uint8_t*)&image1[0][0],
		keyboard, NULL, NULL,
		"Saturated add of 16bpp pixels"
	);

	if (result < 0) {
		printf("Xscr error: %s\n", Xscr_error_str(result));
		return 1;
	}
	else
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
