#include <immintrin.h>

#define FORCE_INLINE inline __attribute__((always_inline))

namespace avx512sort {

    // sort 16 elements
    void FORCE_INLINE sort1xreg_update(const __m512i b, const __m512i v1, __m512i& r1) {

        const uint64_t lt1    = _mm512_cmplt_epi32_mask(v1, b);
        const uint64_t lt_cnt = _mm_popcnt_u64(lt1);

        const uint64_t eq1    = _mm512_cmpeq_epi32_mask(v1, b);
        const uint64_t eq_cnt = _mm_popcnt_u64(eq1);

        const uint64_t mask   = (uint64_t(1) << (lt_cnt + eq_cnt)) - (uint64_t(1) << lt_cnt);

        r1 = _mm512_mask_mov_epi32(r1, mask, b);
    }


    // sort less than 16 elements
    void FORCE_INLINE sort1xreg_tail_update(const __m512i b, const __m512i v1, __mmask16 v1tail, __m512i& r1) {

        const uint64_t lt1    = _mm512_mask_cmplt_epi32_mask(v1tail, v1, b);
        const uint64_t eq1    = _mm512_mask_cmpeq_epi32_mask(v1tail, v1, b);
        const uint64_t lt_cnt = _mm_popcnt_u64(lt1);
        const uint64_t eq_cnt = _mm_popcnt_u64(eq1);

        const uint64_t mask   = (uint64_t(1) << (lt_cnt + eq_cnt)) - (uint64_t(1) << lt_cnt);

        r1 = _mm512_mask_mov_epi32(r1, mask, b);
    }


    // sort 32 elements
    void FORCE_INLINE sort2xreg_update(
        const __m512i b,
        const __m512i v1, const __m512i v2,
        __m512i& r1, __m512i& r2) {

        const uint64_t lt1    = _mm512_cmplt_epi32_mask(v1, b);
        const uint64_t lt2    = _mm512_cmplt_epi32_mask(v2, b);
        const uint64_t lt_cnt = _mm_popcnt_u64(lt1 | (lt2 << 16));

        const uint64_t eq1    = _mm512_cmpeq_epi32_mask(v1, b);
        const uint64_t eq2    = _mm512_cmpeq_epi32_mask(v2, b);
        const uint64_t eq_cnt = _mm_popcnt_u64(eq1 | (eq2 << 16));

        const uint64_t mask   = (uint64_t(1) << (lt_cnt + eq_cnt)) - (uint64_t(1) << lt_cnt);

        r1 = _mm512_mask_mov_epi32(r1, mask & 0xffff, b);
        r2 = _mm512_mask_mov_epi32(r2, (mask >> 16) & 0xffff, b);
    }


    // sort 17 .. 31 elements
    void FORCE_INLINE sort2xreg_tail_update(
        const __m512i b,
        const __m512i v1, const __m512i v2, __mmask16 v2tail,
        __m512i& r1, __m512i& r2) {

        const uint64_t lt1    = _mm512_cmplt_epi32_mask(v1, b);
        const uint64_t lt2    = _mm512_mask_cmplt_epi32_mask(v2tail, v2, b);
        const uint64_t lt_cnt = _mm_popcnt_u64(lt1 | (lt2 << 16));

        const uint64_t eq1    = _mm512_cmpeq_epi32_mask(v1, b);
        const uint64_t eq2    = _mm512_mask_cmpeq_epi32_mask(v2tail, v2, b);
        const uint64_t eq_cnt = _mm_popcnt_u64(eq1 | (eq2 << 16));

        const uint64_t mask   = (uint64_t(1) << (lt_cnt + eq_cnt)) - (uint64_t(1) << lt_cnt);

        r1 = _mm512_mask_mov_epi32(r1, mask & 0xffff, b);
        r2 = _mm512_mask_mov_epi32(r2, (mask >> 16) & 0xffff, b);
    }


