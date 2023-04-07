/* Code generated automatically; DO NOT EDIT */
    const __m128i t0 = input;
    switch (code) {
        case 0: // [1, 1, 1, 1]
            {
            const __m128i pattern = _mm_setr_epi8(0, 2, 4, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            res.ipv4 = _mm_cvtsi128_si32(t1) & 0x0f0f0f0f;
            }
        break;
        case 1: // [1, 1, 1, 2]
            {
            const __m128i pattern = _mm_setr_epi8(-1, -1, -1, 6, 0, 2, 4, 7, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 2: // [1, 1, 1, 3]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, -1, 4, 7, 8, -1, -1, -1, -1, -1, -1, 6, 6);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 3: // [1, 1, 2, 1]
            {
            const __m128i pattern = _mm_setr_epi8(-1, -1, 4, -1, 0, 2, 5, 7, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 4: // [1, 1, 2, 2]
            {
            const __m128i pattern = _mm_setr_epi8(-1, -1, 4, 7, 0, 2, 5, 8, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 5: // [1, 1, 2, 3]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, 4, 5, 8, 9, -1, -1, -1, -1, -1, 4, 7, 7);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 6: // [1, 1, 3, 1]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, 5, 6, -1, 8, -1, -1, -1, -1, 4, 4, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 7: // [1, 1, 3, 2]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, 5, 6, 8, 9, -1, -1, -1, -1, 4, 4, -1, 8);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 8: // [1, 1, 3, 3]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, -1, 2, 5, 6, 9, 10, -1, -1, -1, -1, 4, 4, 8, 8);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 9: // [1, 2, 1, 1]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 2, -1, -1, 0, 3, 5, 7, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 10: // [1, 2, 1, 2]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 2, -1, 7, 0, 3, 5, 8, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 11: // [1, 2, 1, 3]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, -1, 5, 8, 9, -1, -1, -1, 2, -1, -1, 7, 7);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 12: // [1, 2, 2, 1]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 2, 5, -1, 0, 3, 6, 8, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 13: // [1, 2, 2, 2]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 2, 5, 8, 0, 3, 6, 9, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 14: // [1, 2, 2, 3]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, 5, 6, 9, 10, -1, -1, -1, 2, -1, 5, 8, 8);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 15: // [1, 2, 3, 1]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, 6, 7, -1, 9, -1, -1, -1, 2, 5, 5, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 16: // [1, 2, 3, 2]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, 6, 7, 9, 10, -1, -1, -1, 2, 5, 5, -1, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 17: // [1, 2, 3, 3]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 2, 3, 6, 7, 10, 11, -1, -1, -1, 2, 5, 5, 9, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 18: // [1, 3, 1, 1]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, -1, 6, -1, 8, -1, -1, 2, 2, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 19: // [1, 3, 1, 2]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, -1, 6, 8, 9, -1, -1, 2, 2, -1, -1, -1, 8);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 20: // [1, 3, 1, 3]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, -1, 6, 9, 10, -1, -1, 2, 2, -1, -1, 8, 8);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 21: // [1, 3, 2, 1]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 6, 7, -1, 9, -1, -1, 2, 2, -1, 6, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 22: // [1, 3, 2, 2]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 6, 7, 9, 10, -1, -1, 2, 2, -1, 6, -1, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 23: // [1, 3, 2, 3]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 6, 7, 10, 11, -1, -1, 2, 2, -1, 6, 9, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 24: // [1, 3, 3, 1]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 7, 8, -1, 10, -1, -1, 2, 2, 6, 6, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 25: // [1, 3, 3, 2]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 7, 8, 10, 11, -1, -1, 2, 2, 6, 6, -1, 10);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 26: // [1, 3, 3, 3]
            {
            const __m128i pattern = _mm_setr_epi8(-1, 0, 3, 4, 7, 8, 11, 12, -1, -1, 2, 2, 6, 6, 10, 10);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 27: // [2, 1, 1, 1]
            {
            const __m128i pattern = _mm_setr_epi8(0, -1, -1, -1, 1, 3, 5, 7, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 28: // [2, 1, 1, 2]
            {
            const __m128i pattern = _mm_setr_epi8(0, -1, -1, 7, 1, 3, 5, 8, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 29: // [2, 1, 1, 3]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, -1, 5, 8, 9, -1, 0, -1, -1, -1, -1, 7, 7);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 30: // [2, 1, 2, 1]
            {
            const __m128i pattern = _mm_setr_epi8(0, -1, 5, -1, 1, 3, 6, 8, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 31: // [2, 1, 2, 2]
            {
            const __m128i pattern = _mm_setr_epi8(0, -1, 5, 8, 1, 3, 6, 9, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 32: // [2, 1, 2, 3]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, 5, 6, 9, 10, -1, 0, -1, -1, -1, 5, 8, 8);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 33: // [2, 1, 3, 1]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, 6, 7, -1, 9, -1, 0, -1, -1, 5, 5, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 34: // [2, 1, 3, 2]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, 6, 7, 9, 10, -1, 0, -1, -1, 5, 5, -1, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 35: // [2, 1, 3, 3]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, -1, 3, 6, 7, 10, 11, -1, 0, -1, -1, 5, 5, 9, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 36: // [2, 2, 1, 1]
            {
            const __m128i pattern = _mm_setr_epi8(0, 3, -1, -1, 1, 4, 6, 8, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 37: // [2, 2, 1, 2]
            {
            const __m128i pattern = _mm_setr_epi8(0, 3, -1, 8, 1, 4, 6, 9, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 38: // [2, 2, 1, 3]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, -1, 6, 9, 10, -1, 0, -1, 3, -1, -1, 8, 8);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 39: // [2, 2, 2, 1]
            {
            const __m128i pattern = _mm_setr_epi8(0, 3, 6, -1, 1, 4, 7, 9, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 40: // [2, 2, 2, 2]
            {
            const __m128i pattern = _mm_setr_epi8(0, 3, 6, 9, 1, 4, 7, 10, -1, -1, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            }
        break;
        case 41: // [2, 2, 2, 3]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, 6, 7, 10, 11, -1, 0, -1, 3, -1, 6, 9, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 42: // [2, 2, 3, 1]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, 7, 8, -1, 10, -1, 0, -1, 3, 6, 6, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 43: // [2, 2, 3, 2]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, 7, 8, 10, 11, -1, 0, -1, 3, 6, 6, -1, 10);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 44: // [2, 2, 3, 3]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 3, 4, 7, 8, 11, 12, -1, 0, -1, 3, 6, 6, 10, 10);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 45: // [2, 3, 1, 1]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, -1, 7, -1, 9, -1, 0, 3, 3, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 46: // [2, 3, 1, 2]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, -1, 7, 9, 10, -1, 0, 3, 3, -1, -1, -1, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 47: // [2, 3, 1, 3]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, -1, 7, 10, 11, -1, 0, 3, 3, -1, -1, 9, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 48: // [2, 3, 2, 1]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 7, 8, -1, 10, -1, 0, 3, 3, -1, 7, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 49: // [2, 3, 2, 2]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 7, 8, 10, 11, -1, 0, 3, 3, -1, 7, -1, 10);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 50: // [2, 3, 2, 3]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 7, 8, 11, 12, -1, 0, 3, 3, -1, 7, 10, 10);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 51: // [2, 3, 3, 1]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 8, 9, -1, 11, -1, 0, 3, 3, 7, 7, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 52: // [2, 3, 3, 2]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 8, 9, 11, 12, -1, 0, 3, 3, 7, 7, -1, 11);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 53: // [2, 3, 3, 3]
            {
            const __m128i pattern = _mm_setr_epi8(0, 1, 4, 5, 8, 9, 12, 13, -1, 0, 3, 3, 7, 7, 11, 11);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 54: // [3, 1, 1, 1]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, -1, 6, -1, 8, 0, 0, -1, -1, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 55: // [3, 1, 1, 2]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, -1, 6, 8, 9, 0, 0, -1, -1, -1, -1, -1, 8);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 56: // [3, 1, 1, 3]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, -1, 6, 9, 10, 0, 0, -1, -1, -1, -1, 8, 8);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 57: // [3, 1, 2, 1]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 6, 7, -1, 9, 0, 0, -1, -1, -1, 6, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 58: // [3, 1, 2, 2]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 6, 7, 9, 10, 0, 0, -1, -1, -1, 6, -1, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 59: // [3, 1, 2, 3]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 6, 7, 10, 11, 0, 0, -1, -1, -1, 6, 9, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 60: // [3, 1, 3, 1]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 7, 8, -1, 10, 0, 0, -1, -1, 6, 6, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 61: // [3, 1, 3, 2]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 7, 8, 10, 11, 0, 0, -1, -1, 6, 6, -1, 10);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 62: // [3, 1, 3, 3]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, -1, 4, 7, 8, 11, 12, 0, 0, -1, -1, 6, 6, 10, 10);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 63: // [3, 2, 1, 1]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, -1, 7, -1, 9, 0, 0, -1, 4, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 64: // [3, 2, 1, 2]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, -1, 7, 9, 10, 0, 0, -1, 4, -1, -1, -1, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 65: // [3, 2, 1, 3]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, -1, 7, 10, 11, 0, 0, -1, 4, -1, -1, 9, 9);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 66: // [3, 2, 2, 1]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 7, 8, -1, 10, 0, 0, -1, 4, -1, 7, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 67: // [3, 2, 2, 2]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 7, 8, 10, 11, 0, 0, -1, 4, -1, 7, -1, 10);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 68: // [3, 2, 2, 3]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 7, 8, 11, 12, 0, 0, -1, 4, -1, 7, 10, 10);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 69: // [3, 2, 3, 1]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 8, 9, -1, 11, 0, 0, -1, 4, 7, 7, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 70: // [3, 2, 3, 2]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 8, 9, 11, 12, 0, 0, -1, 4, 7, 7, -1, 11);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 71: // [3, 2, 3, 3]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 4, 5, 8, 9, 12, 13, 0, 0, -1, 4, 7, 7, 11, 11);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 72: // [3, 3, 1, 1]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, -1, 8, -1, 10, 0, 0, 4, 4, -1, -1, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 73: // [3, 3, 1, 2]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, -1, 8, 10, 11, 0, 0, 4, 4, -1, -1, -1, 10);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 74: // [3, 3, 1, 3]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, -1, 8, 11, 12, 0, 0, 4, 4, -1, -1, 10, 10);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 75: // [3, 3, 2, 1]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 8, 9, -1, 11, 0, 0, 4, 4, -1, 8, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 76: // [3, 3, 2, 2]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 8, 9, 11, 12, 0, 0, 4, 4, -1, 8, -1, 11);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 77: // [3, 3, 2, 3]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 8, 9, 12, 13, 0, 0, 4, 4, -1, 8, 11, 11);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 78: // [3, 3, 3, 1]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 9, 10, -1, 12, 0, 0, 4, 4, 8, 8, -1, -1);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 79: // [3, 3, 3, 2]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 9, 10, 12, 13, 0, 0, 4, 4, 8, 8, -1, 12);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
        case 80: // [3, 3, 3, 3]
            {
            const __m128i pattern = _mm_setr_epi8(1, 2, 5, 6, 9, 10, 13, 14, 0, 0, 4, 4, 8, 8, 12, 12);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);
            const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30
            const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2 = _mm_subs_epu8(t1, ascii0);
            const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3 = _mm_maddubs_epi16(t2, weights);
            const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5 = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            }
        break;
    }
