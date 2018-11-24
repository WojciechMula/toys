#include <immintrin.h>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <stdexcept>

#include "config.h"

#ifdef HAVE_SSE2
#   include "extract.sse2.cpp"
#endif
#ifdef HAVE_SSE41
#   include "extract.sse41.cpp"
#endif
#ifdef HAVE_AVX2
#   include "extract.avx2.cpp"
#endif
#ifdef HAVE_AVX512F
#   include "extract.avx512f.cpp"
#endif


#include "testbase.h"

#if defined(HAVE_SSE2) || defined(HAVE_SSE41)
#   define TEST_SSE
class TestSSE : public TestBase<TestSSE, 16> {
public:
    void run() {
        test("SSE", extract_sse2);
#if defined(HAVE_SSE41)
        test("SSE4.1", extract_sse41);
#endif
    }

public:
    template <typename FUNCTION>
    void execute(FUNCTION fun) {

        const __m128i in  = _mm_loadu_si128((const __m128i*)input);
        output = fun(in, index);
    }
};
#endif


#if defined(HAVE_AVX2)
#   define TEST_AVX2
class TestAVX2 : public TestBase<TestAVX2, 32> {
public:
    void run() {
        test("AVX2", extract_avx2);
    }

public:
    template <typename FUNCTION>
    void execute(FUNCTION fun) {

        const __m256i in  = _mm256_loadu_si256((const __m256i*)input);
        output = fun(in, index);
    }
};
#endif


#if defined(HAVE_AVX512F)
#   define TEST_AVX512
class TestAVX512 : public TestBase<TestAVX512, 64> {
public:
    void run() {
        test("AVX512F", extract_avx512f);
    }

public:
    template <typename FUNCTION>
    void execute(FUNCTION fun) {

        const __m512i in  = _mm512_loadu_si512((const __m512i*)input);
        output = fun(in, index);
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
