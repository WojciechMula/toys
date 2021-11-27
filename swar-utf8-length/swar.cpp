#include "swar.h"

#include <cstdint>
#include "scalar.h"

size_t swar_count_code_points(const char* buf, size_t len) {
    const uint64_t* qword = reinterpret_cast<const uint64_t*>(buf);
    const uint64_t* end = qword + len / 8;

    size_t count = 0;
    for (/**/; qword != end; qword++) {
        // detect bit patterns 10xx.xxxx

                                                            // continuation     ASCII        ASCII    leading bytes
        const uint64_t t0 = *qword;                         //  10xx.xxxx   00xx.xxxx    01xx.xxxx    11xx.xxxx 
        const uint64_t t1 = ~t0;                            //  01xx.xxxx   01xx.xxxx    10xx.xxxx    00xx.xxxx
        const uint64_t t2 = t1 & 0x04040404040404040llu;    //  0100.0000   0100.0000    0000.0000    0000.0000
        const uint64_t t3 = t2 + t2;                        //  1000.0000   1000.0000    0000.0000    0000.0000
        const uint64_t t4 = t0 & t3;                        //  1000.0000   0000.0000    0000.0000    0000.000

        // we're counting evertyhing but continuation bytes
        count += 8 - __builtin_popcountll(t4);
    }

    return count + ((len % 8) ? count_code_points((const char*)end, len % 8) : 0);
}
