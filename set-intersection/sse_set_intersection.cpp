#include <immintrin.h>

#include "vector_utils.h"

template <typename INSERTER>
void sse_set_intersection(const vec& A, const vec& B, INSERTER output) {

    __m128i a_rep;
    __m128i b;

    size_t ai = 0;
    size_t bi = 0;

    a_rep = _mm_set1_epi32(A[ai]);
    b     = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&B[bi]));

    while (ai < A.size() && bi < B.size()) {
        const __m128i lt = _mm_cmplt_epi32(b, a_rep);
        const uint16_t mask = _mm_movemask_epi8(lt);
        if (mask == 0xffff) {
            // all elements in b are smaller, fetch the next chunk from B
            bi += 4;
            b = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&B[bi]));
        } else {
            // there might be element equal to A[ai]
            // a simple linear search, as there're only 4 elements to search in
            for (size_t i = 0; i < 4; i++) {
                if (B[bi + i] == A[ai]) {
                    output = A[ai];
                    break;
                }
            }

            // fetch the next value from A
            ai += 1;
            a_rep = _mm_set1_epi32(A[ai]);
        }
    }
}

