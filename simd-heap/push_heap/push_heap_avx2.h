#include <cstdlib>
#include <immintrin.h>

__m256i avx2_sort_values[8];

#ifndef HAVE_AVX512
// AVX2 does not provide scatter, so we emulate it in a most obvious way
void _mm256_i32scatter_epi32(int32_t* base, __m256i vec_indices, __m256i vec_values, size_t /*scale*/) {
    uint32_t indices[8];
    uint32_t values[8];

    _mm256_storeu_si256((__m256i*)indices, vec_indices);
    _mm256_storeu_si256((__m256i*)values, vec_values);

    for (int i=0; i < 8; i++) {
        const size_t idx = indices[i];
        base[idx] = values[i];
    }
}
#endif

void push_heap_avx2(int32_t* start, size_t size) {
    if (size <= 255) {
        std::push_heap(start, start + size);
        return;
    }

    size_t index = size - 1;
    while (index >= 256) {
        // 1. Construct indices from the current element to parent nodes 7 levels up
        ssize_t parent = 0;

        uint32_t tmp[8];
        tmp[0] = index;
        for (int i=1; i < 8; i++) {
            parent = (index - 1)/2;
            tmp[i] = parent;
            index = parent;
        }

        const __m256i indices = _mm256_load_si256((const __m256i*)tmp);

        // 2. Load values from the selected path
        const __m256i values = _mm256_i32gather_epi32((const int*)start, indices, sizeof(uint32_t));

        // 3. Broadcast 0th element from the vector
        const __m256i last_value = _mm256_permutevar8x32_epi32(values, _mm256_setzero_si256());

        // 3. Check if the heap property is violated.
        const __m256i mask = _mm256_cmpgt_epi32(values, last_value);

        const uint8_t any_parent_less = _mm256_movemask_ps(_mm256_castsi256_ps(mask));
        if (any_parent_less == 0) {
            const __m256i sorted = _mm256_permutevar8x32_epi32(values, avx2_sort_values[7]);
            _mm256_i32scatter_epi32(start, indices, sorted, sizeof(uint32_t));
            index = tmp[7];
            continue;
        }

        // 4. Elements on the path be should sorted, we need to locate where to insert a new value.
        const int new_index = __builtin_ctz(any_parent_less) - 1;
        if (new_index > 0) {
            const __m256i sorted = _mm256_permutevar8x32_epi32(values, avx2_sort_values[new_index]);
            _mm256_i32scatter_epi32(start, indices, sorted, sizeof(uint32_t));
        }
    }

    std::push_heap(start, start + index + 1);
}

void push_heap_avx2_setup() {
    avx2_sort_values[0]  = _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7);
    avx2_sort_values[1]  = _mm256_setr_epi32(1, 0, 2, 3, 4, 5, 6, 7);
    avx2_sort_values[2]  = _mm256_setr_epi32(1, 2, 0, 3, 4, 5, 6, 7);
    avx2_sort_values[3]  = _mm256_setr_epi32(1, 2, 3, 0, 4, 5, 6, 7);
    avx2_sort_values[4]  = _mm256_setr_epi32(1, 2, 3, 4, 0, 5, 6, 7);
    avx2_sort_values[5]  = _mm256_setr_epi32(1, 2, 3, 4, 5, 0, 6, 7);
    avx2_sort_values[6]  = _mm256_setr_epi32(1, 2, 3, 4, 5, 6, 0, 7);
    avx2_sort_values[7]  = _mm256_setr_epi32(1, 2, 3, 4, 5, 6, 7, 0);
}
