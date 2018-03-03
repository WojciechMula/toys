#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <chrono>

#include <cstdint>
#include <cassert>

#include <immintrin.h>

using Clock = std::chrono::steady_clock;

auto elapsed(const Clock::time_point& t1, const Clock::time_point& t2) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}


using vec = std::vector<int32_t>;


template <typename SOURCE>
vec create(size_t size, SOURCE source) {

    std::set<int32_t> tmp;
    for (size_t i=0; i < size; i++) {
        tmp.insert(source());
    }

    while (tmp.size() < size) {
        tmp.insert(source());
    }

    vec result(tmp.begin(), tmp.end());
    assert(result.size() == size);

    return result;
}

vec create_sorted(size_t size) {
    return create(size, []{return rand();});
}

vec sample_sorted(const vec& input, size_t size) {

    return create(size, [&input]{
        const size_t index = rand() % input.size();
        return input[index];
    });
}

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

constexpr int STD = 0;
constexpr int SSE = 1;
constexpr int BINARY = 2;

template <int version = STD>
void test(const char* info, const vec& a, const vec& b, int k) {
    vec result;
    volatile int32_t ref = 0;

    printf("%s [a.size = %lu, b.size = %lu, %d iterations] ", info, a.size(), b.size(), k);
    fflush(stdout);

    Clock::rep best_time = 0;
    int tmp = k;
    while (tmp-- > 0) {
        result.clear();
        const auto t1 = Clock::now();
        if constexpr (version == STD) {
            std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
        } else if constexpr (version == SSE) {
            sse_set_intersection(a, b, std::back_inserter(result));
        } else if constexpr (version == BINARY) {
            binsearch_set_intersection(a, b, std::back_inserter(result));
        }
        const auto t2 = Clock::now();
        best_time += elapsed(t1, t2);

        ref += std::accumulate(result.begin(), result.end(), int32_t(0));
    }

    printf("%lu us (%d)\n", best_time, ref);
}


int main() {

    auto vec2 = create_sorted(1024*1024);
    auto vec1 = sample_sorted(vec2, 1024);

    test<STD>("std", vec1, vec2, 1000);
    test<SSE>("SSE", vec1, vec2, 1000);
    test<BINARY>("binsearch", vec1, vec2, 1000);
}
