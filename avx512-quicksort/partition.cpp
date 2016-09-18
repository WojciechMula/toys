void partition_epi32(uint32_t* array, const uint32_t pivot, int& left, int& right) {

    while (left <= right) {

        while (array[left] < pivot) {
            left += 1;
        }

        while (array[right] > pivot) {
            right -= 1;
        }

        if (left <= right) {
            const uint32_t t = array[left];
            array[left]      = array[right];
            array[right]     = t;

            left  += 1;
            right -= 1;
        }
    }
}
