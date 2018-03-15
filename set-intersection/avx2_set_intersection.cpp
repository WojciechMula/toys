#include <immintrin.h>

#include "vector_utils.h"

template <typename INSERTER>
void avx2_set_intersection(const vec& A, const vec& B, INSERTER output) {

    __m256i a_rep;
    __m256i b;

    size_t ai = 0;
    size_t bi = 0;

    a_rep = _mm256_set1_epi32(A[ai]);
    b     = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(&B[bi]));

    while (ai < A.size() && bi < B.size()) {
        const __m256i lt = _mm256_cmpgt_epi32(a_rep, b);
        const uint32_t mask = _mm256_movemask_ps((__m256)lt);
        if (mask == 0xff) {
            // all elements in b are smaller, fetch the next chunk from B
            bi += 8;
            b = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(&B[bi]));
        } else {
            const auto first_ge_idx = __builtin_ctz(~mask);
            if (B[bi + first_ge_idx] == A[ai]) {
                output = A[ai];
            }

            // fetch the next value from A
            ai += 1;
            a_rep = _mm256_set1_epi32(A[ai]);
        }
    }
}

