#include "common.cpp"
#include "scalar.cpp"
#include "sse.cpp"
#ifdef HAVE_AVX512F
#   include "avx512f.cpp"
#endif
#ifdef HAVE_AVX512BW
#   include "avx512bw.cpp"
#endif
