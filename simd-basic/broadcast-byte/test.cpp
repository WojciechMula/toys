#include <immintrin.h>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cassert>

#include "config.h"

#ifdef HAVE_SSE2
#   include "broadcast.sse2.cpp"
#endif
#ifdef HAVE_SSSE3
#   include "broadcast.ssse3.cpp"
#endif
#ifdef HAVE_AVX2
#   include "broadcast.avx2.cpp"
#endif
#ifdef HAVE_AVX512F
#   include "broadcast.avx512f.cpp"
#endif
#ifdef HAVE_AVX512BW
#   include "broadcast.avx512bw.cpp"
#endif


#include "testbase.h"

#if defined(HAVE_SSE2) || defined(HAVE_SSSE3)
#   define TEST_SSE
class TestSSE : public TestBase<TestSSE, 16> {
public:
    void run() {
        test("SSE", broadcast_sse2);
#if defined(HAVE_SSSE3)
        test("SSSE3", broadcast_ssse3);
#endif
    }

public:
    template <typename FUNCTION>
    void execute(FUNCTION fun) {

        const __m128i ret = fun(byte);
        _mm_storeu_si128((__m128i*)output, ret);
    }
};
#endif


#if defined(HAVE_AVX2)
#   define TEST_AVX2
class TestAVX2 : public TestBase<TestAVX2, 32> {
public:
    void run() {
        test("AVX2 [1]", broadcast_avx2__version1);
        test("AVX2 [2]", broadcast_avx2__version2);
    }

public:
    template <typename FUNCTION>
    void execute(FUNCTION fun) {

        const __m256i ret = fun(byte);
        _mm256_storeu_si256((__m256i*)output, ret);
    }
};
#endif


#if defined(HAVE_AVX512F) || defined(HAVE_AVX512BW)
#   define TEST_AVX512
class TestAVX512 : public TestBase<TestAVX512, 64> {
public:
    void run() {
        test("AVX512F [1]", broadcast_avx512f__version_1);
        test("AVX512F [2]", broadcast_avx512f__version_2);
#if defined(HAVE_AVX512BW)
        test("AVX512BW [1]", broadcast_avx512bw__version_1);
        test("AVX512BW [2]", broadcast_avx512bw__version_2);
#endif
    }

public:
    template <typename FUNCTION>
    void execute(FUNCTION fun) {

        const __m512i ret = fun(byte);
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
