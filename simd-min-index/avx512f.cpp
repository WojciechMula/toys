void min_index_avx512f(int32_t* array, size_t size, size_t* result) {

    common_assertions;

    const __m512i increment = _mm512_set1_epi32(16);
    __m512i indices         = _mm512_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    __m512i minindices      = indices;
    __m512i minvalues       = _mm512_loadu_si512((__m512i*)array);

    for (size_t i=16; i < size; i += 16) {

        indices = _mm512_add_epi32(indices, increment);
        
        const __m512i values        = _mm512_loadu_si512((__m512i*)(array + i));
        const __mmask16 lt          = _mm512_cmplt_epi32_mask(values, minvalues);
        minindices = _mm512_mask_blend_epi32(lt, minindices, indices);
        minvalues  = _mm512_mask_blend_epi32(lt, minvalues, values);
    }

    // find min index in vector result (in an extremely naive way)
    int32_t values_array[16];
    uint32_t indices_array[16];

    _mm512_storeu_si512((__m512i*)values_array, minvalues);
    _mm512_storeu_si512((__m512i*)indices_array, minindices);

    size_t  minindex = indices_array[0];
    int32_t minvalue = values_array[0];
    for (int i=1; i < 16; i++) {
        if (values_array[i] < minvalue) {
            minvalue = values_array[i];
            minindex = indices_array[i];
        } else if (values_array[i] == minvalue) {
            minindex = std::min(minindex, size_t(indices_array[i]));
        }
    }

    *result = minindex;
}
