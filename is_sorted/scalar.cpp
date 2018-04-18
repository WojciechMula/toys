bool is_sorted(const int32_t* input, size_t n) {
    for (size_t i=0; i + 1 < n; i++) {
        if (input[i] > input[i + 1])
            return false;
    }

    return true;
}
