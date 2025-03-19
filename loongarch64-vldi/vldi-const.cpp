#include <cstdint>
#include <cstdio>
#include <vector>
#include <string>

/*
    Encoding of argument for LoongArch64 xvldi instruction
    See: https://jia.je/unofficial-loongarch-intrinsics-guide/lasx/misc/#__m256i-__lasx_xvldi-imm_n1024_1023-imm

    1: imm[12:8]=0b10000: broadcast imm[7:0] as 32-bit elements to all lanes
    2: imm[12:8]=0b10001: broadcast imm[7:0] << 8 as 32-bit elements to all lanes
    3: imm[12:8]=0b10010: broadcast imm[7:0] << 16 as 32-bit elements to all lanes
    4: imm[12:8]=0b10011: broadcast imm[7:0] << 24 as 32-bit elements to all lanes
    5: imm[12:8]=0b10100: broadcast imm[7:0] as 16-bit elements to all lanes
    6: imm[12:8]=0b10101: broadcast imm[7:0] << 8 as 16-bit elements to all lanes
    7: imm[12:8]=0b10110: broadcast (imm[7:0] << 8) | 0xFF as 32-bit elements to all lanes
    8: imm[12:8]=0b10111: broadcast (imm[7:0] << 16) | 0xFFFF as 32-bit elements to all lanes
    9: imm[12:8]=0b11000: broadcast imm[7:0] as 8-bit elements to all lanes
   10: imm[12:8]=0b11001: repeat each bit of imm[7:0] eight times, and broadcast the result as 64-bit elements to all lanes
*/

enum class VldiOperation {
    BroadcastU8ToU32                    = 0b10000,
    BroadcastU8ShiftedBy8ToU32          = 0b10001,
    BroadcastU8ShiftedBy16ToU32         = 0b10010,
    BroadcastU8ShiftedBy24ToU32         = 0b10011,
    BroadcastU8ToU16                    = 0b10100,
    BroadcastU8ShiftedBy8ToU16          = 0b10101,
    BroadcastU8ShiftedBy8OrFFToU32      = 0b10110,
    BroadcastU8ShiftedBy8OrFFFFToU32    = 0b10111,
    BroadcastU8                         = 0b11000,
    BitmaskToBytemask                   = 0b11001,
};

std::string describe(VldiOperation op, uint8_t imm) {
    char buf[256];
#define fmt(format, args) if (snprintf(buf, sizeof(buf), format, args) >= int(sizeof(buf))) { \
        printf("unable to format string '%s'", format);                             \
        abort();                                                                    \
    }

    switch (op) {
        case VldiOperation::BroadcastU8ToU32:
            fmt("imm[12:8]=0b10000: broadcast imm[7:0]=0x%02x as 32-bit elements to all lanes", imm);
            break;
        case VldiOperation::BroadcastU8ShiftedBy8ToU32:
            fmt("imm[12:8]=0b10001: broadcast imm[7:0]=0x%02x << 8 as 32-bit elements to all lanes", imm);
            break;
        case VldiOperation::BroadcastU8ShiftedBy16ToU32:
            fmt("imm[12:8]=0b10010: broadcast imm[7:0]=0x%02x << 16 as 32-bit elements to all lanes", imm);
            break;
        case VldiOperation::BroadcastU8ShiftedBy24ToU32:
            fmt("imm[12:8]=0b10011: broadcast imm[7:0]=0x%02x << 24 as 32-bit elements to all lanes", imm);
            break;
        case VldiOperation::BroadcastU8ToU16:
            fmt("imm[12:8]=0b10100: broadcast imm[7:0]=0x%02x as 16-bit elements to all lanes", imm);
            break;
        case VldiOperation::BroadcastU8ShiftedBy8ToU16:
            fmt("imm[12:8]=0b10101: broadcast imm[7:0]=0x%02x << 8 as 16-bit elements to all lanes", imm);
            break;
        case VldiOperation::BroadcastU8ShiftedBy8OrFFToU32:
            fmt("imm[12:8]=0b10110: broadcast (imm[7:0]=0x%02x << 8) | 0xFF as 32-bit elements to all lanes", imm);
            break;
        case VldiOperation::BroadcastU8ShiftedBy8OrFFFFToU32:
            fmt("imm[12:8]=0b10111: broadcast (imm[7:0]=0x%02x << 16) | 0xFFFF as 32-bit elements to all lanes", imm);
            break;
        case VldiOperation::BroadcastU8:
            fmt("imm[12:8]=0b11000: broadcast imm[7:0]=0x%02x as 8-bit elements to all lanes", imm);
            break;
        case VldiOperation::BitmaskToBytemask:
            fmt("imm[12:8]=0b11001: repeat each bit of imm[7:0]=0x%02x eight times, and broadcast the result as 64-bit elements to all lanes", imm);
            break;
        default:
            fmt("wrong operation code %x", unsigned(op));
    }

