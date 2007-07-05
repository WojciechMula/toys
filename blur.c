#include <stdint.h>
#include <string.h>

void blur_calc_gray_sums(
	uint8_t  *src_img,
	uint16_t *sum_tbl,
	unsigned int width
) {
	int x;
	uint8_t *pix;
	uint16_t a, b, c;

	pix = src_img;
	a = 0x00;//*pix++;
	b = pix[0];//*pix++;
	for (x=0; x < width-1; x++) {
		c = pix[x+1];//*pix++;
		sum_tbl[x] = a + b + c;
		a = b;
		b = c;
	}

	c = 0x00;
	sum_tbl[width-1] = a + b + c;
}

void x86blur_calc_gray_sums(
	uint8_t  *src_img,
	uint16_t *sum_tbl,
	unsigned int width
) {
	asm(
	"   xorl %%eax, %%eax                     \n\t" // a = 0x00
	"   xorl %%ebx, %%ebx                     \n\t"
	"   xorl %%ecx, %%ecx                     \n\t"
	"                                         \n\t"
	"   movb (%%esi), %%bl                    \n\t" // b = pix[0]
	"   addl $1, %%esi                        \n\t"
	"                                         \n\t"
	".2:                                      \n\t"
	"   movb (%%esi), %%cl                    \n\t" // c = pix[x+1]
	"   addl %%ebx, %%eax                     \n\t" // a += b
	"   addl $1, %%esi                        \n\t" // pix++;
	"   addl %%ecx, %%eax                     \n\t" // a += c
	"                                         \n\t"
	"   movw %%ax, (%%edi)                    \n\t" // sum_tbl[x] = a
	"   movl %%ebx, %%eax                     \n\t" // a = b
	"   movl %%ecx, %%ebx                     \n\t" // b = c
	"                                         \n\t"
	"   addl $2, %%edi                        \n\t" // x++;
	"   subl $1, %%edx                        \n\t"
	"   jnz  .2                               \n\t"
	
	: /* no ouput */
	: "S" (src_img), "D" (sum_tbl), "d" (width)
	: "%eax", "%ebx", "%ecx", "memory"
	);
}


void blur_gray_img(
	uint8_t *src_img,
	uint8_t *dst_img,
	unsigned int width,
	unsigned int height
) {
	static uint16_t sums[3*4096]; // should be large enough
	
	int x, y;
	int base = 8192;

	memset((void*)&sums[0], 0x00, width*2);
	x86blur_calc_gray_sums(src_img, &sums[4094], width);
	for (y=0; y < height-1; y++) {
		x86blur_calc_gray_sums(src_img + (y+1)*width, &sums[base], width);
		asm(
		"                                         \n\t"
		".L1:                                     \n\t"
		"    xorl  %%eax, %%eax                   \n\t"
		"    movw      (%%esi), %%ax              \n\t"
		"    addw  8192(%%esi), %%ax              \n\t"
		"    addw 16384(%%esi), %%ax              \n\t"
		"                                         \n\t"
		"    addl  $2, %%esi                      \n\t"
		"    imull $7281, %%eax, %%eax            \n\t"
		"    addl  $1, %%edi                      \n\t"
		"    shrl  $16, %%eax                     \n\t"
		"                                         \n\t"
		"    decl  %%ecx                          \n\t"
		"    movb  %%al, (%%edi)                  \n\t"
		"                                         \n\t"
		"    jnz   .L1                            \n\t"
		"                                         \n\t"
		: /* no output */
		: "S" (sums), "D" (&dst_img[y*width-1]), "c" (width)
		: "%eax", "%edx"
		);
		//for (x=0; x < width; x++)
		//	dst_img[y*width + x] = (7281*(sums[x] + sums[4096+x] + sums[8192+x]) >> 16);

		base += 4096;
		if (base == 12288)
			base = 0;
	}
}


