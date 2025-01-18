#include <cstdlib>

template <typename Type, typename Compare>
void push_heap_scalar(Type* start, Type* end, Compare cmp) {
    Type* array         = start;
    ssize_t index       = (end - start) - 1;
    ssize_t parent_idx  = (index - 1) / 2;

    const Type new_value = array[index];
    int n = 0;
    while (parent_idx >= 0) {
        n += 1;
        if (cmp(array[parent_idx], new_value)) {
            array[index]      = array[parent_idx];
            array[parent_idx] = new_value;

            index      = parent_idx;
            parent_idx = (index - 1) / 2;
        } else
            break;
    }
}