    // sort 48 elements
    void FORCE_INLINE sort3xreg_update(
        const __m512i b,
        const __m512i v1, const __m512i v2, const __m512i v3,
        __m512i& r1, __m512i& r2, __m512i& r3) {

        const uint64_t lt1    = _mm512_cmplt_epi32_mask(v1, b);
        const uint64_t lt2    = _mm512_cmplt_epi32_mask(v2, b);
        const uint64_t lt3    = _mm512_cmplt_epi32_mask(v3, b);
        const uint64_t lt_cnt = _mm_popcnt_u64(lt1 | (lt2 << 16) | (lt3 << 32));

        const uint64_t eq1    = _mm512_cmpeq_epi32_mask(v1, b);
        const uint64_t eq2    = _mm512_cmpeq_epi32_mask(v2, b);
        const uint64_t eq3    = _mm512_cmpeq_epi32_mask(v3, b);
        const uint64_t eq_cnt = _mm_popcnt_u64(eq1 | (eq2 << 16) | (eq3 << 32));

        const uint64_t mask   = (uint64_t(1) << (lt_cnt + eq_cnt)) - (uint64_t(1) << lt_cnt);

        r1 = _mm512_mask_mov_epi32(r1, mask & 0xffff, b);
        r2 = _mm512_mask_mov_epi32(r2, (mask >> 16) & 0xffff, b);
        r3 = _mm512_mask_mov_epi32(r3, (mask >> 32) & 0xffff, b);
    }


    // sort 33 .. 47 elements
    void FORCE_INLINE sort3xreg_tail_update(
        const __m512i b,
        const __m512i v1, const __m512i v2, const __m512i v3, __mmask16 v3tail,
        __m512i& r1, __m512i& r2, __m512i& r3) {

        const uint64_t lt1    = _mm512_cmplt_epi32_mask(v1, b);
        const uint64_t lt2    = _mm512_cmplt_epi32_mask(v2, b);
        const uint64_t lt3    = _mm512_mask_cmplt_epi32_mask(v3tail, v3, b);
        const uint64_t lt_cnt = _mm_popcnt_u64(lt1 | (lt2 << 16) | (lt3 << 32));

        const uint64_t eq1    = _mm512_cmpeq_epi32_mask(v1, b);
        const uint64_t eq2    = _mm512_cmpeq_epi32_mask(v2, b);
        const uint64_t eq3    = _mm512_mask_cmpeq_epi32_mask(v3tail, v3, b);
        const uint64_t eq_cnt = _mm_popcnt_u64(eq1 | (eq2 << 16) | (eq3 << 32));

        const uint64_t mask   = (uint64_t(1) << (lt_cnt + eq_cnt)) - (uint64_t(1) << lt_cnt);

        r1 = _mm512_mask_mov_epi32(r1, mask & 0xffff, b);
        r2 = _mm512_mask_mov_epi32(r2, (mask >> 16) & 0xffff, b);
        r3 = _mm512_mask_mov_epi32(r3, (mask >> 32) & 0xffff, b);
    }


