#include <cstdio>
#include <cstring>

#include "decode.exception.cpp"
#include "decode.scalar.cpp"

template <typename FN>
bool test_scalar(FN fn) {

    uint8_t input[4];
    union {
        uint8_t output_bytes[4];
        uint32_t output_dword;
    };

    for (unsigned i=0; i < 4; i++) {

        for (unsigned j=0; j < 4; j++) {
            input[j] = base64::lookup[0];
        }

        for (unsigned k=0; k < 64; k++) {
            input[i] = base64::lookup[k];

            fn(input, 4, output_bytes);

            const uint32_t mask = uint32_t(0x3f) << (i*6);
            if (output_dword & ~mask) {
                printf("modifed unexpected bits: %08x (mask=%08x)\n", output_dword, mask);
                return false;
            }
        }
    }

    return true;
}


int test() {

    printf("lookup...");
    fflush(stdout);
    if (test_scalar(base64::scalar::decode_lookup1)) {
        puts("OK");
    } else {
        return 1;
    }

    printf("four lookups...");
    fflush(stdout);
    if (test_scalar(base64::scalar::decode_lookup2)) {
        puts("OK");
    } else {
        return 1;
    }

#if defined(HAVE_BMI2)
    printf("lookup (BMI2)...");
    fflush(stdout);
    if (test_scalar(base64::scalar::decode_lookup1_bmi2)) {
        puts("OK");
    } else {
        return 1;
    }
#endif

    return 0;
}


int main() {

    base64::scalar::prepare_lookup();
    base64::scalar::prepare_lookup32();

    try {
        return test();
    } catch (base64::invalid_input& e) {
        
        printf("invalid input byte %c (%02x)\n", e.byte, e.byte);
        return 2;
    }
}
