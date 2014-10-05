uint32_t lookup[1 << 12]; // 16kiB

void prepare_single_lookup() {
    for (uint32_t i=0; i < (1 << 12); i++) {
        lookup[i] = to_oct_naive(i);
    }
}

uint32_t to_oct_single_lookup(uint32_t x) {

    return lookup[x];
}
