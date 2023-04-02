/* Code generated automatically; DO NOT EDIT */
    const __m128i ascii0 = _mm_set1_epi8('0');
    const __m128i t0 = _mm_sub_epi8(input, ascii0);
    switch (ipv4.size()) {
        case 7: // 1 case(s)
            switch (dotmask & 0x7f) {
                case 0x2a: // [1, 1, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 2, 4, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
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
                        const __m128i pattern = _mm_setr_epi8(0, 2, 4, 7, -1, -1, -1, 6, -1, -1, -1, -1, 1, 3, 5, 6);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x4a: // [1, 1, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 2, 5, 7, -1, -1, 4, -1, -1, -1, -1, -1, 1, 3, 4, 8);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x52: // [1, 2, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 3, 5, 7, -1, 2, -1, -1, -1, -1, -1, -1, 1, 2, 6, 8);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x54: // [2, 1, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 3, 5, 7, 0, -1, -1, -1, -1, -1, -1, -1, 0, 4, 6, 8);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
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
                        const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, -1, 4, 7, 8, -1, -1, -1, -1, -1, -1, 6, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, -1, -1, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x4a: // [1, 1, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 2, 5, 8, -1, -1, 4, 7, -1, -1, -1, -1, 1, 3, 4, 7);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x8a: // [1, 1, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, 5, 6, -1, 8, -1, -1, -1, -1, 4, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, -1, 99, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x52: // [1, 2, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 3, 5, 8, -1, 2, -1, 7, -1, -1, -1, -1, 1, 2, 6, 7);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x92: // [1, 2, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 3, 6, 8, -1, 2, 5, -1, -1, -1, -1, -1, 1, 2, 5, 9);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0xa2: // [1, 3, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, -1, 6, -1, 8, -1, -1, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 99, -1, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x54: // [2, 1, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 3, 5, 8, 0, -1, -1, 7, -1, -1, -1, -1, 0, 4, 6, 7);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x94: // [2, 1, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 3, 6, 8, 0, -1, 5, -1, -1, -1, -1, -1, 0, 4, 5, 9);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0xa4: // [2, 2, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 4, 6, 8, 0, 3, -1, -1, -1, -1, -1, -1, 0, 3, 7, 9);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0xa8: // [3, 1, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, -1, 6, -1, 8, 0, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, -1, -1, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
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
                        const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, 4, 5, 8, 9, -1, -1, -1, -1, -1, -1, 7, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, -1, 9, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x8a: // [1, 1, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, 5, 6, 8, 9, -1, -1, -1, -1, 4, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, -1, 99, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x52: // [1, 2, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, -1, 5, 8, 9, -1, -1, -1, -1, -1, -1, 7, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 9, -1, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x92: // [1, 2, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 3, 6, 9, -1, 2, 5, 8, -1, -1, -1, -1, 1, 2, 5, 8);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x112: // [1, 2, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, 6, 7, -1, 9, -1, -1, -1, -1, 5, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 9, 99, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0xa2: // [1, 3, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, -1, 6, 8, 9, -1, -1, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 99, -1, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x122: // [1, 3, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 6, 7, -1, 9, -1, -1, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 99, 9, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x54: // [2, 1, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, -1, 5, 8, 9, -1, -1, -1, -1, -1, -1, 7, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, -1, -1, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x94: // [2, 1, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 3, 6, 9, 0, -1, 5, 8, -1, -1, -1, -1, 0, 4, 5, 8);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x114: // [2, 1, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, 6, 7, -1, 9, -1, -1, -1, -1, 5, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, -1, 99, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0xa4: // [2, 2, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 4, 6, 9, 0, 3, -1, 8, -1, -1, -1, -1, 0, 3, 7, 8);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x124: // [2, 2, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 4, 7, 9, 0, 3, 6, -1, -1, -1, -1, -1, 0, 3, 6, 10);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x144: // [2, 3, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, -1, 7, -1, 9, -1, -1, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 99, -1, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0xa8: // [3, 1, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, -1, 6, 8, 9, 0, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, -1, -1, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x128: // [3, 1, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 6, 7, -1, 9, 0, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, -1, 9, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x148: // [3, 2, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, -1, 7, -1, 9, 0, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 9, -1, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
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
                        const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, 5, 6, 9, 10, -1, -1, -1, -1, 4, -1, 8, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, -1, 99, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x92: // [1, 2, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, 5, 6, 9, 10, -1, -1, -1, -1, -1, -1, 8, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 9, 9, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x112: // [1, 2, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, 6, 7, 9, 10, -1, -1, -1, -1, 5, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 9, 99, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0xa2: // [1, 3, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, -1, 6, 9, 10, -1, -1, 2, -1, -1, -1, 8, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 99, -1, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x122: // [1, 3, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 6, 7, 9, 10, -1, -1, 2, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 99, 9, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x222: // [1, 3, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 7, 8, -1, 10, -1, -1, 2, -1, 6, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 99, 99, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x94: // [2, 1, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, 5, 6, 9, 10, -1, -1, -1, -1, -1, -1, 8, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, -1, 9, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x114: // [2, 1, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, 6, 7, 9, 10, -1, -1, -1, -1, 5, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, -1, 99, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0xa4: // [2, 2, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, -1, 6, 9, 10, -1, -1, -1, -1, -1, -1, 8, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 9, -1, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x124: // [2, 2, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 4, 7, 10, 0, 3, 6, 9, -1, -1, -1, -1, 0, 3, 6, 9);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const uint32_t msd = _mm_extract_epi32(t1, 3);
                        if (haszero32(msd)) {
                            res.err = errLeadingZeros;
                            return res;
                        }
                        const uint64_t w01 = _mm_cvtsi128_si64(t1);
                        const uint32_t w0  = w01;
                        const uint32_t w1  = (w01 >> 32);
                        res.ipv4 = 10 * w1 + w0;
                        }
                    break;
                case 0x224: // [2, 2, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, 7, 8, -1, 10, -1, -1, -1, -1, 6, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 9, 99, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x144: // [2, 3, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, -1, 7, 9, 10, -1, -1, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 99, -1, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x244: // [2, 3, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 7, 8, -1, 10, -1, -1, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 99, 9, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0xa8: // [3, 1, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, -1, 6, 9, 10, 0, -1, -1, -1, -1, -1, 8, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, -1, -1, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x128: // [3, 1, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 6, 7, 9, 10, 0, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, -1, 9, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x228: // [3, 1, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 7, 8, -1, 10, 0, -1, -1, -1, 6, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, -1, 99, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x148: // [3, 2, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, -1, 7, 9, 10, 0, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 9, -1, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x248: // [3, 2, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 7, 8, -1, 10, 0, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 9, 9, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x288: // [3, 3, 1, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, -1, 8, -1, 10, 0, -1, 4, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 99, -1, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
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
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, 6, 7, 10, 11, -1, -1, -1, -1, 5, -1, 9, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 9, 99, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x122: // [1, 3, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 6, 7, 10, 11, -1, -1, 2, -1, -1, -1, 9, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 99, 9, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x222: // [1, 3, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 7, 8, 10, 11, -1, -1, 2, -1, 6, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 99, 99, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x114: // [2, 1, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, 6, 7, 10, 11, -1, -1, -1, -1, 5, -1, 9, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, -1, 99, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x124: // [2, 2, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, 6, 7, 10, 11, -1, -1, -1, -1, -1, -1, 9, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 9, 9, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x224: // [2, 2, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, 7, 8, 10, 11, -1, -1, -1, -1, 6, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 9, 99, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x144: // [2, 3, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, -1, 7, 10, 11, -1, -1, 3, -1, -1, -1, 9, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 99, -1, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x244: // [2, 3, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 7, 8, 10, 11, -1, -1, 3, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 99, 9, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x444: // [2, 3, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 8, 9, -1, 11, -1, -1, 3, -1, 7, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 99, 99, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x128: // [3, 1, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 6, 7, 10, 11, 0, -1, -1, -1, -1, -1, 9, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, -1, 9, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x228: // [3, 1, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 7, 8, 10, 11, 0, -1, -1, -1, 6, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, -1, 99, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x148: // [3, 2, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, -1, 7, 10, 11, 0, -1, -1, -1, -1, -1, 9, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 9, -1, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x248: // [3, 2, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 7, 8, 10, 11, 0, -1, -1, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 9, 9, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x448: // [3, 2, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 8, 9, -1, 11, 0, -1, -1, -1, 7, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 9, 99, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x288: // [3, 3, 1, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, -1, 8, 10, 11, 0, -1, 4, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 99, -1, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x488: // [3, 3, 2, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 8, 9, -1, 11, 0, -1, 4, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 99, 9, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
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
                        const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 7, 8, 11, 12, -1, -1, 2, -1, 6, -1, 10, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(-1, 99, 99, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x224: // [2, 2, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, 7, 8, 11, 12, -1, -1, -1, -1, 6, -1, 10, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 9, 99, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x244: // [2, 3, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 7, 8, 11, 12, -1, -1, 3, -1, -1, -1, 10, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 99, 9, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x444: // [2, 3, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 8, 9, 11, 12, -1, -1, 3, -1, 7, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 99, 99, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x228: // [3, 1, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 7, 8, 11, 12, 0, -1, -1, -1, 6, -1, 10, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, -1, 99, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x248: // [3, 2, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 7, 8, 11, 12, 0, -1, -1, -1, -1, -1, 10, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 9, 9, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x448: // [3, 2, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 8, 9, 11, 12, 0, -1, -1, -1, 7, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 9, 99, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x288: // [3, 3, 1, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, -1, 8, 11, 12, 0, -1, 4, -1, -1, -1, 10, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 99, -1, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x488: // [3, 3, 2, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 8, 9, 11, 12, 0, -1, 4, -1, -1, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 99, 9, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x888: // [3, 3, 3, 1]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 9, 10, -1, 12, 0, -1, 4, -1, 8, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 99, 99, -1, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
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
                        const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 8, 9, 12, 13, -1, -1, 3, -1, 7, -1, 11, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(9, 99, 99, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x448: // [3, 2, 3, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 8, 9, 12, 13, 0, -1, -1, -1, 7, -1, 11, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 9, 99, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x488: // [3, 3, 2, 3]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 8, 9, 12, 13, 0, -1, 4, -1, -1, -1, 11, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 99, 9, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                case 0x888: // [3, 3, 3, 2]
                        {
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 9, 10, 12, 13, 0, -1, 4, -1, 8, -1, -1, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 99, 99, 9, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
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
                        const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 9, 10, 13, 14, 0, -1, 4, -1, 8, -1, 12, -1);
                        const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
                        const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
                        const __m128i t2  = _mm_maddubs_epi16(t1, mul);
                        const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);
                        const __m128i t4  = _mm_add_epi16(t3, t2);
                        const __m128i minval = _mm_setr_epi16(99, 99, 99, 99, 0, 0, 0, 0);
                        const __m128i maxval = _mm_set1_epi16(0x0100);
                        const __m128i gt = _mm_cmpgt_epi16(t4, minval);
                        const __m128i lt = _mm_cmplt_epi16(t4, maxval);
                        const __m128i ir = _mm_and_si128(gt, lt);
                        const uint64_t w1 = _mm_cvtsi128_si64(ir);
                        if (haszero64(w1)) {
                            res.err = errInvalidInput;
                            return res;
                        }
                        const __m128i t5  = _mm_packus_epi16(t4, t4);
                        const uint32_t w0 = _mm_cvtsi128_si32(t5);
                        res.ipv4 = w0;
                        }
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
    }
