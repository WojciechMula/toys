_v$ = 8                                       ; size = 4
unsigned int accumulate_epi32(std::vector<int,std::allocator<int> > const &) PROC ; accumulate_epi32, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        xor     edx, edx
        push    ebx
        push    esi
        push    edi
        mov     edi, DWORD PTR [ecx+4]
        xor     ebx, ebx
        mov     ecx, DWORD PTR [ecx]
        mov     eax, edi
        sub     eax, ecx
        xor     esi, esi
        add     eax, 3
        shr     eax, 2
        cmp     ecx, edi
        cmova   eax, ebx
        test    eax, eax
        je      SHORT $LN23@accumulate
        cmp     eax, 16                             ; 00000010H
        jb      SHORT $LN23@accumulate
        and     eax, -16                      ; fffffff0H
        vpxor   xmm1, xmm1, xmm1
        vpxor   xmm2, xmm2, xmm2
        npad    11
$LL16@accumulate:
        vpaddd  ymm1, ymm1, YMMWORD PTR [ecx]
        vpaddd  ymm2, ymm2, YMMWORD PTR [ecx+32]
        add     esi, 16                             ; 00000010H
        add     ecx, 64                             ; 00000040H
        cmp     esi, eax
        jne     SHORT $LL16@accumulate
        vpaddd  ymm0, ymm1, ymm2
        vphaddd ymm0, ymm0, ymm0
        vphaddd ymm1, ymm0, ymm0
        vextracti128 xmm0, ymm1, 1
        vpaddd  xmm0, xmm1, xmm0
        vmovd   edx, xmm0
$LN23@accumulate:
        cmp     ecx, edi
        je      SHORT $LN29@accumulate
$LL22@accumulate:
        add     edx, DWORD PTR [ecx]
        add     ecx, 4
        cmp     ecx, edi
        jne     SHORT $LL22@accumulate
$LN29@accumulate:
        pop     edi
        pop     esi
        mov     eax, edx
        pop     ebx
        vzeroupper
        ret     0
unsigned int accumulate_epi32(std::vector<int,std::allocator<int> > const &) ENDP ; accumulate_epi32

_v$ = 8                                       ; size = 4
unsigned int accumulate_epi8(std::vector<signed char,std::allocator<signed char> > const &) PROC ; accumulate_epi8, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        xor     eax, eax
        push    ebx
        push    esi
        push    edi
        mov     edi, DWORD PTR [ecx+4]
        xor     ebx, ebx
        mov     ecx, DWORD PTR [ecx]
        mov     edx, edi
        sub     edx, ecx
        xor     esi, esi
        cmp     ecx, edi
        cmova   edx, ebx
        test    edx, edx
        je      SHORT $LN23@accumulate
        cmp     edx, 16                             ; 00000010H
        jb      SHORT $LN23@accumulate
        and     edx, -16                      ; fffffff0H
        vpxor   xmm1, xmm1, xmm1
        vpxor   xmm2, xmm2, xmm2
        npad    1
$LL16@accumulate:
        vmovq   xmm0, QWORD PTR [ecx]
        vpmovsxbd ymm0, xmm0
        vpaddd  ymm1, ymm0, ymm1
        vmovq   xmm0, QWORD PTR [ecx+8]
        add     esi, 16                             ; 00000010H
        add     ecx, 16                             ; 00000010H
        vpmovsxbd ymm0, xmm0
        vpaddd  ymm2, ymm0, ymm2
        cmp     esi, edx
        jne     SHORT $LL16@accumulate
        vpaddd  ymm0, ymm1, ymm2
        vphaddd ymm0, ymm0, ymm0
        vphaddd ymm1, ymm0, ymm0
        vextracti128 xmm0, ymm1, 1
        vpaddd  xmm0, xmm1, xmm0
        vmovd   eax, xmm0
$LN23@accumulate:
        cmp     ecx, edi
        je      SHORT $LN15@accumulate
$LL22@accumulate:
        movsx   edx, BYTE PTR [ecx]
        inc     ecx
        add     eax, edx
        cmp     ecx, edi
        jne     SHORT $LL22@accumulate
$LN15@accumulate:
        pop     edi
        pop     esi
        pop     ebx
        vzeroupper
        ret     0
unsigned int accumulate_epi8(std::vector<signed char,std::allocator<signed char> > const &) ENDP ; accumulate_epi8
