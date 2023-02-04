#include "textflag.h"
#include "funcdata.h"
#include "go_asm.h"

TEXT ·procedure(SB), NOSPLIT|NOFRAME, $0-8
    MOVQ            ctx+0(FP), AX

    // 1. load values
    MOVL            $0x01010101, BX
    VPBROADCASTD    BX, Z11

    MOVL            $1, BX
    VPBROADCASTD    BX, Z12

    MOVL            context_word(AX), BX    // input data
    VPBROADCASTD    BX, Z0

    MOVL            context_char(AX), BX    // populated byte
    VPBROADCASTD    BX, Z1

    // 2. find bytes not equal          // Z0 = [aa|ff|aa|ff]
    VPXORD          Z0, Z1, Z0          // Z0 = [00|55|00|55]

    // 3. byte != input[i] ? 1 : 0
    VPMINUB         Z11, Z0, Z0         // Z0 = [00|01|00|01]

    // 4. negate it
    VPXORD          Z11, Z0, Z2         // Z2 = [01|00|01|00]

    // 5. build mask from 0 to the first bit set
    VPSUBD          Z12, Z2, Z0         // Z0 = [01|00|00|ff]
    VPANDND         Z0, Z2, Z0          // Z0 = [00|00|00|ff]

    // 6. count k leading zeros: the position of the first
    //    occurrence of byte 1 (from step #4) is
    //
    //          4 - (k / 8)
    //
    VPLZCNTD        Z0, Z0          // Z0 = k
    VPSRLD          $3, Z0, Z0      // Z0 = k / 8
    VPSLLD          $2, Z12, Z12    // Z12 = 4
    VPSUBD          Z0, Z12, Z0     // Z0 = 4 - (k / 8)

next:
    MOVL            X0, context_pos(AX)

    RET
