#include "common.cpp"
#include "sse.cpp"
#include "scalar.cpp"
#ifdef HAVE_AVX512BW
#   include "avx512bw.cpp"
#   include "avx512bw_masks.cpp"
#endif
#ifdef HAVE_AVX512VBMI
#   include "avx512vbmi.cpp"
#endif

