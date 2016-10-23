/*
    What does VPCONFLICTD do?

    Pass up to 16 elements of vector in cmd line, this program will
    print VPCONFLICTD result.
*/


#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <immintrin.h>

void bin(uint32_t x) {
    for (int i=15; i >= 0; i--) {
        putchar(x & (uint32_t(1) << i) ? '1' : '.');
    }
}

void dump_bin(__m512i value) {

    uint32_t tmp[16];
    _mm512_storeu_si512(tmp, value);
    putchar('[');
    for (int i=0; i < 16; i++) {
        if (i > 0) {
            putchar('|');
        }

        bin(tmp[i]);
    }
    putchar(']');
    putchar('\n');
}


void dump_hex(__m512i value) {

    uint32_t tmp[16];
    _mm512_storeu_si512(tmp, value);
    putchar('[');
    for (int i=0; i < 16; i++) {
        if (i > 0) {
            putchar('|');
        }

        printf("%08x", tmp[i]);
    }
    putchar(']');
    putchar('\n');
}


void demo(int argc, char* argv[]) {

    uint32_t tmp[16];
    
    const int n = argc > 17 ? 17 : argc;

    for (int i=0; i < 16; i++) {
        tmp[i] = i;
    }
    
    for (int i=1; i < n; i++) {
        if ((strcmp(argv[i], "-") == 0) || (strcmp(argv[i], "?") == 0)) {
            continue;
        }
        tmp[i - 1] = atoi(argv[i]);
    }

    const __m512i in  = _mm512_loadu_si512(tmp);
    const __m512i out = _mm512_conflict_epi32(in);
 
    printf("input  = "); dump_hex(in);
    printf("output = "); dump_hex(out);
    printf("       = "); dump_bin(out);
}


int main(int argc, char* argv[]) {

    if (argc == 1) {
        puts("usage");
        printf("%s [up to 16 numbers]\n", argv[0]);
    } else {
        demo(argc, argv);
    }
}
