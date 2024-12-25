#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <immintrin.h>

#include "scalar.cpp"

#ifdef HAVE_AVX2
#   include "avx2.cpp"
#endif

#ifdef HAVE_AVX512
#   include "avx512.cpp"
#endif

using signature_t = void(*)(const uint16_t*, const uint16_t*, uint16_t*, size_t);
using function_names_t = std::map<signature_t, std::string>;

function_names_t function_names() {
    function_names_t names;

    names[scalar_div_u16] = "scalar";

    #ifdef HAVE_AVX2
        names[avx2_div_u16_cvtt] = "AVX2 (cvtt)";
        names[avx2_div_u16_cvtt_ver2] = "AVX2 (cvtt, v2)";
        names[avx2_div_u16_cvtt_x4] = "AVX2 (cvtt, v2, x4)";
        names[avx2_div_u16_cvtt_x2] = "AVX2 (cvtt, v2, x2)";
        names[avx2_div_u16_rcp] = "AVX2 (rcp)";
    #endif

    #ifdef HAVE_AVX512
        names[avx512_div_u16_cvtt] = "AVX512 (cvtt)";
        names[avx512_div_u16_cvtt_x4] = "AVX512 (cvtt, x4)";
        names[avx512_div_u16_cvtt_x2] = "AVX512 (cvtt, x2)";
    #endif

    return names;
}
