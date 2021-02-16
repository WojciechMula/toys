__ymm@2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a DB '*'
        DB      '*******************************'
__ymm@0000002a0000002a0000002a0000002a0000002a0000002a0000002a0000002a DB '*'
        DB      00H, 00H, 00H, '*', 00H, 00H, 00H, '*', 00H, 00H, 00H, '*', 00H
        DB      00H, 00H, '*', 00H, 00H, 00H, '*', 00H, 00H, 00H, '*', 00H, 00H
        DB      00H, '*', 00H, 00H, 00H

_x$ = 8                                       ; size = 1
int <lambda_f3afbc86506e0312b90066281c1f0bbd>::operator()(signed char)const  PROC ; <lambda_f3afbc86506e0312b90066281c1f0bbd>::operator(), COMDAT
        movsx   eax, BYTE PTR _x$[esp-4]
        add     eax, 42                             ; 0000002aH
        ret     4
int <lambda_f3afbc86506e0312b90066281c1f0bbd>::operator()(signed char)const  ENDP ; <lambda_f3afbc86506e0312b90066281c1f0bbd>::operator()

_x$ = 8                                       ; size = 4
int <lambda_9e76ea6a3a10c252a1a3eb944ba013e5>::operator()(int)const  PROC ; <lambda_9e76ea6a3a10c252a1a3eb944ba013e5>::operator(), COMDAT
        mov     eax, DWORD PTR _x$[esp-4]
        add     eax, 42                             ; 0000002aH
        ret     4
int <lambda_9e76ea6a3a10c252a1a3eb944ba013e5>::operator()(int)const  ENDP ; <lambda_9e76ea6a3a10c252a1a3eb944ba013e5>::operator()

_v$ = 8                                       ; size = 4
void transform_inc_epi32(std::vector<int,std::allocator<int> > &) PROC ; transform_inc_epi32, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        push    ebx
        push    esi
        push    edi
        mov     edi, DWORD PTR [ecx+4]
        xor     ebx, ebx
        mov     eax, DWORD PTR [ecx]
        mov     esi, edi
        sub     esi, eax
        xor     ecx, ecx
        add     esi, 3
        mov     edx, eax
        shr     esi, 2
        cmp     eax, edi
        cmova   esi, ecx
        test    esi, esi
        je      SHORT $LN31@transform_
        cmp     esi, 32                             ; 00000020H
        jb      SHORT $LN31@transform_
        lea     ecx, DWORD PTR [eax-4]
        lea     ecx, DWORD PTR [ecx+esi*4]
        cmp     eax, ecx
        jbe     SHORT $LN31@transform_
        vmovdqu ymm1, YMMWORD PTR __ymm@0000002a0000002a0000002a0000002a0000002a0000002a0000002a0000002a
        and     esi, -32                      ; ffffffe0H
        npad    1
$LL24@transform_:
        vpaddd  ymm0, ymm1, YMMWORD PTR [eax]
        vmovdqu YMMWORD PTR [edx], ymm0
        vpaddd  ymm0, ymm1, YMMWORD PTR [eax+32]
        vmovdqu YMMWORD PTR [edx+32], ymm0
        vpaddd  ymm0, ymm1, YMMWORD PTR [eax+64]
        vmovdqu YMMWORD PTR [edx+64], ymm0
        vpaddd  ymm0, ymm1, YMMWORD PTR [eax+96]
        vmovdqu YMMWORD PTR [edx+96], ymm0
        add     ebx, 32                             ; 00000020H
        sub     edx, -128               ; ffffff80H
        sub     eax, -128               ; ffffff80H
        cmp     ebx, esi
        jne     SHORT $LL24@transform_
$LN31@transform_:
        cmp     eax, edi
        je      SHORT $LN23@transform_
        sub     edx, eax
        npad    7
$LL30@transform_:
        mov     ecx, DWORD PTR [eax]
        add     ecx, 42                             ; 0000002aH
        mov     DWORD PTR [edx+eax], ecx
        add     eax, 4
        cmp     eax, edi
        jne     SHORT $LL30@transform_
$LN23@transform_:
        pop     edi
        pop     esi
        pop     ebx
        vzeroupper
        ret     0
void transform_inc_epi32(std::vector<int,std::allocator<int> > &) ENDP ; transform_inc_epi32

_v$ = 8                                       ; size = 4
void transform_inc_epi8(std::vector<signed char,std::allocator<signed char> > &) PROC ; transform_inc_epi8, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        push    ebx
        push    esi
        push    edi
        mov     edi, DWORD PTR [ecx+4]
        xor     ebx, ebx
        mov     eax, DWORD PTR [ecx]
        mov     esi, edi
        sub     esi, eax
        xor     ecx, ecx
        cmp     eax, edi
        mov     edx, eax
        cmova   esi, ecx
        test    esi, esi
        je      SHORT $LN33@transform_
        cmp     esi, 128                      ; 00000080H
        jb      SHORT $LN33@transform_
        lea     ecx, DWORD PTR [eax-1]
        add     ecx, esi
        cmp     eax, ecx
        jbe     SHORT $LN33@transform_
        vmovdqu ymm1, YMMWORD PTR __ymm@2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a2a
        and     esi, -128               ; ffffff80H
        npad    5
$LL24@transform_:
        vpaddb  ymm0, ymm1, YMMWORD PTR [eax]
        vmovdqu YMMWORD PTR [edx], ymm0
        vpaddb  ymm0, ymm1, YMMWORD PTR [eax+32]
        vmovdqu YMMWORD PTR [edx+32], ymm0
        vpaddb  ymm0, ymm1, YMMWORD PTR [eax+64]
        vmovdqu YMMWORD PTR [edx+64], ymm0
        vpaddb  ymm0, ymm1, YMMWORD PTR [eax+96]
        vmovdqu YMMWORD PTR [edx+96], ymm0
        sub     ebx, -128               ; ffffff80H
        sub     edx, -128               ; ffffff80H
        sub     eax, -128               ; ffffff80H
        cmp     ebx, esi
        jne     SHORT $LL24@transform_
$LN33@transform_:
        cmp     eax, edi
        je      SHORT $LN23@transform_
        sub     edx, eax
        npad    7
$LL32@transform_:
        mov     cl, BYTE PTR [eax]
        add     cl, 42                                    ; 0000002aH
        mov     BYTE PTR [edx+eax], cl
        inc     eax
        cmp     eax, edi
        jne     SHORT $LL32@transform_
$LN23@transform_:
        pop     edi
        pop     esi
        pop     ebx
        vzeroupper
        ret     0
void transform_inc_epi8(std::vector<signed char,std::allocator<signed char> > &) ENDP ; transform_inc_epi8
