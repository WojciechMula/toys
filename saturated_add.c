/*
	$Date: 2007-06-29 23:11:55 $, $Revision: 1.2 $

	Demo program use to test/profile asm routines
	that perform saturated add of two 16bpp images.
	Algorithms were described on my webpage (polish
	text) http://www.mula.w.pl/artices/saturared_add.html

	load_ppm.c is also availlable on my site:
	http://www.mula.w.pl/snippets/load_ppm.c
	(no headers!).

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

void usage(FILE* file) {
	const char* usage =

"Saturated add of 16bpp images\n"
"Author: Wojciech Mula, wojciech_mula@poczta.onet.pl\n"
"\n"
"a. progname test mmx|x86 times\n"
"b. progname view mmx|x86 filename.ppm\n"
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

/* X-Window local variables ****************************/
Display	*display;  // display
int	screen;    // main screen
Window	window;
GC      defaultGC; // graphics context

int init_graphics() {
//	XSetWindowAttributes wa;

	// try open defult display
	display = XOpenDisplay(NULL);
	if (!display)
		die("Can't open display.");
	
	screen = DefaultScreen(display);
	if (DefaultDepth(display, screen) != 16)
		die("This program needs depth 16bpp, your screen is %dbpp", DefaultDepth(display, screen));

	window = XCreateSimpleWindow( // make a simple window
		display, 
		RootWindow(display, screen),
		0, 0,
		640, 480,
		1,
		BlackPixel(display, screen),
		WhitePixel(display, screen)
		);

//	wa.backing_store = Always;
//	XChangeWindowAttributes(display, window, CWBackingStore, &wa);

	XMapWindow(display, window); // show it on the screen

	// setup graphics context
	defaultGC = XCreateGC(display, window, 0, 0);
	XSetForeground(display, defaultGC, BlackPixel(display, screen) );
	XSetBackground(display, defaultGC, WhitePixel(display, screen) );

	XFlush(display); // send command to the X-server
	return 1;
}

char* short_help =
	"a, <Enter> - add image2 to image1\n"
	"r    - reset image1 (use original image)\n"
	"\n"
	"i    - set image2 to original image \n"
	"c    - set image2 to const value (R=1, G=2, B=1)\n"
	"\n"
	"m    - use MMX procedure\n"
	"x    - use x86 procedure\n"
	"\n"
	"?, h - this help\n"
	"q    - quit\n";


int main(int argc, char* argv[]) {
	int times, result, c, x, y;
	uint16_t R, G, B;
	int img_width, img_height, img_bits;
	char MMX, update, quit;
	char ans[256];
	uint8_t *img, *pix;
	XImage* image;

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
		result = load_ppm(file, &img_width, &img_height, &img_bits, &img);
		fclose(file);

		if (result < 0)
			die("PPM file error: %s", PPM_errmsg[-result]);
		if (img_width != 640 || img_height != 480)
			die("Wrong dimensions of image: %dx%d, required 640x480",
			    img_width, img_height);
		if (img_bits != 255)
			die("PPM max value is %d, required 255", img_bits);

	
		pix = &img[0];
		for (y=0; y < 480; y++)
			for (x=0; x < 640; x++) {
				R = (*pix++) >> 3;
				G = (*pix++) >> 2;
				B = (*pix++) >> 3;
				image1[y][x] = (R << 11) | (G << 5) | B;
			}

		free(img);
		memcpy( (void*)&image2[0][0], (void*)&image1[0][0], 640*480*2);
		memcpy( (void*)&image3[0][0], (void*)&image1[0][0], 640*480*2);

		if (!init_graphics())
			die("Can't open display");
	
		image = XCreateImage(display, DefaultVisual(display, screen),
			16, ZPixmap, 0, (char*)&image1[0][0],
			640, 480, 16, 0);
		
		puts(short_help);
		update = 1;
		quit   = 0;
		while (!quit) {
			if (update) {
				XPutImage(display, window, DefaultGC(display, screen),
				          image, 0, 0, 0, 0, 640, 480);
				XSync(display, 1);
				update = 0;
			}
			
			fprintf(stdout, "> ");
			fflush(stdout);
			fgets(ans, sizeof(ans), stdin);
		
			c = (strlen(ans) <= 2) ? ans[0] : 0;
			switch (c) {
				case '?':
				case 'h':
				case 'H':
					puts(short_help);
					break;

				case 'm':
				case 'M':
					puts("Use MMX routine");
					MMX = 1;
					break;
				
				case 'x':
				case 'X':
					puts("Use x86 routine");
					MMX = 0;
					break;

				case 'r':
				case 'R':
					memcpy( (void*)&image1[0][0], (void*)&image3[0][0], 640*480*2);
					update = 1;
					break;

				case 'i':
				case 'I':
					memcpy( (void*)&image2[0][0], (void*)&image3[0][0], 640*480*2);
					break;

				case 'c':
				case 'C':
					for (y=0; y < 480; y++)
						for (x=0; x < 640; x++)
							image2[y][x] = 0x0841;
					break;

				case 'a':
				case 'A':
				case '\n':
					if (MMX)
						MMX_saturated_add(&image1[0][0], &image2[0][0], 640, 480);
					else
						x86_saturated_add(&image1[0][0], &image2[0][0], 640, 480);
					update = 1;
					break;

				case 'q':
				case 'Q':
					quit = 1;
					break;
			}
		}
		fputc('\n', stdout);

		XCloseDisplay(display);
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
