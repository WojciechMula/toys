/*
	Convert to hexadecimal representation

	Author  : Wojciech Muła
	Date    : 2014-09-14
	License : BSD
*/


#include <assert.h>
#include <stdint.h>
#include <stdio.h>


// --- SWAR version -------------------------------------------------------


#define packed(byte) ((uint8_t)(byte) * 0x01010101u)

uint32_t nibbles_to_hex_swar(uint32_t nibbles) {
	assert((nibbles & 0xf0f0f0f0) == 0);

	const uint32_t ascii09    = nibbles + packed('0');
	const uint32_t correction = packed('a' - '0' - 10);

	const uint32_t tmp  = nibbles  + packed(128 - 10);
	const uint32_t msb  = tmp & packed(0x80);
	const uint32_t mask = msb - (msb >> 7);

	return ascii09 + (mask & correction);
}

#undef packed


// --- SIMD version -------------------------------------------------------

#define SIMD_ALIGN __attribute__((aligned(16)))                                                     
#define packed_byte(x)   {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x}


uint8_t ascii0[16] 		SIMD_ALIGN = packed_byte('0');
uint8_t correction[16] 	SIMD_ALIGN = packed_byte('a' - '0' - 10);
uint8_t nine[16] 		SIMD_ALIGN = packed_byte(9);

uint32_t nibbles_to_hex_simd(uint32_t nibbles) {
	uint32_t result;

	__asm__ __volatile__ (
		// 1. load
		"movd       %%eax,  %%xmm0    	\n"
		"movdqa     %%xmm0, %%xmm1    	\n"

		// 2. convert to ASCII values 0..9
		"paddb      ascii0, %%xmm1  	\n"

		// 3. make mask
		"pcmpgtb    nine, %%xmm0  		\n"

		// 3. produce result
		"pand       correction, %%xmm0 	\n"
		"paddb      %%xmm0, %%xmm1		\n"

		// store
		"movd       %%xmm1, (%%ebx)     \n"

		: /* no output */
		: "a" (nibbles),
		  "b" (&result)
        : "memory"
	);

	return result;
}


// --- naive version - used to verification -------------------------------

uint8_t nibble_to_hex_naive(uint8_t b) {
	if (b < 10) {
		return b + '0';
	} else {
		return (b - 10) + 'a';
	}
}


uint32_t nibbles_to_hex_naive(uint32_t nibbles) {
	assert((nibbles & 0xf0f0f0f0) == 0);
	
	union {
		uint32_t dword;
		uint8_t  byte[4];
	} result;

	result.dword = nibbles;

	for (int i=0; i < 4; i++) {
		result.byte[i] = nibble_to_hex_naive(result.byte[i]);
	}

	return result.dword;
}

