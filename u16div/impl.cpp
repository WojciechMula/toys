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

using signature_t = void(*)(const uint16_t*, const uint16_t*, uint16_t*, size_t);
using function_names_t = std::map<signature_t, std::string>;

function_names_t function_names() {
    function_names_t names;

    names[scalar_div_u16] = "scalar";

    #ifdef HAVE_AVX2
        names[avx2_div_u16_cvtt] = "AVX2 (cvtt)";
        names[avx2_div_u16_rcp] = "AVX2 (rcp)";
    #endif

    return names;
}
