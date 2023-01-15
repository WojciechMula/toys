#include "textflag.h"
#include "funcdata.h"
#include "go_asm.h"

TEXT ·procedure(SB), NOSPLIT|NOFRAME, $0-8
    MOVQ            ctx+0(FP), AX

    MOVL            context_in(AX), BX  // load token operation
    VPBROADCASTD    BX, Z0              // broadcast the token
    VPXORD          Z1, Z1, Z1          // Z1 = 0.0, thus token response is ZERO_VALUE_TOKEN = 2
    VFIXUPIMMPS     $0, Z0, Z1, Z0

    MOVL            X0, context_u32(AX)
    MOVL            X0, context_f32(AX)

    RET
