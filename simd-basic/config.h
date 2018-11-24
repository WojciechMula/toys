#if defined(HAVE_AVX512VBMI) && !defined(HAVE_AVX512BW)
#   define HAVE_AVX512BW 1
#endif

#if defined(HAVE_AVX512BW) && !defined(HAVE_AVX512F)
#   define HAVE_AVX512F 1
#endif

#if defined(HAVE_AVX512F) && !defined(HAVE_AVX2)
#   define HAVE_AVX2 1
#endif

#if defined(HAVE_AVX2) && !defined(HAVE_SSSE3)
#   define HAVE_SSSE3 1
#   define HAVE_SSE41 1
#   define HAVE_SSE42 1
#endif

#if (defined(HAVE_SSE41) || defined(HAVE_SSE42)) && !defined(HAVE_SSSE3)
#   define HAVE_SSSE3 1
#endif

#if defined(HAVE_SSSE3) && !defined(HAVE_SSE2)
#   define HAVE_SSE2 1
#endif
