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
#if defined(HAVE_AVX512_INSTRUCTIONS)
#   include "encode.avx512.cpp"
#endif

#include "application.cpp"

class Application final: public ApplicationBase {

    double reference_time;

public:
    Application(const CommandLine& c)
        : ApplicationBase(c) {}

    int run() {
        
        reference_time = 0.0;

        #include "functions.cpp"

        if (cmd.empty() || cmd.has("scalar32")) {
            measure("scalar (32 bit)", base64::scalar::encode32);
        }

        if (cmd.empty() || cmd.has("scalar64")) {
            measure("scalar (64 bit)", base64::scalar::encode64);
        }

        if (cmd.empty() || cmd.has("sse")) {
            measure("SSE (lookup: naive)", sse_naive);
        }

        if (cmd.empty() || cmd.has("sse1")) {
            measure("SSE (lookup: other improved)", sse_optimized1);
        }

        if (cmd.empty() || cmd.has("sse2")) {
            measure("SSE (lookup: improved)", sse_optimized2);
        }

        if (cmd.empty() || cmd.has("sse3")) {
            measure("SSE (lookup: pshufb-based)", sse_pshufb);
        }

        if (cmd.empty() || cmd.has("sse3/improved")) {
            measure("SSE (lookup: pshufb improved)", sse_pshufb_improved);
        }

        if (cmd.empty() || cmd.has("sse1/unrolled")) {
            measure("SSE (lookup: other improved, unrolled)", sse_optimized1_unrolled);
        }

        if (cmd.empty() || cmd.has("sse2/unrolled")) {
            measure("SSE (lookup: improved, unrolled)", sse_optimized2_unrolled);
        }

        if (cmd.empty() || cmd.has("sse2/unrolled2")) {
            measure("SSE (lookup: pshufb-based, unrolled)", sse_pshufb_unrolled);
        }

        if (cmd.empty() || cmd.has("sse3/improved/unrolled")) {
            measure("SSE (lookup: pshufb improved unrolled)", sse_pshufb_improved_unrolled);
        }

        if (cmd.empty() || cmd.has("sse2/fully_unrolled")) {
            measure("SSE (fully unrolled improved lookup)", base64::sse::encode_full_unrolled);
        }

#if defined(HAVE_BMI2_INSTRUCTIONS)
        if (cmd.empty() || cmd.has("bmi1")) {
            measure("SSE & BMI2 (lookup: naive)", sse_bmi2_naive);
        }

        if (cmd.empty() || cmd.has("bmi2")) {
            measure("SSE & BMI2 (lookup: improved)", sse_bmi2_optimized);
        }
#endif

#if defined(HAVE_AVX2_INSTRUCTIONS)
        if (cmd.empty() || cmd.has("avx2")) {
            measure("AVX2 (lookup: improved)", avx2_optimized2);
        }

        if (cmd.empty() || cmd.has("avx2/unrolled")) {
            measure("AVX2 (lookup: improved, unrolled)", avx2_optimized2_unrolled);
        }

        if (cmd.empty() || cmd.has("avx2/pshufb")) {
            measure("AVX2 (lookup: pshufb-based)", avx2_pshufb);
        }

        if (cmd.empty() || cmd.has("avx2/pshufb/unrolled")) {
            measure("AVX2 (lookup: pshufb-based, unrolled)", avx2_pshufb_unrolled);
        }

        if (cmd.empty() || cmd.has("avx2/pshufb/improved")) {
            measure("AVX2 (lookup: pshufb improved)", avx2_pshufb_improved);
        }

        if (cmd.empty() || cmd.has("avx2/pshufb/improved/unrolled")) {
            measure("AVX2 (lookup: pshufb unrolled improved)", avx2_pshufb_improved_unrolled);
        }
#endif

#if defined(HAVE_AVX512_INSTRUCTIONS)
        if (cmd.empty() || cmd.has("avx512")) {
            measure("AVX512", avx512_swar);
        }

        if (cmd.empty() || cmd.has("avx512/xor")) {
            measure("AVX512 (with xor)", avx512_swar);
        }

        if (cmd.empty() || cmd.has("avx512/gather")) {
            measure("AVX512 (gather)", avx512_gathers);
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

        printf("%0.5f", time);

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

