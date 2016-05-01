//=== SSE4 implementation - 64-bit code ==================================
#include <immintrin.h>

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

	uint32_t* ptr = (uint32_t*)data;

	// step on Re and Im axis
	dRe = (Re_max - Re_min)/width;
	dIm = (Im_max - Im_min)/height;

	// prepare vectors
	// 1. threshold
    const __m128 vec_threshold = _mm_set1_ps(threshold);

	// 2. Cim
    __m128 Cim = _mm_set1_ps(Im_min);

	// 3. Re advance every x iteration
    const __m128 vec_dRe = _mm_set1_ps(4*dRe);

	// 4. Im advance every y iteration
    const __m128 vec_dIm = _mm_set1_ps(dIm);

	// calculations
	for (y=0; y < height; y++) {

        __m128 Cre = _mm_setr_ps(Re_min, Re_min + dRe, Re_min + 2*dRe, Re_min + 3*dRe);

		for (x=0; x < width; x+=4) {

            __m128 Xre = _mm_setzero_ps();
            __m128 Xim = _mm_setzero_ps();

            __m128i itercount = _mm_setzero_si128();

            int i;
            for (i=0; i < maxiters; i++) {

			    // Tre = Xre^2 - Xim^2 + Cim
                const __m128 Xre2 = _mm_mul_ps(Xre, Xre);
                const __m128 Xim2 = _mm_mul_ps(Xim, Xim);
                const __m128 Tre  = _mm_add_ps(Cre, _mm_sub_ps(Xre2, Xim2));

			    // Tim = 2*Xre*Xim + Cre
                const __m128 t1  = _mm_mul_ps(Xre, Xim);
                const __m128 Tim = _mm_add_ps(Cim, _mm_add_ps(t1, t1));

                // sqr_dist = Tre^2 + Tim^2
                __m128 Tre2 = _mm_mul_ps(Tre, Tre);
                __m128 Tim2 = _mm_mul_ps(Tim, Tim);
                __m128 sqr_dist = _mm_add_ps(Tre2, Tim2);

                // sqr_dist < threshold => 4 elements vector
                __m128 cmp = _mm_cmple_ps(sqr_dist, vec_threshold);
                const unsigned mask = _mm_movemask_ps(cmp);
                if (mask == 0) {
                    break;
                }

                itercount = _mm_sub_epi32(itercount, (__m128i)cmp);

                Xre = Tre;
                Xim = Tim;

            } // for

            const __m128i t1 = _mm_packus_epi16(itercount, itercount);
            const __m128i t2 = _mm_packus_epi16(t1, t1);

            *ptr++ = _mm_cvtsi128_si32(t2);

			// advance Cre vector
            Cre = _mm_add_ps(Cre, vec_dRe);
		}

		// advance Cim vector
        Cim = _mm_add_ps(Cim, vec_dIm);
	}
}

