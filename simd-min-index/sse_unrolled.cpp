void min_index_sse_unrolled(int32_t* array, size_t size, size_t* result)
{
    common_assertions;

    const __m128i increment = _mm_set1_epi32(4);
    __m128i indices         = _mm_setr_epi32(0, 1, 2, 3);
    __m128i minindices      = indices;
    __m128i minvalues       = _mm_loadu_si128((__m128i*)array);

    for (size_t i=0; i < size; i += 4 * 4) {
        
        const __m128i values0 = _mm_loadu_si128((__m128i*)(array + i + 0*4));
        const __m128i values1 = _mm_loadu_si128((__m128i*)(array + i + 1*4));
        const __m128i values2 = _mm_loadu_si128((__m128i*)(array + i + 2*4));
        const __m128i values3 = _mm_loadu_si128((__m128i*)(array + i + 3*4));

        minindices = _mm_blendv_epi8(minindices, indices, _mm_cmplt_epi32(values0, minvalues));
        minvalues  = _mm_min_epi32(values0, minvalues);
        indices = _mm_add_epi32(indices, increment);

        minindices = _mm_blendv_epi8(minindices, indices, _mm_cmplt_epi32(values1, minvalues));
        minvalues  = _mm_min_epi32(values1, minvalues);
        indices = _mm_add_epi32(indices, increment);

        minindices = _mm_blendv_epi8(minindices, indices, _mm_cmplt_epi32(values2, minvalues));
        minvalues  = _mm_min_epi32(values2, minvalues);
        indices = _mm_add_epi32(indices, increment);

        minindices = _mm_blendv_epi8(minindices, indices, _mm_cmplt_epi32(values3, minvalues));
        minvalues  = _mm_min_epi32(values3, minvalues);
        indices = _mm_add_epi32(indices, increment);
    }

    // find min index in vector result (in an extremely naive way)
    int32_t values_array[4];
    uint32_t indices_array[4];

    _mm_storeu_si128((__m128i*)values_array, minvalues);
    _mm_storeu_si128((__m128i*)indices_array, minindices);

    size_t  minindex = indices_array[0];
    int32_t minvalue = values_array[0];
    for (int i=1; i < 4; i++) {
        if (values_array[i] < minvalue) {
            minvalue = values_array[i];
            minindex = indices_array[i];
        }
    }

    *result = minindex;
}
