char* utoa32_sse_2(uint32_t x) {
	uint32_t offset = 0;

	__asm__ __volatile__ (
		// 1) x divmod 10^4
		"movd		%%eax, %%xmm1					\n"

		// xmm0 = eax div 10000
		"movdqa		div_10000, %%xmm0				\n"
		"pmuludq	%%xmm1, %%xmm0					\n"
		"psrlq		$45, %%xmm0						\n"

		// xmm3 = (eax div 10000) * 10000
		"movdqa		mul_10000trick, %%xmm3			\n"
		"pmuludq	%%xmm3, %%xmm0					\n"

		// xmm1 = eax mod 10000
		// xmm0 = [ eax div 10000 | eax mod 10000 | ... ]
		"paddd		%%xmm1, %%xmm0					\n"
		"psllq		$2, %%xmm0						\n" // v[i] *= 4

		// [   abcd  |  abcd    |  abcd     |   abcd | ... ]
		"punpcklwd	%%xmm0, %%xmm0					\n"
		"punpckldq	%%xmm0, %%xmm0					\n"

		// [ a * 2^(7 + 2) | ab * 2^(3 + 2) | abc * 2^(1 + 2) |  abcd * 2^(0 + 2) | ... ] + garbages at lower bits!
		"pmulhuw	div_consts, %%xmm0				\n"

		"movdqa		mul_10, %%xmm7				\n"

		// xmm0 = [     a |     ab |    abc |  abcd | ... ] -- variable shift right
		"pmulhuw	shift_consts, %%xmm0			\n"
		// xmm7 = [    a0 |    ab0 |   abc0 |     0 | ... ] -- v[i] *= 10
		"pmullw		%%xmm0, %%xmm7					\n"
		// xmm7 = [     0 |     a0 |    ab0 |  abc0 | ... ]
		"psllq		$16, %%xmm7						\n"
		// xmm0 = [     a |      b |      c |     d | ... ]
		"psubw		%%xmm7, %%xmm0					\n"

		// pack word => bytes
		"pxor		%%xmm2, %%xmm2					\n"
		"packuswb	%%xmm0, %%xmm2					\n"

		// 4) conversion to ASCII and skip leading zeros
		"movdqa		to_ascii, %%xmm7				\n"
		"paddb		%%xmm7, %%xmm2					\n"
		// xmm2 - result
		"pcmpeqb	%%xmm2, %%xmm7					\n"
		"pmovmskb	%%xmm7, %%eax					\n"
		"not		%%eax							\n"
		"orl		$0x8000, %%eax					\n"
		"bsf		%%eax, %%eax					\n"
		// eax = position of first non-zero digit

		// 5) save
		"L1:movdqa		%%xmm2, utoa_buffer			\n"
		: "=a" (offset)
		: "a" (x)
	);

	return &utoa_buffer[offset];
}
