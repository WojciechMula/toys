#include <immintrin.h>

bool is_heap_avx2_epi32(const int32_t* begin, const int32_t* end) {
    const ssize_t k = 32/4; // words in a vector

    if (end - begin < 2 * k) {
        return std::is_heap(begin, end);
    }

    const int32_t* parent = begin;
    const int32_t* current = begin + 1;

    const __m256i lo = _mm256_setr_epi32(0, 0, 1, 1, 2, 2, 3, 3);
    const __m256i hi = _mm256_setr_epi32(4, 4, 5, 5, 6, 6, 7, 7);

    while (end - current >= 2 * k) {
        // 1. load parents
        // tmp = [p3|p2|p1|p0]
        const __m256i tmp = _mm256_loadu_si256((const __m256i*)parent);
        // p0  = [p1|p1|p0|p0]
        const __m256i p0  = _mm256_permutevar8x32_epi32(tmp, lo);
        // p1  = [p3|p3|p2|p2]                               
        const __m256i p1  = _mm256_permutevar8x32_epi32(tmp, hi);

        // 2. load children
        const __m256i children0 = _mm256_loadu_si256((const __m256i*)(current + 0));
        const __m256i children1 = _mm256_loadu_si256((const __m256i*)(current + k));

        // 3. compare parents with their children
        const __m256i lt0 = _mm256_cmpgt_epi32(children0, p0);
        const __m256i lt1 = _mm256_cmpgt_epi32(children1, p1);
        const __m256i t0 = _mm256_or_si256(lt0, lt1);

        if (_mm256_movemask_epi8(t0))
            return false;

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
