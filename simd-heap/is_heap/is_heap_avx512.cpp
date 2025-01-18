#include <immintrin.h>

bool is_heap_avx512_epi32(const int32_t* begin, const int32_t* end) {
    const ssize_t k = 64/4; // words in a vector

    if (end - begin < 2 * k) {
        return std::is_heap(begin, end);
    }

    const int32_t* parent = begin;
    const int32_t* current = begin + 1;

    const __m512i lo = _mm512_setr_epi32(0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7);
    const __m512i hi = _mm512_setr_epi32(8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15);

    while (end - current >= 2 * k) {
        // 1. load parents
        // tmp = [p3|p2|p1|p0]
        const __m512i tmp = _mm512_loadu_si512((const __m512i*)parent);
        // p0  = [p1|p1|p0|p0]
        const __m512i p0  = _mm512_permutexvar_epi32(lo, tmp);
        // p1  = [p3|p3|p2|p2]                               
        const __m512i p1  = _mm512_permutexvar_epi32(hi, tmp);

        // 2. load children
        const __m512i children0 = _mm512_loadu_si512((const __m512i*)(current + 0));
        const __m512i children1 = _mm512_loadu_si512((const __m512i*)(current + k));

        // 3. compare parents with their children
        const __mmask16 lt0 = _mm512_cmpgt_epi32_mask(children0, p0);
        const __mmask16 lt1 = _mm512_cmpgt_epi32_mask(children1, p1);

        if (!_kortest_mask16_u8(lt0, lt1, nullptr)) {
            return false;
        }

        if (current + 2*k > end)
            break;

        parent  += k;
        current += 2*k;
    }

    for (ssize_t i = current - begin; i < end - begin; i++) {
        if (begin[(i - 1) / 2] < begin[i]) {
            return false;
        }
    }

    return true;
}
