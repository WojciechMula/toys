void Manual_AVX_SoA_improved(
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
    __m256i vecTrisCulled = _mm256_setzero_si256();
 
    // Loop Through 8 Triangles Per Pass
    for (int i = 0; i < N; i += 8)
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

        // wmu: Treat the mask as vector of integers: 0xffffffff is -1, 0 is 0
        //      "Treat" means just casting, no extra instructions are generated here.
        const __m256i test_int = (__m256i)test;

        // wmu: increment the vector counter
        vecTrisCulled = _mm256_sub_epi32(vecTrisCulled, test_int);
   }

   // wmu: Only once get the sum of elements from vecTrisCulled,
   //      And this is done in the most naive way, no horizontal additions
   //      (compiler may rewrite it anyway).
   const int total = _mm256_extract_epi32(vecTrisCulled, 0)
                   + _mm256_extract_epi32(vecTrisCulled, 1)
                   + _mm256_extract_epi32(vecTrisCulled, 2)
                   + _mm256_extract_epi32(vecTrisCulled, 3)
                   + _mm256_extract_epi32(vecTrisCulled, 4)
                   + _mm256_extract_epi32(vecTrisCulled, 5)
                   + _mm256_extract_epi32(vecTrisCulled, 6)
                   + _mm256_extract_epi32(vecTrisCulled, 7);

   // set the output variable
   if (cullMode == BACK_CW || cullMode == FRONT_CCW)
   {
       static_assert(1000000 % 8 == 0, "number of processed vectros * 8");
       trisCulled = (1000000 - total);
   }
   else if (cullMode == FRONT_CW || cullMode == BACK_CCW)
   {
        trisCulled = total;
   }
}
