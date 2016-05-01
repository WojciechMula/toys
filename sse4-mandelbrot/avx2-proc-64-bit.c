//=== AVX2 implementation - 64-bit code ==================================
#include <immintrin.h>

void AVX2_mandelbrot(
	float Re_min, float Re_max,
	float Im_min, float Im_max,
	float threshold,
	int maxiters,
	int width, int height,
	uint8_t *data)

{
	float dRe, dIm;
	int x, y;

	uint64_t* ptr = (uint64_t*)data;

	// step on Re and Im axis
	dRe = (Re_max - Re_min)/width;
	dIm = (Im_max - Im_min)/height;

	// prepare vectors
	// 1. threshold
    const __m256 vec_threshold = _mm256_set1_ps(threshold);

	// 2. Cim
    __m256 Cim = _mm256_set1_ps(Im_min);

	// 3. Re advance every x iteration
    const __m256 vec_dRe = _mm256_set1_ps(8*dRe);

	// 4. Im advance every y iteration
    const __m256 vec_dIm = _mm256_set1_ps(dIm);

	// calculations
	for (y=0; y < height; y++) {

        __m256 Cre = _mm256_setr_ps(
            Re_min + 0*dRe, Re_min + 1*dRe, Re_min + 2*dRe, Re_min + 3*dRe,
            Re_min + 4*dRe, Re_min + 5*dRe, Re_min + 6*dRe, Re_min + 7*dRe
        );

		for (x=0; x < width; x+=8) {

            __m256 Xre = _mm256_setzero_ps();
            __m256 Xim = _mm256_setzero_ps();

            __m256i itercount = _mm256_setzero_si256();

            int i;
            for (i=0; i < maxiters; i++) {

			    // Tre = Xre^2 - Xim^2 + Cim
                const __m256 Xre2 = _mm256_mul_ps(Xre, Xre);
                const __m256 Xim2 = _mm256_mul_ps(Xim, Xim);
                const __m256 Tre  = _mm256_add_ps(Cre, _mm256_sub_ps(Xre2, Xim2));

			    // Tim = 2*Xre*Xim + Cre
                const __m256 t1  = _mm256_mul_ps(Xre, Xim);
                const __m256 Tim = _mm256_add_ps(Cim, _mm256_add_ps(t1, t1));

                // sqr_dist = Tre^2 + Tim^2
                __m256 Tre2 = _mm256_mul_ps(Tre, Tre);
                __m256 Tim2 = _mm256_mul_ps(Tim, Tim);
                __m256 sqr_dist = _mm256_add_ps(Tre2, Tim2);

                // sqr_dist < threshold => 8 elements vector
                __m256 cmp = _mm256_cmp_ps(sqr_dist, vec_threshold, _CMP_LE_OS);
                const unsigned mask = _mm256_movemask_ps(cmp);
                if (mask == 0) {
                    break;
                }

                itercount = _mm256_sub_epi32(itercount, (__m256i)cmp);

                Xre = Tre;
                Xim = Tim;

            } // for

            const __m256i t1 = _mm256_shuffle_epi8(itercount, _mm256_setr_epi8(
                0, 4, 8, 12,
                (char)0xff, (char)0xff, (char)0xff, (char)0xff,
                (char)0xff, (char)0xff, (char)0xff, (char)0xff,
                (char)0xff, (char)0xff, (char)0xff, (char)0xff,

                (char)0xff, (char)0xff, (char)0xff, (char)0xff,
                0, 4, 8, 12, 
                (char)0xff, (char)0xff, (char)0xff, (char)0xff,
                (char)0xff, (char)0xff, (char)0xff, (char)0xff
            ));

            *ptr++ = _mm256_extract_epi64(t1, 0) | _mm256_extract_epi64(t1, 2);

			// advance Cre vector
            Cre = _mm256_add_ps(Cre, vec_dRe);
		}

		// advance Cim vector
        Cim = _mm256_add_ps(Cim, vec_dIm);
	}
}

