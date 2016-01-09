#include <cstdio>
#include <cstring>

#include "lookup.reference.cpp"
#include "lookup.sse.cpp"

const char* lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

bool test_reference() {

    for (unsigned i=0; i < 64; i++) {
        
        const auto ref = reference::lookup(i);
        if (ref != lookup[i]) {

            printf("failed at %d (%d != %d)\n", i, ref, lookup[i]);
            return false;
        }
    }

    return true;
}


bool test_sse() {

    uint8_t input[16];
    uint8_t output[16];

    for (unsigned byte=0; byte < 16; byte++) {
        
        for (unsigned j=0; j < 16; j++) {
            input[j] = 0;
        }

        for (unsigned i=0; i < 64; i++) {

            input[byte] = i;

            __m128i in  = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input));
            __m128i out = base64::sse::lookup(in);

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

    printf("reference branchless implementation... ");
    fflush(stdout);
    if (test_reference()) {
        puts("OK");
    } else {
        return 1;
    }

    printf("SIMD implementation... ");
    fflush(stdout);
    if (test_sse()) {
        puts("OK");
    } else {
        return 1;
    }

    return 0;
}


int main() {

    return test();
}
