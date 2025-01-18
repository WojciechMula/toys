#include <cstdlib>
#include <immintrin.h>

__m512i avx512_sort_values[16];

void push_heap_avx512(int32_t* start, size_t size) {
    ssize_t index = size - 1;
    if ((index >= 32767) && (index < 65535)) { // we're handling insertions only at level #15

        // 1. Build indices values
        uint32_t tmp[16];
        tmp[0]  = index;
        tmp[15] = 0;
        for (int i=1; i < 15; i++) {
            const ssize_t parent = (index - 1)/2;
            tmp[i] = parent;
            index = parent;
        }

        const __m512i indices = _mm512_load_si512(tmp);

        // 2. Load values from path between the new element and the root.
        const __m512i values = _mm512_i32gather_epi32(indices, start, sizeof(uint32_t));

        // 3. Check if the heap propery is violated.
        const __m512i new_value = _mm512_permutexvar_epi32(_mm512_setzero_si512(), values);
        const __mmask16 any_parent_less = _mm512_cmpgt_epu32_mask(values, new_value);

        // 4. Elements on the path be should sorted, we need to locate where to insert the new value.
        const int new_index = __builtin_ctz(any_parent_less) - 1;
        if (new_index > 0) {
            const __m512i sorted = _mm512_permutexvar_epi32(avx512_sort_values[new_index], values);
            _mm512_i32scatter_epi32(start, indices, sorted, sizeof(uint32_t));
        }
    } else {
        std::push_heap(start, start + size);
        abort();
    }
}

void push_heap_avx512_setup() {
    avx512_sort_values[0]  = _mm512_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    avx512_sort_values[1]  = _mm512_setr_epi32(1, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    avx512_sort_values[2]  = _mm512_setr_epi32(1, 2, 0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    avx512_sort_values[3]  = _mm512_setr_epi32(1, 2, 3, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    avx512_sort_values[4]  = _mm512_setr_epi32(1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    avx512_sort_values[5]  = _mm512_setr_epi32(1, 2, 3, 4, 5, 0, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    avx512_sort_values[6]  = _mm512_setr_epi32(1, 2, 3, 4, 5, 6, 0, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    avx512_sort_values[7]  = _mm512_setr_epi32(1, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 12, 13, 14, 15);
    avx512_sort_values[8]  = _mm512_setr_epi32(1, 2, 3, 4, 5, 6, 7, 8, 0, 9, 10, 11, 12, 13, 14, 15);
    avx512_sort_values[9]  = _mm512_setr_epi32(1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 14, 15);
    avx512_sort_values[10] = _mm512_setr_epi32(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 11, 12, 13, 14, 15);
    avx512_sort_values[11] = _mm512_setr_epi32(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 12, 13, 14, 15);
    avx512_sort_values[12] = _mm512_setr_epi32(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 13, 14, 15);
    avx512_sort_values[13] = _mm512_setr_epi32(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0, 14, 15);
    avx512_sort_values[14] = _mm512_setr_epi32(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 15);
    avx512_sort_values[15] = _mm512_setr_epi32(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0);
}
