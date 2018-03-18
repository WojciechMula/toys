//--- defines ----------------------------------------------------------
#define packed_byte(x)   {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x}
#define packed_word(x)   {x, x, x, x, x, x, x, x}
#define packed_dword(x)   {x, x, x, x}

//--- SSE helper vectors -----------------------------------------------
uint16_t div_10[8] SIMD_ALIGN = packed_word(DIV_10);
uint16_t mul_10[8] SIMD_ALIGN = packed_word(10);

uint16_t div_100[8] SIMD_ALIGN = packed_word(DIV_100);
uint16_t mul_100[8] SIMD_ALIGN = packed_word(100);

uint32_t div_10000[4] SIMD_ALIGN = packed_dword(DIV_10000);
uint32_t mul_10000[4] SIMD_ALIGN = packed_dword(10000);

uint8_t  to_ascii[16] SIMD_ALIGN = packed_byte('0');

// utoa32_sse_2 specific
uint32_t mul_10000trick[4] SIMD_ALIGN = packed_dword(65536 - 10000);

uint16_t	div_consts[8] SIMD_ALIGN = {
				8389,	// div 10^3, shift = 23 + 2
				5243,	// div 10^2, shift = 19 + 2
			   13108,	// div 10^1, shift = 17 + 2
			  0x8000,	// 
				8389,
				5243,
			   13108,
			  0x8000
};

uint16_t	shift_consts[8] SIMD_ALIGN = {
				1 << (16 - (23 + 2 - 16)),
				1 << (16 - (19 + 2 - 16)),
				1 << (16 - 1 - 2),
				1 << (15),
				1 << (16 - (23 + 2 - 16)),
				1 << (16 - (19 + 2 - 16)),
				1 << (16 - 1 - 2),
				1 << (15)
};

