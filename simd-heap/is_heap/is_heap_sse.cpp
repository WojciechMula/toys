#include <immintrin.h>

bool is_heap_sse_epi32(const int32_t* begin, const int32_t* end) {
    const ssize_t k = 16/4; // words in a vector

    if (end - begin < 2 * k) {
        return std::is_heap(begin, end);
    }

    const int32_t* parent = begin;
    const int32_t* current = begin + 1;

    while (end - current >= 2 * k) {
        // 1. load parents
        // tmp = [p3|p2|p1|p0]
        const __m128i tmp = _mm_loadu_si128((const __m128i*)parent);
        // p0  = [p1|p1|p0|p0]
        const __m128i p0  = _mm_unpacklo_epi32(tmp, tmp);
        // p1  = [p3|p3|p2|p2]
        const __m128i p1  = _mm_unpackhi_epi32(tmp, tmp);

        // 2. load children
        const __m128i children0 = _mm_loadu_si128((const __m128i*)(current + 0));
        const __m128i children1 = _mm_loadu_si128((const __m128i*)(current + k));

        // 3. compare parents with their children
        const __m128i lt0 = _mm_cmplt_epi32(p0, children0);
        const __m128i lt1 = _mm_cmplt_epi32(p1, children1);
        const __m128i t0 = _mm_or_si128(lt0, lt1);

        if (_mm_movemask_epi8(t0))
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
