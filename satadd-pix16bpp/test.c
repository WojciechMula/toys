/*
	What is it?
	------------------------------------------------------------------------

	Demo program use to test/profile asm routines that perform saturated
	add of two 16bpp images.	Algorithms were described on my webpage (polish
	text) http://0x80.pl/artices/saturated_add.html.

	------------------------------------------------------------------------

	Run program without arguments to read help.

	------------------------------------------------------------------------

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

#include "x86.c"
#include "mmx.c"

void usage(FILE* file) {
	const char* usage =

"Saturated add of 16bpp images\n"
"\n"
"Usage:\n"
"\n"
"progname mmx|x86 times\n"
"\n"
"   Run procedure x86 or MMX optimized that perform saturated\n"
"   addition as many times as user want. Useful for profiling.\n"
;

	fputs(usage, file);
}

#define SIZEX 640
#define SIZEY 480

uint16_t image1[SIZEY][SIZEX];
uint16_t image2[SIZEY][SIZEX];
uint16_t image3[SIZEY][SIZEX];

int main(int argc, char* argv[]) {
	int times;

	if (argc != 3) {
		usage(stdout);
		exit(EXIT_FAILURE);
	}

	times = atoi(argv[2]) > 0 ? atoi(argv[2]) : 1000;
	if (strcasecmp(argv[1], "MMX") == 0) {
		while (times--)
				MMX_saturated_add(&image1[0][0], &image2[0][0], SIZEX, SIZEY);
			return 0;
	}
	if (strcasecmp(argv[1], "x86") == 0) {
		while (times--)
			x86_saturated_add(&image1[0][0], &image2[0][0], SIZEX, SIZEY);
		return 0;
	}

	usage(stdout);
	return 0;
}


// vim: ts=2 sw=2 nowrap noexpandtab
