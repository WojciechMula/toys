#include <cstdio>
#include <cstdint>
#include <immintrin.h>

int code_block(int x) {

    int result = -1;

    static void* labels[8] = {
        &&case_0, &&case_3, &&case_4, &&case_7, &&case_8, &&case_11,
        &&case_default, &&case_default
    };

    const __m256i vec = _mm256_set1_epi32(x);
    const __m256i lookup = _mm256_setr_epi32(
        0, 3, 4, 7, 8, 11,
        -1, -1 // these two don't matter
    );

    const __m256i mask = _mm256_cmpeq_epi32(vec, lookup);
        
    uint32_t bitmask = _mm256_movemask_ps((__m256)mask) | 0xc0;
    goto *labels[__builtin_ctz(bitmask)];

case_0:
    puts("zero");
    goto end;
    
case_3:
    puts("one");
    result = 42;
    goto end;

case_4:
    puts("two");
    result = 42;
    goto end;

case_7:
    puts("three");
    result = 1024;
    goto end;

case_8:
    puts("four");
    result = 42;
    goto end;
    
case_11:
    puts("five");
    result = 1024;
    goto end;

case_default:
    result = -1;

end:
    return result;
}
