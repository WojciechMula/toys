void bitmask_avx2(uint32_t* ptr, size_t n, uint32_t key, uint8_t* out) {

    uint32_t* output = (uint32_t*)out;

    const size_t N = 8*4; // unrolled 4 times
    const size_t chunks = n / N;
    const size_t tail   = n % N;

    const __m256i vkey = _mm256_set1_epi32(key);
    
    for (size_t i=0; i < chunks; i++) {
        
        const __m256i in0 = _mm256_loadu_si256((const __m256i*)(ptr + i*N + 0*8));
        const __m256i in1 = _mm256_loadu_si256((const __m256i*)(ptr + i*N + 1*8));
        const __m256i in2 = _mm256_loadu_si256((const __m256i*)(ptr + i*N + 2*8));
        const __m256i in3 = _mm256_loadu_si256((const __m256i*)(ptr + i*N + 3*8));

        const __m256i eq0 = _mm256_cmpeq_epi32(in0, vkey);
        const __m256i eq1 = _mm256_cmpeq_epi32(in1, vkey);
        const __m256i eq2 = _mm256_cmpeq_epi32(in2, vkey);
        const __m256i eq3 = _mm256_cmpeq_epi32(in3, vkey);

        // eq0 = [a0 a1 a2 a3 a4 a5 a6 a7] (packed dword)
        // eq1 = [b0 b1 b2 b3 b4 b5 b6 b7] (packed dword)
        // eq2 = [c0 c1 c2 c3 c4 c5 c6 c7] (packed dword)
        // eq3 = [d0 d1 d2 d3 d4 d5 d6 d7] (packed dword)

        //  t0 = [a0 a1 a2 a3 c0 c1 c2 c3 a4 a5 a6 a7 c4 c5 c6 c7] (packed word)
        const __m256i t0  = _mm256_packs_epi32(eq0, eq2);
        // m02 = [a0 a1 a2 a3 a4 a5 a6 a7 c0 c1 c2 c3 c4 c5 c6 c7] (packed word)
        const __m256i m02 = _mm256_permutevar8x32_epi32(t0,
                                _mm256_setr_epi32(0, 1, 4, 5, 2, 3, 6, 7));

        //  t0 = [b0 b1 b2 b3 d0 d1 d2 d3 b4 b5 b6 b7 d4 d5 d6 d7] (packed word)
        const __m256i t1 = _mm256_packs_epi32(eq1, eq3);
        // m13 = [b0 b1 b2 b3 b4 b5 b6 b7 d0 d1 d2 d3 d4 d5 d6 d7] (packed word)
        const __m256i m13 = _mm256_permutevar8x32_epi32(t1,
                                _mm256_setr_epi32(0, 1, 4, 5, 2, 3, 6, 7));

        // m   = [a0..7 b0..7 c0..7 d0..7] (packed byte)
        const __m256i m   = _mm256_packs_epi16(m02, m13);

        *output++ = _mm256_movemask_epi8(m);
    }

    if (tail > 0) {
        bitmask_better_2(ptr + chunks*N, tail, key, out + chunks*N);
    }
}
