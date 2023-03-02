#include "textflag.h"
#include "funcdata.h"
#include "go_asm.h"

/*
This code comes from the Intel's doc. See the exact reference in histogram.go.

vmovaps zmm4, all_1 // {1, 1, ..., 1}
vmovaps zmm5, all_negative_1
vmovaps zmm6, all_31
vmovaps zmm7, all_bins_minus_1  // [wmu] skipped, as we assume inputs are already valid
mov ebx, num_inputs
mov r10, pInput
mov r15, pHistogram
xor rcx, rcx
histogram_loop:
vpandd zmm3, zmm7, [r10+rcx*4]  // [wmu] replaced with simple MOV [BTW: here is a silent assumption ptr is aligned]
vpconflictd zmm0, zmm3
kxnorw k1, k1, k1
vmovaps zmm2, zmm4
vpxord zmm1, zmm1, zmm1
vpgatherdd zmm1{k1}, [r15+zmm3*4]
vptestmd k1, zmm0, zmm0
kortestw k1, k1
je update
vplzcntd zmm0, zmm0
vpsubd zmm0, zmm6, zmm0
conflict_loop:
vpermd zmm8{k1}{z}, zmm0, zmm2
vpermd zmm0{k1}, zmm0, zmm0
vpaddd zmm2{k1}, zmm2, zmm8
vpcmpned k1, zmm5, zmm0             // [wmu] Go asm does not support this mnemonic; we use VPCMPD $4, ...   // $4 = NE
kortestw k1, k1
jne conflict_loop
update:
vpaddd zmm0, zmm2, zmm1
kxnorw k1, k1, k1
add rcx, 16
vpscatterdd [r15+zmm3*4]{k1}, zmm0
cmp ecx, ebx
jb histogram_loop
*/

TEXT ·histogramIntelAsm(SB), NOSPLIT|NOFRAME, $0-32
    // set constants
    VPTERNLOGD  $0xff, Z5, Z5, Z5       // Z5 = uint32(0xffffffff) = int32(-1)
    VPABSD      Z5, Z4                  // Z4 = uint32(1)
    VPSRLD      $27, Z5, Z6             // Z6 = 31

    // load parameters
    MOVQ        ptr+0(FP), R10          // R10 = &input[0]
    MOVQ        count+8(FP), BX         // BX  = len(input)
    MOVQ        output+16(FP), R15      // R15 = &output[0]

    XORQ        CX, CX

histogram_loop:
    VMOVDQU32   0(R10)(CX*4), Z3        // Z3 = next chunk
    VPCONFLICTD Z3, Z0
    KXNORW      K1, K1, K1              // K1 = all ones
    VMOVDQA64   Z4, Z2
    VPXORD      Z1, Z1, Z1
    VPGATHERDD  0(R15)(Z3*4), K1, Z1    // Z1 = indices
    
    VPTESTMD    Z0, Z0, K1              // K1 = all conflict words are 0? no conficts then
    KORTESTW    K1, K1
    JZ          update

    VPLZCNTD    Z0, Z0
    VPSUBD      Z0, Z6, Z0

conflict_loop:
    VPERMD.Z    Z2, Z0, K1, Z8
    VPERMD      Z0, Z0, K1, Z0
    VPADDD      Z8, Z2, K1, Z2

    VPCMPD      $4, Z0, Z5, K1
    KORTESTW    K1, K1
    JNE         conflict_loop

update:
    VPADDD      Z1, Z2, Z0
    KXNORW      K1, K1, K1
    ADDQ        $16, CX
    VPSCATTERDD Z0, K1, 0(R15)(Z3*4)
    CMPQ        CX, BX
    JB          histogram_loop

    RET

