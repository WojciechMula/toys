__ymm@0000002a0000002a0000002a0000002a0000002a0000002a0000002a0000002a DB '*'
        DB      00H, 00H, 00H, '*', 00H, 00H, 00H, '*', 00H, 00H, 00H, '*', 00H
        DB      00H, 00H, '*', 00H, 00H, 00H, '*', 00H, 00H, 00H, '*', 00H, 00H
        DB      00H, '*', 00H, 00H, 00H
__ymm@0000000100000001000000010000000100000001000000010000000100000001 DB 01H
        DB      00H, 00H, 00H, 01H, 00H, 00H, 00H, 01H, 00H, 00H, 00H, 01H, 00H
        DB      00H, 00H, 01H, 00H, 00H, 00H, 01H, 00H, 00H, 00H, 01H, 00H, 00H
        DB      00H, 01H, 00H, 00H, 00H

_v$ = 8                                       ; size = 4
unsigned int count_epi32(std::vector<int,std::allocator<int> > const &) PROC ; count_epi32, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        xor     edx, edx
        vmovdqu ymm6, YMMWORD PTR __ymm@0000002a0000002a0000002a0000002a0000002a0000002a0000002a0000002a
        push    ebx
        push    esi
        mov     esi, DWORD PTR [ecx+4]
        xor     ebx, ebx
        mov     ecx, DWORD PTR [ecx]
        mov     eax, esi
        sub     eax, ecx
        add     eax, 3
        shr     eax, 2
        push    edi
        xor     edi, edi
        cmp     ecx, esi
        cmova   eax, ebx
        test    eax, eax
        je      SHORT $LN21@count_epi3
        cmp     eax, 16                             ; 00000010H
        jb      SHORT $LN21@count_epi3
        vmovdqu ymm5, YMMWORD PTR __ymm@0000000100000001000000010000000100000001000000010000000100000001
        and     eax, -16                      ; fffffff0H
        vpxor   xmm3, xmm3, xmm3
        vpxor   xmm4, xmm4, xmm4
        npad    11
$LL14@count_epi3:
        vpcmpeqd ymm2, ymm6, YMMWORD PTR [ecx]
        vpaddd  ymm0, ymm5, ymm3
        vpand   ymm0, ymm0, ymm2
        vpandn  ymm1, ymm2, ymm3
        vpcmpeqd ymm2, ymm6, YMMWORD PTR [ecx+32]
        vpor    ymm3, ymm0, ymm1
        vpaddd  ymm0, ymm5, ymm4
        add     edi, 16                             ; 00000010H
        add     ecx, 64                             ; 00000040H
        vpandn  ymm1, ymm2, ymm4
        vpand   ymm0, ymm0, ymm2
        vpor    ymm4, ymm0, ymm1
        cmp     edi, eax
        jne     SHORT $LL14@count_epi3
        vpaddd  ymm0, ymm4, ymm3
        vphaddd ymm0, ymm0, ymm0
        vphaddd ymm1, ymm0, ymm0
        vextracti128 xmm0, ymm1, 1
        vpaddd  xmm0, xmm1, xmm0
        vmovd   edx, xmm0
$LN21@count_epi3:
        cmp     ecx, esi
        je      SHORT $LN28@count_epi3
$LL19@count_epi3:
        cmp     DWORD PTR [ecx], 42                 ; 0000002aH
        lea     eax, DWORD PTR [edx+1]
        cmovne  eax, edx
        add     ecx, 4
        mov     edx, eax
        cmp     ecx, esi
        jne     SHORT $LL19@count_epi3
$LN28@count_epi3:
        pop     edi
        pop     esi
        mov     eax, edx
        pop     ebx
        vzeroupper
        ret     0
unsigned int count_epi32(std::vector<int,std::allocator<int> > const &) ENDP ; count_epi32

_v$ = 8                                       ; size = 4
unsigned int count_epi8(std::vector<signed char,std::allocator<signed char> > const &) PROC ; count_epi8, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        xor     edx, edx
        vmovdqu ymm6, YMMWORD PTR __ymm@0000002a0000002a0000002a0000002a0000002a0000002a0000002a0000002a
        push    ebx
        push    esi
        mov     esi, DWORD PTR [ecx+4]
        xor     ebx, ebx
        mov     ecx, DWORD PTR [ecx]
        mov     eax, esi
        sub     eax, ecx
        push    edi
        xor     edi, edi
        cmp     ecx, esi
        cmova   eax, ebx
        test    eax, eax
        je      SHORT $LN21@count_epi8
        cmp     eax, 16                             ; 00000010H
        jb      SHORT $LN21@count_epi8
        vmovdqu ymm5, YMMWORD PTR __ymm@0000000100000001000000010000000100000001000000010000000100000001
        and     eax, -16                      ; fffffff0H
        vpxor   xmm3, xmm3, xmm3
        vpxor   xmm4, xmm4, xmm4
        npad    1
$LL14@count_epi8:
        vmovq   xmm0, QWORD PTR [ecx]
        vpmovsxbd ymm0, xmm0
        vpcmpeqd ymm2, ymm0, ymm6
        vpaddd  ymm0, ymm5, ymm3
        vpand   ymm0, ymm0, ymm2
        vpandn  ymm1, ymm2, ymm3
        vpor    ymm3, ymm0, ymm1
        vmovq   xmm0, QWORD PTR [ecx+8]
        vpmovsxbd ymm0, xmm0
        vpcmpeqd ymm2, ymm0, ymm6
        vpaddd  ymm0, ymm5, ymm4
        add     edi, 16                             ; 00000010H
        add     ecx, 16                             ; 00000010H
        vpandn  ymm1, ymm2, ymm4
        vpand   ymm0, ymm0, ymm2
        vpor    ymm4, ymm0, ymm1
        cmp     edi, eax
        jne     SHORT $LL14@count_epi8
        vpaddd  ymm0, ymm4, ymm3
        vphaddd ymm0, ymm0, ymm0
        vphaddd ymm1, ymm0, ymm0
        vextracti128 xmm0, ymm1, 1
        vpaddd  xmm0, xmm1, xmm0
        vmovd   edx, xmm0
$LN21@count_epi8:
        cmp     ecx, esi
        je      SHORT $LN28@count_epi8
$LL19@count_epi8:
        cmp     BYTE PTR [ecx], 42                        ; 0000002aH
        lea     eax, DWORD PTR [edx+1]
        cmovne  eax, edx
        inc     ecx
        mov     edx, eax
        cmp     ecx, esi
        jne     SHORT $LL19@count_epi8
$LN28@count_epi8:
        pop     edi
        pop     esi
        mov     eax, edx
        pop     ebx
        vzeroupper
        ret     0
unsigned int count_epi8(std::vector<signed char,std::allocator<signed char> > const &) ENDP ; count_epi8
