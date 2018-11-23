#include <immintrin.h>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "config.h"

#ifdef HAVE_SSE2
#   include "reverse.sse2.cpp"
#endif
#ifdef HAVE_SSSE3
#   include "reverse.ssse3.cpp"
#endif
#ifdef HAVE_AVX2
#   include "reverse.avx2.cpp"
#endif
#ifdef HAVE_AVX512F
#   include "reverse.avx512f.cpp"
#endif
#ifdef HAVE_AVX512BW
#   include "reverse.avx512bw.cpp"
#endif
#ifdef HAVE_AVX512VBMI
#   include "reverse.avx512vbmi.cpp"
#endif


#include "testbase.h"

#if defined(HAVE_SSE2) || defined(HAVE_SSSE3)
#   define TEST_SSE
class TestSSE : public TestBase<TestSSE, 16> {
public:
    void run() {
        test("SSE", reverse_sse2);
#if defined(HAVE_SSSE3)
        test("SSSE3", reverse_ssse3);
#endif
    }

public:
    template <typename FUNCTION>
    void execute(FUNCTION fun) {

        const __m128i in  = _mm_loadu_si128((const __m128i*)input);
        const __m128i ret = fun(in);

        _mm_storeu_si128((__m128i*)output, ret);
    }
};
#endif


#if defined(HAVE_AVX2)
#   define TEST_AVX2
class TestAVX2 : public TestBase<TestAVX2, 32> {
public:
    void run() {
        test("AVX2 [1]", reverse_avx2__version_1);
        test("AVX2 [2]", reverse_avx2__version_2);
    }

public:
    template <typename FUNCTION>
    void execute(FUNCTION fun) {

        const __m256i in  = _mm256_loadu_si256((const __m256i*)input);
        const __m256i ret = fun(in);

        _mm256_storeu_si256((__m256i*)output, ret);
    }
};
#endif


#if defined(HAVE_AVX512F) || defined(HAVE_AVX512BW) || defined(HAVE_AVX512VBMI)
#   define TEST_AVX512
class TestAVX512 : public TestBase<TestAVX512, 64> {
public:
    void run() {
        test("AVX512F", reverse_avx512f);
#if defined(HAVE_AVX512BW)
        test("AVX512BW", reverse_avx512bw);
#endif
#if defined(HAVE_AVX512VBMI)
        test("AVX512VBMI", reverse_avx512vbmi);
#endif
    }

public:
    template <typename FUNCTION>
    void execute(FUNCTION fun) {

        const __m512i in  = _mm512_loadu_si512((const __m512i*)input);
        const __m512i ret = fun(in);

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
#if defined(TEST_AVX2)
    {
        TestAVX2 test;
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
