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
