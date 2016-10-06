//=== AVX512F + FMA implementation - 64-bit code ===========================
#include <immintrin.h>

void AVX512F_FMA_mandelbrot(
    float Re_min, float Re_max,
    float Im_min, float Im_max,
    float threshold,
    int maxiters,
    int width, int height,
    uint8_t *data)

{
    float dRe, dIm;
    int x, y;

    __m128i* ptr = (__m128i*)data;

    // step on Re and Im axis
    dRe = (Re_max - Re_min)/width;
    dIm = (Im_max - Im_min)/height;

    // prepare vectors
    // 1. threshold
    const __m512 vec_threshold = _mm512_set1_ps(threshold);

    // 2. Cim
    __m512 Cim = _mm512_set1_ps(Im_min);

    // 3. Re advance every x iteration
    const __m512 vec_dRe = _mm512_set1_ps(16*dRe);

    // 4. Im advance every y iteration
    const __m512 vec_dIm = _mm512_set1_ps(dIm);

    // calculations
    for (y=0; y < height; y++) {

        __m512 Cre = _mm512_setr_ps(
            Re_min +  0*dRe, Re_min +  1*dRe, Re_min +  2*dRe, Re_min +  3*dRe,
            Re_min +  4*dRe, Re_min +  5*dRe, Re_min +  6*dRe, Re_min +  7*dRe,
            Re_min +  8*dRe, Re_min +  9*dRe, Re_min + 10*dRe, Re_min + 11*dRe,
            Re_min + 12*dRe, Re_min + 13*dRe, Re_min + 14*dRe, Re_min + 15*dRe
        );

        for (x=0; x < width; x+=16) {

            __m512 Xre = _mm512_setzero_ps();
            __m512 Xim = _mm512_setzero_ps();

            __m512i itercount = _mm512_setzero_si512();

            int i;
            for (i=0; i < maxiters; i++) {

			    // Tre = Xre^2 - Xim^2 + Cim
                const __m512 Xre2 = _mm512_mul_ps(Xre, Xre);
                const __m512 Xim2 = _mm512_mul_ps(Xim, Xim);
                const __m512 Tre  = _mm512_add_ps(Cre, _mm512_sub_ps(Xre2, Xim2));

			    // Tim = 2*Xre*Xim + Cre
                const __m512 t1  = _mm512_mul_ps(Xre, Xim);
                const __m512 Tim = _mm512_add_ps(Cim, _mm512_add_ps(t1, t1));

                // sqr_dist = Tre^2 + Tim^2
                __m512 Tre2 = _mm512_mul_ps(Tre, Tre);
                __m512 Tim2 = _mm512_mul_ps(Tim, Tim);
                __m512 sqr_dist = _mm512_add_ps(Tre2, Tim2);

                // sqr_dist < threshold => 16-bit mask
                const __mmask16 mask = _mm512_cmp_ps_mask(sqr_dist, vec_threshold, _CMP_LE_OS);
                if (mask == 0) {
                    break;
                }

                itercount = _mm512_mask_add_epi32(itercount, mask, itercount, _mm512_set1_epi32(1));
                Xre = Tre;
                Xim = Tim;

            } // for

            *ptr++ = _mm512_cvtepi32_epi8(itercount);

            // advance Cre vector
            Cre = _mm512_add_ps(Cre, vec_dRe);
        }

        // advance Cim vector
        Cim = _mm512_add_ps(Cim, vec_dIm);
    }
}

