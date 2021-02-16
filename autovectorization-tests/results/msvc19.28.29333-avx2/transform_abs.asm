__ymm@0b0a0908030201000b0a0908030201000b0a0908030201000b0a090803020100 DB 00H
        DB      01H, 02H, 03H, 08H, 09H, 0aH, 0bH, 00H, 01H, 02H, 03H, 08H, 09H
        DB      0aH, 0bH, 00H, 01H, 02H, 03H, 08H, 09H, 0aH, 0bH, 00H, 01H, 02H
        DB      03H, 08H, 09H, 0aH, 0bH
__ymm@000000000c080400000000000c080400000000000c080400000000000c080400 DB 00H
        DB      04H, 08H, 0cH, 00H, 00H, 00H, 00H, 00H, 04H, 08H, 0cH, 00H, 00H
        DB      00H, 00H, 00H, 04H, 08H, 0cH, 00H, 00H, 00H, 00H, 00H, 04H, 08H
        DB      0cH, 00H, 00H, 00H, 00H

_x$ = 8                                       ; size = 1
int <lambda_21e59dec347ca9de929daf396058ff70>::operator()(signed char)const  PROC ; <lambda_21e59dec347ca9de929daf396058ff70>::operator(), COMDAT
        movsx   eax, BYTE PTR _x$[esp-4]
        cdq
        xor     eax, edx
        sub     eax, edx
        ret     4
int <lambda_21e59dec347ca9de929daf396058ff70>::operator()(signed char)const  ENDP ; <lambda_21e59dec347ca9de929daf396058ff70>::operator()

_x$ = 8                                       ; size = 4
int <lambda_e1144f6ea261b1a44a9b01c165d42bf1>::operator()(int)const  PROC ; <lambda_e1144f6ea261b1a44a9b01c165d42bf1>::operator(), COMDAT
        mov     eax, DWORD PTR _x$[esp-4]
        cdq
        xor     eax, edx
        sub     eax, edx
        ret     4
int <lambda_e1144f6ea261b1a44a9b01c165d42bf1>::operator()(int)const  ENDP ; <lambda_e1144f6ea261b1a44a9b01c165d42bf1>::operator()

_v$ = 8                                       ; size = 4
void transform_abs_epi32(std::vector<int,std::allocator<int> > &) PROC ; transform_abs_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    ebx
        push    esi
        push    edi
        mov     ebx, DWORD PTR [eax+4]
        xor     edi, edi
        mov     ecx, DWORD PTR [eax]
        mov     edx, ebx
        sub     edx, ecx
        xor     eax, eax
        add     edx, 3
        mov     esi, ecx
        shr     edx, 2
        cmp     ecx, ebx
        cmova   edx, eax
        test    edx, edx
        je      SHORT $LN33@transform_
        cmp     edx, 32                             ; 00000020H
        jb      SHORT $LN33@transform_
        lea     eax, DWORD PTR [ecx-4]
        lea     eax, DWORD PTR [eax+edx*4]
        cmp     ecx, eax
        jbe     SHORT $LN33@transform_
        and     edx, -32                      ; ffffffe0H
        npad    9
$LL24@transform_:
        vpabsd  ymm0, YMMWORD PTR [ecx]
        vmovdqu YMMWORD PTR [esi], ymm0
        vpabsd  ymm0, YMMWORD PTR [ecx+32]
        vmovdqu YMMWORD PTR [esi+32], ymm0
        vpabsd  ymm0, YMMWORD PTR [ecx+64]
        vmovdqu YMMWORD PTR [esi+64], ymm0
        vpabsd  ymm0, YMMWORD PTR [ecx+96]
        vmovdqu YMMWORD PTR [esi+96], ymm0
        add     edi, 32                             ; 00000020H
        sub     esi, -128               ; ffffff80H
        sub     ecx, -128               ; ffffff80H
        cmp     edi, edx
        jne     SHORT $LL24@transform_
$LN33@transform_:
        cmp     ecx, ebx
        je      SHORT $LN23@transform_
        sub     esi, ecx
        npad    3
$LL32@transform_:
        mov     eax, DWORD PTR [ecx]
        cdq
        xor     eax, edx
        sub     eax, edx
        mov     DWORD PTR [esi+ecx], eax
        add     ecx, 4
        cmp     ecx, ebx
        jne     SHORT $LL32@transform_
$LN23@transform_:
        pop     edi
        pop     esi
        pop     ebx
        vzeroupper
        ret     0
