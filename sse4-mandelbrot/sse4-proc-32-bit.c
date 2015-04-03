//=== SSE4 implementation ================================================
#define SIMD_ALIGN __attribute__((aligned(16)))

// XXX: volatile = gcc 3.4.4 temp. hack
volatile float SSE_Cre[4]		SIMD_ALIGN;
volatile float SSE_Cim[4]		SIMD_ALIGN;
volatile float SSE_threshold[4]		SIMD_ALIGN;
volatile float SSE_4dRe[4]		SIMD_ALIGN;
volatile float SSE_dIm[4]		SIMD_ALIGN;


void SSE_mandelbrot(
	float Re_min, float Re_max,
	float Im_min, float Im_max,
	float threshold,
	int maxiters,
	int width, int height,
	uint8_t *data)

{
	float dRe, dIm;
	int x, y;

	uint8_t* ptr = data;

	// step on Re and Im axis
	dRe = (Re_max - Re_min)/width;
	dIm = (Im_max - Im_min)/height;

	
	// prepare vectors
	// 1. threshold (xmm7)
	SSE_threshold[0] = threshold;
	SSE_threshold[1] = threshold;
	SSE_threshold[2] = threshold;
	SSE_threshold[3] = threshold;
#ifdef WINDOWS
	__asm__ volatile ("movups _SSE_threshold, %xmm7");
#else
	__asm__ volatile ("movups SSE_threshold, %xmm7");
#endif
	
	
	// 2. Cim (xmm1)
	SSE_Cim[0] = Im_min;
	SSE_Cim[1] = Im_min;
	SSE_Cim[2] = Im_min;
	SSE_Cim[3] = Im_min;
#ifdef WINDOWS
	__asm__ volatile ("movups _SSE_Cim, %xmm1");
#else
	__asm__ volatile ("movups SSE_Cim, %xmm1");
#endif

	// 3. Re advance every x iteration (memory)
	SSE_4dRe[0] = SSE_4dRe[1] = SSE_4dRe[2] = SSE_4dRe[3] = 4*dRe;

	// 4. Im advance every y iteration (memory)
	SSE_dIm[0] = SSE_dIm[1] = SSE_dIm[2] = SSE_dIm[3] = dIm;


	// calculations
	for (y=0; y < height; y++) {

		// xmm0 = {Re_min, Re_min + dRe, Re_min + 2*dRe + Re_min + 3*dRe
		SSE_Cre[0] = Re_min;
		SSE_Cre[1] = Re_min + dRe;
		SSE_Cre[2] = Re_min + 2*dRe;
		SSE_Cre[3] = Re_min + 3*dRe;
#ifdef WINDOWS
		__asm__ volatile ("movups _SSE_Cre, %xmm0");
#else
		__asm__ volatile ("movups SSE_Cre, %xmm0");
#endif

		for (x=0; x < width; x+=4) {
			__asm__ volatile (
			"xorps    %%xmm2, %%xmm2	\n"	// Xre = 0.0
			"xorps    %%xmm3, %%xmm3	\n"	// Xim = 0.0
			"pxor     %%xmm6, %%xmm6	\n"	// xmm6 = 4 x itercount

			"0:				\n"
			// Tim = 2*Xre*Xim + Cre
			"movaps   %%xmm2, %%xmm4	\n"
			"mulps    %%xmm3, %%xmm4	\n"	// xmm4 = Xre*Xim
			"addps    %%xmm4, %%xmm4	\n"	// xmm4 = 2*Xre*Xim
			"addps    %%xmm1, %%xmm4	\n"	// xmm4 = 2*Xre*Xim + Cre
			
			// Tre = Xre^2 - Xim^2 + Cim
			"mulps    %%xmm2, %%xmm2	\n"	// xmm2 = Xre^2
			"mulps    %%xmm3, %%xmm3	\n"	// xmm3 = Xim^2
			"addps    %%xmm0, %%xmm2	\n"	// xmm2 = Xre^2 + Cim
			"subps    %%xmm3, %%xmm2	\n"	// xmm2 = Xre^2 - Xim^2 + Cim

			// calculate distance
			"movaps   %%xmm2, %%xmm5	\n"
			"movaps   %%xmm4, %%xmm3	\n"
			"mulps    %%xmm5, %%xmm5	\n"	// xmm5 = Tre^2
			"mulps    %%xmm4, %%xmm4	\n"	// xmm4 = Tim^2
			"addps    %%xmm5, %%xmm4	\n"	// xmm4 = Tre^2 + Tim^2

#ifdef SSE2
			"cmpleps  %%xmm7, %%xmm4	\n"	// xmm4 < threshold
			"pmovmskb %%xmm4, %%edx 	\n"	// all greater?
			"test      %%edx, %%edx		\n"
			"jz	  3f			\n"	// break
#else // SSE4.1
			"cmpleps  %%xmm7, %%xmm4	\n"	// xmm4 < threshold
			"ptest    %%xmm4, %%xmm4	\n"	// all greater?
			"jz	  3f			\n"	// break
#endif

			"psubd    %%xmm4, %%xmm6	\n"	// at least on less:
								// advance itercount
								// for xmm[4] < threshold


			"subl     $1, %%ecx		\n"
			"jnz      0b			\n"
			"3:				\n"

			"packuswb  %%xmm6, %%xmm6	\n"	// convert itercounts
			"packuswb  %%xmm6, %%xmm6	\n"	// from dwords to bytes
			"movd      %%xmm6, (%%eax)	\n"	// and save

			:
			: "c" (maxiters),
			  "a" (ptr)
#ifdef SSE2
			: "edx"
#endif
			);

			// advance Cre vector
#ifdef WINDOWS
			__asm__ volatile ("addps _SSE_4dRe, %xmm0");
#else
			__asm__ volatile ("addps SSE_4dRe, %xmm0");
#endif

			// advance data ptr
			ptr += 4;
		}

		// advance Cim vector
#ifdef WINDOWS
		__asm__ volatile ("addps _SSE_dIm, %xmm1");
#else
		__asm__ volatile ("addps SSE_dIm, %xmm1");
#endif
	}
}
