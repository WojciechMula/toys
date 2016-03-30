void dump_hex(const uint8_t* buf, size_t num) {
    for (size_t i=0; i < num; i++) {
        printf("%02x", buf[i]);
    }
}


void dump(__m128i xmm) {
    
    uint8_t buf[16];
    _mm_storeu_si128(reinterpret_cast<__m128i*>(buf), xmm);
    dump_hex(buf, 16);
}


void dump(const char* name, __m128i xmm) {
    
    printf("%-20s = [", name);
    dump(xmm);
    printf("]\n");
}