#undef fmt

    return buf;
}

struct MatchResult {
    uint32_t imm8;
    VldiOperation op;

    std::string describe() const {
        return ::describe(op, imm8);
    }

    uint64_t value() const {
        switch (op) {
            case VldiOperation::BroadcastU8ToU32:
                return imm8;
            case VldiOperation::BroadcastU8ShiftedBy8ToU32:
                return imm8 << 8;
            case VldiOperation::BroadcastU8ShiftedBy16ToU32:
                return imm8 << 16;
            case VldiOperation::BroadcastU8ShiftedBy24ToU32:
                return imm8 << 24;
                break;
            case VldiOperation::BroadcastU8ToU16:
                return imm8 | (imm8 << 16);
            case VldiOperation::BroadcastU8ShiftedBy8ToU16:
                return (imm8 << 8) | (imm8 << 24);
            case VldiOperation::BroadcastU8ShiftedBy8OrFFToU32:
                return (imm8 << 8) | 0xff;
            case VldiOperation::BroadcastU8ShiftedBy8OrFFFFToU32:
                return (imm8 << 16) | 0xffff;
            case VldiOperation::BroadcastU8:
                return (imm8 << 24) | (imm8 << 16) | (imm8 << 16) | imm8;
            case VldiOperation::BitmaskToBytemask:
                return (imm8 & 0x01 ? (uint64_t(0xff) << 0*8) : 0)
                     | (imm8 & 0x02 ? (uint64_t(0xff) << 1*8) : 0)
                     | (imm8 & 0x04 ? (uint64_t(0xff) << 2*8) : 0)
                     | (imm8 & 0x08 ? (uint64_t(0xff) << 3*8) : 0)
                     | (imm8 & 0x10 ? (uint64_t(0xff) << 4*8) : 0)
                     | (imm8 & 0x20 ? (uint64_t(0xff) << 5*8) : 0)
                     | (imm8 & 0x40 ? (uint64_t(0xff) << 6*8) : 0)
                     | (imm8 & 0x80 ? (uint64_t(0xff) << 7*8) : 0);
            default:
                return -1;
        }
    }

    int code() const {
        const uint16_t operation = uint16_t(op) << 8;

        return int(operation | imm8) - 8192;
    }
};

bool is_bytemask(uint8_t x) {
    return (x == 0x00) || (x == 0xff);
}

void match_u16_aux(uint16_t x, std::vector<MatchResult>& res) {
    const uint8_t b0 = (x >> 0*8) & 0xff;
    const uint8_t b1 = (x >> 1*8) & 0xff;

    if (uint16_t(b0) == x) {
        res.push_back(MatchResult{b0, VldiOperation::BroadcastU8ToU16});
    }

    if ((uint16_t(b1) << 8) == x) {
        res.push_back(MatchResult{b1, VldiOperation::BroadcastU8ShiftedBy8ToU16});
    }

    if (b0 == b1) {
        res.push_back(MatchResult{b0, VldiOperation::BroadcastU8});
    }

    if (is_bytemask(b0) && is_bytemask(b1)) {
        const uint8_t imm8 = (b0 ? 0x55 : 0x00)
                           | (b1 ? 0xaa : 0x00);

        res.push_back(MatchResult{imm8, VldiOperation::BitmaskToBytemask});
    }
}

