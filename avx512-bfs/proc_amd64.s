#include "textflag.h"
#include "funcdata.h"
#include "go_asm.h"

TEXT ·procedure1(SB), NOSPLIT|NOFRAME, $0-8
    MOVQ            ctx+0(FP), AX

    // load consts
    MOVL            $0x0f0f0f0f, BX
    VPBROADCASTD    BX, Z10

    MOVL            $4, BX
    VPBROADCASTD    BX, Z11             // Z11 = 4

    MOVL            $0xfffffffc, BX
    VPBROADCASTD    BX, Z12             // Z12 = 0xfffffffc = mask out two lowest bits

    // load input
    MOVL            context_in(AX), BX  // load const
    VPBROADCASTD    BX, Z0              // Z0 = |a1|b2|c3|d4|...
    VPTESTMD        Z0, Z0, K1          // K1 = mask for zeros

    // 1. swap nibbles
    VPANDD          Z0, Z10, Z1         // Z1 = |01|02|03|04|...
    VPSLLD          $4, Z1, Z1          // Z1 = |10|20|30|40|...
    VPSRLD          $4, Z0, Z0          // Z0 = |0a|1b|2c|3d|
    VPTERNLOGD      $0xec, Z10, Z1, Z0  // Z0 = (Z10 and Z0) or Z1
                                        //    = |1a|2b|3c|4d|...

    // 2. swap bytes
    VBROADCASTF32X4 bswap32<>(SB), Z10
    VPSHUFB         Z10, Z0, Z0         // Z0 = |4d|2b|3c|4d|...

    // 3. count leading zeros
    VPLZCNTD        Z0, Z1              // n = lzcnt
    VPANDD          Z1, Z12, Z1         // n = (lzcnt/4)*4

    // 4. move the first non-zero nibble to 0th position
    VPSLLVD         Z1, Z0, Z0
    VPSRLD          $28, Z0, Z0

    // 5. lookup BFS for the nibble (0 for 0 input)
    VMOVDQU32.Z     bfs<>(SB), K1, Z10
    VPERMD          Z10, Z0, Z0
    VPADDD          Z1, Z0, Z0

    //
    MOVL            X0, context_bfs(AX)

    RET


TEXT ·procedure2(SB), NOSPLIT|NOFRAME, $0-8
    MOVQ            ctx+0(FP), AX

    // 0. preload constants
    MOVL            $4, BX
    VPBROADCASTD    BX, Z11             // Z11 = 4

    MOVL            $0xfffffff8, BX
    VPBROADCASTD    BX, Z12             // Z12 = 0xfffffff8 = mask out three lowest bits

    MOVL            $0x0000000f, BX
    VPBROADCASTD    BX, Z13             // Z13 = mask lower nibble

    VBROADCASTF32X4 bswap32<>(SB), Z10  // Z10 = bswap

    //
    MOVL            context_in(AX), BX  // load input
    VPBROADCASTD    BX, Z0              // Z0 = |a1|b2|c3|d4|...
    VPTESTMD        Z0, Z0, K1          // K1 = mask for zeros

    // 1. swap bytes
    VPSHUFB         Z10, Z0, Z0         // Z0 = |4d|2b|3c|4d|...

    // 2. count leading zeros
    VPLZCNTD        Z0, Z1              // n = lzcnt
    VPANDD          Z1, Z12, Z1         // n = (lzcnt/8)*8

    // 3. move the first non-zero byte to 0th position
    VPSLLVD         Z1, Z0, Z0
    VPSRLD          $24, Z0, Z0

    // 4. shift right lower nibble if zero
    VPTESTNMD       Z0, Z13, K1, K2
    VPSRLD          $4, Z0, K2, Z0

    // 5. lookup BFS for the nibble (0 for 0 input)
    VMOVDQU32.Z     bfs<>(SB), K1, Z10
    VPERMD          Z10, Z0, Z0
    VPADDD          Z1, Z0, Z0
    VPADDD          Z11, Z0, K2, Z0     // add 4 if shifted zero nibble out

    //
next:
    MOVL            X0, context_bfs(AX)

    RET


