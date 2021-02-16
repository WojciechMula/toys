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
        cmp     eax, 32                             ; 00000020H
        jb      SHORT $LN23@accumulate
        vpbroadcastd zmm0, edx
        and     eax, -32                      ; ffffffe0H
        vmovdqu32 zmm1, zmm0
        npad    7
$LL16@accumulate:
        vpaddd  zmm0, zmm0, ZMMWORD PTR [ecx]
        vpaddd  zmm1, zmm1, ZMMWORD PTR [ecx+64]
        add     esi, 32                             ; 00000020H
        sub     ecx, -128               ; ffffff80H
        cmp     esi, eax
        jne     SHORT $LL16@accumulate
        vpaddd  zmm1, zmm0, zmm1
        vextracti32x8 ymm0, zmm1, 1
        vpaddd  ymm1, ymm0, ymm1
        vextracti32x4 xmm0, ymm1, 1
        vpaddd  xmm1, xmm0, xmm1
        vpsrldq xmm0, xmm1, 8
        vpaddd  xmm1, xmm0, xmm1
        vpsrldq xmm0, xmm1, 4
        vpaddd  xmm0, xmm0, xmm1
        vmovd   edx, xmm0
$LN23@accumulate:
        cmp     ecx, edi
        je      SHORT $LN29@accumulate
        npad    3
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
        xor     ebx, ebx
        mov     esi, DWORD PTR [ecx+4]
        mov     edx, esi
        mov     ecx, DWORD PTR [ecx]
        sub     edx, ecx
        push    edi
        xor     edi, edi
        cmp     ecx, esi
        cmova   edx, ebx
        test    edx, edx
        je      SHORT $LN23@accumulate
        cmp     edx, 32                             ; 00000020H
        jb      SHORT $LN23@accumulate
        vpbroadcastd zmm1, eax
        and     edx, -32                      ; ffffffe0H
        vmovdqu32 zmm2, zmm1
$LL16@accumulate:
        vpmovsxbd zmm0, XMMWORD PTR [ecx]
        vpaddd  zmm1, zmm1, zmm0
        vpmovsxbd zmm0, XMMWORD PTR [ecx+16]
        add     edi, 32                             ; 00000020H
        add     ecx, 32                             ; 00000020H
        vpaddd  zmm2, zmm2, zmm0
        cmp     edi, edx
        jne     SHORT $LL16@accumulate
        vpaddd  zmm1, zmm1, zmm2
        vextracti32x8 ymm0, zmm1, 1
        vpaddd  ymm1, ymm0, ymm1
        vextracti32x4 xmm0, ymm1, 1
        vpaddd  xmm1, xmm0, xmm1
        vpsrldq xmm0, xmm1, 8
        vpaddd  xmm1, xmm0, xmm1
        vpsrldq xmm0, xmm1, 4
        vpaddd  xmm0, xmm0, xmm1
        vmovd   eax, xmm0
$LN23@accumulate:
        cmp     ecx, esi
        je      SHORT $LN15@accumulate
        npad    4
$LL22@accumulate:
        movsx   edx, BYTE PTR [ecx]
        inc     ecx
        add     eax, edx
        cmp     ecx, esi
        jne     SHORT $LL22@accumulate
$LN15@accumulate:
        pop     edi
        pop     esi
        pop     ebx
        vzeroupper
        ret     0
unsigned int accumulate_epi8(std::vector<signed char,std::allocator<signed char> > const &) ENDP ; accumulate_epi8
