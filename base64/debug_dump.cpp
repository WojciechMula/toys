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


#if defined(HAVE_AVX2_INSTRUCTIONS)
void dump(__m256i xmm) {
    
    uint8_t buf[32];
    _mm256_storeu_si256(reinterpret_cast<__m256i*>(buf), xmm);
    dump_hex(buf, 32);
}
#endif


#if defined(HAVE_AVX512_INSTRUCTIONS)
void dump(__m512i xmm) {
    
    uint8_t buf[64];
    _mm512_storeu_si512(reinterpret_cast<__m512*>(buf), xmm);
    dump_hex(buf, 64);
}
#endif


template <typename T>
void dump(const char* name, T vector) {
    
    printf("%-20s = [", name);
    dump(vector);
    printf("]\n");
}


#define DUMP(var) dump(#var, var)
