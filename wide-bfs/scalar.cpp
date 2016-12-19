uint64_t scalar_bfs(const uint64_t* data, size_t n) {

    for (size_t i=0; i < n; i++) {
        if (data[i]) {
            return i * 64 + bfs(data[i]);
        }
    }

    return -1;
}
