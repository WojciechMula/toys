#include <cstdio>
#include "lasx-const.h"

void dump_u32(__m256i x) {
    uint32_t tmp[32/4];
    __lasx_xvst(x, tmp, 0);
    putchar('[');
    for (int i=0; i < 32/4; i++) {
        if (i > 0) {
            putchar(' ');
        }

        printf("%08x", tmp[i]);
    }
    puts("]");
}

int main() {
    const auto a = lasx_splat_u32<0xfffffff8>();
    dump_u32(a);

    const auto b = lasx_splat_u32<0x42ffff>();
    dump_u32(b);

    const auto c = lasx_splat_u32<0x424344>();
    dump_u32(c);
}
