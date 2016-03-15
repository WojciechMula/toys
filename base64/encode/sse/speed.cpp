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

    double reference_time;

public:
    Application(const CommandLine& c)
        : ApplicationBase(c) {}

    int run() {
        
        reference_time = 0.0;

        if (cmd.empty() || cmd.has("scalar32")) {
            measure("scalar32", base64::scalar::encode32);
        }

        if (cmd.empty() || cmd.has("scalar64")) {
            measure("scalar64", base64::scalar::encode64);
        }

        auto sse_naive = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode(base64::sse::lookup_naive, input, bytes, output);
        };

        auto sse_optimized1 = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode(base64::sse::lookup_version1, input, bytes, output);
        };

        auto sse_optimized2 = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode(base64::sse::lookup_version2, input, bytes, output);
        };

        auto sse_optimized1_unrolled = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode_unrolled(base64::sse::lookup_version1, input, bytes, output);
        };

        auto sse_optimized2_unrolled = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode_unrolled(base64::sse::lookup_version2, input, bytes, output);
        };

        if (cmd.empty() || cmd.has("sse")) {
            measure("SSE (naive)", sse_naive);
        }

        if (cmd.empty() || cmd.has("sse1")) {
            measure("SSE (optimized v1)", sse_optimized1);
        }

        if (cmd.empty() || cmd.has("sse2")) {
            measure("SSE (optimized v2)", sse_optimized2);
        }

        if (cmd.empty() || cmd.has("sse1/unrolled")) {
            measure("SSE (optimized v1 unrolled)", sse_optimized1_unrolled);
        }

        if (cmd.empty() || cmd.has("sse2/unrolled")) {
            measure("SSE (optimized v2 unrolled)", sse_optimized2_unrolled);
        }

        if (cmd.empty() || cmd.has("sse2/fully_unrolled")) {
            measure("SSE (optimized v2 fully unrolled)", base64::sse::encode_full_unrolled);
        }

#if defined(HAVE_BMI2_INSTRUCTIONS)
        auto sse_bmi2_naive = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode_bmi2(base64::sse::lookup_naive, input, bytes, output);
        };

        auto sse_bmi2_optimized = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode_bmi2(base64::sse::lookup_version1, input, bytes, output);
        };

        if (cmd.empty() || cmd.has("bmi1")) {
            measure("SSE & BMI2 (naive)", sse_bmi2_naive);
        }

        if (cmd.empty() || cmd.has("bmi2")) {
            measure("SSE & BMI2 (optimized)", sse_bmi2_optimized);
        }
#endif

#if defined(HAVE_AVX2_INSTRUCTIONS)
        auto avx2_optimized2 = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::avx2::encode(base64::avx2::lookup_version2, input, bytes, output);
        };

        auto avx2_optimized2_unrolled = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::avx2::encode_unrolled(base64::avx2::lookup_version2, input, bytes, output);
        };

        if (cmd.empty() || cmd.has("avx2")) {
            measure("AVX2 (optimized v2)", avx2_optimized2);
        }

        if (cmd.empty() || cmd.has("avx2/unrolled")) {
            measure("AVX2 (optimized v2 unrolled)", avx2_optimized2_unrolled);
        }
#endif

        return 0;
    }

    template<typename T>
    double measure(const char* name, T callback) {

        initialize();

        printf("%-40s... ", name);
        fflush(stdout);

        unsigned n = iterations;
        double time = -1;
        while (n-- > 0) {

            const auto t1 = get_time();
            callback(input.get(), get_input_size(), output.get());
            const auto t2 = get_time();

            const double t = (t2 - t1)/1000000.0;
            if (time < 0) {
                time = t;
            } else {
                time = std::min(time, t);
            }
        }

        printf("%0.3f", time);

        if (reference_time == 0.0) {
            reference_time = time;
        } else {
            printf(" (speedup %0.2f)", reference_time/time);
        }

        putchar('\n');

        return time;
    }
};


int main(int argc, char* argv[]) {

    CommandLine cmd(argc, argv);
    Application app(cmd);

    return app.run();
}

