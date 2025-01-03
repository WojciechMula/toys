#include <cstdio>
#include <random>
#include <limits>
#include "benchmark.h"

#include "impl.cpp"
#include "benchmark.cpp.inl"

int main() {
    std::random_device random_device;
    std::mt19937 random_engine{random_device()};
    std::uniform_int_distribution<uint32_t> random_u32(0, std::numeric_limits<uint32_t>::max());

    for (size_t i=0; i < SIZE; i++) {
        data[i] = i;
        mask[i] = rand_non_zero(random_engine, random_u32);
    }

    auto names = function_names();
    global_label_width = (int)longest_function_label(names);

    const size_t repeat = 100;

    puts("testing any mask");
    BENCH(scalar_pext_u32);
    #ifdef HAVE_AVX2
        BENCH(avx2_pext_u32);
        BENCH(avx2_pext_u32_ee);
    #endif
    #ifdef HAVE_AVX512
        BENCH(avx512_pext_u32);
        BENCH(avx512_pext_u32_ee);
    #endif

    {
        constexpr int bits = 6;
        printf("testing mask having no more than %d bits set\n", bits);
        for (size_t i=0; i < SIZE; i++) {
            mask[i] = rand(random_engine, bits);
        }

        BENCH(scalar_pext_u32);
        #ifdef HAVE_AVX2
            BENCH(avx2_pext_u32_6bits);
            BENCH(avx2_pext_u32_6bits_ee);
        #endif
        #ifdef HAVE_AVX512
            BENCH(avx512_pext_u32_6bits);
            BENCH(avx512_pext_u32_6bits_ee);
        #endif
    }

    {
        constexpr int bits = 8;
        printf("testing mask having no more than %d bits set\n", bits);
        for (size_t i=0; i < SIZE; i++) {
            mask[i] = rand(random_engine, bits);
        }

        BENCH(scalar_pext_u32);
        #ifdef HAVE_AVX2
            BENCH(avx2_pext_u32_8bits);
            BENCH(avx2_pext_u32_8bits_ee);
        #endif
        #ifdef HAVE_AVX512
            BENCH(avx512_pext_u32_8bits);
            BENCH(avx512_pext_u32_8bits_ee);
        #endif
    }

    {
        constexpr int bits = 16;
        printf("testing mask having no more than %d bits set\n", bits);
        for (size_t i=0; i < SIZE; i++) {
            mask[i] = rand(random_engine, bits);
        }

        BENCH(scalar_pext_u32);
        #ifdef HAVE_AVX2
            BENCH(avx2_pext_u32_16bits);
            BENCH(avx2_pext_u32_16bits_ee);
        #endif
        #ifdef HAVE_AVX512
            BENCH(avx512_pext_u32_16bits);
            BENCH(avx512_pext_u32_16bits_ee);
        #endif
    }

    {
        constexpr int bits = 24;
        printf("testing mask having no more than %d bits set\n", bits);
        for (size_t i=0; i < SIZE; i++) {
            mask[i] = rand(random_engine, bits);
        }

        BENCH(scalar_pext_u32);
        #ifdef HAVE_AVX2
            BENCH(avx2_pext_u32_24bits);
            BENCH(avx2_pext_u32_24bits_ee);
        #endif
        #ifdef HAVE_AVX512
            BENCH(avx512_pext_u32_24bits);
            BENCH(avx512_pext_u32_24bits_ee);
        #endif
    }
}
