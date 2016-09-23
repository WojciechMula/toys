#include "common.h"
#include "quicksort.cpp"
#ifdef HAVE_AVX2_INSTRUCTIONS
#   include "avx2-quicksort.cpp"
#endif
#ifdef HAVE_AVX512F_INSTRUCTIONS
#   include "avx512-quicksort.cpp"
#endif

