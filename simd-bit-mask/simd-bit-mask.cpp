#include <cstdio>
#include <cstdint>
#include <immintrin.h>

// input:    k - number of bits
// returns:  a vector where bits from k to max are set.
__m256i mask(int k) {
    // assert(i >= 0 && i <= 256);

    const size_t chunk_size = 32;
    const size_t n     = k / chunk_size;
    const size_t shift = k % chunk_size;

    const __m256i chunk_numbers = _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7);
    const __m256i chunk         = _mm256_set1_epi32(n);
    
    // set all chunks from n-th up to the end to 0xffffffff
    const __m256i tmp1 = _mm256_cmpgt_epi32(chunk_numbers, chunk);

    // shift bits in n-th chunk left by required amount
    const __m256i tmp2 = _mm256_cmpeq_epi32(chunk_numbers, chunk);
    const __m256i tmp3 = _mm256_slli_epi32(tmp2, shift);

    return _mm256_or_si256(tmp1, tmp3);
}

void _mm256_dump_bin(const __m256i& v);

int main() {
    
    for (int i=0; i < 257; i++) {

        auto v = mask(i);
        printf("%3d ", i);
        _mm256_dump_bin(v);
        putchar('\n');
    }
}


void dump_bin(uint8_t v) {

    for (int i=0; i < 8; i++) {
        uint8_t mask = 1 << i;

        putchar((v & mask) ? '1' : '0');
    }
}

void _mm256_dump_bin(const __m256i& v) {
    
    uint8_t tmp[32];

    _mm256_storeu_si256(reinterpret_cast<__m256i*>(tmp), v);

    for (int i=0; i < 32; i++) {
        dump_bin(tmp[i]);
    }
}