TEXT ·procedure3(SB), NOSPLIT|NOFRAME, $0-8
    MOVQ            ctx+0(FP), AX

    // 0. preload constants
    MOVL            $16, BX
    VPBROADCASTD    BX, Z10             // shift right amount

    MOVL            $0x0000ffff, BX
    VPBROADCASTD    BX, Z11             // lower half of a word

    MOVL            $32, BX
    VPBROADCASTD    BX, Z12

    //
    MOVL            context_in(AX), BX  // load input
    VPBROADCASTD    BX, Z0              // Z0 = |a1|b2|c3|d4|...
    VPTESTMD        Z0, Z0, K1          // K1 = mask for zero elements

    VPXORD          Z1, Z1, Z1          // BFS = 0

    // 1. check lower 16 bits
    VPTESTNMD       Z0, Z11, K2
    VPSRLVD         Z10, Z0, K2, Z0
    VPADDD          Z10, Z1, K2, Z1
    VPSRLD          $8, Z11, Z11        // Z11 = 0x000000ff
    VPSRLD          $1, Z10, Z10        // Z10 = 8

    // 2. check lower 8 bits
    VPTESTNMD       Z0, Z11, K2
    VPSRLVD         Z10, Z0, K2, Z0
    VPADDD          Z10, Z1, K2, Z1
    VPSRLD          $4, Z11, Z11        // Z11 = 0x0000000f
    VPSRLD          $1, Z10, Z10        // Z10 = 4

    // 3. check lower 4 bits
    VPTESTNMD       Z0, Z11, K2
    VPSRLVD         Z10, Z0, K2, Z0
    VPADDD          Z10, Z1, K2, Z1

    // 4. lookup BFS for the nibble (0 for 0 input)
    VMOVDQU32       bfs<>(SB), Z10
    VPERMD          Z10, Z0, Z0
    VPADDD          Z1, Z0, Z0

next:
    MOVL            X0, context_bfs(AX)

    RET

// LUT for 32-bit bswap
DATA bswap32<>+(4*0)(SB)/4, $0x00010203 // single 128-bit lane
DATA bswap32<>+(4*1)(SB)/4, $0x04050607
DATA bswap32<>+(4*2)(SB)/4, $0x08090a0b
DATA bswap32<>+(4*3)(SB)/4, $0x0c0d0e0f
GLOBL bswap32<>(SB), RODATA|NOPTR, $16

// LUT for bfs on a single nibble
DATA bfs<>+(4*0x00)(SB)/4,  $4 // 0000
DATA bfs<>+(4*0x01)(SB)/4,  $0 // 0001
DATA bfs<>+(4*0x02)(SB)/4,  $1 // 0010
DATA bfs<>+(4*0x03)(SB)/4,  $0 // 0011
DATA bfs<>+(4*0x04)(SB)/4,  $2 // 0100
DATA bfs<>+(4*0x05)(SB)/4,  $0 // 0101
DATA bfs<>+(4*0x06)(SB)/4,  $1 // 0110
DATA bfs<>+(4*0x07)(SB)/4,  $0 // 0111
DATA bfs<>+(4*0x08)(SB)/4,  $3 // 1000
DATA bfs<>+(4*0x09)(SB)/4,  $0 // 1001
DATA bfs<>+(4*0x0a)(SB)/4,  $1 // 1010
DATA bfs<>+(4*0x0b)(SB)/4,  $0 // 1011
DATA bfs<>+(4*0x0c)(SB)/4,  $2 // 1100
DATA bfs<>+(4*0x0d)(SB)/4,  $0 // 1101
DATA bfs<>+(4*0x0e)(SB)/4,  $1 // 1110
DATA bfs<>+(4*0x0f)(SB)/4,  $0 // 1111
GLOBL bfs<>(SB), RODATA|NOPTR, $64


TEXT ·procedure4(SB), NOSPLIT|NOFRAME, $0-8
    MOVQ            ctx+0(FP), AX

    // load consts
    MOVL            $0x0f0f0f0f, BX
    VPBROADCASTD    BX, Z10

    VBROADCASTF32X4 swapbitslo<>(SB), Z11
    VBROADCASTF32X4 swapbitshi<>(SB), Z12
    VBROADCASTF32X4 bswap32<>(SB), Z13

    // load input
    MOVL            context_in(AX), BX  // load const
    VPBROADCASTD    BX, Z0              // Z0 = |a1|b2|c3|d4|...

    // 1. separate lo and hi nibbles
    VPANDD          Z0, Z10, Z1         // Z1 = |01|02|03|04|... -- lo nibbles
    VPSRLD          $4, Z0, Z2          //
    VPANDD          Z2, Z10, Z2         // Z2 = |0a|0b|0c|0d|... -- hi nibbles

    // 2. swap bits in lo nibbles & hi nibbles
    VPSHUFB         Z1, Z11, Z1
    VPSHUFB         Z2, Z12, Z2
    VPORD           Z1, Z2, Z0

    // 3. swap bytes
    VPSHUFB         Z13, Z0, Z0

    // 4. count leading zeros
    VPLZCNTD        Z0, Z0              // n = lzcnt

    //
