#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#include "Xscr.h"
#include "load_ppm.h"

int width, height;
uint8_t *imgA, *imgB, *data;
uint8_t alpha;

int function = 0;


uint32_t getTime(void) {
	static struct timeval T;
	gettimeofday(&T, NULL);
	return (T.tv_sec * 1000000) + T.tv_usec;
}


void SSSE3_blend() {
	int n = width * height * 4;

	__asm__ volatile (
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
		"	movdqa %%xmm0, (%%edi)		\n"
		"	addl $16, %%edi			\n"
		"					\n"
		"	subl  $1, %%ecx			\n"
		"	jnz   0b			\n"
		"					\n"
		: /* no output */
		: "a" (imgA),
		  "b" (imgB),
		  "D" (data),
		  "c" (n/16),
		  "d" (alpha)
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
				printf("C impl");
				blend();
				break;
			case 1:
				printf(" SSSE3");
				SSSE3_blend();
				break;
		}
		t2 = getTime();
		printf(" = %dus\n", t2-t1);
		Xscr_redraw();
		old_alpha = alpha;
	}
}

void buttons(
	int x, int y, Time t,
	unsigned int button, 
	KeyOrButtonState s,
	unsigned int kb_mask
) {
	printf("state=%s, button=%d\n",
	        s==Pressed ? "Pressed" : "Released",
	        button
	);
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
		case XK_space:
			function = (function + 1) % 2;
			break;

		case XK_q:
		case XK_Q:
			Xscr_quit();
			break;
	}
}


int main(int argc, char* argv[]) {
	int result;
	FILE* f;
	int maxval;

	f = fopen("A.ppm", "rb");
	ppm_load_32bpp(f, &width, &height, &maxval, &imgA, 1);
	fclose(f);
	f = fopen("B.ppm", "rb");
	ppm_load_32bpp(f, &width, &height, &maxval, &imgB, 1);
	fclose(f);

	posix_memalign((void*)&data, 16, width*height*4);

	memcpy(data, imgA, width*height*4);

	// run mainloop
	result = Xscr_mainloop(
		width, height, DEPTH_32bpp, False, data, 
		keyboard, motion, buttons,
		"Xscr demo"
	);

	// check exit status
	if (result < 0) {
		printf("Xscr error: %s\n", Xscr_errormsg[-result]);
	}

	free(imgA);
	free(imgB);
	return 0;
}

