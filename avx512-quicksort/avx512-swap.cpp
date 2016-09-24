namespace qs {
    namespace avx512 {

        void swap_epi32(__m512i& a, __m512i& b, __mmask16 mask_a, __mmask16 mask_b) {
            
            assert(mask_a != 0);
            assert(mask_b != 0);
            assert(_mm_popcnt_u64(mask_a) == _mm_popcnt_u64(mask_b));

            const __m512i to_swap_b = _mm512_mask_compress_epi32(_mm512_setzero_si512(), mask_a, a);
            const __m512i to_swap_a = _mm512_mask_compress_epi32(_mm512_setzero_si512(), mask_b, b);

            a = _mm512_mask_expand_epi32(a, mask_a, to_swap_a);
            b = _mm512_mask_expand_epi32(b, mask_b, to_swap_b);
        }


    } // namespace avx512

} // namespace qa
