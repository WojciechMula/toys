#include "textflag.h"
#include "funcdata.h"
#include "go_asm.h"


TEXT ·avx512(SB), NOSPLIT|NOFRAME, $0-8
    MOVQ    ctx+0(FP), R15
    MOVL    context_input(R15), AX

    VPBROADCASTD    AX, X0

    // 1. ABSB
    VPABSB  X0, X1
    MOVL    X1, context_abs_byte(R15)

    // 2. ABSW
    VPABSW  X0, X1
    MOVL    X1, context_abs_word(R15)

    // 3. float32 to int32
    VCVTPS2DQ   X0, X1
    MOVL        X1, context_float32_to_int32(R15)

    // 4. int32 to float32
    VCVTDQ2PS   X0, X1
    MOVL        X1, context_int32_to_float32(R15)

    // 5. reciprocal 1/x
    VRCP14PS    X0, X1
    MOVL        X1, context_rcp_float32(R15)

    // 5. reciprocal 1/sqrt(x)
    VRSQRTPS    X0, X1
    MOVL        X1, context_rcp_sqrt_float32(R15)

end:
    RET
