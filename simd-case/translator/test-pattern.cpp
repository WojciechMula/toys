#include <cstdio>

#include <cstdint>
#include <immintrin.h>

int switch_procedure(int x) {

    int r = 0;

#ifndef SIMD
    switch (x) {
#endif
    // SIMD-case-start
        case 102:
            r = 1;
            break;
        case 203:
            r = 2;
            break;
        case 304:
            r = 3;
            break;
        case 405:
            r = 4;
            break;
        case 607:
            r = 5;
            break;
        case 708:
            r = 6;
            break;
        case 809:
            r = 7;
            break;
        case 910:
            r = 8;
            break;
        case 1011:
            r = 9;
            break;
        case 1112:
            r = 10;
            break;
        case 1113:
            r = 11;
            break;
        case 1214:
            r = 12;
            break;
        case 1315:
            r = 13;
            break;
        case 1416:
            r = 14;
            break;

    // SIMD-case-end
#ifndef SIMD
    }
#endif

    return r;
}
