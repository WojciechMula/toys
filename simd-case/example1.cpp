#include <immintrin.h>
#include <cstdint>

enum class Colour: uint32_t {
    RED     = 0x00ff0000,
    GREEN   = 0x0000ff00,
    BLUE    = 0x000000ff,
    WHITE   = 0x00ffffff,
    GRAY0   = 0x00333333,
    GRAY1   = 0x00aaaaaa,
    GRAY2   = 0x00dddddd,
    BLACK   = 0x00000000
};

int palette(Colour col) {
    switch (col) {
        case Colour::RED:
            return 0;
        case Colour::GREEN:
            return 1;
        case Colour::BLUE:
            return 2;
        case Colour::WHITE:
            return 3;
        case Colour::GRAY0:
            return 4;
        case Colour::GRAY1:
            return 5;
        case Colour::GRAY2:
            return 6;
        case Colour::BLACK:
            return 7;
        default:
            return -1;
    }
}
