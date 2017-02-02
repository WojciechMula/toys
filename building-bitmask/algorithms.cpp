#include "scalar.cpp"
#include "sse.cpp"

#ifdef HAVE_AVX512_INSTRUCTIONS
#   ifndef HAVE_AVX2_INSTRUCTIONS
#       define HAVE_AVX2_INSTRUCTIONS
#   endif
#   include "avx512.cpp"
#endif

#ifdef HAVE_AVX2_INSTRUCTIONS
#   include "avx2.cpp"
#endif
