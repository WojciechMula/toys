uint32_t extract_sse2(const __m128i v, int index) {
    switch (index) {
        case 0:
            // fetch the lowest dword
            return _mm_cvtsi128_si32(v);
        case 1: {
            // Shift right the whole register, then get the lowest dword.
            // The instruction accepts only immediate value, thus
            // we must dispatch index in runtime.
            const __m128i tmp = _mm_bsrli_si128(v, 1);
            return _mm_cvtsi128_si32(tmp);
        }
        case 2: {
            const __m128i tmp = _mm_bsrli_si128(v, 2);
            return _mm_cvtsi128_si32(tmp);
        }
        case 3: {
            const __m128i tmp = _mm_bsrli_si128(v, 3);
            return _mm_cvtsi128_si32(tmp);
        }
        case 4: {
            const __m128i tmp = _mm_bsrli_si128(v, 4);
            return _mm_cvtsi128_si32(tmp);
        }
        case 5: {
            const __m128i tmp = _mm_bsrli_si128(v, 5);
            return _mm_cvtsi128_si32(tmp);
        }
        case 6: {
            const __m128i tmp = _mm_bsrli_si128(v, 6);
            return _mm_cvtsi128_si32(tmp);
        }
        case 7: {
            const __m128i tmp = _mm_bsrli_si128(v, 7);
            return _mm_cvtsi128_si32(tmp);
        }
        case 8: {
            const __m128i tmp = _mm_bsrli_si128(v, 8);
            return _mm_cvtsi128_si32(tmp);
        }
        case 9: {
            const __m128i tmp = _mm_bsrli_si128(v, 9);
            return _mm_cvtsi128_si32(tmp);
        }
        case 10: {
            const __m128i tmp = _mm_bsrli_si128(v, 10);
            return _mm_cvtsi128_si32(tmp);
        }
        case 11: {
            const __m128i tmp = _mm_bsrli_si128(v, 11);
            return _mm_cvtsi128_si32(tmp);
        }
        case 12: {
            const __m128i tmp = _mm_bsrli_si128(v, 12);
            return _mm_cvtsi128_si32(tmp);
        }
        default:
            throw std::runtime_error("invalid value");
    }

    return 0;
}
