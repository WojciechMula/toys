#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define SIMD_ALIGN __attribute__((aligned(16)))

uint8_t populate_alpha_lo[16] SIMD_ALIGN = {
	// 0 1 2 3 4 5 6 7 8 9 a b c d e f
	// r g b A r g b A r g b A r g b A
	0xff, 0x3, 0xff, 0x3, 0xff, 0x3, 0xff, 0xff,
	0xff, 0x7, 0xff, 0x7, 0xff, 0x7, 0xff, 0xff,
};


uint8_t populate_alpha_hi[16] SIMD_ALIGN = {
	0xff, 0xb, 0xff, 0xb, 0xff, 0xb, 0xff, 0xff,
	0xff, 0xf, 0xff, 0xf, 0xff, 0xf, 0xff, 0xff,
};

void blend_image_inplace(uint32_t* background, uint32_t* foreground, int count) {
	uint32_t Rf, Gf, Bf, Af;
	uint32_t Rb, Gb, Bb;
	uint32_t R, G, B;

	while (count) {
		Rf =  (*foreground) & 0xff;
		Gf = ((*foreground) >>  8) & 0xff;
		Bf = ((*foreground) >> 16) & 0xff;
		Af = ((*foreground) >> 24) & 0xff;
		
		Rb =  (*background) & 0xff;
		Gb = ((*background) >>  8) & 0xff;
		Bb = ((*background) >> 16) & 0xff;

		R = (Rf * Af)/256 + Rb;
		G = (Gf * Af)/256 + Gb;
		B = (Bf * Af)/256 + Bb;

		if (R > 255) R = 255;
		if (G > 255) G = 255;
		if (B > 255) B = 255;

		(*background) = R | (G << 8) | (B << 16);

		foreground += 1;
		background += 1;
		count -= 1;
	}
}


void sse4_blend_image_inplace(uint32_t* background, uint32_t* foreground, int count) {
	asm volatile (
		"movdqa populate_alpha_lo, %%xmm6	\n"
		"movdqa populate_alpha_hi, %%xmm7	\n"
		"				\n"
		"0:				\n"

		"movdqa (%%esi), %%xmm0		\n"	// 4 foreground pixels
		"movhlps %%xmm0, %%xmm1		\n"
		"				\n"
		"pmovzxbw %%xmm0, %%xmm2	\n"	// components
		"pmovzxbw %%xmm1, %%xmm3	\n"
		"				\n"
		"pshufb	 %%xmm7, %%xmm0		\n"	// alpha
		"pshufb	 %%xmm6, %%xmm1		\n"
		"				\n"
		"pmulhuw %%xmm2, %%xmm0		\n"
		"pmulhuw %%xmm3, %%xmm1		\n"
		"				\n"
		"movdqa (%%edi), %%xmm2		\n"
		"				\n"
		"packuswb %%xmm1, %%xmm0	\n"
		"packuswb %%xmm5, %%xmm4	\n"
		"				\n"
		"paddusb %%xmm2, %%xmm0		\n"
		"movdqa  %%xmm0, (%%edi)	\n"
		"				\n"
		"addl $16, %%esi		\n"
		"addl $16, %%edi		\n"
		"subl  $1, %%ecx		\n"
		"jnz   0b			\n"


		: /* no output */
		: "D" (background),
		  "S" (foreground),
		  "c" (count/4)
		: "memory"
		
	);
}


void sse4_blend_image_inplace_unrolled(uint32_t* background, uint32_t* foreground, int count) {
	asm volatile (
		"0:				\n"

		"movdqa (%%esi), %%xmm0		\n"	// 4 foreground pixels
		"movdqa 16(%%esi), %%xmm4	\n"	// 4 foreground pixels
		"movhlps %%xmm0, %%xmm1		\n"
		"movhlps %%xmm4, %%xmm5		\n"
		"				\n"
		"pmovzxbw %%xmm0, %%xmm2	\n"	// components
		"pmovzxbw %%xmm1, %%xmm3	\n"
		"pmovzxbw %%xmm4, %%xmm6	\n"	// components
		"pmovzxbw %%xmm5, %%xmm7	\n"
		"				\n"
		"pshufb	 populate_alpha_lo, %%xmm0		\n"	// alpha
		"pshufb	 populate_alpha_hi, %%xmm1		\n"
		"pshufb	 populate_alpha_lo, %%xmm4		\n"	// alpha
		"pshufb	 populate_alpha_hi, %%xmm5		\n"
		"				\n"
		"pmulhuw %%xmm2, %%xmm0		\n"
		"pmulhuw %%xmm3, %%xmm1		\n"
		"pmulhuw %%xmm6, %%xmm4		\n"
		"pmulhuw %%xmm7, %%xmm5		\n"
		"				\n"
		"movdqa (%%edi), %%xmm2		\n"
		"movdqa 16(%%edi), %%xmm6		\n"
		"				\n"
		"				\n"
		"packuswb %%xmm1, %%xmm0	\n"
		"packuswb %%xmm5, %%xmm4	\n"
		"				\n"
		"paddusb %%xmm2, %%xmm0		\n"
		"paddusb %%xmm6, %%xmm4		\n"
		"movdqa  %%xmm0, (%%edi)	\n"
		"movdqa  %%xmm4, 16(%%edi)	\n"
		"				\n"
		"addl $32, %%esi		\n"
		"addl $32, %%edi		\n"
		"subl  $1, %%ecx		\n"
		"jnz   0b			\n"


		: /* no output */
		: "D" (background),
		  "S" (foreground),
		  "c" (count/8)
		: "memory"
		
	);
}

#define WIDTH  320
#define HEIGHT 200
#define SIZE (WIDTH)*(HEIGHT)

uint32_t fore[WIDTH][HEIGHT] SIMD_ALIGN;
uint32_t back[WIDTH][HEIGHT] SIMD_ALIGN;


int main(int argc, char* argv[]) {

	int n = 1000;

	printf("argc=%d\n", argc);
	switch (argc) {
		case 1:
			puts("x86");
			while (n--)
				blend_image_inplace(&fore[0][0], &back[0][0], SIZE);
			break;

		case 2:
			puts("SSE4");
			while (n--)
				sse4_blend_image_inplace(&fore[0][0], &back[0][0], SIZE);
			break;

		case 3:
			puts("SSE4 unrolled");
			while (n--)
				sse4_blend_image_inplace_unrolled(&fore[0][0], &back[0][0], SIZE);
			break;
	}

	return 0;
}
