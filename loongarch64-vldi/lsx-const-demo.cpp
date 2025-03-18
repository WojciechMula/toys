#include <cstdio>
#include "lsx-const.h"

void dump_u32(__m128i x) {
    uint32_t tmp[16/4];
    __lsx_vst(x, tmp, 0);
    putchar('[');
    for (int i=0; i < 16/4; i++) {
        if (i > 0) {
            putchar(' ');
        }

        printf("%08x", tmp[i]);
    }
    puts("]");
}

int main() {
    const auto a = lsx_splat_u32<0xfffffff8>();
    dump_u32(a);

    const auto b = lsx_splat_u32<0x42ffff>();
    dump_u32(b);

    const auto c = lsx_splat_u32<0x424344>();
    dump_u32(c);
}
