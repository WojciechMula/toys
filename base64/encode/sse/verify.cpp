#include <cstdio>
#include <cstring>

#include "lookup.reference.cpp"
#include "lookup.sse.cpp"

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

    return 0;
}


int main() {

    return test();
}
