void min_index_scalar(int32_t* array, size_t size, size_t* result) {

    common_assertions;

    size_t minindex = 0;
    int32_t minvalue = array[0];

    for (size_t i=1; i < size; i++) {
        if (array[i] < minvalue) {
            minvalue = array[i];
            minindex = i;
        }
    }

    *result = minindex;
}