void transform_abs_epi32(std::vector<int,std::allocator<int> > &) ENDP ; transform_abs_epi32

_v$ = 8                                       ; size = 4
void transform_abs_epi8(std::vector<signed char,std::allocator<signed char> > &) PROC ; transform_abs_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    ebx
        push    esi
        push    edi
        mov     edi, DWORD PTR [eax+4]
        xor     ebx, ebx
        mov     ecx, DWORD PTR [eax]
        mov     edx, edi
        sub     edx, ecx
        xor     eax, eax
        cmp     ecx, edi
        mov     esi, ecx
        cmova   edx, eax
        test    edx, edx
        je      $LN33@transform_
        cmp     edx, 32                             ; 00000020H
        jb      $LN33@transform_
        lea     eax, DWORD PTR [ecx-1]
        add     eax, edx
        cmp     ecx, eax
        jbe     $LN33@transform_
        and     edx, -32                      ; ffffffe0H
        npad    4
$LL24@transform_:
        vmovq   xmm0, QWORD PTR [ecx]
        vpmovsxbd ymm0, xmm0
        vpabsd  ymm0, ymm0
        vpshufb ymm0, ymm0, YMMWORD PTR __ymm@000000000c080400000000000c080400000000000c080400000000000c080400
        vpermq  ymm0, ymm0, 216                   ; 000000d8H
        vpshufb ymm0, ymm0, YMMWORD PTR __ymm@0b0a0908030201000b0a0908030201000b0a0908030201000b0a090803020100
        vextracti128 xmm0, ymm0, 0
        vmovq   QWORD PTR [esi], xmm0
        vmovq   xmm0, QWORD PTR [ecx+8]
        vpmovsxbd ymm0, xmm0
        vpabsd  ymm0, ymm0
        vpshufb ymm0, ymm0, YMMWORD PTR __ymm@000000000c080400000000000c080400000000000c080400000000000c080400
        vpermq  ymm0, ymm0, 216                   ; 000000d8H
        vpshufb ymm0, ymm0, YMMWORD PTR __ymm@0b0a0908030201000b0a0908030201000b0a0908030201000b0a090803020100
        vextracti128 xmm0, ymm0, 0
        vmovq   QWORD PTR [esi+8], xmm0
        vmovq   xmm0, QWORD PTR [ecx+16]
        vpmovsxbd ymm0, xmm0
        vpabsd  ymm0, ymm0
        vpshufb ymm0, ymm0, YMMWORD PTR __ymm@000000000c080400000000000c080400000000000c080400000000000c080400
        vpermq  ymm0, ymm0, 216                   ; 000000d8H
        vpshufb ymm0, ymm0, YMMWORD PTR __ymm@0b0a0908030201000b0a0908030201000b0a0908030201000b0a090803020100
        vextracti128 xmm0, ymm0, 0
        vmovq   QWORD PTR [esi+16], xmm0
        vmovq   xmm0, QWORD PTR [ecx+24]
        vpmovsxbd ymm0, xmm0
        vpabsd  ymm0, ymm0
        vpshufb ymm0, ymm0, YMMWORD PTR __ymm@000000000c080400000000000c080400000000000c080400000000000c080400
        vpermq  ymm0, ymm0, 216                   ; 000000d8H
        vpshufb ymm0, ymm0, YMMWORD PTR __ymm@0b0a0908030201000b0a0908030201000b0a0908030201000b0a090803020100
        vextracti128 xmm0, ymm0, 0
        vmovq   QWORD PTR [esi+24], xmm0
        add     ebx, 32                             ; 00000020H
        add     esi, 32                             ; 00000020H
        add     ecx, 32                             ; 00000020H
        cmp     ebx, edx
        jne     $LL24@transform_
$LN33@transform_:
        cmp     ecx, edi
        je      SHORT $LN23@transform_
        sub     esi, ecx
        npad    3
$LL32@transform_:
        movsx   eax, BYTE PTR [ecx]
        cdq
        xor     eax, edx
        sub     eax, edx
        mov     BYTE PTR [esi+ecx], al
        inc     ecx
        cmp     ecx, edi
        jne     SHORT $LL32@transform_
$LN23@transform_:
        pop     edi
        pop     esi
        pop     ebx
        vzeroupper
        ret     0
void transform_abs_epi8(std::vector<signed char,std::allocator<signed char> > &) ENDP ; transform_abs_epi8
