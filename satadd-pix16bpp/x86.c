void x86_saturated_add(uint16_t *A, uint16_t *B, int width, int height) {
	int x, y;
	uint32_t *a;
	uint32_t *b;

	a = (uint32_t*)A;
	b = (uint32_t*)B;
	for (y=0; y < height; y++)
		for (x=0; x < width/2; x++) {
		__asm__ volatile(
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

