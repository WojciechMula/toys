#include <cstdio>
#include <cstdint>

int main() {
    union {
        uint32_t img;
        float    val;
    } f32;

    union {
        uint64_t img;
        double   val;
    } f64;

    for (uint32_t imm=0; imm < 256; imm++) {
        // 1. (imm[7] << 31) | ((1-imm[6]) << 30) | ((imm[6] * 0x1F) << 25) | (imm[5:0] << 19)
        {
            const uint32_t imm7 = imm >> 6;
            const uint32_t imm6 = ((imm >> 5) & 0x1);
            const uint32_t imm5 = imm & 0x1f;

            f32.img = (imm7 << 31)
                    | ((1 - imm6) << 30)
                    | (imm6 * 0x1f) << 25
                    | (imm5 << 19);
        }

        // 2. (imm[7] << 63) | ((1-imm[6]) << 62) | ((imm[6] * 0xFF) << 54) | (imm[5:0] << 48)
        {
            const uint64_t imm7 = imm >> 6;
            const uint64_t imm6 = ((imm >> 5) & 0x1);
            const uint64_t imm5 = imm & 0x1f;

            f64.img = (imm7 << 63)
                    | ((1 - imm6) << 62)
                    | (imm6 * 0xff) << 54
                    | (imm5 << 48);
        }

        printf("%02x:\n", imm);
        printf("\tf32 = %10f %08x\n", imm, f32.val, f32.img);
        printf("\tf64 = %10f %016x\n", imm, f64.val, f64.img);
    }
}
