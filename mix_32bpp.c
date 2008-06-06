#ifndef _XOPEN_SOURCE
#	define _XOPEN_SOURCE 600
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdarg.h>
#include <sys/time.h>
#include <time.h>

#include "Xscr.h"
#include "load_ppm.h"

int width, height, maxval;
uint8_t *imgA, *imgB, *data;
uint8_t alpha;

int function = 0;


uint32_t getTime(void) {
	static struct timeval T;
	gettimeofday(&T, NULL);
	return (T.tv_sec * 1000000) + T.tv_usec;
}


void SSSE3_blend() __attribute__((noinline));
void SSSE3_blend() {
	int n = width * height * 4;

	__asm__ volatile (
#ifndef GCC_FIXED_BUG
		"	pushal				\n"
#endif
		"	pxor   %%xmm0, %%xmm0		\n"
		"	movd    %%edx, %%xmm6		\n"
		"	xorl      $-1, %%edx		\n"
		"	movd    %%edx, %%xmm7		\n"

		"	pshufb %%xmm0, %%xmm6		\n"
		"	pshufb %%xmm0, %%xmm7		\n"
		"					\n"
		"	psllw      $8, %%xmm6		\n"
		"	psllw      $8, %%xmm7		\n"
		"0:					\n"
		"	movdqa (%%eax), %%xmm0		\n"
		"	movdqa (%%ebx), %%xmm2		\n"
		"	movhlps %%xmm0, %%xmm1		\n"
		"	movhlps %%xmm2, %%xmm3		\n"
		"					\n"
		"	pmovzxbw  %%xmm0, %%xmm0	\n"
		"	pmovzxbw  %%xmm1, %%xmm1	\n"
		"	pmovzxbw  %%xmm2, %%xmm2	\n"
		"	pmovzxbw  %%xmm3, %%xmm3	\n"
		"					\n"
		"	pmulhuw %%xmm6, %%xmm0		\n"
		"	pmulhuw %%xmm6, %%xmm1		\n"
		"	pmulhuw %%xmm7, %%xmm2		\n"
		"	pmulhuw %%xmm7, %%xmm3		\n"
		"					\n"
		"	packuswb %%xmm1, %%xmm0		\n"
		"	packuswb %%xmm3, %%xmm2		\n"
		"					\n"
		"	paddusb %%xmm2, %%xmm0		\n"
		"	addl $16, %%eax			\n"
		"	addl $16, %%ebx			\n"
		"					\n"
#ifdef NONTEMPORAL_STORES
		"	movntdq %%xmm0, (%%edi)		\n"
#else
		"	movdqa %%xmm0, (%%edi)		\n"
#endif
		"	addl $16, %%edi			\n"
		"					\n"
		"	subl  $1, %%ecx			\n"
		"	jnz   0b			\n"
#ifndef GCC_FIXED_BUG
		"	popal				\n"
#endif
		"					\n"
		: /* no output */
		: "a" (imgA),
		  "b" (imgB),
		  "D" (data),
		  "c" (n/16),
		  "d" (alpha)
	);
}