void blur_calc_32bpp_sums(
	uint8_t  *src_img,
	uint16_t *sum_tbl,
	unsigned int width
) {
	int x;
	uint8_t *pix;
	uint16_t Ra, Rb, Rc;
	uint16_t Ga, Gb, Gc;
	uint16_t Ba, Bb, Bc;

	pix = src_img;
/*	Ra = *pix++;
	Ga = *pix++;
	Ba = *pix++;
	pix++;*/

	Ra = Ga = Ba = 0x00;
	
	Rb = *pix++;
	Gb = *pix++;
	Bb = *pix++;
	pix++;

	for (x=0; x < width-1; x++) {
		Rc = *pix++;
		Gc = *pix++;
		Bc = *pix++;
		pix++;

		sum_tbl[3*x + 0] = Ra + Rb + Rc;
		sum_tbl[3*x + 1] = Ga + Gb + Gc;
		sum_tbl[3*x + 2] = Ba + Bb + Bc;
		Ra = Rb;
		Rb = Rc;
		
		Ga = Gb;
		Gb = Gc;
		
		Ba = Bb;
		Bb = Bc;
	}
	
	Rc = Gc = Bc = 0x00;
	sum_tbl[3*(width-1) + 0] = Ra + Rb + Rc;
	sum_tbl[3*(width-1) + 1] = Ga + Gb + Gc;
	sum_tbl[3*(width-1) + 2] = Ba + Bb + Bc;
}


void blur_32bpp_img(
	uint8_t *src_img,
	uint8_t *dst_img,
	unsigned int width,
	unsigned int height
) {
	static uint16_t sum_0[4096]; // should be large enough
	static uint16_t sum_1[4096]; // for present screens
	static uint16_t sum_2[4096];

	uint16_t *A, *B, *C, *T;


	int x, y;

	A = &sum_0[0];
	B = &sum_1[0];
	C = &sum_2[0];

	memset((void*)A, 0x00, width*2*3);
	blur_calc_32bpp_sums(src_img, B, width);
	for (y=0; y < height-1; y++) {
		blur_calc_32bpp_sums(src_img + (y+1)*width*4, C, width);
		for (x=0; x < width; x++) {
			dst_img[y*width*4 + 4*x + 0] = (1820*(A[3*x + 0] + B[3*x + 0] + C[3*x + 0]) >> 14);
			dst_img[y*width*4 + 4*x + 1] = (1820*(A[3*x + 1] + B[3*x + 1] + C[3*x + 1]) >> 14);
			dst_img[y*width*4 + 4*x + 2] = (1820*(A[3*x + 2] + B[3*x + 2] + C[3*x + 2]) >> 14);
		}
		T = A;
		A = B;
		B = C;
		C = T;
	}
}

#include <stdio.h>
#include <string.h>
#include "Xscr.c"
#include "load_ppm.c"

uint8_t *data;
uint8_t *img;

void keyboard(int x, int y, Time t, KeySym c, State s, unsigned int kb_mask) {
	if (s == Released) return;

	switch (c) {
		case XK_q:
		case XK_Q:
		case XK_Escape:
			Xscr_quit();
			break;

		case XK_r:
		case XK_R:
			memcpy( (void*)data, (void*)img, 640*480 );
			Xscr_redraw();
			break;

		case XK_b:
		case XK_B:
			blur_gray_img(data, data, 640, 480);
			//blur_32bpp_img(data, data, 640, 480);
			Xscr_redraw();
			break;
	}
}

int main(int argc, char* argv[]) {
	FILE* f;
	int width, height, maxval, result;

	if (argc == 1) {
		printf("usage: progname file.ppm\n");
		return 1;
	}
	f = fopen(argv[1], "rb");
	if (!f) {
		printf("Can't open file %s\n", argv[1]);
		return 1;
	}
	result = ppm_load_gray(f, &width, &height, &maxval, &data, 0);
	fclose(f);
	if (result < 0) {
		printf("PPM error: %s\n", PPM_errormsg[-result]);
		return 1;
	}

	img = (uint8_t*)malloc(640*480);
	memcpy((void*)img, (void*)data, 640*480);

	result = Xscr_mainloop(640, 480, DEPTH_gray, data, False,
		keyboard, NULL, NULL, "Blur demo");
	if (result < 0) {
		printf("Xscr error: %s\n", Xscr_errormsg[-result]);
		return 1;
	}

	return 0;
}
