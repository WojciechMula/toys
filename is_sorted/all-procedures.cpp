#include "scalar.cpp"
#include "sse.cpp"
#include "sse.simd-generic.cpp"
#ifdef HAVE_AVX2
#   include "avx2.cpp"
#   include "avx2.simd-generic.cpp"
#endif // HAVE_AVX2
#ifdef HAVE_AVX512
#   include "avx512.cpp"
#endif // HAVE_AVX512
