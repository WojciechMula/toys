#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <X11/Xlib.h>


void saturated_add(unsigned short *A, unsigned short *B, int width, int height) {
	int x, y;
	unsigned int *a;
	unsigned int *b;
	unsigned int res;

	a = (unsigned int*)A;
	b = (unsigned int*)B;
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


void MMX_saturated_add(unsigned short *A, unsigned short *B, int width, int height) {
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
//		"   pand %%mm7, %%mm2                     \n\t"
//		"   pand %%mm6, %%mm3                     \n\t"
		"   por  %%mm5, %%mm0                     \n\t"
		"   por  %%mm4, %%mm1                     \n\t"
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

void ordie(char* info);
void die(char* info);

unsigned short int raw_image[480][640];
unsigned char image_line[640][3];

/* X-Window local variables ****************************/
Display	*display;  // display
int	screen;    // main screen
Window	window;
GC      defaultGC; // graphics context

int init_graphics() {
	// try open defult display
	display = XOpenDisplay(NULL);
	if (!display) {
		die("Can't open display.");
		return 0;
	}
	screen = DefaultScreen(display);
	window = XCreateSimpleWindow( // make a simple window
		display, 
		RootWindow(display, screen),
		0, 0,
		640, 480,
		1,
		BlackPixel(display, screen),
		WhitePixel(display, screen)
		);

	XMapWindow(display, window); // show it on the screen

	// setup graphics context
	defaultGC = XCreateGC(display, window, 0, 0);
	if (defaultGC < 0) {
		die("Cant make a graphics context.");
		return 0;
	}
	XSetForeground(display, defaultGC, BlackPixel(display, screen) );
	XSetBackground(display, defaultGC, WhitePixel(display, screen) );

	//XFlush(display); // send command to the X-server
	return 1;
}

//#define TEST

#ifdef TEST
int main() {
	int i=500;
	while (i--)
		MMX_saturated_add(raw_image, raw_image, 640, 480);
	asm("emms");
	return 0;
}
#else
int main() {
	FILE* f;
	int x, y;
	unsigned short int R, G, B;
	XImage* img;
	XWindowAttributes wa;

	if (!init_graphics())
		return 1;
	
	f = fopen("test.raw", "rb");
	for (y=0; y < 480; y++) {
		fread(image_line, 640, 3, f);
		for (x=0; x < 640; x++) {
			R = image_line[x][0] >> 3;
			G = image_line[x][1] >> 2;
			B = image_line[x][2] >> 3;
			raw_image[y][x] = (R << 11) | (G << 5) | B;
		}
	}
	fclose(f);

	img = XCreateImage(
		display,
		DefaultVisual(display, screen),
		16,
		ZPixmap,
		0,
		(char*)&raw_image[0][0],
		640,
		480,
		16, 0);

#define PutImage \
	XPutImage(display, window, DefaultGC(display, screen), img, 0, 0, 0, 0, 640, 480); \
	XSync(display, 0);

	PutImage;
	
	while (1) {
		//MMX_saturated_add(raw_image, raw_image, 640, 480);
		saturated_add(raw_image, raw_image, 640, 480);
		PutImage;
		if (getchar() == 'q') break;
	}
	asm("emms");

	XCloseDisplay(display);
	return 0;
}
#endif

void ordie(char* info) {
	if (errno != 0) {
		fprintf(stderr, "%s [errno=%d]: %s\n", info, errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void die(char* info) {
	fprintf(stderr, "%s\n", info);
	exit(EXIT_FAILURE);
}
