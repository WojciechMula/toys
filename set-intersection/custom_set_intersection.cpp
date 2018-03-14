#include "vector_utils.h"

template <typename INSERTER>
void custom_set_intersection(const vec& A, const vec& B, INSERTER output) {

    size_t i = 0;
    size_t j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            i += 1;
        } else if (B[j] < A[i]) {
            j += 1;
        } else {
            // A[i] == B[j]
            *output++ = A[i];

            i += 1;
            j += 1;
        }
    }
}
