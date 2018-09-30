void min_index_avx2(int32_t* array, size_t size, size_t* result) {

    common_assertions;

    const __m256i increment = _mm256_set1_epi32(8);
    __m256i indices         = _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7);
    __m256i minindices      = indices;
    __m256i minvalues       = _mm256_loadu_si256((__m256i*)array);

    for (size_t i=8; i < size; i += 8) {

        indices = _mm256_add_epi32(indices, increment);
        
        const __m256i values        = _mm256_loadu_si256((__m256i*)(array + i));
        const __m256i lt            = _mm256_cmpgt_epi32(minvalues, values);
        minindices = _mm256_blendv_epi8(minindices, indices, lt);
        minvalues  = _mm256_min_epi32(values, minvalues);
    }

    // find min index in vector result (in an extremely naive way)
    int32_t values_array[8];
    uint32_t indices_array[8];

    _mm256_storeu_si256((__m256i*)values_array, minvalues);
    _mm256_storeu_si256((__m256i*)indices_array, minindices);

    size_t  minindex = indices_array[0];
    int32_t minvalue = values_array[0];
    for (int i=1; i < 8; i++) {
        if (values_array[i] < minvalue) {
            minvalue = values_array[i];
            minindex = indices_array[i];
        } else if (values_array[i] == minvalue) {
            minindex = std::min(minindex, size_t(indices_array[i]));
        }
    }

    *result = minindex;
}