    // sort 64 elements
    void FORCE_INLINE sort4xreg_update(
        const __m512i b,
        const __m512i v1, const __m512i v2, const __m512i v3, const __m512i v4,
        __m512i& r1, __m512i& r2, __m512i& r3, __m512i& r4) {

        const uint64_t lt1    = _mm512_cmplt_epi32_mask(v1, b);
        const uint64_t lt2    = _mm512_cmplt_epi32_mask(v2, b);
        const uint64_t lt3    = _mm512_cmplt_epi32_mask(v3, b);
        const uint64_t lt4    = _mm512_cmplt_epi32_mask(v4, b);
        const uint64_t lt_cnt = _mm_popcnt_u64(lt1 | (lt2 << 16) | (lt3 << 32) | (lt4 << 48));

        const uint64_t eq1    = _mm512_cmpeq_epi32_mask(v1, b);
        const uint64_t eq2    = _mm512_cmpeq_epi32_mask(v2, b);
        const uint64_t eq3    = _mm512_cmpeq_epi32_mask(v3, b);
        const uint64_t eq4    = _mm512_cmpeq_epi32_mask(v4, b);
        const uint64_t eq_cnt = _mm_popcnt_u64(eq1 | (eq2 << 16) | (eq3 << 32) | (eq4 << 48));

        if (eq_cnt == 64) {
            r1 = r2 = r3 = r4 = b;
            return;
        }

        const uint64_t mask   = (uint64_t(1) << (lt_cnt + eq_cnt)) - (uint64_t(1) << lt_cnt);

        r1 = _mm512_mask_mov_epi32(r1, mask & 0xffff, b);
        r2 = _mm512_mask_mov_epi32(r2, (mask >> 16) & 0xffff, b);
        r3 = _mm512_mask_mov_epi32(r3, (mask >> 32) & 0xffff, b);
        r4 = _mm512_mask_mov_epi32(r4, (mask >> 48) & 0xffff, b);
    }


    // sort 49 to 63 elements
    void FORCE_INLINE sort4xreg_tail_update(
        const __m512i b,
        const __m512i v1, const __m512i v2, const __m512i v3, const __m512i v4, __mmask16 v4tail,
        __m512i& r1, __m512i& r2, __m512i& r3, __m512i& r4) {

        const uint64_t lt1    = _mm512_cmplt_epi32_mask(v1, b);
        const uint64_t lt2    = _mm512_cmplt_epi32_mask(v2, b);
        const uint64_t lt3    = _mm512_cmplt_epi32_mask(v3, b);
        const uint64_t lt4    = _mm512_mask_cmplt_epi32_mask(v4tail, v4, b);
        const uint64_t lt_cnt = _mm_popcnt_u64(lt1 | (lt2 << 16) | (lt3 << 32) | (lt4 << 48));

        const uint64_t eq1    = _mm512_cmpeq_epi32_mask(v1, b);
        const uint64_t eq2    = _mm512_cmpeq_epi32_mask(v2, b);
        const uint64_t eq3    = _mm512_cmpeq_epi32_mask(v3, b);
        const uint64_t eq4    = _mm512_mask_cmpeq_epi32_mask(v4tail, v4, b);
        const uint64_t eq_cnt = _mm_popcnt_u64(eq1 | (eq2 << 16) | (eq3 << 32) | (eq4 << 48));

        if (eq_cnt == 64) {
            r1 = r2 = r3 = r4 = b;
            return;
        }

        const uint64_t mask   = (uint64_t(1) << (lt_cnt + eq_cnt)) - (uint64_t(1) << lt_cnt);

        r1 = _mm512_mask_mov_epi32(r1, mask & 0xffff, b);
        r2 = _mm512_mask_mov_epi32(r2, (mask >> 16) & 0xffff, b);
        r3 = _mm512_mask_mov_epi32(r3, (mask >> 32) & 0xffff, b);
        r4 = _mm512_mask_mov_epi32(r4, (mask >> 48) & 0xffff, b);
    }


    // ------------------------------------------------------------


    __m512i sort1xreg(const __m512i v) {

        __m512i result = v;
        __m512i index = _mm512_setzero_si512();
        __m512i incr  = _mm512_set1_epi32(1);

    #define STEP(unused) { \
        const __m512i b = _mm512_permutexvar_epi32(index, v); \
        index  = _mm512_add_epi32(index, incr); \
        sort1xreg_update(b, v, result); \
    }

        STEP(0x0); STEP(0x1); STEP(0x2); STEP(0x3);
        STEP(0x4); STEP(0x5); STEP(0x6); STEP(0x7);
        STEP(0x8); STEP(0x9); STEP(0xa); STEP(0xb);
        STEP(0xc); STEP(0xd); STEP(0xe); STEP(0xf);

