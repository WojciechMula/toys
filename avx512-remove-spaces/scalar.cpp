void remove_spaces__scalar(const char* src, char* dst, size_t n) {
    for (size_t i=0; i < n; i++) {
        if (src[i] != ' ')
            *dst++ = src[i];
    }
}
