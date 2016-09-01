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
#   include "encode.avx512.cpp"
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
template <typename ENCODING_FN>
bool test_avx512(ENCODING_FN function) {

    base64::avx512::initialize();

    uint8_t input[64];
    uint8_t output[64];

    for (int index=0; index < 4*12; index++) {
        for (uint8_t value=0; value < 64; value++) {
            
            memset(input, 0, 64);

            const size_t shift  = index * 6;
            const size_t byte   = shift / 8;
            const size_t lshift = shift % 8;

            switch (lshift) {
                case 0:
                    input[byte] = value;
                    break;

                case 1:
                    input[byte] = value << 1;
                    break;

                case 2:
                    input[byte] = value << 2;
                    break;

                case 3:
                    input[byte]     = value << 3;
                    input[byte + 1] = value >> 5;
                    break;

                case 4:
                    input[byte]     = value << 4;
                    input[byte + 1] = value >> 4;
                    break;

                case 5:
                    input[byte]     = value << 5;
                    input[byte + 1] = value >> 3;
                    break;

                case 6:
                    input[byte]     = value << 6;
                    input[byte + 1] = value >> 2;
                    break;

                case 7:
                    input[byte]     = value << 7;
                    input[byte + 1] = value >> 1;
                    break;
            } // switch

            function(input, 4*12, output);

            // verify
            for (int i=0; i < 64; i++) {
                
                if (i != index) {
                    if (output[i] != lookup[0]) {
                        printf("failed for %d at %d: got %d\n", value, index, output[i]);
                        return false;
                    }
                } else {
                    if (output[index] != lookup[value]) {
                        printf("failed for %d at %d: got %d, expected %d\n", value, index, output[index], lookup[value]);
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
    printf("AVX512F (comparison based)... ");
    fflush(stdout);

    if (test_avx512(base64::avx512::encode_with_SWAR)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("AVX512F (comparison based - xor variant)... ");
    fflush(stdout);

    if (test_avx512(base64::avx512::encode_with_SWAR_xor)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("AVX512F (gather)... ");
    fflush(stdout);

    if (test_avx512(base64::avx512::encode_with_gathers)) {
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
