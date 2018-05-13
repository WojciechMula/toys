#include <cstdint>
#include <immintrin.h>

void jpeg_zigzag_sse(const uint8_t* in, uint8_t* out) {
    
    const __m128i A = _mm_loadu_si128((const __m128i*)(in + 0*16));
    const __m128i B = _mm_loadu_si128((const __m128i*)(in + 1*16));
    const __m128i C = _mm_loadu_si128((const __m128i*)(in + 2*16));
    const __m128i D = _mm_loadu_si128((const __m128i*)(in + 3*16));
    
    // row0 = [ A0| A1| A8| B0| A9| A2| A3|A10| B1| B8| C0| B9| B2|A11| A4| A5]
    const __m128i row0_A = _mm_shuffle_epi8(A,
                           _mm_setr_epi8(0, 1, 8, -1, 9, 2, 3,10, -1, -1, -1, -1, -1,11, 4, 5));
    const __m128i row0_B = _mm_shuffle_epi8(B,
                           _mm_setr_epi8(-1, -1, -1, 0, -1, -1, -1,-1, 1, 8, -1, 9, 2,-11, -1, -1));

    __m128i row0 = _mm_or_si128(row0_A, row0_B);
    row0 = _mm_insert_epi8(row0, _mm_extract_epi8(C, 0), 10);

    // row1 = [A12  B3 B10  C1  C8  D0  C9  C2 B11  B4 A13  A6  A7 A14  B5 B12]
    const __m128i row1_A = _mm_shuffle_epi8(A,
                           _mm_setr_epi8(12, -1, -1, -1, -1, -1, -1, -1, -1, -1, 13, 6, 7, 14, -1, -1));
    const __m128i row1_B = _mm_shuffle_epi8(B,
                           _mm_setr_epi8(-1, 3, 10, -1, -1, -1, -1, -1, 11, 4, -1, -1, -1, -1, 5, 12));
    const __m128i row1_C = _mm_shuffle_epi8(C,
                           _mm_setr_epi8(-1, -1, -1, 1, 8, -1, 9, 2, -1, -1, -1, -1, -1, -1, -1, -1));

    __m128i row1 = _mm_or_si128(row1_A,
                   _mm_or_si128(row1_B, row1_C));
    row1 = _mm_insert_epi8(row1, _mm_extract_epi8(D, 0), 5);

    // row2 = [C3 C10  D1  D8  D9  D2 C11  C4 B13  B6 A15  B7 B14  C5 C12  D3]
    const __m128i row2_B = _mm_shuffle_epi8(B,
                           _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, 13, 6, -1, 7, 14, -1, -1, -1));
    const __m128i row2_C = _mm_shuffle_epi8(C,
                           _mm_setr_epi8(3, 10, -1, -1, -1, -1, 11, 4, -1, -1, -1, -1, -1, 5, 12, -1));
    const __m128i row2_D = _mm_shuffle_epi8(D,
                           _mm_setr_epi8(-1, -1, 1, 8, 9, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3));
    __m128i row2 = _mm_or_si128(row2_B,
                   _mm_or_si128(row2_C, row2_D));
    row2 = _mm_insert_epi8(row2, _mm_extract_epi8(A, 15), 10);

    // row3 = D10 D11  D4 C13  C6 B15  C7 C14  D5 D12 D13  D6 C15  D7 D14 D15
    const __m128i row3_C = _mm_shuffle_epi8(C,
                           _mm_setr_epi8(-1, -1, -1, 13, 6, -1, 7, 14, -1, -1, -1, -1, 15, -1, -1, -1));
    const __m128i row3_D = _mm_shuffle_epi8(D,
                           _mm_setr_epi8(10, 11, 4, -1, -1, -1, -1, -1, 5, 12, 13, 6, -1, 7, 14, 15));
    __m128i row3 = _mm_or_si128(row3_C, row3_D);
    row3 = _mm_insert_epi8(row3, _mm_extract_epi8(B, 15), 5);

    _mm_storeu_si128((__m128i*)(out + 0*16), row0);
    _mm_storeu_si128((__m128i*)(out + 1*16), row1);
    _mm_storeu_si128((__m128i*)(out + 2*16), row2);
    _mm_storeu_si128((__m128i*)(out + 3*16), row3);
}
