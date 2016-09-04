#include <cstdio>
#include <cstring>
#include <cassert>

#include "config.h"
#include "lookup.reference.cpp"
#include "lookup.sse.cpp"
#if defined(HAVE_AVX2_INSTRUCTIONS)
#   include "lookup.avx2.cpp"
#endif
#if defined(HAVE_AVX512_INSTRUCTIONS)
#   include "lookup.avx512.cpp"
#   include "unpack.avx512.cpp"
#endif

const char* lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

template<typename LOOKUP_FN>
bool test_scalar(LOOKUP_FN fn) {

    for (unsigned i=0; i < 64; i++) {

        const auto ref = fn(i);
        if (ref != lookup[i]) {

            printf("failed at %d (%d != %d)\n", i, ref, lookup[i]);
            return false;
        }
    }

    return true;
}


template<typename LOOKUP_FN>
bool test_sse(LOOKUP_FN fn) {

    uint8_t input[16];
    uint8_t output[16];

    for (unsigned byte=0; byte < 16; byte++) {

        for (unsigned j=0; j < 16; j++) {
            input[j] = 0;
        }

        for (unsigned i=0; i < 64; i++) {

            input[byte] = i;

            __m128i in  = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input));
            __m128i out = fn(in);

            _mm_storeu_si128(reinterpret_cast<__m128i*>(output), out);

            for (unsigned j=0; j < 16; j++) {

                if (j == byte) {
                    if (output[j] != lookup[i]) {
                        printf("failed at %d, byte %d - wrong result\n", i, byte);
                        return false;
                    }
                } else {
                    if (output[j] != lookup[0]) {
                        printf("failed at %d, byte %d - spoiled random byte\n", i, byte);
                        return false;
                    }
                }
            }
        }
    }

    return true;
}


#if defined(HAVE_AVX2_INSTRUCTIONS)
template<typename LOOKUP_FN>
bool test_avx2(LOOKUP_FN fn) {

    uint8_t input[32];
    uint8_t output[32];

    for (unsigned byte=0; byte < 32; byte++) {

        for (unsigned j=0; j < 32; j++) {
            input[j] = 0;
        }

        for (unsigned i=0; i < 64; i++) {

            input[byte] = i;

            __m256i in  = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input));
            __m256i out = fn(in);

            _mm256_storeu_si256(reinterpret_cast<__m256i*>(output), out);

            for (unsigned j=0; j < 32; j++) {

                if (j == byte) {
                    if (output[j] != lookup[i]) {
                        printf("failed at %d, byte %d - wrong result\n", i, byte);
                        printf("%02x != %02x (%c != %c)\n", output[j], lookup[i], output[j], lookup[i]);
                        return false;
                    }
                } else {
                    if (output[j] != lookup[0]) {
                        printf("failed at %d, byte %d - spoiled random byte\n", i, byte);
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
#endif


#if defined(HAVE_AVX512_INSTRUCTIONS)
template<typename LOOKUP_FN>
bool test_avx512(LOOKUP_FN fn) {

    base64::avx512::initialize();

    uint8_t input[64];
    uint8_t output[64];

    for (unsigned byte=0; byte < 64; byte++) {

        for (unsigned j=0; j < 64; j++) {
            input[j] = 0;
        }

        for (unsigned i=0; i < 64; i++) {

            input[byte] = i;

            __m512i in  = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(input));
            __m512i out = fn(in);

            _mm512_storeu_si512(reinterpret_cast<__m512i*>(output), out);

            for (unsigned j=0; j < 64; j++) {

                if (j == byte) {
                    if (output[j] != lookup[i]) {
                        printf("failed at %d, byte %d - wrong result\n", i, byte);
                        printf("%02x != %02x (%c != %c)\n", output[j], lookup[i], output[j], lookup[i]);
                        return false;
                    }
                } else {
                    if (output[j] != lookup[0]) {
                        printf("failed at %d, byte %d - spoiled random byte\n", i, byte);
                        return false;
                    }
                }
            }
        }
    }

    return true;
}


template<typename UNPACK_FN>
bool test_avx512_unpack(UNPACK_FN unpack) {

    base64::avx512::initialize();

    uint8_t input[64];
    uint8_t output[64];
    uint64_t* first_qword = reinterpret_cast<uint64_t*>(input);

    for (unsigned byte=0; byte < 4; byte++) {

        for (unsigned j=0; j < 64; j++) {
            input[j] = 0;
        }

        for (int i=0; i < 64; i++) {

            *first_qword = uint64_t(i) << (byte * 6);

            __m512i in  = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(input));
            __m512i out = unpack(in);

            _mm512_storeu_si512(reinterpret_cast<__m512i*>(output), out);

            for (unsigned j=0; j < 4; j++) {

                if (j == byte) {
                    if (output[j] != i) {
                        printf("failed at %d, byte %d - wrong result\n", i, byte);
                        return false;
                    }
                } else {
                    if (output[j] != 0) {
                        printf("failed at %d, byte %d - spoiled random byte\n", i, byte);
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
#endif


int test() {

    printf("reference branchless (optimized v2)... ");
    fflush(stdout);
    if (test_scalar(reference::lookup_version2)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("reference branchless (naive)... ");
    fflush(stdout);
    if (test_scalar(reference::lookup_naive)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("reference branchless (optimized)... ");
    fflush(stdout);
    if (test_scalar(reference::lookup_version1)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("SSE implementation of naive algorithm... ");
    fflush(stdout);
    if (test_sse(base64::sse::lookup_naive)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("SSE implementation of optimized algorithm (ver 1)... ");
    fflush(stdout);
    if (test_sse(base64::sse::lookup_version1)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("SSE implementation of optimized algorithm (ver 2)... ");
    fflush(stdout);
    if (test_sse(base64::sse::lookup_version2)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("SSE pshufb-based algorithm... ");
    fflush(stdout);
    if (test_sse(base64::sse::lookup_pshufb)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("SSE pshufb improved algorithm... ");
    fflush(stdout);
    if (test_sse(base64::sse::lookup_pshufb_improved)) {
        puts("OK");
    } else {
        return 1;
    }

#if defined(HAVE_AVX2_INSTRUCTIONS)
    printf("AVX2 implementation of optimized algorithm... ");
    fflush(stdout);
    if (test_avx2(base64::avx2::lookup_version2)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("AVX2 implementation of pshufb-based algorithm... ");
    fflush(stdout);
    if (test_avx2(base64::avx2::lookup_pshufb)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("AVX2 implementation of pshufb improved algorithm... ");
    fflush(stdout);
    if (test_avx2(base64::avx2::lookup_pshufb_improved)) {
        puts("OK");
    } else {
        return 1;
    }
#endif

#if defined(HAVE_AVX512_INSTRUCTIONS)
    printf("AVX512F lookup:\n");
    printf("AVX512F (incremental arithmetic)... ");
    fflush(stdout);

    if (test_avx512(base64::avx512::lookup_incremental_arithmetic)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("AVX512F (incremental logic)... ");
    fflush(stdout);

    if (test_avx512(base64::avx512::lookup_incremental_logic)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("AVX512F unpack:\n");
    printf("AVX512F (default)... ");
    fflush(stdout);

    if (test_avx512_unpack(base64::avx512::unpack_default)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("AVX512F (improved)... ");
    fflush(stdout);

    if (test_avx512_unpack(base64::avx512::unpack_improved)) {
        puts("OK");
    } else {
        return 1;
    }
#endif
    return 0;
}


int main() {

    return test();
}
