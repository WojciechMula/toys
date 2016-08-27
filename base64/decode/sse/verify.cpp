#include <cstdio>
#include <cstring>

#include "config.h"
#include "../../bmi2.cpp"

#include "decode.common.cpp"
#include "decode.scalar.cpp"
#include "decoders.sse.cpp"
#if defined(HAVE_AVX2_INSTRUCTIONS)
#   include "decoders.avx2.cpp"
#endif

#if defined(HAVE_AVX512BW_INSTRUCTIONS)
#   include "decoders.avx512bw.cpp"
#endif

#include "function_registry.cpp"


class Test {

    uint8_t input[64];
    uint8_t output[64];
    unsigned bytes;
    unsigned out_size;
    unsigned current;

    uint8_t decode_table[256]; // ASCII -> raw value or 0xff if a value is not valid

public:
    Test(unsigned in_size, unsigned out_size)
        : bytes(in_size)
        , out_size(out_size) {

        for (unsigned i=0; i < 256; i++) {
            decode_table[i] = 0xff;
        }

        for (unsigned i=0; i < 64; i++) {
            uint8_t idx = base64::lookup[i];
            decode_table[idx] = i;
        }
    }

public:
    template <typename FN>
    bool run(FN fn) {

        for (current=0; current < bytes; current++) {

            clear_input();

            for (unsigned k=0; k < 256; k++) {
                input[current] = k;

                if (decode_table[k] != 0xff) {

                    try {
                        fn(input, bytes, output);
                    } catch (base64::invalid_input& e) {
                        printf("unexpected error: invalid input byte %c (%02x)\n", e.byte, e.byte);
                        return false;
                    }

                    const bool ok = validate_output(decode_table[k]);
                    if (!ok) {
                        return false;
                    }
                } else {
                    try {
                        fn(input, bytes, output);

                        printf("function should return error for invalid input %02x\n", k);
                        dump_input();
                        return false;
                    } catch (base64::invalid_input& e) {

                        if (e.offset != current) {
                            printf("exception field 'offset' is %lu, should be %u\n", e.offset, current);
                            return false;
                        }

                        if (e.byte != k) {
                            printf("exception field 'byte' is %u, should be %u\n", e.byte, k);
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }

private:
    void clear_input() {
        for (unsigned i=0; i < bytes; i++) {
            input[i] = base64::lookup[0];
        }
    }

    bool validate_output(unsigned expected_current) {

        for (unsigned i=0; i < bytes; i++) {

            const uint8_t val = get_6bit_word(i);
            if (i == current) {
                if (val != expected_current) {
                    printf("6-bit field #%d has value %d, expected %d\n", i, val, expected_current);
                    dump_input();
                    dump_output();
                    return false;
                }
            } else {
                if (val != 0) {
                    printf("6-bit field #%d has value %d, expected to be cleared\n", i, val);
                    dump_input();
                    dump_output();
                    return false;
                }
            }
        }

        return true;
    }

    void dump_output() {

        for (int i=out_size - 1; i >= 0; i--) {
            printf("%02x", output[i]);
        }

        putchar('\n');
    }

    void dump_input() {

        for (int i=bytes - 1; i >= 0; i--) {
            printf("%02x", input[i]);
        }

        putchar('\n');
    }

    uint8_t get_6bit_word(unsigned i) {

        const unsigned pos   = i * 6;
        const unsigned idx   = pos / 8;
        const unsigned shift = pos % 8;

        if (shift == 0) {
            return output[idx] & 0x3f;
        } else {
            const uint8_t b0 = output[idx];
            const uint8_t b1 = output[idx + 1];

            return ((b0 >> shift) | (b1 << (8 - shift))) & 0x3f;
        }
    }
};


int test() {

    FunctionRegistry names;
    auto show_name = [names](const char* name) {
        printf("%*s ... ", -names.get_width(), names[name]);
        fflush(stdout);
    };

    show_name("scalar");
    {   Test test(4, 3);

        if (test.run(base64::scalar::decode_lookup1)) {
            puts("OK");
        } else {
            return 1;
        }
    }

    show_name("improved");
    fflush(stdout);
    {   Test test(4, 3);

        if (test.run(base64::scalar::decode_lookup2)) {
            puts("OK");
        } else {
            return 1;
        }
    }

#if defined(HAVE_BMI2_INSTRUCTIONS)
    show_name("scalar_bmi2");
    {   Test test(4, 3);

        if (test.run(base64::scalar::decode_lookup1_bmi2)) {
            puts("OK");
        } else {
            return 1;
        }
     }
#endif // HAVE_BMI2_INSTRUCTIONS

#define RUN_TEMPLATE1(input_size, output_size, name, decode_fn, lookup_fn) { \
        show_name(name); \
        auto function = [](const uint8_t* input, size_t size, uint8_t* output) { \
            return decode_fn(lookup_fn, input, size, output); \
        }; \
        Test test(input_size, output_size); \
        \
        if (test.run(function)) { \
            puts("OK"); \
        } else { \
            return 1; \
        } \
    }

#define RUN_TEMPLATE2(input_size, output_size, name, decode_fn, lookup_fn, pack_fn) { \
        show_name(name); \
        auto function = [](const uint8_t* input, size_t size, uint8_t* output) { \
            return decode_fn(lookup_fn, pack_fn, input, size, output); \
        }; \
        Test test(input_size, output_size); \
        \
        if (test.run(function)) { \
            puts("OK"); \
        } else { \
            return 1; \
        } \
    }

#define RUN_SSE_TEMPLATE2(name, decode_fn, lookup_fn, pack_fn) \
    RUN_TEMPLATE2(16, 12, name, decode_fn, lookup_fn, pack_fn)

#define RUN_AVX2_TEMPLATE2(name, decode_fn, lookup_fn, pack_fn) \
    RUN_TEMPLATE2(32, 24, name, decode_fn, lookup_fn, pack_fn)

#define RUN_SSE_TEMPLATE1(name, decode_fn, lookup_fn) \
    RUN_TEMPLATE1(16, 12, name, decode_fn, lookup_fn)

#define RUN_AVX2_TEMPLATE1(name, decode_fn, lookup_fn) \
    RUN_TEMPLATE1(32, 24, name, decode_fn, lookup_fn)

    {
    using namespace base64::sse;

    RUN_SSE_TEMPLATE2("sse/base/naive",                  decode, lookup_base,        pack_naive);
    RUN_SSE_TEMPLATE2("sse/blend/naive",                 decode, lookup_byte_blend,  pack_naive);
    RUN_SSE_TEMPLATE2("sse/incremental/naive",           decode, lookup_incremental, pack_naive);
    RUN_SSE_TEMPLATE2("sse/pshufb/naive",                decode, lookup_pshufb,      pack_naive);

    RUN_SSE_TEMPLATE2("sse/base/improved",               decode, lookup_base,        pack_improved);
    RUN_SSE_TEMPLATE2("sse/blend/improved",              decode, lookup_byte_blend,  pack_improved);
    RUN_SSE_TEMPLATE2("sse/incremental/improved",        decode, lookup_incremental, pack_improved);
    RUN_SSE_TEMPLATE2("sse/pshufb/improved",             decode, lookup_pshufb, pack_improved);

    RUN_SSE_TEMPLATE2("sse/base/madd_improved",          decode, lookup_base,        pack_madd_improved);
    RUN_SSE_TEMPLATE2("sse/blend/madd_improved",         decode, lookup_byte_blend,  pack_madd_improved);
    RUN_SSE_TEMPLATE2("sse/incremental/madd_improved",   decode, lookup_incremental, pack_madd_improved);
    RUN_SSE_TEMPLATE2("sse/pshufb/madd_improved",        decode, lookup_pshufb, pack_madd_improved);

    RUN_SSE_TEMPLATE2("sse/base/madd",                   decode, lookup_base,        pack_madd);
    RUN_SSE_TEMPLATE2("sse/blend/madd",                  decode, lookup_byte_blend,  pack_madd);
    RUN_SSE_TEMPLATE2("sse/incremental/madd",            decode, lookup_incremental, pack_madd);
    RUN_SSE_TEMPLATE2("sse/pshufb/madd",                 decode, lookup_pshufb, pack_madd);
    }

#if defined(HAVE_BMI2_INSTRUCTIONS)
    {
    using namespace base64::sse;

    RUN_SSE_TEMPLATE1("sse_bmi2/base",          decode_bmi2, lookup_base);
    RUN_SSE_TEMPLATE1("sse_bmi2/blend",         decode_bmi2, lookup_byte_blend);
    RUN_SSE_TEMPLATE1("sse_bmi2/incremental",   decode_bmi2, lookup_incremental);
    }
#endif

#if defined(HAVE_AVX2_INSTRUCTIONS)
    {
    using namespace base64::avx2;

    RUN_AVX2_TEMPLATE2("avx2/base/naive",            decode, lookup_base,        pack_naive);
    RUN_AVX2_TEMPLATE2("avx2/blend/naive",           decode, lookup_byte_blend,  pack_naive);
    RUN_AVX2_TEMPLATE2("avx2/pshufb/naive",          decode, lookup_pshufb,      pack_naive);

    RUN_AVX2_TEMPLATE2("avx2/base/improved",         decode, lookup_base,        pack_improved);
    RUN_AVX2_TEMPLATE2("avx2/blend/improved",        decode, lookup_byte_blend,  pack_improved);
    RUN_AVX2_TEMPLATE2("avx2/pshufb/improved",       decode, lookup_pshufb,      pack_improved);

    RUN_AVX2_TEMPLATE2("avx2/base/madd_improved",    decode, lookup_base,        pack_madd_improved);
    RUN_AVX2_TEMPLATE2("avx2/blend/madd_improved",   decode, lookup_byte_blend,  pack_madd_improved);
    RUN_AVX2_TEMPLATE2("avx2/pshufb/madd_improved",  decode, lookup_pshufb,      pack_madd_improved);

    RUN_AVX2_TEMPLATE2("avx2/base/madd",             decode, lookup_base,        pack_madd);
    RUN_AVX2_TEMPLATE2("avx2/blend/madd",            decode, lookup_byte_blend,  pack_madd);
    RUN_AVX2_TEMPLATE2("avx2/pshufb/madd",           decode, lookup_pshufb,      pack_madd);
    }

    #if defined(HAVE_BMI2_INSTRUCTIONS)
    {
    using namespace base64::avx2;

    RUN_AVX2_TEMPLATE1("avx2_bmi2/base",  decode_bmi2, lookup_base);
    RUN_AVX2_TEMPLATE1("avx2_bmi2/blend", decode_bmi2, lookup_byte_blend);
    }
    #endif // HAVE_BMI2_INSTRUCTIONS

#endif // HAVE_AVX2_INSTRUCTIONS

#if defined(HAVE_AVX512BW_INSTRUCTIONS)
    {
    using namespace base64::avx512bw;
    RUN_TEMPLATE2(64, 48, "avx512", decode, lookup, pack_madd)
    }
#endif // HAVE_AVX512BW_INSTRUCTIONS
    return 0;
}


int main() {

    base64::scalar::prepare_lookup();
    base64::scalar::prepare_lookup32();
#if defined(HAVE_AVX512BW_INSTRUCTIONS)
    base64::avx512bw::prepare_lookups();
#endif // HAVE_AVX512BW_INSTRUCTIONS


    try {
        return test();
    } catch (base64::invalid_input& e) {

        printf("invalid input byte %c (%02x)\n", e.byte, e.byte);
        return 2;
    }
}
