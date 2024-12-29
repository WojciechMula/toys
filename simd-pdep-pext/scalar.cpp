void scalar_pext_u32(const uint32_t* data, const uint32_t* mask, uint32_t* out, size_t n) {
    for (size_t i=0; i < n; i++) {
        out[i] = _pext_u32(data[i], mask[i]);
    }
}

void scalar_pdep_u32(const uint32_t* data, const uint32_t* mask, uint32_t* out, size_t n) {
    for (size_t i=0; i < n; i++) {
        out[i] = _pdep_u32(data[i], mask[i]);
    }
}
