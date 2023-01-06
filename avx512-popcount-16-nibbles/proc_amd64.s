#include "textflag.h"
#include "funcdata.h"
#include "go_asm.h"


#define CONST_DATA_U64(name, offset, value) DATA name<>+(offset)(SB)/8, value
#define CONST_GLOBAL(name, size) GLOBL name<>(SB), RODATA|NOPTR, size
#define CONST_GET_PTR(name, offset) name<>+(offset)(SB)


TEXT ·procedure(SB), NOSPLIT|NOFRAME, $0-8
    MOVQ        ctx+0(FP), R15
   
    // 1. Load 16 input nibbles (a 64-bit word)
    MOVQ context_input(R15), BX

    // 2. Populate the word 16 times
    VPBROADCASTQ    BX, Z10
    VMOVDQA64       Z10, Z11

    // 3. Load const nibbles: each 64-bit word contains different nibble
    VMOVDQU64       CONST_GET_PTR(equals_nibbles_lo, 0), Z20
    VMOVDQU64       CONST_GET_PTR(equals_nibbles_hi, 0), Z21

    // 4. Compare nibbles with XOR: a nibble is zero if it equals to the const nibble
    VPXORQ          Z10, Z20, Z20
    VPXORQ          Z11, Z21, Z21

    // 5. Turn zero nibbles into 0x1
    MOVQ            $0x7777777777777777, BX
    VPBROADCASTQ    BX, Z5              // Z5  = nibble(0x7)
    VPANDQ          Z20, Z5, Z22        // Z22 = lower 3 bits 
    VPADDQ          Z22, Z5, Z22        // Z22 = 3rd bits are set if any three lower bits were set
    VPTERNLOGQ      $0x01, Z5, Z22, Z20 // nibble: (~0x7 & ~(tmp | input)) = now 3rd bit is set if nibble was zero
    VPSRLQ          $3, Z20, Z20        // move 3rd bit to 0th position

    // repeat the same for the second reg
    VPANDQ          Z21, Z5, Z23
    VPADDQ          Z23, Z5, Z23
    VPTERNLOGQ      $0x01, Z5, Z23, Z21
    VPSRLQ          $3, Z21, Z21

    // 6. Perform popcount on nibbles at byte level; note that input bytes
    //    can only be: 0x00, 0x01, 0x10 or 0x11.
    VPXORQ          Z25, Z25, Z25
    VPSADBW         Z25, Z20, Z20
    VPSADBW         Z25, Z21, Z21

    // Note: We may first merge 16 x 64-bit values (that are have set only
    // lower 8 bits) into a single register. It requires some shuffling,
    // so it seems to not be worth doing.

    // 7. Add nibble popcounts
    MOVQ            $0x0f0f0f0f0f0f0f0f, BX
    VPBROADCASTQ    BX, Z5
    VPANDQ          Z20, Z5, Z22    // Z22 - lower nibble
    VPSRLQ          $4, Z20, Z20    // Z20 - higer nibble
    VPADDQ          Z20, Z22, Z20   // Z20 - sum of the nibbles: popcount

    VPANDQ          Z21, Z5, Z23    // Z23 - lower nibble
    VPSRLQ          $4, Z21, Z21    // Z21 - higer nibble
    VPADDQ          Z21, Z23, Z21   // Z21 - sum of the nibbles: popcount

end:
    // 8. Save results back
    VMOVDQU64       Z20,  0+context_output(R15)
    VMOVDQU64       Z21, 64+context_output(R15)

    RET

CONST_DATA_U64(equals_nibbles_lo, 0*8, $0x0000000000000000)
CONST_DATA_U64(equals_nibbles_lo, 1*8, $0x1111111111111111)
CONST_DATA_U64(equals_nibbles_lo, 2*8, $0x2222222222222222)
CONST_DATA_U64(equals_nibbles_lo, 3*8, $0x3333333333333333)
CONST_DATA_U64(equals_nibbles_lo, 4*8, $0x4444444444444444)
CONST_DATA_U64(equals_nibbles_lo, 5*8, $0x5555555555555555)
CONST_DATA_U64(equals_nibbles_lo, 6*8, $0x6666666666666666)
CONST_DATA_U64(equals_nibbles_lo, 7*8, $0x7777777777777777)
CONST_GLOBAL(equals_nibbles_lo, $64)

CONST_DATA_U64(equals_nibbles_hi, 0*8, $0x8888888888888888)
CONST_DATA_U64(equals_nibbles_hi, 1*8, $0x9999999999999999)
CONST_DATA_U64(equals_nibbles_hi, 2*8, $0xaaaaaaaaaaaaaaaa)
CONST_DATA_U64(equals_nibbles_hi, 3*8, $0xbbbbbbbbbbbbbbbb)
CONST_DATA_U64(equals_nibbles_hi, 4*8, $0xcccccccccccccccc)
CONST_DATA_U64(equals_nibbles_hi, 5*8, $0xdddddddddddddddd)
CONST_DATA_U64(equals_nibbles_hi, 6*8, $0xeeeeeeeeeeeeeeee)
CONST_DATA_U64(equals_nibbles_hi, 7*8, $0xffffffffffffffff)
CONST_GLOBAL(equals_nibbles_hi, $64)
