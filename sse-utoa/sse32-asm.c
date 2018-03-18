char* utoa32_sse(uint32_t x) {
	uint32_t offset = 0;

	__asm__ __volatile__ (
		// 1) x divmod 10^4
		"movd		%%eax, %%xmm1					\n"

		// xmm0 = eax div 10000
		"movdqa		div_10000, %%xmm0				\n"
		"pmuludq	%%xmm1, %%xmm0					\n"
		"psrlq		$45, %%xmm0						\n"

		// xmm3 = (eax div 10000) * 10000
		"movdqa		mul_10000, %%xmm3				\n"
		"pmuludq	%%xmm0, %%xmm3					\n"

		// xmm1 = eax mod 10000
		"psubd		%%xmm3, %%xmm1					\n"

		// xmm0 = [ eax div 10000 | eax mod 10000 | ... ]
		"punpcklwd	%%xmm1, %%xmm0					\n"
		
		// 2) x[i] divmod 10^2

		// xmm0 = [ abcd | efgh | ijkl | mnop | ... ], [a..p] - decimal digits
		"movdqa		div_100, %%xmm1					\n"
		"movdqa		mul_100, %%xmm2					\n"

		// xmm1 = [ 00ab | 00ef | 00ij | 00mn | ... ]
		"pmulhuw	%%xmm0, %%xmm1					\n"
		"psrlw		$3, %%xmm1						\n"

		// xmm2 = [ ab00 | ef00 | ij00 | mn00 | ...]
		"pmullw		%%xmm1, %%xmm2					\n"

		// xmm0 = [ 00cd | 00gh | 00kl | 00op | ... ]
		"psubw		%%xmm2, %%xmm0					\n"

		// xmm1 = [ 00ab | 00cd | 00ef | 00gh | ... ]
		"punpcklwd	%%xmm0, %%xmm1					\n"

		// 3) x[i] divmod 10
		"movdqa		div_10, %%xmm0					\n"
		"movdqa		mul_10, %%xmm2					\n"

		// xmm0 = x[i] div 10
		"pmulhuw	%%xmm1, %%xmm0					\n"
		
		// xmm1 = x[i] mod 10
		"pmullw		%%xmm0, %%xmm2					\n"
		"psubw		%%xmm2, %%xmm1					\n"
		
		// result
		"punpcklwd	%%xmm1, %%xmm0					\n"
		"pxor		%%xmm2, %%xmm2					\n"
		"packuswb	%%xmm0, %%xmm2					\n"

		// 4) conversion to ASCII and skip leading zeros
		"movdqa		to_ascii, %%xmm0				\n"
		"paddb		%%xmm0, %%xmm2					\n"
		// xmm2 - result
		"pcmpeqb	%%xmm2, %%xmm0					\n"
		"pmovmskb	%%xmm0, %%eax					\n"
		"not		%%eax							\n"
		"orl		$0x8000, %%eax					\n"
		"bsf		%%eax, %%eax					\n"
		// eax = position of first non-zero digit

		// 5) save
		"movdqa		%%xmm2, utoa_buffer				\n"
		: "=a" (offset)
		: "a" (x)
	);

	return &utoa_buffer[offset];
}
