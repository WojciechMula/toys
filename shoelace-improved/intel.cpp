// code from "Single Instruction Multiple Data Made Easy with Intel® Implicit SPMD Program Compiler"
// https://software.intel.com/en-us/articles/simd-made-easy-with-intel-ispc

void Manual_AVX_SoA(
    float const*const x0,
    float const*const x1,
    float const*const x2,
    float const*const y0,
    float const*const y1,
    float const*const y2,
    int cullMode,
    int &trisCulled
)
{
    int i;
    trisCulled = 0;
 
    // Loop Through 8 Triangles Per Pass
    for (i = 0; i < 1000000; i += 8)
   { 
        // Load Per-Triangle X-Components
        const __m256 i0x0 = _mm256_load_ps(x0 + i);
        const __m256 i1x1 = _mm256_load_ps(x1 + i);
        const __m256 i2x2 = _mm256_load_ps(x2 + i);

        // Load Per-Triangle Y-Components
        const __m256 i3y0 = _mm256_load_ps(y0 + i);
        const __m256 i4y1 = _mm256_load_ps(y1 + i);
        const __m256 i5y2 = _mm256_load_ps(y2 + i);
 
        // First Shift & Multiply
        const __m256 m0g0 = _mm256_mul_ps(i0x0, i4y1);
        const __m256 m0g1 = _mm256_mul_ps(i1x1, i5y2);
        const __m256 m0g2 = _mm256_mul_ps(i2x2, i3y0);

        // Second Shift & Multiply
        const __m256 m1g0 = _mm256_mul_ps(i1x1, i3y0);
        const __m256 m1g1 = _mm256_mul_ps(i2x2, i4y1);
        const __m256 m1g2 = _mm256_mul_ps(i0x0, i5y2);
 
        // Subtract for Differences
        const __m256 d0 = _mm256_sub_ps(m0g0, m1g0);
        const __m256 d1 = _mm256_sub_ps(m0g1, m1g1);
        const __m256 d2 = _mm256_sub_ps(m0g2, m1g2);
 
        // Sum for Area
        const __m256 s = _mm256_add_ps(_mm256_add_ps(d0, d1), d2);

        // Create a comparison mask 
        const __m256 m = _mm256_setzero_ps();

        // compare the values against 0 - result will be 0xffffffff or 0
        const __m256 test = _mm256_cmp_ps(s, m, _CMP_NLE_US);
        const __m256i test_int = _mm256_cvtps_epi32(test);  // convert the result to an integer
  
        // set the max to 1
        const __m256i one = _mm256_set1_epi32(1);
 
         // compute the min between 0xffffffff/0x0 stored in test_int and 1
        const __m256i max = _mm256_min_epu32(one, test_int);
 
         // horizontally add the values to get the result in element 0
         // adds elements 0 & 1, and 2 & 3 and stores them in elements 0, 1
        __m256i sum = _mm256_hadd_epi32(max, max);          	
        
        // adds elements 0 and 1, the total should now be in element 0
        sum = _mm256_hadd_epi32(sum, sum);           

        // adds elements 0 and 1, the total should now be in element 0
        sum = _mm256_hadd_epi32(sum, sum);  

        // extract the total from element zero
        int total = _mm256_extract_epi32(sum, 0);
 
        if (cullMode == BACK_CW || cullMode == FRONT_CCW)
        {
            trisCulled += (8 - total);
        }
        else if (cullMode == FRONT_CW || cullMode == BACK_CCW)
        {
             trisCulled += total;
        }
    }
}
