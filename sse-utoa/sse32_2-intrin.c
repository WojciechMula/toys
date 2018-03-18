char* utoa32_sse_2(uint32_t v) {

    // v is a 8-digit number: abcdefh (a..h are decimal digits)
    __m128i x = _mm_cvtsi32_si128(v);

    const __m128i div_10000 = _mm_set1_epi32(DIV_10000);
    const int div_10000_shift = 45;

    const __m128i mul_10000_merge = _mm_set1_epi32(65536 - 10000);

    const __m128i div_var = _mm_setr_epi16(
        8389,	// div 10^3, shift = 23 + 2
        5243,	// div 10^2, shift = 19 + 2
       13108,	// div 10^1, shift = 17 + 2
      0x8000,	// 
        8389,
        5243,
       13108,
      0x8000);

    const __m128i shift_var = _mm_setr_epi16(
        1 << (16 - (23 + 2 - 16)),
        1 << (16 - (19 + 2 - 16)),
        1 << (16 - 1 - 2),
        1 << (15),
        1 << (16 - (23 + 2 - 16)),
        1 << (16 - (19 + 2 - 16)),
        1 << (16 - 1 - 2),
        1 << (15)
    );

    const __m128i mul_10    = _mm_set1_epi16(10);
    const __m128i ascii0    = _mm_set1_epi8('0');

    //                [ 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 ]
    // x            = [       0       |       0       |       0       |      abcdefgh ]
	// x div 10^4   = [       0       |       0       |       0       |          abcd ]
    __m128i x_div_10000;
    x_div_10000 = _mm_mul_epu32(x, div_10000);
    x_div_10000 = _mm_srli_epi64(x_div_10000, div_10000_shift);

    // y            = [   0   |   0   |   0   |   0   |   0   |   0   |  abcd |  efgh ]
    __m128i y;
    y = _mm_mul_epu32(x_div_10000, mul_10000_merge);
    y = _mm_add_epi32(x, y);

    // t0           = [     0 |     0 |     0 |     0 |  abcd |  abcd |  efgh |  efgh ]
    __m128i t0;
    t0 = _mm_unpacklo_epi16(y, y);
    // t0           = [  efgh |  efgh |  efgh |  efgh |  abcd |  abcd |  abcd |  abcd ]
    t0 = _mm_shuffle_epi32(t0, 0x05); // order: 0, 0, 1, 1 = b000001010

    // z * 4
    t0 = _mm_slli_epi16(t0, 2);

    // z divide by 10^3, 10^2, 10^1 and 10^0
    // t1 = [ a << 9 | ab << 5 | abc << 3 | abcd << 2 | e << 9 | ef << 5 | efg << 3 | efgh << 2 ]
    __m128i t1;
    t1 = _mm_mulhi_epu16(t0, div_var);

    // variable shift by 9, 5, 3, 2
    // t2 = [ 000a | 00ab | 0abc | abcd | 000e | 00ef | 0efg | efgh ]
    __m128i t2;
    t2 = _mm_mulhi_epu16(t1, shift_var);
    
    // t3 = [ 0000 | 000a | 00ab | 0abc | 0000 | 000e | 00ef | 0efg ]
    __m128i t3 = _mm_slli_epi64(t2, 16);

    // t4 = [ 0000 | 00a0 | 0ab0 | abc0 | 0000 | 00e0 | 0ef0 | efg0 ]
    __m128i t4 = _mm_mullo_epi16(t3, mul_10);

    // t5 = t2 - t4
    // t5 = [    a |    b |    c |    d |    e |    f |    g |    h ]
    __m128i t5 = _mm_sub_epi16(t2, t4);

    // t6 = [              0               | a | b | c| d | e | f | g | h ]
    __m128i t6 = _mm_packus_epi16(_mm_setzero_si128(), t5);

    // determine number of leading zeros
    uint16_t mask = ~_mm_movemask_epi8(_mm_cmpeq_epi8(t6, _mm_setzero_si128()));
    uint32_t offset = __builtin_ctz(mask | 0x8000);

    // convert to ascii
    t6 = _mm_add_epi8(t6, ascii0);

    // and save result
    _mm_storeu_si128((__m128i*)utoa_buffer, t6);

    return &utoa_buffer[offset];
}
