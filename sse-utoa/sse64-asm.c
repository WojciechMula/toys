char* utoa64_sse(uint64_t x) {
	uint32_t offset = 0;
	uint32_t a, b;

	// can't be easliy done in SSE
	a = x / 100000000;
	b = x % 100000000;

	__asm__ __volatile__ (
		"movd %%eax, %%xmm0							\n"
		"movd %%ebx, %%xmm1							\n"
		"punpckldq %%xmm1, %%xmm0					\n"
		"pshufd $0b11001101, %%xmm0, %%xmm0			\n"	// prepare data for pmuludq

		// 1) divmod 10^4

		"movdqa	div_10000, %%xmm1					\n"
		"movdqa mul_10000, %%xmm2					\n"

		// xmm1 = x[i] div 1000
		"pmuludq	%%xmm0, %%xmm1					\n"	// div
		"psrlq		$45, %%xmm1						\n"

		// xmm0 = x[i] mod 1000
		"pmuludq	%%xmm1, %%xmm2					\n" // mod
		"psubd		%%xmm2, %%xmm0					\n"

		"pshufd		$0b10110011, %%xmm0, %%xmm0		\n" // join div & mod results
		"por		%%xmm1, %%xmm0					\n"

		// 2) divmod 10^2

		"movdqa	div_100, %%xmm1						\n"
		"movdqa	mul_100, %%xmm2						\n"
		"											\n"
		"pmulhuw %%xmm0, %%xmm1						\n"	// div
		"psrlw       $3, %%xmm1						\n"
		"pmullw  %%xmm1, %%xmm2						\n" // mod
		"psubw	 %%xmm2, %%xmm0						\n"
		
		"pslld		$16, %%xmm0						\n"	// join div & mod results
		"por 		%%xmm1, %%xmm0					\n"

		// 3) divmod 10

		"movdqa div_10, %%xmm1						\n"
		"movdqa mul_10, %%xmm2						\n"
		
		"pmulhuw %%xmm0, %%xmm1						\n"	// div
		"pmullw  %%xmm1, %%xmm2						\n"
		"psubw	 %%xmm2, %%xmm0						\n"	// mod

		"psllw		$8,		%%xmm0					\n"	// join div & mod result
		"por		%%xmm1, %%xmm0					\n"
		
		// 4) convert to ASCII, count leading zeros and save result
			
		"movdqa		to_ascii, %%xmm2				\n"
		"paddb		%%xmm2, %%xmm0					\n"
		"pcmpeqb	%%xmm0, %%xmm2					\n"
		"pmovmskb	%%xmm2, %%eax					\n"
		"not		%%eax							\n"
		"orl		$0x8000, %%eax					\n"
		"bsf		%%eax, %%eax					\n"

		"movdqa		%%xmm0, utoa_buffer				\n"
		: "=a" (offset)
		: "a" (b),
		  "b" (a)
	);

	return &utoa_buffer[offset];
}
