#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <immintrin.h>

float sse_div(uint32_t x) {
    const __m128i x_u32 = _mm_cvtsi32_si128(x);
    const __m128  x_f32 = _mm_cvtepi32_ps(x_u32);
    const __m128  one   = _mm_set1_ps(1.0);

    const __m128  y = _mm_div_ps(one, x_f32);

    return _mm_cvtss_f32(y);
}

float sse_rcp(uint32_t x) {
    const __m128i x_u32 = _mm_cvtsi32_si128(x);
    const __m128  x_f32 = _mm_cvtepi32_ps(x_u32);

    const __m128  y = _mm_rcp_ps(x_f32);

    return _mm_cvtss_f32(y);
}

int main() {
    printf("+-----+-------------------------+-------------------------+-----------+\n");
    printf("|     |        1 / x            |    approx 1 / x         |           |\n");
    printf("|  x  +----------+--------------+----------+--------------+   error   |\n");
    printf("|     |   float  |     hex      |   float  |     hex      |           |\n");
    printf("+=====+==========+==============+==========+==============+===========+\n");

    for (uint32_t b=1; b < 256; b++) {
        union {
            float fp;
            uint32_t img;
        } div, rcp;

        div.fp = sse_div(b);
        rcp.fp = sse_rcp(b);

        printf("| %3d | %7.6f | ``%08x`` | %7.6f | ``%08x`` | %9.6f |\n", b, div.fp, div.img, rcp.fp, rcp.img, div.fp - rcp.fp);
        printf("+-----+----------+--------------+----------+--------------+-----------+\n");
    }
}