    #undef STEP

        return result;
    }


    template <unsigned size>
    __m512i sort1xreg_tail(const __m512i v) {

        static_assert(size > 1, "invalid size");
        static_assert(size < 16, "invalid size");

        const __mmask16 tail = (1 << size) - 1;

        __m512i result = v;
        __m512i index = _mm512_setzero_si512();
        __m512i incr  = _mm512_set1_epi32(1);

    #define STEP(step) if (step < size) { \
        const __m512i b = _mm512_permutexvar_epi32(index, v); \
        index  = _mm512_add_epi32(index, incr); \
        sort1xreg_tail_update(b, v, tail, result); \
    }

        STEP(0x0); STEP(0x1); STEP(0x2); STEP(0x3);
        STEP(0x4); STEP(0x5); STEP(0x6); STEP(0x7);
        STEP(0x8); STEP(0x9); STEP(0xa); STEP(0xb);
        STEP(0xc); STEP(0xd); STEP(0xe); STEP(0xf);

    #undef STEP

        return result;
    }


    void sort2xreg(__m512i& v1, __m512i& v2) {

        __m512i r1 = v1;
        __m512i r2 = v2;
        __m512i index;
        __m512i incr  = _mm512_set1_epi32(1);

    #define STEP(input) { \
        const __m512i b = _mm512_permutexvar_epi32(index, input); \
        index  = _mm512_add_epi32(index, incr); \
        sort2xreg_update(b, v1, v2, r1, r2); \
    }

    #define STEP_16x(input) \
        index = _mm512_setzero_si512(); \
        STEP(input); STEP(input); STEP(input); STEP(input); \
        STEP(input); STEP(input); STEP(input); STEP(input); \
        STEP(input); STEP(input); STEP(input); STEP(input); \
        STEP(input); STEP(input); STEP(input); STEP(input);


        STEP_16x(v1);
        STEP_16x(v2);

    #undef STEP_16x
    #undef STEP

        v1 = r1;
        v2 = r2;
    }


    template <unsigned size>
    void sort2xreg_tail(__m512i& v1, __m512i& v2) {

        static_assert(size > 16, "invalid size");
        static_assert(size < 32, "invalid size");

        const __mmask16 tail = (1 << (size - 16)) - 1;

        __m512i r1 = v1;
        __m512i r2 = v2;
        __m512i index;
        __m512i incr  = _mm512_set1_epi32(1);

    #define STEP(step, input) if (step < size) { \
        const __m512i b = _mm512_permutexvar_epi32(index, input); \
        index  = _mm512_add_epi32(index, incr); \
        sort2xreg_tail_update(b, v1, v2, tail, r1, r2); \
    }

    #define STEP_16x(shift, input) \
        index = _mm512_setzero_si512(); \
        STEP(0x0 + shift, input); STEP(0x1 + shift, input); STEP(0x2 + shift, input); STEP(0x3 + shift, input); \
        STEP(0x4 + shift, input); STEP(0x5 + shift, input); STEP(0x6 + shift, input); STEP(0x7 + shift, input); \
        STEP(0x8 + shift, input); STEP(0x9 + shift, input); STEP(0xa + shift, input); STEP(0xb + shift, input); \
        STEP(0xc + shift, input); STEP(0xd + shift, input); STEP(0xe + shift, input); STEP(0xf + shift, input);


        STEP_16x( 0, v1);
        STEP_16x(16, v2);

    #undef STEP_16x
    #undef STEP

        v1 = r1;
        v2 = r2;
    }


    void sort3xreg(__m512i& v1, __m512i& v2, __m512i& v3) {

        __m512i r1 = v1;
        __m512i r2 = v2;
        __m512i r3 = v3;
        __m512i index;
        __m512i incr  = _mm512_set1_epi32(1);

    #define STEP(input) { \
        const __m512i b = _mm512_permutexvar_epi32(index, input); \
        index  = _mm512_add_epi32(index, incr); \
        sort3xreg_update(b, v1, v2, v3, r1, r2, r3); \
    }

    #define STEP_16x(input) \
        index = _mm512_setzero_si512(); \
        STEP(input); STEP(input); STEP(input); STEP(input); \
        STEP(input); STEP(input); STEP(input); STEP(input); \
        STEP(input); STEP(input); STEP(input); STEP(input); \
        STEP(input); STEP(input); STEP(input); STEP(input);


        STEP_16x(v1);
        STEP_16x(v2);
        STEP_16x(v3);

    #undef STEP_16x
    #undef STEP

        v1 = r1;
        v2 = r2;
        v3 = r3;
    }


    template <unsigned size>
    void sort3xreg_tail(__m512i& v1, __m512i& v2, __m512i& v3) {

        static_assert(size > 32, "invalid size");
        static_assert(size < 48, "invalid size");

        const __mmask16 tail = (1 << (size - 32)) - 1;

        __m512i r1 = v1;
        __m512i r2 = v2;
        __m512i r3 = v3;
        __m512i index;
        __m512i incr  = _mm512_set1_epi32(1);

    #define STEP(step, input) if (step < size) { \
        const __m512i b = _mm512_permutexvar_epi32(index, input); \
        index  = _mm512_add_epi32(index, incr); \
        sort3xreg_tail_update(b, v1, v2, v3, tail, r1, r2, r3); \
    }

    #define STEP_16x(shift, input) \
        index = _mm512_setzero_si512(); \
        STEP(0x0 + shift, input); STEP(0x1 + shift, input); STEP(0x2 + shift, input); STEP(0x3 + shift, input); \
        STEP(0x4 + shift, input); STEP(0x5 + shift, input); STEP(0x6 + shift, input); STEP(0x7 + shift, input); \
        STEP(0x8 + shift, input); STEP(0x9 + shift, input); STEP(0xa + shift, input); STEP(0xb + shift, input); \
        STEP(0xc + shift, input); STEP(0xd + shift, input); STEP(0xe + shift, input); STEP(0xf + shift, input);


        STEP_16x( 0, v1);
        STEP_16x(16, v2);
        STEP_16x(32, v3);

    #undef STEP_16x
    #undef STEP

        v1 = r1;
        v2 = r2;
        v3 = r3;
    }


    void sort4xreg(__m512i& v1, __m512i& v2, __m512i& v3, __m512i& v4) {

        __m512i r1 = v1;
        __m512i r2 = v2;
        __m512i r3 = v3;
        __m512i r4 = v4;
        __m512i index;
        __m512i incr  = _mm512_set1_epi32(1);

    #define STEP(input) { \
        const __m512i b = _mm512_permutexvar_epi32(index, input); \
        index  = _mm512_add_epi32(index, incr); \
        sort4xreg_update(b, v1, v2, v3, v4, r1, r2, r3, r4); \
    }

    #define STEP_16x(input) \
        index = _mm512_setzero_si512(); \
        STEP(input); STEP(input); STEP(input); STEP(input); \
        STEP(input); STEP(input); STEP(input); STEP(input); \
        STEP(input); STEP(input); STEP(input); STEP(input); \
        STEP(input); STEP(input); STEP(input); STEP(input);


        STEP_16x(v1);
        STEP_16x(v2);
        STEP_16x(v3);
        STEP_16x(v4);

    #undef STEP_16x
    #undef STEP

        v1 = r1;
        v2 = r2;
        v3 = r3;
        v4 = r4;
    }


    template <unsigned size>
    void sort4xreg_tail(__m512i& v1, __m512i& v2, __m512i& v3, __m512i& v4) {

        static_assert(size > 48, "invalid size");
        static_assert(size < 64, "invalid size");

        const __mmask16 tail = (1 << (size - 48)) - 1;

        __m512i r1 = v1;
        __m512i r2 = v2;
        __m512i r3 = v3;
        __m512i r4 = v4;
        __m512i index;
        __m512i incr  = _mm512_set1_epi32(1);

    #define STEP(step, input) if (step < size) { \
        const __m512i b = _mm512_permutexvar_epi32(index, input); \
        index  = _mm512_add_epi32(index, incr); \
        sort4xreg_tail_update(b, v1, v2, v3, v4, tail, r1, r2, r3, r4); \
    }

    #define STEP_16x(shift, input) \
        index = _mm512_setzero_si512(); \
        STEP(0x0 + shift, input); STEP(0x1 + shift, input); STEP(0x2 + shift, input); STEP(0x3 + shift, input); \
        STEP(0x4 + shift, input); STEP(0x5 + shift, input); STEP(0x6 + shift, input); STEP(0x7 + shift, input); \
        STEP(0x8 + shift, input); STEP(0x9 + shift, input); STEP(0xa + shift, input); STEP(0xb + shift, input); \
        STEP(0xc + shift, input); STEP(0xd + shift, input); STEP(0xe + shift, input); STEP(0xf + shift, input);


        STEP_16x( 0, v1);
        STEP_16x(16, v2);
        STEP_16x(32, v3);
        STEP_16x(48, v4);

    #undef STEP_16x
    #undef STEP

        v1 = r1;
        v2 = r2;
        v3 = r3;
        v4 = r4;
    }


    void sort_inplace(uint32_t* array, size_t size) {
        if (size == 0 && size == 1) {
            return;
        }

        if (size <= 16) {
            __m512i v1 = _mm512_loadu_si512(array);

            switch (size) {
                case 2:  v1 = sort1xreg_tail<2>(v1); break;
                case 3:  v1 = sort1xreg_tail<3>(v1); break;
                case 4:  v1 = sort1xreg_tail<4>(v1); break;
                case 5:  v1 = sort1xreg_tail<5>(v1); break;
                case 6:  v1 = sort1xreg_tail<6>(v1); break;
                case 7:  v1 = sort1xreg_tail<7>(v1); break;
                case 8:  v1 = sort1xreg_tail<8>(v1); break;
                case 9:  v1 = sort1xreg_tail<9>(v1); break;
                case 10: v1 = sort1xreg_tail<10>(v1); break;
                case 11: v1 = sort1xreg_tail<11>(v1); break;
                case 12: v1 = sort1xreg_tail<12>(v1); break;
                case 13: v1 = sort1xreg_tail<13>(v1); break;
                case 14: v1 = sort1xreg_tail<14>(v1); break;
                case 15: v1 = sort1xreg_tail<15>(v1); break;
                case 16: v1 = sort1xreg(v1); break;
            }

            _mm512_storeu_si512(array, v1);
            return;
        }

        if (size <= 32) {
            __m512i v1 = _mm512_loadu_si512(array);
            __m512i v2 = _mm512_loadu_si512(array + 16);

            switch (size) {
                case 17: sort2xreg_tail<17>(v1, v2); break;
                case 18: sort2xreg_tail<18>(v1, v2); break;
                case 19: sort2xreg_tail<19>(v1, v2); break;
                case 20: sort2xreg_tail<20>(v1, v2); break;
                case 21: sort2xreg_tail<21>(v1, v2); break;
                case 22: sort2xreg_tail<22>(v1, v2); break;
                case 23: sort2xreg_tail<23>(v1, v2); break;
                case 24: sort2xreg_tail<24>(v1, v2); break;
                case 25: sort2xreg_tail<25>(v1, v2); break;
                case 26: sort2xreg_tail<26>(v1, v2); break;
                case 27: sort2xreg_tail<27>(v1, v2); break;
                case 28: sort2xreg_tail<28>(v1, v2); break;
                case 29: sort2xreg_tail<29>(v1, v2); break;
                case 30: sort2xreg_tail<30>(v1, v2); break;
                case 31: sort2xreg_tail<31>(v1, v2); break;
                case 32: sort2xreg(v1, v2); break;
            }

            _mm512_storeu_si512(array, v1);
            _mm512_storeu_si512(array + 16, v2);
            return;
        }

        if (size <= 48) {
            __m512i v1 = _mm512_loadu_si512(array);
            __m512i v2 = _mm512_loadu_si512(array + 16);
            __m512i v3 = _mm512_loadu_si512(array + 32);

            switch (size) {
                case 33: sort3xreg_tail<33>(v1, v2, v3); break;
                case 34: sort3xreg_tail<34>(v1, v2, v3); break;
                case 35: sort3xreg_tail<35>(v1, v2, v3); break;
                case 36: sort3xreg_tail<36>(v1, v2, v3); break;
                case 37: sort3xreg_tail<37>(v1, v2, v3); break;
                case 38: sort3xreg_tail<38>(v1, v2, v3); break;
                case 39: sort3xreg_tail<39>(v1, v2, v3); break;
                case 40: sort3xreg_tail<40>(v1, v2, v3); break;
                case 41: sort3xreg_tail<41>(v1, v2, v3); break;
                case 42: sort3xreg_tail<42>(v1, v2, v3); break;
                case 43: sort3xreg_tail<43>(v1, v2, v3); break;
                case 44: sort3xreg_tail<44>(v1, v2, v3); break;
                case 45: sort3xreg_tail<45>(v1, v2, v3); break;
                case 46: sort3xreg_tail<46>(v1, v2, v3); break;
                case 47: sort3xreg_tail<47>(v1, v2, v3); break;
                case 48: sort3xreg(v1, v2, v3); break;
            }

            _mm512_storeu_si512(array, v1);
            _mm512_storeu_si512(array + 16, v2);
            _mm512_storeu_si512(array + 32, v3);
            return;
        }

        if (size <= 64) {
            __m512i v1 = _mm512_loadu_si512(array);
            __m512i v2 = _mm512_loadu_si512(array + 16);
            __m512i v3 = _mm512_loadu_si512(array + 32);
            __m512i v4 = _mm512_loadu_si512(array + 48);

            switch (size) {
                case 49: sort4xreg_tail<49>(v1, v2, v3, v4); break;
                case 50: sort4xreg_tail<50>(v1, v2, v3, v4); break;
                case 51: sort4xreg_tail<51>(v1, v2, v3, v4); break;
                case 52: sort4xreg_tail<52>(v1, v2, v3, v4); break;
                case 53: sort4xreg_tail<53>(v1, v2, v3, v4); break;
                case 54: sort4xreg_tail<54>(v1, v2, v3, v4); break;
                case 55: sort4xreg_tail<55>(v1, v2, v3, v4); break;
                case 56: sort4xreg_tail<56>(v1, v2, v3, v4); break;
                case 57: sort4xreg_tail<57>(v1, v2, v3, v4); break;
                case 58: sort4xreg_tail<58>(v1, v2, v3, v4); break;
                case 59: sort4xreg_tail<59>(v1, v2, v3, v4); break;
                case 60: sort4xreg_tail<60>(v1, v2, v3, v4); break;
                case 61: sort4xreg_tail<61>(v1, v2, v3, v4); break;
                case 62: sort4xreg_tail<62>(v1, v2, v3, v4); break;
                case 63: sort4xreg_tail<63>(v1, v2, v3, v4); break;
                case 64: sort4xreg(v1, v2, v3, v4); break;
            }

            _mm512_storeu_si512(array, v1);
            _mm512_storeu_si512(array + 16, v2);
            _mm512_storeu_si512(array + 32, v3);
            _mm512_storeu_si512(array + 48, v4);
            return;
        }
    }

} // namespace avx512sort
