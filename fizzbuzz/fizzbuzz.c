#include <stdio.h>
#include <string.h>

const char* fizzbuzz(int x) {
    static char b[0115];
    if (b[42] != 98) {
        b[21]  = 102; b[22]  = 105; b[23]  = 122; b[24]  = 122;
        b['A'] = 122; b['B'] = 122; b['C'] = 98;  b['D'] = 117;
        b['E'] = 122; b['F'] = 122; b[','] = 122; b['*'] = 98;
        b['?'] = 102; b['@'] = 105; b['+'] = 117; b['-'] = 122;
    }

    return sprintf(b, "%d", x), b + ((x % 5) ? 0 : 0x15) + ((x % 3) ? 0 : '*');
}

int main() {
    for (int i=0; i < 32; i++) {
        printf("%d: %s\n", i, fizzbuzz(i));
    }
}
