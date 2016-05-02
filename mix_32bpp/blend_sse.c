// the translation of procedure swar_64bit_blend
/*
    and   : 3
    or    : 1
    add   : 2
    shift : 3
    mul   : 4
*/
void blend_sse_1() {

    const uint16_t alpha0 = alpha;
    const uint16_t alpha1 = 255 - alpha;

	const int n = width * height * 4;

    const __m128i v_alpha0 = _mm_set1_epi16(alpha0);
    const __m128i v_alpha1 = _mm_set1_epi16(alpha1);
    const __m128i mask00ff = _mm_set1_epi16((int16_t)0x00ff);
    const __m128i maskff00 = _mm_set1_epi16((int16_t)0xff00);

    for (size_t i=0; i < n; i += 16) {
        __m128i A = _mm_load_si128((__m128i*)(imgA + i));
        __m128i B = _mm_load_si128((__m128i*)(imgB + i));

        __m128i A0 = _mm_and_si128(A, mask00ff);
        __m128i B0 = _mm_and_si128(B, mask00ff);
        __m128i A1 = _mm_srli_epi16(A, 8);
        __m128i B1 = _mm_srli_epi16(B, 8);

        A0 = _mm_mullo_epi16(A0, v_alpha0);
        B0 = _mm_mullo_epi16(B0, v_alpha1);

        A1 = _mm_mullo_epi16(A1, v_alpha0);
        B1 = _mm_mullo_epi16(B1, v_alpha1);
        
        __m128i R0 = _mm_add_epi16(A0, B0);
        R0 = _mm_srli_epi16(R0, 8);

        __m128i R1 = _mm_add_epi16(A1, B1);
        R1 = _mm_and_si128(R1, maskff00);

        _mm_store_si128((__m128i*)(data + i), _mm_or_si128(R0, R1));
    }
}


// another version (surprisingly, not faster)
/*
    and   : 5
    or    : 1
    add   : 2
    shift : 0
    mul   : 4
*/
void blend_sse_2() {

    const uint16_t alpha0 = alpha;
    const uint16_t alpha1 = 255 - alpha;

	const int n = width * height * 4;

    const __m128i v_alpha0 = _mm_set1_epi16(alpha0 << 8);
    const __m128i v_alpha1 = _mm_set1_epi16(alpha1 << 8);
    const __m128i mask00ff = _mm_set1_epi16((int16_t)0x00ff);
    const __m128i maskff00 = _mm_set1_epi16((int16_t)0xff00);

    for (size_t i=0; i < n; i += 16) {
        __m128i A = _mm_load_si128((__m128i*)(imgA + i));
        __m128i B = _mm_load_si128((__m128i*)(imgB + i));

        __m128i A0 = _mm_and_si128(A, mask00ff);
        __m128i B0 = _mm_and_si128(B, mask00ff);
        __m128i A1 = _mm_and_si128(A, maskff00);
        __m128i B1 = _mm_and_si128(B, maskff00);

        A0 = _mm_mulhi_epu16(A0, v_alpha0);
        B0 = _mm_mulhi_epu16(B0, v_alpha1);

        A1 = _mm_mulhi_epu16(A1, v_alpha0);
        B1 = _mm_mulhi_epu16(B1, v_alpha1);
        
        __m128i R0 = _mm_add_epi16(A0, B0);
        __m128i R1 = _mm_and_si128(_mm_add_epi16(A1, B1), maskff00);

        _mm_store_si128((__m128i*)(data + i), _mm_or_si128(R0, R1));
    }
}

#define blend_sse blend_sse_1
