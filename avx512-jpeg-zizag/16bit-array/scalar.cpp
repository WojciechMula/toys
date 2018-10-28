void jpeg_zigzag_scalar(const uint16_t* in, uint16_t* out) {
    for (int i=0; i < 64; i++) {
        unsigned index = zigzag_shuffle[i];
        out[i] = in[index];
    }
}
