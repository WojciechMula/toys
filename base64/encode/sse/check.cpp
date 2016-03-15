#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <memory>

#include "config.h"
#include "../../gettime.cpp"
#include "../../cmdline.cpp"
#include "../../fnv32.cpp"

#include "encode.scalar.cpp"
#include "lookup.sse.cpp"
#include "encode.sse.cpp"
#if defined(HAVE_AVX2_INSTRUCTIONS)
#   include "lookup.avx2.cpp"
#   include "encode.avx2.cpp"
#endif

#include "application.cpp"

class Application final: public ApplicationBase {

public:
    Application(const CommandLine& c)
        : ApplicationBase(c) {}

    int run() {

        auto sse_naive = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode(base64::sse::lookup_naive, input, bytes, output);
        };

        auto sse_optimized1 = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode(base64::sse::lookup_version1, input, bytes, output);
        };

        auto sse_optimized2 = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode(base64::sse::lookup_version2, input, bytes, output);
        };

#if defined(HAVE_BMI2_INSTRUCTIONS)
        auto sse_bmi2_naive = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode_bmi2(base64::sse::lookup_naive, input, bytes, output);
        };

        auto sse_bmi2_optimized = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode_bmi2(base64::sse::lookup_version1, input, bytes, output);
        };
#endif

#if defined(HAVE_AVX2_INSTRUCTIONS)
        auto avx2_optimized2 = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::avx2::encode(base64::avx2::lookup_version2, input, bytes, output);
        };

        auto avx2_optimized2_unrolled = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::avx2::encode_unrolled(base64::avx2::lookup_version2, input, bytes, output);
        };
#endif

        uint32_t valid;
        valid = check("scalar32", base64::scalar::encode32, 0);
        check("scalar64", base64::scalar::encode64, valid);
        check("SSE (naive)", sse_naive, valid);
        check("SSE (optimized v1)", sse_optimized1, valid);
        check("SSE (optimized v2)", sse_optimized2, valid);
#if defined(HAVE_BMI2_INSTRUCTIONS)
        check("SSE & BMI2 (naive)", sse_bmi2_naive, valid);
        check("SSE & BMI2 (optimized)", sse_bmi2_optimized, valid);
#endif
#if defined(HAVE_AVX2_INSTRUCTIONS)
        check("AVX2 (optimized v2)", avx2_optimized2, valid);
        check("AVX2 (optimized v2 unrolled)", avx2_optimized2_unrolled, valid);
#endif

        return 0;
    }

private:
    template<typename T>
    uint32_t check(const char* name, T callback, uint32_t valid) {

        initialize();

        printf("%20s... ", name);
        fflush(stdout);

        clear_output();
        callback(input.get(), get_input_size(), output.get());

        const uint32_t result = FNV32::get(reinterpret_cast<const char*>(output.get()), get_output_size() - 16);

        if (valid != 0) {
            printf("%08x %s\n", result, (valid != result) ? "!!!ERROR!!!" : "OK");
        } else {
            printf("%08x\n", result);
        }
        return result;
    }
};


int main(int argc, char* argv[]) {

    CommandLine cmd(argc, argv);
    Application app(cmd);

    return app.run();
}

