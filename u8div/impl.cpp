#include <cstdint>
#include <cstdlib>
#include <cstring>
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
#   include "avx512_long_div.cpp"
#endif
