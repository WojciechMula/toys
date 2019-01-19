#pragma once

#include "scalar.h"
#ifdef HAVE_SSE
#   include "sse.h"
#endif
#ifdef HAVE_AVX2
#   include "avx2.h"
#endif
#ifdef HAVE_AVX512BW
#   include "avx512bw.h"
#endif
