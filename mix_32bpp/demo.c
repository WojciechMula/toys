/*
	Image crossfading --- SSE implementation, $Revision: 1.10 $

	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	License: BSD

	initial release 5-06-2008, last update $Date: 2008-06-21 22:15:11 $

	----------------------------------------------------------------------

	Comparison of three crossfading procedures:
	1. x86    --- naive C implementation
	2. sse4   --- SSE implementation
	3. sse4-2 --- SSE4 implementation, that use new instruction PMADDUBSW
*/

#ifndef _XOPEN_SOURCE
#	define _XOPEN_SOURCE 600
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdarg.h>
#include <stdint.h>
#include <sys/time.h>
#include <time.h>
#include <immintrin.h>
#include <emmintrin.h>

#include "../Xscr/Xscr.h"
#include "../loadppm/load_ppm.h"


//=== global variables ===================================================
int width, height, maxval;
uint8_t *imgA, *imgB, *data;
uint8_t alpha;

int function = 0;


#define OPT_COUNT 6

static char* function_name[OPT_COUNT] = {
	"x86", "SSE4", "SSE4-2", "swar-64bit", "SSE(1)", "SSE(2)",
};


//=== common functions ===================================================
uint32_t getTime(void) {
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

	exit(2);
}



//=== crossfading implementations ========================================
#include "blend_scalar.c"
#include "blend_sse4.c"
#include "blend_sse42.c"
#include "blend_swar_64bit.c"
#include "blend_sse.c"


//=== X11 procedures =====================================================
static struct {
	uint32_t sum;
	int32_t n;
} frequency[OPT_COUNT];


void motion(
	int x, int y, Time t,
	unsigned int kb_mask
) {
	static uint8_t old_alpha = 255;

	alpha = (255*x/width);
	if (alpha != old_alpha) {
		uint32_t t1, t2;

		t1 = getTime();
		switch (function) {
			case 0:
				printf("%s", function_name[function]);
				blend();
				break;
			case 1:
				printf("%s", function_name[function]);
				SSE4_blend();
				break;
			case 2:
				printf("%s", function_name[function]);
				SSE42_blend();
				break;
			case 3:
				printf("%s", function_name[function]);
				swar_64bit_blend();
				break;
			case 4:
				printf("%s", function_name[function]);
				blend_sse_1();
				break;
			case 5:
				printf("%s", function_name[function]);
				blend_sse_2();
				break;
			default:
				return;
		}
		t2 = getTime();
		printf(" = %d us\n", t2-t1);
		Xscr_redraw();
		old_alpha = alpha;

		frequency[function].n   += 1;
		frequency[function].sum += (t2 - t1);
	}
}


void keyboard(
	int x, int y, Time t,
	KeySym c,
	KeyOrButtonState s,
	unsigned int state
) {

	if (s != Pressed)
		return;

	switch (c) {
		case XK_Tab:
		case XK_Return:
		case XK_space:
			function = (function + 1) % OPT_COUNT;
			break;

		case XK_1:
			function = 0;
			break;

		case XK_2:
			function = 1;
			break;

		case XK_3:
			function = 2;
			break;

		case XK_4:
			function = 3;
			break;

		case XK_5:
			function = 4;
			break;

		case XK_6:
			function = 5;
			break;

		case XK_q:
		case XK_Q:
			Xscr_quit();
			break;
	}
}


void view(const char* file1, const char* file2) {
	FILE *f;
	int err;

	int w1, h1, w2, h2;

	f = fopen(file1, "rb");
	if (f == NULL)
		die("Can't open %s", file1);
	err = ppm_load_32bpp(f, &w1, &h1, &maxval, &imgA, 32);
	if (err < 0)
		die("Can't read %s: %s", file1, PPM_errormsg[-err]);
	else
	if ((((uintptr_t)imgA) & 0x0f) != 0x00)
		die("Compile load_ppm library with -DPPM_ALIGN_MALLOC=16.");
	fclose(f);

	f = fopen(file2, "rb");
	if (f == NULL)
		die("Can't open %s", file2);
	ppm_load_32bpp(f, &w2, &h2, &maxval, &imgB, 32);
	if (err < 0)
		die("Can't read %s: %s", file2, PPM_errormsg[-err]);
	else
	if ((((uintptr_t)imgB) & 0x0f) != 0x00)
		die("Compile load_ppm library with -DPPM_ALIGN_MALLOC=16.");
	fclose(f);


	printf("imgA = %d(%d) x %d, imgB = %d(%d) x %d\n",
		w1,
		ppm_bytes_per_line(w1, 4, 32),
		h1,
		w2,
		ppm_bytes_per_line(w2, 4, 32),
		h2
	);


	if (ppm_bytes_per_line(w1, 4, 32) != ppm_bytes_per_line(w2, 4, 32)) {
		die("Images should have similar width.");
	}

	width  = ppm_bytes_per_line(w1, 4, 16)/4;
	height = h1 < h2 ? h1 : h2;

	printf("%d x %d\n", width, height);

	if (posix_memalign((void*)&data, 16, width*height*4))
		die("No free memory");

	memcpy(data, imgA, width*height*4);

	int i;
	for (i=0; i < OPT_COUNT; i++) {
		frequency[i].n = 0;
		frequency[i].sum = 0;
	}

	// run mainloop
	err = Xscr_mainloop(
		width, height, DEPTH_32bpp, False, data,
		keyboard, motion, NULL,
		"Image mixing demo"
	);

	// check exit status
	if (err < 0) {
		printf("Xscr error: %s\n", Xscr_error_str(err));
	}
	else {
		for (i=0; i < OPT_COUNT; i++) {
			printf("function %-11s called %5d time(s) ",
				function_name[i], frequency[i].n
			);
			if (frequency[i].n > 0)
				printf("average time %d us\n",
					frequency[i].sum / frequency[i].n
				);
			else
				putchar('\n');
		}
	}

	free(imgA);
	free(imgB);
	free(data);
}


int main(int argc, char* argv[]) {
    if (argc < 3) {
		printf("%s file1.ppm file2.ppm\n", argv[0]);
		return EXIT_FAILURE;
	}
    else
        view(argv[1], argv[2]);

	return EXIT_SUCCESS;
}

