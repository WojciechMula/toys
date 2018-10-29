void jpeg_zigzag_scalar(const uint16_t* in, uint16_t* out) {
    for (int i=0; i < 64; i++) {
        unsigned index = zigzag_shuffle[i];
        out[i] = in[index];
    }
}

void jpeg_zigzag_scalar_unrolled4(const uint16_t* in, uint16_t* out) {
    for (int i=0; i < 64; i += 4) {
        unsigned index0 = zigzag_shuffle[i + 0];
        unsigned index1 = zigzag_shuffle[i + 1];
        unsigned index2 = zigzag_shuffle[i + 2];
        unsigned index3 = zigzag_shuffle[i + 3];
        out[i + 0] = in[index0];
        out[i + 1] = in[index1];
        out[i + 2] = in[index2];
        out[i + 3] = in[index3];
    }
}