void match_u32_aux(uint32_t x, std::vector<MatchResult>& res) {
    const uint8_t b0 = (x >> 0*8) & 0xff;
    const uint8_t b1 = (x >> 1*8) & 0xff;
    const uint8_t b2 = (x >> 2*8) & 0xff;
    const uint8_t b3 = (x >> 3*8) & 0xff;

    if ((b0 == b2) && (b1 == b3)) {
        match_u16_aux(x & 0xffff, res);
    }

    if (uint32_t(b0) == x) {
        res.push_back(MatchResult{b0, VldiOperation::BroadcastU8ToU32});
    }

    if ((uint32_t(b1) << 8) == x) {
        res.push_back(MatchResult{b1, VldiOperation::BroadcastU8ShiftedBy8ToU32});
    }

    if ((uint32_t(b2) << 16) == x) {
        res.push_back(MatchResult{b2, VldiOperation::BroadcastU8ShiftedBy16ToU32});
    }

    if ((uint32_t(b2) << 24) == x) {
        res.push_back(MatchResult{b3, VldiOperation::BroadcastU8ShiftedBy24ToU32});
    }

    if (((uint32_t(b1) << 8) | 0xff) == x) {
        res.push_back(MatchResult{b1, VldiOperation::BroadcastU8ShiftedBy8OrFFToU32});
    }

    if (((uint32_t(b2) << 16) | 0xffff) == x) {
        res.push_back(MatchResult{b2, VldiOperation::BroadcastU8ShiftedBy8OrFFFFToU32});
    }

    // Case #9 is handled in `match_u16_aux`, not repeating it here

    if (is_bytemask(b0) && is_bytemask(b1) && is_bytemask(b2) && is_bytemask(b3)) {
        const uint8_t imm8 = (b0 ? 0x11 : 0x00)
                           | (b1 ? 0x22 : 0x00)
                           | (b2 ? 0x44 : 0x00)
                           | (b3 ? 0x88 : 0x00);
        res.push_back(MatchResult{imm8, VldiOperation::BitmaskToBytemask});
    }
}

void match_u64_aux(uint64_t x, std::vector<MatchResult>& res) {
    const uint8_t b0 = (x >> 0*8) & 0xff;
    const uint8_t b1 = (x >> 1*8) & 0xff;
    const uint8_t b2 = (x >> 2*8) & 0xff;
    const uint8_t b3 = (x >> 3*8) & 0xff;
    const uint8_t b4 = (x >> 4*8) & 0xff;
    const uint8_t b5 = (x >> 5*8) & 0xff;
    const uint8_t b6 = (x >> 6*8) & 0xff;
    const uint8_t b7 = (x >> 7*8) & 0xff;

    if ((x & 0xffffffff) == (x >> 32)) {
        match_u32_aux(x & 0xffffffff, res);
    }

    const bool msk = is_bytemask(b0)
                  && is_bytemask(b1)
                  && is_bytemask(b2)
                  && is_bytemask(b3)
                  && is_bytemask(b4)
                  && is_bytemask(b5)
                  && is_bytemask(b6)
                  && is_bytemask(b7);
    if (msk) {
        const uint8_t imm8 = (b0 ? 0x01 : 0x00)
                           | (b1 ? 0x02 : 0x00)
                           | (b2 ? 0x04 : 0x00)
                           | (b3 ? 0x08 : 0x00)
                           | (b4 ? 0x10 : 0x00)
                           | (b5 ? 0x20 : 0x00)
                           | (b6 ? 0x40 : 0x00)
                           | (b7 ? 0x80 : 0x00);
        res.push_back(MatchResult{imm8, VldiOperation::BitmaskToBytemask});
    }
}

int main(int argc, char* argv[]) {
    std::vector<MatchResult> res;
    for (int i=1; i < argc; i++) {
        const uint64_t v = strtoul(argv[i], nullptr, 0);
        printf("'%s' => 0x%lx (%ld)\n", argv[i], v, v);

        bool any_match = false;

        if (v < (uint64_t(1) << 16)) {
            res.clear();
            match_u16_aux(v & 0xffff, res);
            if (!res.empty()) {
                any_match = true;
                printf("  as u16:\n");
                for (const auto& m: res) {
                    printf("   // %s\n", m.describe().c_str());
                    printf("    __lasx_vldi(%d) => 0x%0lx\n", m.code(), m.value());
                }
            }
        }

        if (v < (uint64_t(1) << 32)) {
            res.clear();
            match_u32_aux(v & 0xffffffff, res);
            if (!res.empty()) {
                any_match = true;
                printf("  as u32:\n");
                for (const auto& m: res) {
                    printf("   // %s\n", m.describe().c_str());
                    printf("    __lasx_vldi(%d) => 0x%0lx\n", m.code(), m.value());
                }
            }
        }

        res.clear();
        match_u64_aux(v, res);
        if (!res.empty()) {
            any_match = true;
            printf("  as u64:\n");
            for (const auto& m: res) {
                printf("   // %s\n", m.describe().c_str());
                printf("    __lasx_vldi(%d) => 0x%0lx\n", m.code(), m.value());
            }
        }

        if (!any_match) {
            puts("can't be expressed as `vldi` argument");
        }
    }
}
