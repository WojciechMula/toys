#include "partition.cpp"

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