void SSE4_blend() __attribute__((noinline));
void SSE4_blend() {
	int n = width * height * 4;

	__asm__ volatile (
#ifndef GCC_FIXED_BUG
		"	pushal				\n"
#endif
		"	pxor   %%xmm0, %%xmm0		\n"

		"	movd    %%edx, %%xmm6		\n"
		"	xorl	$0x3f, %%edx		\n"
		"	movd    %%edx, %%xmm7		\n"
		"	pshufb %%xmm0, %%xmm6		\n"
		"	pshufb %%xmm0, %%xmm7		\n"
		"	punpcklbw %%xmm7, %%xmm6	\n"
		"0:					\n"
		"	movdqa (%%eax), %%xmm0		\n"
		"	movdqa (%%ebx), %%xmm2		\n"
		"	movdqa 16(%%eax), %%xmm3	\n"
		"	movdqa 16(%%ebx), %%xmm5	\n"
		"	movdqa  %%xmm0, %%xmm1		\n"
		"	movdqa  %%xmm3, %%xmm4		\n"
		"					\n"
		"	punpcklbw %%xmm2, %%xmm0	\n"
		"	punpckhbw %%xmm2, %%xmm1	\n"
		"	punpcklbw %%xmm5, %%xmm3	\n"
		"	punpckhbw %%xmm5, %%xmm4	\n"
		"					\n"
		"	pmaddubsw %%xmm6, %%xmm0	\n"
		"	pmaddubsw %%xmm6, %%xmm1	\n"
		"	pmaddubsw %%xmm6, %%xmm3	\n"
		"	pmaddubsw %%xmm6, %%xmm4	\n"
		"					\n"
		"	psrlw        $6, %%xmm0		\n"
		"	psrlw        $6, %%xmm1		\n"
		"	psrlw        $6, %%xmm3		\n"
		"	psrlw        $6, %%xmm4		\n"
		"	packuswb %%xmm1, %%xmm0		\n"
		"	packuswb %%xmm4, %%xmm3		\n"
		"					\n"
		"	addl $32, %%eax			\n"
		"	addl $32, %%ebx			\n"
		"					\n"
#ifdef NONTEMPORAL_STORES
		"	movntdq %%xmm0, (%%edi)	\n"
		"	movntdq %%xmm3, 16(%%edi)	\n"
#else
		"	movdqa %%xmm0, (%%edi)		\n"
		"	movdqa %%xmm3, 16(%%edi)	\n"
#endif
		"	addl $32, %%edi			\n"
		"					\n"
		"	subl  $1, %%ecx			\n"
		"	jnz   0b			\n"
#ifndef GCC_FIXED_BUG
		"	popal				\n"
#endif
		: /* no output */
		: "a" (imgA),
		  "b" (imgB),
		  "D" (data),
		  "c" (n/32),
		  "d" (alpha/4)	// [0..63]
	);
}


void blend() {
	int n = width * height * 4;

	uint8_t *iA = imgA;
	uint8_t *iB = imgB;
	uint8_t *iD = data;

	uint32_t a1 = alpha;
	uint32_t a2 = 255 - alpha;

	uint32_t R, G, B;
	uint32_t R1, G1, B1;
	uint32_t R2, G2, B2;

	while (n--) {
		R1 =  (*iA) & 0xff;
		G1 = ((*iA) >>  8) & 0xff;
		B1 = ((*iA) >> 16) & 0xff;
		
		R2 =  (*iB) & 0xff;
		G2 = ((*iB) >>  8) & 0xff;
		B2 = ((*iB) >> 16) & 0xff;

		R = (R1*a1 + R2*a2) >> 8;
		G = (G1*a1 + G2*a2) >> 8;
		B = (B1*a1 + B2*a2) >> 8;

		if (R > 255) R = 255;
		if (G > 255) G = 255;
		if (B > 255) B = 255;

		(*iD) = R | (G << 8) | (B << 16);

		iA++;
		iB++;
		iD++;
	}
}


#define OPT_COUNT 4

static char* function_name[OPT_COUNT] = {
	"x86", "SSSE3", "SSE4"
};


static char* function_name_abbr[OPT_COUNT] = {
	"x86", "SSSE3", "SSE4"
};




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
				SSSE3_blend();
				break;
			case 2:
				printf("%s", function_name[function]);
				SSE4_blend();
				break;
		}
		t2 = getTime();
		printf(" = %dus %d\n", t2-t1, function);
		Xscr_redraw();
		old_alpha = alpha;
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
			function = (function + 1) % 4;
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

		case XK_q:
		case XK_Q:
			Xscr_quit();
			break;
	}
}


void help(char* progname) {
	int i;

	printf("1. %s view file1.ppm file2.ppm\n", progname);
	printf("2. %s measure %s", progname, function_name_abbr[0]);

	for (i=1; i < OPT_COUNT; i++)
		printf("|%s", function_name_abbr[i]);
	
	printf(" repeat-count\n");

	exit(1);
}


