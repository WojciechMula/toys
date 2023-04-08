/* Code generated automatically; DO NOT EDIT */
    switch (ipv4.size()) {
        case 7: // 1 case(s)
            switch (dotmask & 0x7f) {
                case 0x2a: // [1, 1, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 2, 4, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX1
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
                        const __m128i pattern = _mm_setr_epi8(-1, -1, -1, 6, 0, 2, 4, 7, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0x4a: // [1, 1, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, -1, 4, -1, 0, 2, 5, 7, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0x52: // [1, 2, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 2, -1, -1, 0, 3, 5, 7, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0x54: // [2, 1, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, -1, -1, -1, 1, 3, 5, 7, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
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
                        const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, -1, 4, 7, 8, -1, -1, -1, -1, -1, -1, 6, 6);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x4a: // [1, 1, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, -1, 4, 7, 0, 2, 5, 8, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0x8a: // [1, 1, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, 5, 6, -1, 8, -1, -1, -1, -1, 4, 4, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x52: // [1, 2, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 2, -1, 7, 0, 3, 5, 8, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0x92: // [1, 2, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 2, 5, -1, 0, 3, 6, 8, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0xa2: // [1, 3, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, -1, 6, -1, 8, -1, -1, 2, 2, -1, -1, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x54: // [2, 1, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, -1, -1, 7, 1, 3, 5, 8, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0x94: // [2, 1, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, -1, 5, -1, 1, 3, 6, 8, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0xa4: // [2, 2, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 3, -1, -1, 1, 4, 6, 8, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0xa8: // [3, 1, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, -1, 6, -1, 8, 0, 0, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX3
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
                        const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, 4, 5, 8, 9, -1, -1, -1, -1, -1, 4, 7, 7);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x8a: // [1, 1, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, 5, 6, 8, 9, -1, -1, -1, -1, 4, 4, -1, 8);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x52: // [1, 2, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, -1, 5, 8, 9, -1, -1, -1, 2, -1, -1, 7, 7);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x92: // [1, 2, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 2, 5, 8, 0, 3, 6, 9, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0x112: // [1, 2, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, 6, 7, -1, 9, -1, -1, -1, 2, 5, 5, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0xa2: // [1, 3, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, -1, 6, 8, 9, -1, -1, 2, 2, -1, -1, -1, 8);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x122: // [1, 3, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 6, 7, -1, 9, -1, -1, 2, 2, -1, 6, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x54: // [2, 1, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, -1, 5, 8, 9, -1, 0, -1, -1, -1, -1, 7, 7);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x94: // [2, 1, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, -1, 5, 8, 1, 3, 6, 9, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0x114: // [2, 1, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, 6, 7, -1, 9, -1, 0, -1, -1, 5, 5, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0xa4: // [2, 2, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 3, -1, 8, 1, 4, 6, 9, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0x124: // [2, 2, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 3, 6, -1, 1, 4, 7, 9, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0x144: // [2, 3, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, -1, 7, -1, 9, -1, 0, 3, 3, -1, -1, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0xa8: // [3, 1, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, -1, 6, 8, 9, 0, 0, -1, -1, -1, -1, -1, 8);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x128: // [3, 1, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 6, 7, -1, 9, 0, 0, -1, -1, -1, 6, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x148: // [3, 2, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, -1, 7, -1, 9, 0, 0, -1, 4, -1, -1, -1, -1);
                        SSE_CONVERT_MAX3
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
                        const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, 5, 6, 9, 10, -1, -1, -1, -1, 4, 4, 8, 8);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x92: // [1, 2, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, 5, 6, 9, 10, -1, -1, -1, 2, -1, 5, 8, 8);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x112: // [1, 2, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, 6, 7, 9, 10, -1, -1, -1, 2, 5, 5, -1, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0xa2: // [1, 3, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, -1, 6, 9, 10, -1, -1, 2, 2, -1, -1, 8, 8);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x122: // [1, 3, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 6, 7, 9, 10, -1, -1, 2, 2, -1, 6, -1, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x222: // [1, 3, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 7, 8, -1, 10, -1, -1, 2, 2, 6, 6, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x94: // [2, 1, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, 5, 6, 9, 10, -1, 0, -1, -1, -1, 5, 8, 8);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x114: // [2, 1, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, 6, 7, 9, 10, -1, 0, -1, -1, 5, 5, -1, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0xa4: // [2, 2, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, -1, 6, 9, 10, -1, 0, -1, 3, -1, -1, 8, 8);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x124: // [2, 2, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 3, 6, 9, 1, 4, 7, 10, -1, -1, -1, -1, -1, -1, -1, -1);
                        SSE_CONVERT_MAX2
                        }
                    break;
                case 0x224: // [2, 2, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, 7, 8, -1, 10, -1, 0, -1, 3, 6, 6, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x144: // [2, 3, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, -1, 7, 9, 10, -1, 0, 3, 3, -1, -1, -1, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x244: // [2, 3, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 7, 8, -1, 10, -1, 0, 3, 3, -1, 7, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0xa8: // [3, 1, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, -1, 6, 9, 10, 0, 0, -1, -1, -1, -1, 8, 8);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x128: // [3, 1, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 6, 7, 9, 10, 0, 0, -1, -1, -1, 6, -1, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x228: // [3, 1, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 7, 8, -1, 10, 0, 0, -1, -1, 6, 6, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x148: // [3, 2, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, -1, 7, 9, 10, 0, 0, -1, 4, -1, -1, -1, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x248: // [3, 2, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 7, 8, -1, 10, 0, 0, -1, 4, -1, 7, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x288: // [3, 3, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, -1, 8, -1, 10, 0, 0, 4, 4, -1, -1, -1, -1);
                        SSE_CONVERT_MAX3
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
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, 6, 7, 10, 11, -1, -1, -1, 2, 5, 5, 9, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x122: // [1, 3, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 6, 7, 10, 11, -1, -1, 2, 2, -1, 6, 9, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x222: // [1, 3, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 7, 8, 10, 11, -1, -1, 2, 2, 6, 6, -1, 10);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x114: // [2, 1, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, 6, 7, 10, 11, -1, 0, -1, -1, 5, 5, 9, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x124: // [2, 2, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, 6, 7, 10, 11, -1, 0, -1, 3, -1, 6, 9, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x224: // [2, 2, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, 7, 8, 10, 11, -1, 0, -1, 3, 6, 6, -1, 10);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x144: // [2, 3, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, -1, 7, 10, 11, -1, 0, 3, 3, -1, -1, 9, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x244: // [2, 3, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 7, 8, 10, 11, -1, 0, 3, 3, -1, 7, -1, 10);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x444: // [2, 3, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 8, 9, -1, 11, -1, 0, 3, 3, 7, 7, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x128: // [3, 1, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 6, 7, 10, 11, 0, 0, -1, -1, -1, 6, 9, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x228: // [3, 1, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 7, 8, 10, 11, 0, 0, -1, -1, 6, 6, -1, 10);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x148: // [3, 2, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, -1, 7, 10, 11, 0, 0, -1, 4, -1, -1, 9, 9);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x248: // [3, 2, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 7, 8, 10, 11, 0, 0, -1, 4, -1, 7, -1, 10);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x448: // [3, 2, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 8, 9, -1, 11, 0, 0, -1, 4, 7, 7, -1, -1);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x288: // [3, 3, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, -1, 8, 10, 11, 0, 0, 4, 4, -1, -1, -1, 10);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x488: // [3, 3, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 8, 9, -1, 11, 0, 0, 4, 4, -1, 8, -1, -1);
                        SSE_CONVERT_MAX3
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
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 7, 8, 11, 12, -1, -1, 2, 2, 6, 6, 10, 10);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x224: // [2, 2, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, 7, 8, 11, 12, -1, 0, -1, 3, 6, 6, 10, 10);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x244: // [2, 3, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 7, 8, 11, 12, -1, 0, 3, 3, -1, 7, 10, 10);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x444: // [2, 3, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 8, 9, 11, 12, -1, 0, 3, 3, 7, 7, -1, 11);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x228: // [3, 1, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 7, 8, 11, 12, 0, 0, -1, -1, 6, 6, 10, 10);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x248: // [3, 2, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 7, 8, 11, 12, 0, 0, -1, 4, -1, 7, 10, 10);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x448: // [3, 2, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 8, 9, 11, 12, 0, 0, -1, 4, 7, 7, -1, 11);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x288: // [3, 3, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, -1, 8, 11, 12, 0, 0, 4, 4, -1, -1, 10, 10);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x488: // [3, 3, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 8, 9, 11, 12, 0, 0, 4, 4, -1, 8, -1, 11);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x888: // [3, 3, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 9, 10, -1, 12, 0, 0, 4, 4, 8, 8, -1, -1);
                        SSE_CONVERT_MAX3
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
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 8, 9, 12, 13, -1, 0, 3, 3, 7, 7, 11, 11);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x448: // [3, 2, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 8, 9, 12, 13, 0, 0, -1, 4, 7, 7, 11, 11);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x488: // [3, 3, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 8, 9, 12, 13, 0, 0, 4, 4, -1, 8, 11, 11);
                        SSE_CONVERT_MAX3
                        }
                    break;
                case 0x888: // [3, 3, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 9, 10, 12, 13, 0, 0, 4, 4, 8, 8, -1, 12);
                        SSE_CONVERT_MAX3
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
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 9, 10, 13, 14, 0, 0, 4, 4, 8, 8, 12, 12);
                        SSE_CONVERT_MAX3
                        }
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
    }