next:
    MOVL            X0, context_bfs(AX)

    RET

// swap bits in nibble and SHIFT LEFT by 4 bits
DATA swapbitslo<>+(0x00)(SB)/1, $0x00 // 0000 => 0000
DATA swapbitslo<>+(0x01)(SB)/1, $0x80 // 0001 => 1000
DATA swapbitslo<>+(0x02)(SB)/1, $0x40 // 0010 => 0100
DATA swapbitslo<>+(0x03)(SB)/1, $0xc0 // 0011 => 1100
DATA swapbitslo<>+(0x04)(SB)/1, $0x20 // 0100 => 0010
DATA swapbitslo<>+(0x05)(SB)/1, $0xa0 // 0101 => 1010
DATA swapbitslo<>+(0x06)(SB)/1, $0x60 // 0110 => 0110
DATA swapbitslo<>+(0x07)(SB)/1, $0xe0 // 0111 => 1110
DATA swapbitslo<>+(0x08)(SB)/1, $0x10 // 1000 => 0001
DATA swapbitslo<>+(0x09)(SB)/1, $0x90 // 1001 => 1001
DATA swapbitslo<>+(0x0a)(SB)/1, $0x50 // 1010 => 0101
DATA swapbitslo<>+(0x0b)(SB)/1, $0xd0 // 1011 => 1101
DATA swapbitslo<>+(0x0c)(SB)/1, $0x30 // 1100 => 0011
DATA swapbitslo<>+(0x0d)(SB)/1, $0xb0 // 1101 => 1011
DATA swapbitslo<>+(0x0e)(SB)/1, $0x70 // 1110 => 0111
DATA swapbitslo<>+(0x0f)(SB)/1, $0xf0 // 1111 => 1111
GLOBL swapbitslo<>(SB), RODATA|NOPTR, $16

// swap bits in nibble
DATA swapbitshi<>+(0x00)(SB)/1, $0x00 // 0000 => 0000
DATA swapbitshi<>+(0x01)(SB)/1, $0x08 // 0001 => 1000
DATA swapbitshi<>+(0x02)(SB)/1, $0x04 // 0010 => 0100
DATA swapbitshi<>+(0x03)(SB)/1, $0x0c // 0011 => 1100
DATA swapbitshi<>+(0x04)(SB)/1, $0x02 // 0100 => 0010
DATA swapbitshi<>+(0x05)(SB)/1, $0x0a // 0101 => 1010
DATA swapbitshi<>+(0x06)(SB)/1, $0x06 // 0110 => 0110
DATA swapbitshi<>+(0x07)(SB)/1, $0x0e // 0111 => 1110
DATA swapbitshi<>+(0x08)(SB)/1, $0x01 // 1000 => 0001
DATA swapbitshi<>+(0x09)(SB)/1, $0x09 // 1001 => 1001
DATA swapbitshi<>+(0x0a)(SB)/1, $0x05 // 1010 => 0101
DATA swapbitshi<>+(0x0b)(SB)/1, $0x0d // 1011 => 1101
DATA swapbitshi<>+(0x0c)(SB)/1, $0x03 // 1100 => 0011
DATA swapbitshi<>+(0x0d)(SB)/1, $0x0b // 1101 => 1011
DATA swapbitshi<>+(0x0e)(SB)/1, $0x07 // 1110 => 0111
DATA swapbitshi<>+(0x0f)(SB)/1, $0x0f // 1111 => 1111
GLOBL swapbitshi<>(SB), RODATA|NOPTR, $16


