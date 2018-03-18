char* utoa32_sse(uint32_t v) {
    // v is a 8-digit number: abcdefh (a..h are decimal digits)
    __m128i x = _mm_cvtsi32_si128(v);

    const __m128i div_10000 = _mm_set1_epi32(DIV_10000);
    const __m128i mul_10000 = _mm_set1_epi32(10000);
    const int div_10000_shift = 45;

    const __m128i div_100   = _mm_set1_epi16(DIV_100);
    const __m128i mul_100   = _mm_set1_epi16(100);
    const int div_100_shift = 3;

    const __m128i div_10    = _mm_set1_epi16(DIV_10);
    const __m128i mul_10    = _mm_set1_epi16(10);

    const __m128i ascii0    = _mm_set1_epi8('0');
    
    //                [ 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 | 3 | 2 | 1 | 0 ]
    // x            = [       0       |       0       |       0       |      abcdefgh ]
	// x div 10^4   = [       0       |       0       |       0       |          abcd ]
    __m128i x_div_10000;
    x_div_10000 = _mm_mul_epu32(x, div_10000);
    x_div_10000 = _mm_srli_epi64(x_div_10000, div_10000_shift);

    // x mod 10^4   = [       0       |       0       |       0       |          efgh ]
    __m128i x_mod_10000;
    x_mod_10000 = _mm_mul_epu32(x_div_10000, mul_10000);
    x_mod_10000 = _mm_sub_epi32(x, x_mod_10000);

    // y            = [   0   |   0   |   0   |   0   |   0   |   0   |  abcd |  efgh ]
    __m128i y = _mm_unpacklo_epi16(x_div_10000, x_mod_10000);
    
    // y_div_100    = [   0   |   0   |   0   |   0   |   0   |   0   |    ab |    ef ]
    __m128i y_div_100;
    y_div_100 = _mm_mulhi_epu16(y, div_100);
    y_div_100 = _mm_srli_epi16(y_div_100, div_100_shift);

    // y_mod_100    = [   0   |   0   |   0   |   0   |   0   |   0   |    cd |    gh ]
    __m128i y_mod_100;
    y_mod_100 = _mm_mullo_epi16(y_div_100, mul_100);
    y_mod_100 = _mm_sub_epi16(y, y_mod_100);

    // z            = [   0   |   0   |   0   |   0   |    ab |    cd |    ef |    gh ]
    __m128i z = _mm_unpacklo_epi16(y_div_100, y_mod_100);

    // z_div_10     = [   0   |   0   |   0   |   0   |     a |     c |     e |     g ]
    __m128i z_div_10 = _mm_mulhi_epu16(z, div_10);

    // z_mod_10     = [   0   |   0   |   0   |   0   |     b |     d |     f |     h ]
    __m128i z_mod_10;
    z_mod_10 = _mm_mullo_epi16(z_div_10, mul_10);
    z_mod_10 = _mm_sub_epi16(z, z_mod_10);

    // interleave z_mod_10 and z_div_10 - it's still a word vector
    __m128i tmp;
    // tmp          = [   a   |   b   |   c   |   d   |   e   |   f   |   g   |   h   ]
    tmp = _mm_unpacklo_epi16(z_div_10, z_mod_10);

    // tmp          = [ 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | a | b | c | d | e | f | g | h ]
    tmp = _mm_packus_epi16(_mm_setzero_si128(), tmp);

    // determine number of leading zeros
    uint16_t mask = ~_mm_movemask_epi8(_mm_cmpeq_epi8(tmp, _mm_setzero_si128()));
    uint32_t offset = __builtin_ctz(mask | 0x8000);

    // convert to ascii
    tmp = _mm_add_epi8(tmp, ascii0);

    // and save result
    _mm_storeu_si128((__m128i*)utoa_buffer, tmp);

	return &utoa_buffer[offset];
}
