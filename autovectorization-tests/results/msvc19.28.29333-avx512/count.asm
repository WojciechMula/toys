_v$ = 8                                       ; size = 4
unsigned int count_epi32(std::vector<int,std::allocator<int> > const &) PROC ; count_epi32, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        mov     eax, 42                             ; 0000002aH
        push    ebx
        vpbroadcastd zmm6, eax
        push    esi
        mov     esi, DWORD PTR [ecx+4]
        xor     ebx, ebx
        mov     ecx, DWORD PTR [ecx]
        mov     eax, esi
        sub     eax, ecx
        xor     edx, edx
        add     eax, 3
        shr     eax, 2
        push    edi
        xor     edi, edi
        cmp     ecx, esi
        cmova   eax, ebx
        test    eax, eax
        je      $LN21@count_epi3
        cmp     eax, 32                             ; 00000020H
        jb      $LN21@count_epi3
        vpbroadcastd zmm3, edx
        mov     edx, 1
        and     eax, -32                      ; ffffffe0H
        vmovdqu32 zmm4, zmm3
        vpbroadcastd zmm5, edx
        npad    9
$LL14@count_epi3:
        vmovdqu32 zmm0, ZMMWORD PTR [ecx]
        vpcmpd  k1, zmm0, zmm6, 0
        vpmovm2d zmm2, k1
        vpaddd  zmm0, zmm3, zmm5
        vpandd  zmm0, zmm0, zmm2
        vpandnd zmm1, zmm2, zmm3
        vpord   zmm3, zmm0, zmm1
        vmovdqu32 zmm0, ZMMWORD PTR [ecx+64]
        vpcmpd  k1, zmm0, zmm6, 0
        vpmovm2d zmm2, k1
        vpaddd  zmm0, zmm4, zmm5
        add     edi, 32                             ; 00000020H
        sub     ecx, -128               ; ffffff80H
        vpandnd zmm1, zmm2, zmm4
        vpandd  zmm0, zmm0, zmm2
        vpord   zmm4, zmm0, zmm1
        cmp     edi, eax
        jne     SHORT $LL14@count_epi3
        vpaddd  zmm1, zmm3, zmm4
        vextracti32x8 ymm0, zmm1, 1
        vpaddd  ymm1, ymm0, ymm1
        vextracti32x4 xmm0, ymm1, 1
        vpaddd  xmm1, xmm0, xmm1
        vpsrldq xmm0, xmm1, 8
        vpaddd  xmm1, xmm0, xmm1
        vpsrldq xmm0, xmm1, 4
        vpaddd  xmm0, xmm0, xmm1
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
        mov     eax, 42                             ; 0000002aH
        push    ebx
        push    esi
        vpbroadcastd zmm6, eax
        mov     esi, DWORD PTR [ecx+4]
        xor     ebx, ebx
        mov     ecx, DWORD PTR [ecx]
        mov     eax, esi
        sub     eax, ecx
        xor     edx, edx
        push    edi
        xor     edi, edi
        cmp     ecx, esi
        cmova   eax, ebx
        test    eax, eax
        je      $LN21@count_epi8
        cmp     eax, 32                             ; 00000020H
        jb      $LN21@count_epi8
        vpbroadcastd zmm3, edx
        mov     edx, 1
        and     eax, -32                      ; ffffffe0H
        vmovdqu32 zmm4, zmm3
        vpbroadcastd zmm5, edx
$LL14@count_epi8:
        vpmovsxbd zmm0, XMMWORD PTR [ecx]
        vpcmpd  k1, zmm0, zmm6, 0
        vpmovm2d zmm2, k1
        vpaddd  zmm0, zmm3, zmm5
        vpandd  zmm0, zmm0, zmm2
        vpandnd zmm1, zmm2, zmm3
        vpord   zmm3, zmm0, zmm1
        vpmovsxbd zmm0, XMMWORD PTR [ecx+16]
        vpcmpd  k1, zmm0, zmm6, 0
        vpmovm2d zmm2, k1
        vpaddd  zmm0, zmm4, zmm5
        add     edi, 32                             ; 00000020H
        add     ecx, 32                             ; 00000020H
        vpandnd zmm1, zmm2, zmm4
        vpandd  zmm0, zmm0, zmm2
        vpord   zmm4, zmm0, zmm1
        cmp     edi, eax
        jne     SHORT $LL14@count_epi8
        vpaddd  zmm1, zmm3, zmm4
        vextracti32x8 ymm0, zmm1, 1
        vpaddd  ymm1, ymm0, ymm1
        vextracti32x4 xmm0, ymm1, 1
        vpaddd  xmm1, xmm0, xmm1
        vpsrldq xmm0, xmm1, 8
        vpaddd  xmm1, xmm0, xmm1
        vpsrldq xmm0, xmm1, 4
        vpaddd  xmm0, xmm0, xmm1
        vmovd   edx, xmm0
$LN21@count_epi8:
        cmp     ecx, esi
        je      SHORT $LN28@count_epi8
        npad    8
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
