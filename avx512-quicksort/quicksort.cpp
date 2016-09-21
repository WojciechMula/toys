#include "partition.cpp"
#include "avx512-partition.cpp"
#include "avx512-popcnt-partition.cpp"
#include "avx512-bmi2-partition.cpp"


void avx512_quicksort(uint32_t* array, int left, int right) {

    int i = left;
    int j = right;

    const uint32_t pivot = array[(i + j)/2];
    const int AVX512_REGISTER_SIZE = 16; // in 32-bit words

    if (j - i >= 2 * AVX512_REGISTER_SIZE) {
        avx512_partition_epi32(array, pivot, i, j);
    } else {
        partition_epi32(array, pivot, i, j);
    }

    if (left < j) {
        avx512_quicksort(array, left, j);
    }

    if (i < right) {
        avx512_quicksort(array, i, right);
    }
}


void avx512_popcnt_quicksort(uint32_t* array, int left, int right) {

    int i = left;
    int j = right;

    const uint32_t pivot = array[(i + j)/2];
    const int AVX512_REGISTER_SIZE = 16; // in 32-bit words

    if (j - i >= 2 * AVX512_REGISTER_SIZE) {
        avx512_popcnt_partition_epi32(array, pivot, i, j);
    } else {
        partition_epi32(array, pivot, i, j);
    }

    if (left < j) {
        avx512_quicksort(array, left, j);
    }

    if (i < right) {
        avx512_quicksort(array, i, right);
    }
}


void avx512_bmi2_quicksort(uint32_t* array, int left, int right) {

    int i = left;
    int j = right;

    const uint32_t pivot = array[(i + j)/2];
    const int AVX512_REGISTER_SIZE = 16; // in 32-bit words

    if (j - i >= 2 * AVX512_REGISTER_SIZE) {
        avx512_bmi2_partition_epi32(array, pivot, i, j);
    } else {
        partition_epi32(array, pivot, i, j);
    }

    if (left < j) {
        avx512_quicksort(array, left, j);
    }

    if (i < right) {
        avx512_quicksort(array, i, right);
    }
}


void quicksort(uint32_t* array, int left, int right) {

    int i = left;
    int j = right;

    const uint32_t pivot = array[(i + j)/2];

    partition_epi32(array, pivot, i, j);

    if (left < j) {
        quicksort(array, left, j);
    }

    if (i < right) {
        quicksort(array, i, right);
    }
}
