#include <cstdio>
#include <cassert>
#include <cstring>

#include "procedures.cpp"

void verify() {
    char buf[32];

    auto procedures = get_procedures();

    for (uint32_t shift=0; shift < 64 - 16; shift++) {
        for (uint64_t i=0; i <= 999999; i++) {
            uint64_t ref = i << shift;

            if (std::sprintf(buf, "%016lu", ref) > 16) {
                continue;
            }

            for (auto& item: procedures) {
                const uint64_t result = item.fun(buf);

                if (result != ref) {
                    printf("%s failed - %s => %lu\n", item.name.c_str(), buf, result);
                    exit(2);
                }

            }
        }
    }
}


int main() {

    puts("Verfication started, it might take a litte longer");
    verify();
    puts("All OK");
}
