#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <immintrin.h>

#include "scalar.cpp"

// common parameters for templates
constexpr bool no_early_exit = false;
constexpr bool early_exit = true;

#ifdef HAVE_AVX2
#   include "pext_avx2.cpp"
#   include "pdep_avx2.cpp"
#endif

#ifdef HAVE_AVX512
#   include "pext_avx512.cpp"
#   include "pdep_avx512.cpp"
#endif

using signature_t = void(*)(const uint32_t*, const uint32_t*, uint32_t*, size_t);
using function_names_t = std::map<signature_t, std::string>;

function_names_t function_names() {
    function_names_t names;

    names[scalar_pext_u32] = "pext scalar";
    names[scalar_pdep_u32] = "pdep scalar";

    #ifdef HAVE_AVX2
        names[avx2_pext_u32] = "pext AVX2";
        names[avx2_pext_u32_6bits] = "pext AVX2 (6 bit)";
        names[avx2_pext_u32_8bits] = "pext AVX2 (8 bit)";
        names[avx2_pext_u32_16bits] = "pext AVX2 (16 bit)";
        names[avx2_pext_u32_24bits] = "pext AVX2 (24 bit)";
        names[avx2_pext_u32_ee] = "pext AVX2 (early exit)";
        names[avx2_pext_u32_6bits_ee] = "pext AVX2 (6 bit, early exit)";
        names[avx2_pext_u32_8bits_ee] = "pext AVX2 (8 bit, early exit)";
        names[avx2_pext_u32_16bits_ee] = "pext AVX2 (16 bit, early exit)";
        names[avx2_pext_u32_24bits_ee] = "pext AVX2 (24 bit, early exit)";

        names[avx2_pdep_u32] = "pdep AVX2";
        names[avx2_pdep_u32_6bits] = "pdep AVX2 (6 bit)";
        names[avx2_pdep_u32_8bits] = "pdep AVX2 (8 bit)";
        names[avx2_pdep_u32_16bits] = "pdep AVX2 (16 bit)";
        names[avx2_pdep_u32_24bits] = "pdep AVX2 (24 bit)";
        names[avx2_pdep_u32_ee] = "pdep AVX2 (early exit)";
        names[avx2_pdep_u32_6bits_ee] = "pdep AVX2 (6 bit, early exit)";
        names[avx2_pdep_u32_8bits_ee] = "pdep AVX2 (8 bit, early exit)";
        names[avx2_pdep_u32_16bits_ee] = "pdep AVX2 (16 bit, early exit)";
        names[avx2_pdep_u32_24bits_ee] = "pdep AVX2 (24 bit, early exit)";
    #endif

    #ifdef HAVE_AVX512
        names[avx512_pext_u32] = "pext AVX512";
        names[avx512_pext_u32_6bits] = "pext AVX512 (6 bit)";
        names[avx512_pext_u32_8bits] = "pext AVX512 (8 bit)";
        names[avx512_pext_u32_16bits] = "pext AVX512 (16 bit)";
        names[avx512_pext_u32_24bits] = "pext AVX512 (24 bit)";
        names[avx512_pext_u32_ee] = "pext AVX512 (early exit)";
        names[avx512_pext_u32_6bits_ee] = "pext AVX512 (6 bit, early exit)";
        names[avx512_pext_u32_8bits_ee] = "pext AVX512 (8 bit, early exit)";
        names[avx512_pext_u32_16bits_ee] = "pext AVX512 (16 bit, early exit)";
        names[avx512_pext_u32_24bits_ee] = "pext AVX512 (24 bit, early exit)";

        names[avx512_pdep_u32] = "pdep AVX512";
        names[avx512_pdep_u32_6bits] = "pdep AVX512 (6 bit)";
        names[avx512_pdep_u32_8bits] = "pdep AVX512 (8 bit)";
        names[avx512_pdep_u32_16bits] = "pdep AVX512 (16 bit)";
        names[avx512_pdep_u32_24bits] = "pdep AVX512 (24 bit)";
        names[avx512_pdep_u32_ee] = "pdep AVX512 (early exit)";
        names[avx512_pdep_u32_6bits_ee] = "pdep AVX512 (6 bit, early exit)";
        names[avx512_pdep_u32_8bits_ee] = "pdep AVX512 (8 bit, early exit)";
        names[avx512_pdep_u32_16bits_ee] = "pdep AVX512 (16 bit, early exit)";
        names[avx512_pdep_u32_24bits_ee] = "pdep AVX512 (24 bit, early exit)";

        names[avx512_pdep_u32_ver2] = "pdep AVX512 v2";
        names[avx512_pdep_u32_ver2_6bits] = "pdep AVX512 v2 (6 bit)";
        names[avx512_pdep_u32_ver2_8bits] = "pdep AVX512 v2 (8 bit)";
        names[avx512_pdep_u32_ver2_16bits] = "pdep AVX512 v2 (16 bit)";
        names[avx512_pdep_u32_ver2_24bits] = "pdep AVX512 v2 (24 bit)";
        names[avx512_pdep_u32_ver2_ee] = "pdep AVX512 v2 (early exit)";
        names[avx512_pdep_u32_ver2_6bits_ee] = "pdep AVX512 v2 (6 bit, early exit)";
        names[avx512_pdep_u32_ver2_8bits_ee] = "pdep AVX512 v2 (8 bit, early exit)";
        names[avx512_pdep_u32_ver2_16bits_ee] = "pdep AVX512 v2 (16 bit, early exit)";
        names[avx512_pdep_u32_ver2_24bits_ee] = "pdep AVX512 v2 (24 bit, early exit)";
    #endif

    return names;
}

size_t longest_function_label(const function_names_t& names) {
    size_t max = 0;
    for (const auto& item: names) {
        const size_t len = item.second.size();
        if (len > max) {
            max = len;
        }
    }

    return max;
}
