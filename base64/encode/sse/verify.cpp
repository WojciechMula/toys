#include <cstdio>
#include <cstring>

#include "config.h"
#include "lookup.reference.cpp"
#include "lookup.sse.cpp"
#if defined(HAVE_AVX2_INSTRUCTIONS)
#   include "lookup.avx2.cpp"
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

    printf("SSE implementation of optimized algorithm... ");
    fflush(stdout);
    if (test_sse(base64::sse::lookup_version1)) {
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
#endif

    return 0;
}


int main() {

    return test();
}
