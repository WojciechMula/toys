#include "vector_utils.h"

template <typename INSERTER>
void binsearch_set_intersection(const vec& A, const vec& B, INSERTER output) {

    auto it = B.begin();

    for (const auto& a: A) {
        it = std::lower_bound(it, B.end(), a);
        if (it == B.end()) {
            // since there are no values greater or equal the current,
            // there also won't be any for subsequent value (all greater than current)
            return;
        }

        if (*it == a) {
            output = a;
            ++it;
        }
    }
}

