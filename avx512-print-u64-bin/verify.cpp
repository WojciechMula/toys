#include <cstdio>
#include <cstdint>
#include <cstring>

#include "avx512.cpp"

void u64_to_bin(uint64_t v, char* buf) {
    for (int i=0; i < 64; i++) {
        buf[i] = (v & 0x8000'0000'0000'0000) ? '1' : '0';
        v <<= 1;
    }
}

template <typename FN>
bool check(const char* name,  FN func) {
    printf("checking %s... ", name); fflush(stdout);

    char ref[64 + 1];
    char got[64 + 1];

    memset(ref, 0, sizeof(ref));
    memset(got, 0, sizeof(got));

    for (int byte=0; byte < 8; byte++) {
        for (uint64_t v=0; v < 256; v++) {
            const uint64_t qword = v << (byte * 8);

            u64_to_bin(qword, ref);
            func(qword, got);

            if (memcmp(ref, got, sizeof(ref)) != 0) {
                printf("value : %016lx\n", v);
                printf("want  : '%s'\n", ref);
                printf("got   : '%s'\n", got);
                return false;
            }
        }
    }

    puts("OK");
    return true;
}

int main() {
    bool all_ok = true;
    all_ok = check("avx512_u64_to_bin_ver1", avx512_u64_to_bin_ver1) and all_ok;
    all_ok = check("avx512_u64_to_bin_ver2", avx512_u64_to_bin_ver2) and all_ok;

    if (all_ok) {
        puts("All OK");
    }
}
