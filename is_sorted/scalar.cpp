bool is_sorted(const int32_t* input, size_t n) {
    if (n < 2) {
        return true;
    }

    for (size_t i=0; i < n - 1; i++) {
        if (input[i] > input[i + 1])
            return false;
    }

    return true;
}
