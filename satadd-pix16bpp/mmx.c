void MMX_saturated_add(uint16_t *A, uint16_t *B, int width, int height) {
	static uint16_t mask_rb[4] = {0xf81f, 0xf81f, 0xf81f, 0xf81f};
	static uint16_t mask_g[4]  = {0x07e0, 0x07e0, 0x07e0, 0x07e0};
	static uint16_t fill_b[4]  = {0x00e0, 0x00e0, 0x00e0, 0x00e0};
	static uint16_t fill_g[4]  = {0xf800, 0xf800, 0xf800, 0xf800};
	int x, y;
	uint64_t *a;
	uint64_t *b;

	__asm__ volatile(
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
		__asm__ volatile(
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

