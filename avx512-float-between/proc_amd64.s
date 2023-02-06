#include "textflag.h"
#include "funcdata.h"
#include "go_asm.h"

TEXT ·procedure1(SB), NOSPLIT|NOFRAME, $0-8
    MOVQ            ctx+0(FP), AX

    // load data
    MOVQ            context_x(AX), X0
    MOVQ            context_a(AX), X1 // a = (min + max) / 2 -- the middle of the range
    MOVQ            context_b(AX), X2 // b = (max - min) / 2 -- the half of range span

    MOVQ            $0x7fffffffffffffff, BX
    VPBROADCASTQ    BX, Z10            

    // x -= a
    VSUBPD          Z1, Z0, Z0

    // x = abs(x)
    VANDPD          Z10, Z0, Z0

    // x <= b?     
    VCMPPD          $0x12, Z2, Z0, K1   // 0x12 = less-then-or-equal (ordered, non-signaling)

    // read the LSB of mask
    KMOVW           K1, BX
    ANDL            $1, BX

    MOVB            BL, context_inrange(AX)

    RET


TEXT ·procedure2(SB), NOSPLIT|NOFRAME, $0-8
    MOVQ            ctx+0(FP), AX

    // load data
    MOVQ            context_x(AX), X0
    MOVQ            context_a(AX), X1 // a = min
    MOVQ            context_b(AX), X2 // b = max

    // x <= b?     
    VCMPPD          $0x12, Z2, Z0, K1       // 0x12 = less-then-or-equal (ordered, non-signaling)
    VCMPPD          $0x1d, Z1, Z0, K1, K1   // 0x1d = greater-then-or-equal (ordered, non-signaling)

    // read the LSB of mask
    KMOVW           K1, BX
    ANDL            $1, BX

    MOVB            BL, context_inrange(AX)

    RET
