size_t scalar_strlen(const char* s) {
    
    size_t size = 0;
    while (s[size] != 0) {
        size += 1;
    }

    return size;
}
