#include "textflag.h"
#include "funcdata.h"
#include "go_asm.h"

TEXT ·procedure(SB), NOSPLIT|NOFRAME, $0-8
    MOVQ            ctx+0(FP), AX

    MOVL            context_in(AX), BX  // load const
    VPBROADCASTD    BX, Z0
    VPXORD          Z7, Z7, Z7
    VPAVGB          Z0, Z7, Z1
    VPAVGW          Z0, Z7, Z2

    MOVL            X1, context_avgb(AX)
    MOVL            X2, context_avgw(AX)

    RET