TEXT ·procedure5(SB), NOSPLIT|NOFRAME, $0-8
    MOVQ            ctx+0(FP), AX

    // load consts
    MOVL            $0x01010101, BX
    VPBROADCASTD    BX, Z10

    VMOVDQU32 bitswap7<>+0(SB), Z11
    VMOVDQU32 bitswap7<>+64(SB), Z12
    VBROADCASTF32X4 bswap32<>(SB), Z13

    // load input
    MOVL            context_in(AX), BX  // load const
    VPBROADCASTD    BX, Z0              // Z0 = |a1|b2|c3|d4|...

    // 1. swap 7 lower bits
    VMOVDQA32       Z0, Z1
    VPERMI2B        Z12, Z11, Z0

    // 2. move 7th bit to 0th position
    VPSRLD          $7, Z1, Z1
    VPTERNLOGD      $0xea, Z0, Z1, Z10 // Z10 = (Z10 and Z1) or Z0

    // 3. swap bytes
    VPSHUFB         Z13, Z10, Z10

    // 4. count leading zeros
    VPLZCNTD        Z10, Z0              // n = lzcnt

    //
next:
    MOVL            X0, context_bfs(AX)

    RET


DATA bitswap7<>+0x00(SB)/1, $0x00 // 00000000 => 00000000
DATA bitswap7<>+0x01(SB)/1, $0x80 // 00000001 => 10000000
DATA bitswap7<>+0x02(SB)/1, $0x40 // 00000010 => 01000000
DATA bitswap7<>+0x03(SB)/1, $0xc0 // 00000011 => 11000000
DATA bitswap7<>+0x04(SB)/1, $0x20 // 00000100 => 00100000
DATA bitswap7<>+0x05(SB)/1, $0xa0 // 00000101 => 10100000
DATA bitswap7<>+0x06(SB)/1, $0x60 // 00000110 => 01100000
DATA bitswap7<>+0x07(SB)/1, $0xe0 // 00000111 => 11100000
DATA bitswap7<>+0x08(SB)/1, $0x10 // 00001000 => 00010000
DATA bitswap7<>+0x09(SB)/1, $0x90 // 00001001 => 10010000
DATA bitswap7<>+0x0a(SB)/1, $0x50 // 00001010 => 01010000
DATA bitswap7<>+0x0b(SB)/1, $0xd0 // 00001011 => 11010000
DATA bitswap7<>+0x0c(SB)/1, $0x30 // 00001100 => 00110000
DATA bitswap7<>+0x0d(SB)/1, $0xb0 // 00001101 => 10110000
DATA bitswap7<>+0x0e(SB)/1, $0x70 // 00001110 => 01110000
DATA bitswap7<>+0x0f(SB)/1, $0xf0 // 00001111 => 11110000
DATA bitswap7<>+0x10(SB)/1, $0x08 // 00010000 => 00001000
DATA bitswap7<>+0x11(SB)/1, $0x88 // 00010001 => 10001000
DATA bitswap7<>+0x12(SB)/1, $0x48 // 00010010 => 01001000
DATA bitswap7<>+0x13(SB)/1, $0xc8 // 00010011 => 11001000
DATA bitswap7<>+0x14(SB)/1, $0x28 // 00010100 => 00101000
DATA bitswap7<>+0x15(SB)/1, $0xa8 // 00010101 => 10101000
DATA bitswap7<>+0x16(SB)/1, $0x68 // 00010110 => 01101000
DATA bitswap7<>+0x17(SB)/1, $0xe8 // 00010111 => 11101000
DATA bitswap7<>+0x18(SB)/1, $0x18 // 00011000 => 00011000
DATA bitswap7<>+0x19(SB)/1, $0x98 // 00011001 => 10011000
DATA bitswap7<>+0x1a(SB)/1, $0x58 // 00011010 => 01011000
DATA bitswap7<>+0x1b(SB)/1, $0xd8 // 00011011 => 11011000
DATA bitswap7<>+0x1c(SB)/1, $0x38 // 00011100 => 00111000
DATA bitswap7<>+0x1d(SB)/1, $0xb8 // 00011101 => 10111000
DATA bitswap7<>+0x1e(SB)/1, $0x78 // 00011110 => 01111000
DATA bitswap7<>+0x1f(SB)/1, $0xf8 // 00011111 => 11111000
DATA bitswap7<>+0x20(SB)/1, $0x04 // 00100000 => 00000100
DATA bitswap7<>+0x21(SB)/1, $0x84 // 00100001 => 10000100
DATA bitswap7<>+0x22(SB)/1, $0x44 // 00100010 => 01000100
DATA bitswap7<>+0x23(SB)/1, $0xc4 // 00100011 => 11000100
DATA bitswap7<>+0x24(SB)/1, $0x24 // 00100100 => 00100100
DATA bitswap7<>+0x25(SB)/1, $0xa4 // 00100101 => 10100100
DATA bitswap7<>+0x26(SB)/1, $0x64 // 00100110 => 01100100
DATA bitswap7<>+0x27(SB)/1, $0xe4 // 00100111 => 11100100
DATA bitswap7<>+0x28(SB)/1, $0x14 // 00101000 => 00010100
DATA bitswap7<>+0x29(SB)/1, $0x94 // 00101001 => 10010100
DATA bitswap7<>+0x2a(SB)/1, $0x54 // 00101010 => 01010100
DATA bitswap7<>+0x2b(SB)/1, $0xd4 // 00101011 => 11010100
DATA bitswap7<>+0x2c(SB)/1, $0x34 // 00101100 => 00110100
DATA bitswap7<>+0x2d(SB)/1, $0xb4 // 00101101 => 10110100
DATA bitswap7<>+0x2e(SB)/1, $0x74 // 00101110 => 01110100
DATA bitswap7<>+0x2f(SB)/1, $0xf4 // 00101111 => 11110100
DATA bitswap7<>+0x30(SB)/1, $0x0c // 00110000 => 00001100
DATA bitswap7<>+0x31(SB)/1, $0x8c // 00110001 => 10001100
DATA bitswap7<>+0x32(SB)/1, $0x4c // 00110010 => 01001100
DATA bitswap7<>+0x33(SB)/1, $0xcc // 00110011 => 11001100
DATA bitswap7<>+0x34(SB)/1, $0x2c // 00110100 => 00101100
DATA bitswap7<>+0x35(SB)/1, $0xac // 00110101 => 10101100
DATA bitswap7<>+0x36(SB)/1, $0x6c // 00110110 => 01101100
DATA bitswap7<>+0x37(SB)/1, $0xec // 00110111 => 11101100
DATA bitswap7<>+0x38(SB)/1, $0x1c // 00111000 => 00011100
DATA bitswap7<>+0x39(SB)/1, $0x9c // 00111001 => 10011100
DATA bitswap7<>+0x3a(SB)/1, $0x5c // 00111010 => 01011100
DATA bitswap7<>+0x3b(SB)/1, $0xdc // 00111011 => 11011100
DATA bitswap7<>+0x3c(SB)/1, $0x3c // 00111100 => 00111100
DATA bitswap7<>+0x3d(SB)/1, $0xbc // 00111101 => 10111100
DATA bitswap7<>+0x3e(SB)/1, $0x7c // 00111110 => 01111100
DATA bitswap7<>+0x3f(SB)/1, $0xfc // 00111111 => 11111100
DATA bitswap7<>+0x40(SB)/1, $0x02 // 01000000 => 00000010
DATA bitswap7<>+0x41(SB)/1, $0x82 // 01000001 => 10000010
DATA bitswap7<>+0x42(SB)/1, $0x42 // 01000010 => 01000010
DATA bitswap7<>+0x43(SB)/1, $0xc2 // 01000011 => 11000010
DATA bitswap7<>+0x44(SB)/1, $0x22 // 01000100 => 00100010
DATA bitswap7<>+0x45(SB)/1, $0xa2 // 01000101 => 10100010
DATA bitswap7<>+0x46(SB)/1, $0x62 // 01000110 => 01100010
DATA bitswap7<>+0x47(SB)/1, $0xe2 // 01000111 => 11100010
DATA bitswap7<>+0x48(SB)/1, $0x12 // 01001000 => 00010010
DATA bitswap7<>+0x49(SB)/1, $0x92 // 01001001 => 10010010
DATA bitswap7<>+0x4a(SB)/1, $0x52 // 01001010 => 01010010
DATA bitswap7<>+0x4b(SB)/1, $0xd2 // 01001011 => 11010010
DATA bitswap7<>+0x4c(SB)/1, $0x32 // 01001100 => 00110010
DATA bitswap7<>+0x4d(SB)/1, $0xb2 // 01001101 => 10110010
DATA bitswap7<>+0x4e(SB)/1, $0x72 // 01001110 => 01110010
DATA bitswap7<>+0x4f(SB)/1, $0xf2 // 01001111 => 11110010
DATA bitswap7<>+0x50(SB)/1, $0x0a // 01010000 => 00001010
DATA bitswap7<>+0x51(SB)/1, $0x8a // 01010001 => 10001010
DATA bitswap7<>+0x52(SB)/1, $0x4a // 01010010 => 01001010
DATA bitswap7<>+0x53(SB)/1, $0xca // 01010011 => 11001010
DATA bitswap7<>+0x54(SB)/1, $0x2a // 01010100 => 00101010
DATA bitswap7<>+0x55(SB)/1, $0xaa // 01010101 => 10101010
DATA bitswap7<>+0x56(SB)/1, $0x6a // 01010110 => 01101010
DATA bitswap7<>+0x57(SB)/1, $0xea // 01010111 => 11101010
DATA bitswap7<>+0x58(SB)/1, $0x1a // 01011000 => 00011010
DATA bitswap7<>+0x59(SB)/1, $0x9a // 01011001 => 10011010
DATA bitswap7<>+0x5a(SB)/1, $0x5a // 01011010 => 01011010
DATA bitswap7<>+0x5b(SB)/1, $0xda // 01011011 => 11011010
DATA bitswap7<>+0x5c(SB)/1, $0x3a // 01011100 => 00111010
DATA bitswap7<>+0x5d(SB)/1, $0xba // 01011101 => 10111010
DATA bitswap7<>+0x5e(SB)/1, $0x7a // 01011110 => 01111010
DATA bitswap7<>+0x5f(SB)/1, $0xfa // 01011111 => 11111010
DATA bitswap7<>+0x60(SB)/1, $0x06 // 01100000 => 00000110
DATA bitswap7<>+0x61(SB)/1, $0x86 // 01100001 => 10000110
DATA bitswap7<>+0x62(SB)/1, $0x46 // 01100010 => 01000110
DATA bitswap7<>+0x63(SB)/1, $0xc6 // 01100011 => 11000110
DATA bitswap7<>+0x64(SB)/1, $0x26 // 01100100 => 00100110
DATA bitswap7<>+0x65(SB)/1, $0xa6 // 01100101 => 10100110
DATA bitswap7<>+0x66(SB)/1, $0x66 // 01100110 => 01100110
DATA bitswap7<>+0x67(SB)/1, $0xe6 // 01100111 => 11100110
DATA bitswap7<>+0x68(SB)/1, $0x16 // 01101000 => 00010110
DATA bitswap7<>+0x69(SB)/1, $0x96 // 01101001 => 10010110
DATA bitswap7<>+0x6a(SB)/1, $0x56 // 01101010 => 01010110
DATA bitswap7<>+0x6b(SB)/1, $0xd6 // 01101011 => 11010110
DATA bitswap7<>+0x6c(SB)/1, $0x36 // 01101100 => 00110110
DATA bitswap7<>+0x6d(SB)/1, $0xb6 // 01101101 => 10110110
DATA bitswap7<>+0x6e(SB)/1, $0x76 // 01101110 => 01110110
DATA bitswap7<>+0x6f(SB)/1, $0xf6 // 01101111 => 11110110
DATA bitswap7<>+0x70(SB)/1, $0x0e // 01110000 => 00001110
DATA bitswap7<>+0x71(SB)/1, $0x8e // 01110001 => 10001110
DATA bitswap7<>+0x72(SB)/1, $0x4e // 01110010 => 01001110
DATA bitswap7<>+0x73(SB)/1, $0xce // 01110011 => 11001110
DATA bitswap7<>+0x74(SB)/1, $0x2e // 01110100 => 00101110
DATA bitswap7<>+0x75(SB)/1, $0xae // 01110101 => 10101110
DATA bitswap7<>+0x76(SB)/1, $0x6e // 01110110 => 01101110
DATA bitswap7<>+0x77(SB)/1, $0xee // 01110111 => 11101110
DATA bitswap7<>+0x78(SB)/1, $0x1e // 01111000 => 00011110
DATA bitswap7<>+0x79(SB)/1, $0x9e // 01111001 => 10011110
DATA bitswap7<>+0x7a(SB)/1, $0x5e // 01111010 => 01011110
DATA bitswap7<>+0x7b(SB)/1, $0xde // 01111011 => 11011110
DATA bitswap7<>+0x7c(SB)/1, $0x3e // 01111100 => 00111110
DATA bitswap7<>+0x7d(SB)/1, $0xbe // 01111101 => 10111110
DATA bitswap7<>+0x7e(SB)/1, $0x7e // 01111110 => 01111110
DATA bitswap7<>+0x7f(SB)/1, $0xfe // 01111111 => 11111110
GLOBL bitswap7<>(SB), RODATA|NOPTR, $128
