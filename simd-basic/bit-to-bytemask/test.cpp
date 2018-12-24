#include <immintrin.h>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cassert>

#include "config.h"

#ifdef HAVE_SSE2
#   include "bit_to_byte.sse2.cpp"
#endif
#ifdef HAVE_AVX512F
#   include "bit_to_byte.avx512f.cpp"
#endif
#ifdef HAVE_AVX512BW
#   include "bit_to_byte.avx512bw.cpp"
#endif


#include "testbase.h"

#if defined(HAVE_SSE2) || defined(HAVE_SSSE3)
#   define TEST_SSE
class TestSSE : public TestBase<TestSSE, 16> {
public:
    void run() {
        test("SSE", bit_to_byte_sse2);
    }

public:
    template <typename FUNCTION>
    void execute(FUNCTION fun) {

        const __m128i in   = _mm_loadu_si128((const __m128i*)input_vec);
        const __m128i mask = _mm_loadu_si128((const __m128i*)input_mask);
        const __m128i ret  = fun(in, mask);
        _mm_storeu_si128((__m128i*)output, ret);
    }
};
#endif


#if defined(HAVE_AVX512F) || defined(HAVE_AVX512BW)
#   define TEST_AVX512
class TestAVX512 : public TestBase<TestAVX512, 64> {
public:
    void run() {
        test("AVX512F", bit_to_byte_avx512f);
#if defined(HAVE_AVX512BW)
        test("AVX512BW", bit_to_byte_avx512bw);
#endif
    }

public:
    template <typename FUNCTION>
    void execute(FUNCTION fun) {

        const __m512i in   = _mm512_loadu_si512((const __m512i*)input_vec);
        const __m512i mask = _mm512_loadu_si512((const __m512i*)input_mask);
        const __m512i ret  = fun(in, mask);
        _mm512_storeu_si512((__m512i*)output, ret);
    }
};
#endif


int main() {

#if defined(TEST_SSE)
    {
        TestSSE test;
        test.run();
    }
#endif
#if defined(TEST_AVX512)
    {
        TestAVX512 test;
        test.run();
    }
#endif

    return 0;
}
