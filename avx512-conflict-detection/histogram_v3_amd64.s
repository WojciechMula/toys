#include "textflag.h"
#include "funcdata.h"
#include "go_asm.h"

TEXT ·histogramV3Asm(SB), NOSPLIT|NOFRAME, $0-24
    // set constants

     VPTERNLOGD      $0xff, Z10, Z10, Z10
     VPABSD          Z10, Z10                // Z10 = uint32(1)

     // load parameters
     MOVQ            ptr+0(FP), R10          // R10 = &input[0]
     MOVQ            ptr2+8(FP), R11         // R10 = &input[0]
     MOVQ            count+16(FP), BX        // BX  = len(input)
     MOVQ            output+24(FP), R15      // R15 = &output[0]

     VMOVDQU32       (R11), Z2               // Z0 = input bins
     VPSLLD          $2, Z2, Z2
     XORQ            CX, CX

histogram_loop:
    // load input
    VMOVDQU32       (R10)(CX*4), Z0          // Z0 = input bins

    // calculate address: bin * (16*4) + sub-bucket index * 4
    VPSLLD          $6, Z0, Z0
    VPADDD          Z2, Z0, Z0

    // load partial conuter and update
    KXNORQ          K1, K1, K1
    KMOVQ           K1, K2
    VPXORD          Z1, Z1, Z1
    VPGATHERDD      (R15)(Z0*1), K1, Z1
    VPADDD          Z10, Z1, Z1
    VPSCATTERDD     Z1, K2, (R15)(Z0*1)

    // loop handling
    ADDQ            $16, CX
    CMPQ            CX, BX
    JB              histogram_loop

    RET
