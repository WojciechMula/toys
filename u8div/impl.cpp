#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <immintrin.h>

#include "scalar.cpp"

#ifdef HAVE_SSE
#   include "sse.cpp"
#   include "sse_long_div.cpp"
#endif

#ifdef HAVE_AVX2
#   include "avx2.cpp"
#   include "avx2_long_div.cpp"
#endif

#ifdef HAVE_AVX512
#   include "avx512.cpp"
#   include "avx512_long_div.cpp"
#endif

using signature_t = void(*)(const uint8_t*, const uint8_t*, uint8_t*, size_t);
using function_names_t = std::map<signature_t, std::string>;

function_names_t function_names() {
    function_names_t names;

    names[scalar_div_u8] = "scalar";
    names[scalar_div_u8_unrolled4] = "scalar (unrolled x 4)";
    names[scalar_long_div_u8] = "scalar (long div)";
    names[scalar_long_div_u8_autovect] = "scalar (long div, autovect)";

    #ifdef HAVE_SSE
        names[sse_div_u8] = "SSE";
        names[sse_div_u8_no_rounding] = "SSE (no rounding)";
        names[sse_div_u8_cvtt] = "SSE (cvtt)";
        names[sse_div_u8_rcp] = "SSE (rcp)";
        names[sse_long_div_u8] = "SSE long div";
    #endif

    #ifdef HAVE_AVX2
        names[avx2_div_u8] = "AVX2";
        names[avx2_div_u8_cvtt] = "AVX2 (cvtt)";
        names[avx2_div_u8_rcp] = "AVX2 (rcp)";
        names[avx2_div_u8_rcp_4x] = "AVX2 (4x rcp)";
        names[avx2_long_div_u8] = "AVX2 long div";
    #endif

    #ifdef HAVE_AVX512
        names[avx512_div_u8_cvtt] = "AVX512 (cvtt)";
        names[avx512_div_u8_rcp] = "AVX512 (rcp)";
        names[avx2_div_u8_rcp_4x] = "AVX512 (4x rcp)";
        names[avx512_long_div_u8] = "AVX512 long div";
    #endif

    return names;
}