void die(const char* fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	vprintf(fmt, ap);
	putchar('\n');
	va_end(ap);

	exit(2);
}


void measure(int function, int repeat_count) {
	uint32_t t1, t2;
	int n = repeat_count;
	
	printf(
		"function %s, called %d times; image %d x %d\n",
		function_name[function],
		repeat_count,
		width, height
	);

	switch (function) {
		case 0:
			t1 = getTime();
			while (n--)
				blend();
			t2 = getTime();
			break;
		
		case 1:
			t1 = getTime();
			while (n--)
				SSSE3_blend();
			t2 = getTime();
			break;
		
		case 2:
			t1 = getTime();
			while (n--)
				SSE4_blend();
			t2 = getTime();
			break;
		default:
			return;
	}

	printf("time = %d us\n", t2 - t1);
}


void view(const char* file1, const char* file2) {
	FILE *f;
	int err;

	f = fopen(file1, "rb");
	if (f == NULL)
		die("Can't open %s", file1);
	err = ppm_load_32bpp(f, &width, &height, &maxval, &imgA, 1);
	if (err < 0)
		die("Can't read %s: %s", file1, PPM_errormsg[-err]);
	else
	if (((uint32_t)imgA) & 0x0f != 0x00)
		die("Compile load_ppm library with -DPPM_ALIGN_MALLOC=16.");
	fclose(f);

	f = fopen(file2, "rb");
	if (f == NULL)
		die("Can't open %s", file2);
	ppm_load_32bpp(f, &width, &height, &maxval, &imgB, 1);
	if (err < 0)
		die("Can't read %s: %s", file2, PPM_errormsg[-err]);
	else
	if (((uint32_t)imgB) & 0x0f != 0x00)
		die("Compile load_ppm library with -DPPM_ALIGN_MALLOC=16.");
	fclose(f);

	if (posix_memalign((void*)&data, 16, width*height*4))
		die("No free memory");

	memcpy(data, imgA, width*height*4);

	// run mainloop
	err = Xscr_mainloop(
		width, height, DEPTH_32bpp, False, data, 
		keyboard, motion, NULL,
		"Image mixing demo - Wojciech Mula, wojciech_mula@poczta.onet.pl"
	);

	// check exit status
	if (err < 0) {
		printf("Xscr error: %s\n", Xscr_errormsg[-err]);
	}

	free(imgA);
	free(imgB);
	free(data);
}


int main(int argc, char* argv[]) {
	int action = -1;
	int function;
	int repeat_count;

	// parse args
	if (argc < 2)
		help(argv[0]);

	if (strcasecmp(argv[1], "measure") == 0) {
		action = 1;
		if (argc < 4)
			help(argv[0]);

		repeat_count = atoi(argv[3]);
		if (repeat_count < 0)
			help(argv[0]);

		width  = 1024;
		height = 768;
		alpha  = 127;

		imgA = NULL;
		imgB = NULL;
		data = NULL;

		posix_memalign((void*)&imgA, 16, width*height*4);
		if (imgA == NULL) die("No free memory");

		posix_memalign((void*)&imgB, 16, width*height*4);
		if (imgB == NULL) die("No free memory");

		posix_memalign((void*)&data, 16, width*height*4);
		if (data == NULL) die("No free memory");

		for (function=0; function < OPT_COUNT; function++) {
			if (strcasecmp(argv[2], function_name_abbr[function]) == 0) {
				measure(function, repeat_count);
				break;
			}
		}

		free(imgA);
		free(imgB);
		free(data);
		
		if (function == OPT_COUNT)
			help(argv[0]);
		else
			return 0;
	}
	else
	if (strcasecmp(argv[1], "view") == 0) {
		action = 0;
		if (argc < 4)
			help(argv[0]);
		else
			view(argv[2], argv[3]);
	}
	else
		help(argv[0]);

	
	return 0;
}

