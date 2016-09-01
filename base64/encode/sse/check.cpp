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
#   include "lookup.avx512.cpp"
#   include "encode.avx512.cpp"
#endif

#if defined(HAVE_AVX512BW_INSTRUCTIONS)
#   include "encode.avx512bw.cpp"
#endif

#include "application.cpp"

class Application final: public ApplicationBase {

public:
    Application(const CommandLine& c)
        : ApplicationBase(c) {}

    int run() {

        #include "functions.cpp"

        uint32_t valid;
        valid = check("scalar32", base64::scalar::encode32, 0);

        check("scalar64", base64::scalar::encode64, valid);
        check("SSE (naive)", sse_naive, valid);
        check("SSE (optimized v1)", sse_optimized1, valid);
        check("SSE (optimized v2)", sse_optimized2, valid);
        check("SSE (pshuf-based)",  sse_pshufb, valid);
        check("SSE (pshuf improved)",  sse_pshufb_improved, valid);
        check("SSE (optimized v1 unrolled)", sse_optimized1_unrolled, valid);
        check("SSE (optimized v2 unrolled)", sse_optimized2_unrolled, valid);
        check("SSE (pshufb-based unrolled)", sse_pshufb_unrolled, valid);
        check("SSE (pshuf improved unrolled)",  sse_pshufb_improved_unrolled, valid);
        check("SSE (optimized v2 fully unrolled)", base64::sse::encode_full_unrolled, valid);
#if defined(HAVE_BMI2_INSTRUCTIONS)
        check("SSE & BMI2 (naive)", sse_bmi2_naive, valid);
        check("SSE & BMI2 (optimized)", sse_bmi2_optimized, valid);
#endif
#if defined(HAVE_AVX2_INSTRUCTIONS)
        check("AVX2 (optimized v2)",                avx2_optimized2, valid);
        check("AVX2 (optimized v2 unrolled)",       avx2_optimized2_unrolled, valid);
        check("AVX2 (pshufb-based)",                avx2_pshufb, valid);
        check("AVX2 (pshufb-based unrolled)",       avx2_pshufb_unrolled, valid);
        check("AVX2 (pshufb improved)",             avx2_pshufb_improved, valid);
        check("AVX2 (pshufb improved unrolled)",    avx2_pshufb_improved_unrolled, valid);
#endif
#if defined(HAVE_AVX512BW_INSTRUCTIONS)
        check("AVX512BW (improved splitting)", avx512bw, valid);
        check("AVX512BW (faster splitting)", avx512bw_faster, valid);
#endif
#if defined(HAVE_AVX512_INSTRUCTIONS)
        check("AVX512 (incremental arithmetic)", avx512_swar_arith, valid);
        check("AVX512 (incremental logic)", avx512_swar_logic, valid);
        check("AVX512 (gather)", avx512_gathers, valid);
#endif

        return 0;
    }

private:
    template<typename T>
    uint32_t check(const char* name, T callback, uint32_t valid) {

        initialize();

        printf("%-40s... ", name);
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

#if defined(HAVE_AVX512_INSTRUCTIONS)
    base64::avx512::initialize();
#endif

    CommandLine cmd(argc, argv);
    Application app(cmd);

    return app.run();
}

