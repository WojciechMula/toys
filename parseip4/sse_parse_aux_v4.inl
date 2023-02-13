/* Code generated automatically; DO NOT EDIT */
    const __m128i ascii0 = _mm_set1_epi8('0');
    const __m128i t0 = _mm_sub_epi8(input, ascii0);
    switch (ipv4.size()) {
        case 7: // 1 case(s)
            switch (dotmask & 0x7f) {
                case 0x2a: // [1, 1, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(6, 4, 2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        res.ipv4 = _mm_cvtsi128_si32(t1);
                        }
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 8: // 4 case(s)
            switch (dotmask & 0xff) {
                case 0x2a: // [1, 1, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(7, 4, 2, 0, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x4a: // [1, 1, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(7, 5, 2, 0, -1, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x52: // [1, 2, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(7, 5, 3, 0, -1, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x54: // [2, 1, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(7, 5, 3, 1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 9: // 10 case(s)
            switch (dotmask & 0x1ff) {
                case 0x2a: // [1, 1, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(8, 4, 2, 0, 7, -1, -1, -1, 6, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x4a: // [1, 1, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(8, 5, 2, 0, 7, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x8a: // [1, 1, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(8, 6, 2, 0, -1, 5, -1, -1, -1, 4, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x52: // [1, 2, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(8, 5, 3, 0, 7, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x92: // [1, 2, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(8, 6, 3, 0, -1, 5, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0xa2: // [1, 3, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(8, 6, 4, 0, -1, -1, 3, -1, -1, -1, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x54: // [2, 1, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(8, 5, 3, 1, 7, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x94: // [2, 1, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(8, 6, 3, 1, -1, 5, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0xa4: // [2, 2, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(8, 6, 4, 1, -1, -1, 3, 0, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0xa8: // [3, 1, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(8, 6, 4, 2, -1, -1, -1, 1, -1, -1, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 10: // 16 case(s)
            switch (dotmask & 0x3ff) {
                case 0x4a: // [1, 1, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 5, 2, 0, 8, 4, -1, -1, 7, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x8a: // [1, 1, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 6, 2, 0, 8, 5, -1, -1, -1, 4, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x52: // [1, 2, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 5, 3, 0, 8, -1, 2, -1, 7, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x92: // [1, 2, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 6, 3, 0, 8, 5, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x112: // [1, 2, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 7, 3, 0, -1, 6, 2, -1, -1, 5, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0xa2: // [1, 3, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 6, 4, 0, 8, -1, 3, -1, -1, -1, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x122: // [1, 3, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 7, 4, 0, -1, 6, 3, -1, -1, -1, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x54: // [2, 1, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 5, 3, 1, 8, -1, -1, 0, 7, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x94: // [2, 1, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 6, 3, 1, 8, 5, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x114: // [2, 1, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 7, 3, 1, -1, 6, -1, 0, -1, 5, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0xa4: // [2, 2, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 6, 4, 1, 8, -1, 3, 0, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x124: // [2, 2, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 7, 4, 1, -1, 6, 3, 0, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x144: // [2, 3, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 7, 5, 1, -1, -1, 4, 0, -1, -1, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0xa8: // [3, 1, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 6, 4, 2, 8, -1, -1, 1, -1, -1, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x128: // [3, 1, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 7, 4, 2, -1, 6, -1, 1, -1, -1, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x148: // [3, 2, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(9, 7, 5, 2, -1, -1, 4, 1, -1, -1, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 11: // 19 case(s)
            switch (dotmask & 0x7ff) {
                case 0x8a: // [1, 1, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 6, 2, 0, 9, 5, -1, -1, 8, 4, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x92: // [1, 2, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 6, 3, 0, 9, 5, 2, -1, 8, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x112: // [1, 2, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 7, 3, 0, 9, 6, 2, -1, -1, 5, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0xa2: // [1, 3, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 6, 4, 0, 9, -1, 3, -1, 8, -1, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x122: // [1, 3, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 7, 4, 0, 9, 6, 3, -1, -1, -1, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x222: // [1, 3, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 8, 4, 0, -1, 7, 3, -1, -1, 6, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x94: // [2, 1, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 6, 3, 1, 9, 5, -1, 0, 8, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x114: // [2, 1, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 7, 3, 1, 9, 6, -1, 0, -1, 5, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0xa4: // [2, 2, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 6, 4, 1, 9, -1, 3, 0, 8, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x124: // [2, 2, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 7, 4, 1, 9, 6, 3, 0, -1, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x224: // [2, 2, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 8, 4, 1, -1, 7, 3, 0, -1, 6, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x144: // [2, 3, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 7, 5, 1, 9, -1, 4, 0, -1, -1, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x244: // [2, 3, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 8, 5, 1, -1, 7, 4, 0, -1, -1, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0xa8: // [3, 1, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 6, 4, 2, 9, -1, -1, 1, 8, -1, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x128: // [3, 1, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 7, 4, 2, 9, 6, -1, 1, -1, -1, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x228: // [3, 1, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 8, 4, 2, -1, 7, -1, 1, -1, 6, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x148: // [3, 2, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 7, 5, 2, 9, -1, 4, 1, -1, -1, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x248: // [3, 2, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 8, 5, 2, -1, 7, 4, 1, -1, -1, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x288: // [3, 3, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(10, 8, 6, 2, -1, -1, 5, 1, -1, -1, 4, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 12: // 16 case(s)
            switch (dotmask & 0xfff) {
                case 0x112: // [1, 2, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 7, 3, 0, 10, 6, 2, -1, 9, 5, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x122: // [1, 3, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 7, 4, 0, 10, 6, 3, -1, 9, -1, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x222: // [1, 3, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 8, 4, 0, 10, 7, 3, -1, -1, 6, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x114: // [2, 1, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 7, 3, 1, 10, 6, -1, 0, 9, 5, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x124: // [2, 2, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 7, 4, 1, 10, 6, 3, 0, 9, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x224: // [2, 2, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 8, 4, 1, 10, 7, 3, 0, -1, 6, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x144: // [2, 3, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 7, 5, 1, 10, -1, 4, 0, 9, -1, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x244: // [2, 3, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 8, 5, 1, 10, 7, 4, 0, -1, -1, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x444: // [2, 3, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 9, 5, 1, -1, 8, 4, 0, -1, 7, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x128: // [3, 1, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 7, 4, 2, 10, 6, -1, 1, 9, -1, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x228: // [3, 1, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 8, 4, 2, 10, 7, -1, 1, -1, 6, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x148: // [3, 2, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 7, 5, 2, 10, -1, 4, 1, 9, -1, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x248: // [3, 2, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 8, 5, 2, 10, 7, 4, 1, -1, -1, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x448: // [3, 2, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 9, 5, 2, -1, 8, 4, 1, -1, 7, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x288: // [3, 3, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 8, 6, 2, 10, -1, 5, 1, -1, -1, 4, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x488: // [3, 3, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(11, 9, 6, 2, -1, 8, 5, 1, -1, -1, 4, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 13: // 10 case(s)
            switch (dotmask & 0x1fff) {
                case 0x222: // [1, 3, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(12, 8, 4, 0, 11, 7, 3, -1, 10, 6, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x224: // [2, 2, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(12, 8, 4, 1, 11, 7, 3, 0, 10, 6, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x244: // [2, 3, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(12, 8, 5, 1, 11, 7, 4, 0, 10, -1, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x444: // [2, 3, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(12, 9, 5, 1, 11, 8, 4, 0, -1, 7, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x228: // [3, 1, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(12, 8, 4, 2, 11, 7, -1, 1, 10, 6, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x248: // [3, 2, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(12, 8, 5, 2, 11, 7, 4, 1, 10, -1, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x448: // [3, 2, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(12, 9, 5, 2, 11, 8, 4, 1, -1, 7, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x288: // [3, 3, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(12, 8, 6, 2, 11, -1, 5, 1, 10, -1, 4, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x488: // [3, 3, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(12, 9, 6, 2, 11, 8, 5, 1, -1, -1, 4, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x888: // [3, 3, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(12, 10, 6, 2, -1, 9, 5, 1, -1, 8, 4, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 14: // 4 case(s)
            switch (dotmask & 0x3fff) {
                case 0x444: // [2, 3, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(13, 9, 5, 1, 12, 8, 4, 0, 11, 7, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x448: // [3, 2, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(13, 9, 5, 2, 12, 8, 4, 1, 11, 7, -1, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x488: // [3, 3, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(13, 9, 6, 2, 12, 8, 5, 1, 11, -1, 4, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                case 0x888: // [3, 3, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(13, 10, 6, 2, 12, 9, 5, 1, -1, 8, 4, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 15: // 1 case(s)
            switch (dotmask & 0x7fff) {
                case 0x888: // [3, 3, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(14, 10, 6, 2, 13, 9, 5, 1, 12, 8, 4, 0, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w2 = _mm_extract_epi32(t1, 2);
                        const uint32_t w0 = w01;
                        const uint32_t w1 = (w01 >> 32);
                        res.ipv4 = 10 * (10 * w2 + w1) + w0;
                        }
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
    }
