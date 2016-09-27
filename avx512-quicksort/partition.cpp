void scalar_partition_epi32(uint32_t* array, const uint32_t pivot, int& left, int& right) {

    while (left <= right) {

        while (array[left] < pivot) {
            left += 1;
        }

        while (array[right] > pivot) {
            right -= 1;
        }

        if (left <= right) {
            const uint32_t l = array[left];
            const uint32_t r = array[right];

            if (l != r) {
                array[left]  = r;
                array[right] = l;
            }

            left  += 1;
            right -= 1;
        }
    }
}
