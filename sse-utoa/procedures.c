//----------------------------------------------------------------------
//--- SSE implementations ----------------------------------------------
//----------------------------------------------------------------------

// magick numbers for 16-bit division
#define DIV_10		0x199a	// shift = 0 + 16
#define DIV_100		0x147b	// shift = 3 + 16

// magic number for 32-bit division
#define DIV_10000	0xd1b71759		// shift = 13 + 32

#define SIMD_ALIGN __attribute__((aligned(16)))

//---- output buffer for SSE procedures --------------------------------
static char utoa_buffer[32] SIMD_ALIGN;

#ifdef USE_ASM

#include "asm-helpers.c"
#include "sse32-asm.c"
#include "sse32_2-asm.c"
#include "sse64-asm.c"

#else

#include <immintrin.h>
#include "sse32-intrin.c"
#include "sse32_2-intrin.c"
#include "sse64-intrin.c"

#endif
