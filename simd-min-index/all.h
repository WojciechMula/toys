#pragma once

#include <cstdlib>

size_t min_index_scalar(int32_t* array, size_t size);
size_t min_index_sse(int32_t* array, size_t size);
size_t min_index_sse_unrolled(int32_t* array, size_t size);
#ifdef HAVE_AVX2
size_t min_index_avx2(int32_t* array, size_t size);
#endif
#ifdef HAVE_AVX512
size_t min_index_avx512f(int32_t* array, size_t size);
#endif
