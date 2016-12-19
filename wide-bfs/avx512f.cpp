#include <immintrin.h>

uint64_t avx512f_bfs(const uint64_t* data, size_t n) {

    const size_t chunks = n / 8;
    const size_t tail   = n % 8;

    for (size_t i=0; i < chunks; i++) {
        const __m512i  v = _mm512_loadu_si512((const __m512i*)(data + i * 8));
        const uint32_t m = _mm512_cmpneq_epi64_mask(v, _mm512_setzero_si512());
        if (m) {
            const size_t index = bfs(m) + 8*i;

            auto w= index * 64 +  bfs(data[index]);
            //printf("ret = %lu %x %lu\n", w, m, index);
            return w;
        }
    }

    for (size_t i=0; i < tail; i++) {
        const size_t index = i + 8*chunks;
        if (data[index]) {
            return index * 64 + bfs(data[index]);
        }
    }

    return -1;
}

