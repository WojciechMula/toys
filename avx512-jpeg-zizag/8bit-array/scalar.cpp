void jpeg_zigzag_scalar(const uint8_t* in, uint8_t* out) {
    for (int i=0; i < 64; i++) {
        unsigned index = zigzag_shuffle[i];
        out[i] = in[index];
    }
}
