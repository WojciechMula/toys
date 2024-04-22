#include <asm/hwprobe.h>
#include <asm/unistd.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

void print_extensions(uint64_t);

int main() {
    struct riscv_hwprobe probes[] = {
        {RISCV_HWPROBE_KEY_IMA_EXT_0, 0}
    };

    const size_t probes_count = 1; 
#if 0
    const long ret = sys_riscv_hwprobe(&probes, probes_count, 0, NULL, 0);
#else
    const long ret = syscall(__NR_riscv_hwprobe, &probes, probes_count, 0, NULL, 0);
#endif
    if (ret != 0) {
        printf("syscall returned %ld\n", ret);
        return 1;
    }

    for (size_t i=0; i < probes_count; i++) {
        switch (probes[i].key) {
            case RISCV_HWPROBE_KEY_IMA_EXT_0:
                printf("RISCV_HWPROBE_KEY_IMA_EXT_0:\n");
                print_extensions(probes[i].value);
                break;
            default:
                printf("key 0x%016llx: value 0x%016llx\n", probes[i].key, probes[i].value);
                break;
        }
    }
}

void print_extensions(uint64_t bitmask) {
#define supports_extension(name)    \
    if (bitmask & name) {           \
        printf("- %s\n", #name);      \
    }

    supports_extension(RISCV_HWPROBE_IMA_FD);
    supports_extension(RISCV_HWPROBE_IMA_C);
    supports_extension(RISCV_HWPROBE_IMA_V);
    supports_extension(RISCV_HWPROBE_EXT_ZBA);
    supports_extension(RISCV_HWPROBE_EXT_ZBB);
    supports_extension(RISCV_HWPROBE_EXT_ZBS);
    supports_extension(RISCV_HWPROBE_EXT_ZICBOZ);
}
