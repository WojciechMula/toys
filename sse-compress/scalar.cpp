void scalar_compress(uint16_t mask, const char* in, char* out) {
    int i = 0;
    int o = 0;

    mask = ~mask;
    while (mask) {
        if ((mask & 1) == 1) {
            out[o++] = in[i];
        }

        mask >>= 1;
        i++;
    }
}
