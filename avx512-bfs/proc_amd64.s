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
