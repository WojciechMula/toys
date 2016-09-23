#include "avx2-partition.cpp"


void avx2_quicksort(uint32_t* array, int left, int right) {

    int i = left;
    int j = right;

    const uint32_t pivot = array[(i + j)/2];
    const int AVX2_REGISTER_SIZE = 8; // in 32-bit words

    if (j - i >= 2 * AVX2_REGISTER_SIZE) {
        qs::avx2::partition_epi32(array, pivot, i, j);
    } else {
        partition_epi32(array, pivot, i, j);
    }

    if (left < j) {
        avx2_quicksort(array, left, j);
    }

    if (i < right) {
        avx2_quicksort(array, i, right);
    }
}

